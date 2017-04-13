#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char** reverse(char** string_array, int string_length){
	int max = 0;
	char** result_array;
	result_array = malloc(sizeof(char*)*string_length);
	for(int i = 0; i < string_length; i++){
		if(max < strlen(string_array[i])){
			printf("q6: max = %d\n", max);
			max = strlen(string_array[i]);
		}
	}
	char reversed[max+1];
	int g = 0;
	for(int i = 0; i < string_length; i++){
		if(max == strlen(string_array[i])){
			int k = 0;
			printf("q6: max string = %s\n", string_array[i]);
			for(int j = max-1; j >= 0; j--){
				printf("q6: reversed char = %c\n", string_array[i][k]);
				reversed[j] = string_array[i][k];
				k++;
			}
			reversed[max] = '\0';
			printf("q6: reversed = %s\n", reversed);
			result_array[g] = malloc(sizeof(char*)*strlen(reversed)+1);
			result_array[g] = reversed;
			g++;
		}
	}
	result_array[g] = "\0";
	return result_array;
}

int main(){
	char* string_array[5] = {"hello", "my", "name", "is", "Leon Mao"};
	int string_length = 5;
	char** result = reverse(string_array, string_length);

	int i = 0;
	while(strcmp(result[i], "\0") != 0){
		printf("q6: %s\n", result[i]);
		i ++;
	}
	return 0;
}
