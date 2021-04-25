#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 	 
	int pid = fork(); 
	if (pid > 0) 
		printf("parent process with pid:%d\n",getpid());  
	else if (pid == 0) 
	{ 
		sleep(30); 
		printf("\nchild process with pid:%d\n",getpid()); 
	} 
	return 0; 
} 

