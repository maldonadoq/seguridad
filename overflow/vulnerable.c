#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("You must supply a value\n");
		exit(0);
	}

	char buffer[10];
	strcpy(buffer,argv[1]);
	printf("The value is %s\n", buffer);	
	return 0;
}