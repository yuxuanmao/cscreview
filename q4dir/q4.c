#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void replacer(char* fp_name){
	printf("file name = %s\n", fp_name);
	char buf;
	FILE* fp = fopen(fp_name, "r+");
	if(fp == NULL){
		// file does not exit
		perror("fopen");
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	// we are going to read one char so it would be appropriate
	// for us to use fgetc instead of fread
	while(1){
		//buf = fgetc(fp);
		fread(&buf, 1, 1, fp);
		if(feof(fp)){
			break;
		}
		printf("buf = %c\n", buf);
		if(buf == 'a'){
			// fseek by setting the begging from 0 will
			// cause to point to the next char
			fseek(fp, -1, SEEK_CUR);
			buf = 'Z';
			// if(putc(buf, fp) == EOF)
			if(fwrite(&buf, 1, 1, fp) != 1){
				perror("fwrite");
				exit(2);
			}
		}
	}
	fclose(fp);
}

int main(int argc, char** argv){
	if(argc != 2){
		// we expect "replacer data.txt"
		printf("usage: replacer <filename>\n");
		exit(1);
	}
	replacer(argv[1]);
	return 0;
}
