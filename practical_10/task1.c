/*Program to demonstrate pipes in OS
 * Code Written By:Om Chetwani
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFF_SIZE 40
int main()
{
	int pipe1[2],pipe2[2];
	char r[BUFF_SIZE];
	pipe(pipe1);
	pipe(pipe2);
	pid_t p = fork();
	if(p<0)
		printf("Child not Created!!\n");
	else if(p>0)//Parent
	{
		char w[BUFF_SIZE] = "I'm your Daddy";
		printf("\nParent pid:%d",getpid());
		write(pipe1[1],w,BUFF_SIZE);
		read(pipe2[0],r,BUFF_SIZE);
		printf("\n%s\n",r);
	}
	else if(p==0)//Child
	{
		read(pipe1[0],r,BUFF_SIZE);
		printf("%s",r);
		char cw[BUFF_SIZE]="I'm Child";
		write(pipe2[1],cw,BUFF_SIZE);
		printf("\nChild id:%d\n",getpid());
	}
	return 0;
}
