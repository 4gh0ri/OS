#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
	printf("\nChild of P3 Started\n");
	printf("\nPID of P3 Child:%d\n",getpid());
	}
	else
	{
	printf("\nParent of P3 Started\n");
	printf("\nPID of P3 Parent:%d\n",getpid());
	}
	sleep(100);
}
