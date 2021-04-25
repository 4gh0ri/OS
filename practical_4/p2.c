#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
	printf("\nChild of P2 Started\n");
	printf("\nPID of P2 Child:%d\n",getpid());
	}
	else
	{
	printf("\nParent of P2 Started\n");
	printf("\nPID of P2 Parent:%d\n",getpid());
	}
	sleep(100);
}
