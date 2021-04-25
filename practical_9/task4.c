#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t p1=fork();
	pid_t p2=fork();
	printf("\nParent pid:%d ppid:%d",getpid(),getppid());
	if(p1==0 && p2>0)//child_1
	{
		printf("\nChild 1 pid:%d ppid:%d\n",getpid(),getppid());
		pid_t p3=fork();
		if(p3==0)//child of child_1
		{
			printf("\nChild of Child 1 pid:%d ppid:%d\n",getpid(),getppid());
		}
	}
	else if (p1>0 && p2==0)//child_2
	{
		printf("\nChild 2 pid:%d ppid:%d\n",getpid(),getppid());
		pid_t p4=fork();
		if(p4==0)//child of child_2
		{
			printf("\nChild of Child 2 pid:%d ppid:%d\n",getpid(),getppid());
		}
	}
	wait(NULL);
	return 0;
}
