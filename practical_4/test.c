#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
	printf("\nChild of test Started\n");
	printf("\nPID of test Child:%d\n",getpid());
	printf("\nPPID of test CHild:%d",getppid());
	}
	else
	{
	printf("\nParent of test Started\n");
	printf("\nPID of test Parent:%d\n",getpid());
	printf("\n PPID of test Parent:%d",getppid());
	}
	sleep(100);
}
