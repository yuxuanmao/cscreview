#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>


static int count = 0;
void handler(int code){
	fprintf(stderr, "quit poking me\n");
	count ++;
}

int main(){
	// declare struct sigaction
	struct sigaction newact;
	// specify we want to use handler for signal
	newact.sa_handler = handler;
	// we set the default flags
	newact.sa_flags = 0;
	// specify we do not want to receive multiple signals
	sigemptyset(&newact.sa_mask);
	// set what kind of signal received would call handler
	sigaction(SIGUSR1, &newact, NULL);

	int result;
	result = fork();
	if(result == 0){
		int p[2];
		pipe(p);
		result = fork();
		if(result == 0){
			for(int i = 0; i < 10000; i++){
				printf("[CHILD of CHILD] %d\n", i);
			}
			exit(count);
		}else if(result > 0){
			int status2;
			int child2 = -1;
			while(1){
				sleep(1);
				kill(getpid(), 10);
				if(kill(getpid(), 0)){
					break;
				}
			}
			child2 = WEXITSTATUS(status2);
			exit(child2);
		}else{
			perror("fork2");
			exit(0);
		}
	}else if(result > 0){
		int status1;
		int child1 = -1;
		if(wait(&status1) != -1){
			child1 = WEXITSTATUS(status1);
		}
		return child1;
	}else{
		perror("fork1");
		exit(0);
	}
}
