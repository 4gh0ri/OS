#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
	printf("\nChild of P1 Started\n");
	printf("\nPID of P1 Child:%d\n",getpid());
	}
	else
	{
	printf("\nParent of P1 Started\n");
	printf("\nPID of P1 Parent:%d\n",getpid());
	}
	sleep(100);
}