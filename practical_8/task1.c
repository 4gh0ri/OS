#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
	pid_t p=fork();
	if(p>0)
	{
		printf("PID:%d PPID: %d I am the Parent\n",getpid(),getppid());
	}
	else if (p==0)
	{
		printf("\nPID:%d PPID: %d I am the Child\n",getpid(),getppid());
	}
	else
		printf("ERROR!!");
}
