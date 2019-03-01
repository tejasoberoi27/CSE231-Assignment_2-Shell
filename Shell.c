#include <unistd.h> //for syscalls
#include <stdio.h> //for scanf, printf
#include <sys/wait.h>
#include <string.h> //for strlen(), strcmp()
#include <stdlib.h> //for malloc()

char* strip(char* str){
	int len = strlen(str);
	int startI = 0;
	int endI = len-1;
	for(; str[startI]==' ' || str[startI]=='\t'; startI++);
	for(; str[endI]==' ' || str[endI]=='\n' || str[endI]=='\t'; endI--);
	
	int newStrLen = endI-startI+1;
	char* newStr = (char*)malloc(sizeof(char)*newStrLen);//[endI-startI+1];

	for(int i=startI; i<=endI; i++)
		newStr[i-startI] = str[i];
	return newStr;
}

int main (){
	char* command;
	while(strcmp(strip(command),"exit")!=0){
		scanf("%[^\n]",command);
		getchar();//to discard the newline character from STDIN
		command = strip(command);
		
	}
	// int pid, i, status;
	// printf ("main %d parent %d\n", getpid(), getppid());
	// for (i = 0; i < 3; i++) {
	// pid = fork ();
	// if (pid < 0) {
	// printf ("Unable to fork\n");
	// return 0;
	// }
	// if (pid != 0) {
	// waitpid (pid, &status, 0);
	// }
	// }
	// printf ("process %d (parent %d) is terminating\n", getpid(), getppid());
	return 0;
}

/*
1. In case strip does not work properly, can refer to Linux's implementation at https://stackoverflow.com/a/1488419/2806163

*/