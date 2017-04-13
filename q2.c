#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

struct student {
	int age;
	char* name;
};

struct node {
	int item;
	struct node *next;
};

void increase_age(struct student s, int amt){
	s.age += amt;
}

// Compute the sume of an array of integers
int compute_sum(int numbers[]){
	int sum = 0;
	printf("q2(f): size of numbers = %zu\n", sizeof(numbers));
	for(int i = 0; i < sizeof(numbers); i++){
		sum += numbers[i];
	}
	return sum;
}

int piping(){
	int fd[2];
	pipe(fd);
	int result = fork();
	if(result == 0){
		// child process
		close(fd[0]);
		// fd[0] is used to reading
		write(fd[1], "csc209", 7);
		// fd[1] is used to writing
		close(fd[1]);
		printf("[CHILD] pid = %d\n", getpid());
	}else{
		wait(NULL);
		close(fd[1]);
		char buf[7];
		read(fd[0], buf, 7);
		printf("q2(g): %s\n", buf);
		close(fd[0]);
		printf("[PARENT] pid = %d\n", getppid());
		return 1;
	}
	exit(0);
}

// Compute the sum of the items in a linked list with the given head,
// but do not modify the list
int sum(struct node *head){
	int s = 0;
	while (head != NULL){
		printf("sum: at %d\n", head->item);
		s += head->item;
		head = head->next;
	}
	return s;
}

int main(int argc, char **argv){
	char *s;
	s = malloc(14);
	strcpy(s, "Hello");
	strcat(s, ", World!");
	s[13] = '\0';
	printf("q2(a): %s\n", s);

	if(argc == 0){
		printf("do not have a enough argument\n");
		exit(1);
	}
	char ch;
	char *p = &ch;
	ch = argv[argc-1][0];
	printf("q2(b): %c\n", p[0]);

	struct student *hannah = NULL;
	hannah = malloc(sizeof(struct student));
	if( hannah != NULL){
		hannah->age = 10;
	}
	//hannah.name = malloc(14);
	//strcpy(hannah.name, "Hannah");
	hannah->name = "Hannah123456789101112131415161718192021222324";
	printf("q2(c): %s\n", (*hannah).name);

	struct student rob;
	rob.age = 10;
	increase_age(rob, 5);
	printf("q2(e): %d should be 15\n", rob.age);

	int number_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int result = compute_sum(number_array);
	printf("q2(f): result = %d should be 55\n", result);

	// q2(g) piping
	piping();

	// q2(h) sum from linked list
	struct node* head;
	struct node* temp;

	//struct node  temp2;

	head = malloc(sizeof(struct node));
	// before we assign head to temp, we need to initialize
	// be careful that you cannot assign the pointer before you allocate
	// the memory for it
	temp = head;

	//temp = &temp2;
	// if we make an simple non pointer struct node temp2, we can assign
	// the address of temp2 to the pointer as by default, c automatically 
	// gives memory for temp2 at stack, but c will not give memory for
	// pointer variable
	for(int i = 1; i <= 10; i++){
		temp->item = i;
		if(i != 10){
			temp->next = malloc(sizeof(struct node));
		}else{
			temp->next = NULL;
		}
		// we assigned the memory for the temp->next so we can replace
		// the memory of temp
		temp = temp->next;
	}
	printf("q2(h): head = %d\n", head->item);
	//result = sum(&temp2);
	// if we use temp2, which is struct node, we need to input its address as
	// function sum takes pointer of struct node
	result = sum(head);
	printf("q2(h): %d\n", result);

	// q2(i)
	// Remove the dots from word
	char* word = "Ex.ampl.e";
	char* resulti = malloc(strlen(word) + 1); // upper-limit of  not dots
	int j = 0;
	for(int i = 0; i < strlen(word); i++){
		if(word[i] != '.'){
			resulti[j] = word[i];
			j ++;
		}
	}
	printf("q2(i): result = %s\n", resulti);

	return 0;
}
