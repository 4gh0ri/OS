/* Write a C program in UNIX platform to create a child process using fork() system call and
   make the child process to compute the Factorial of a given number.
   Code Written by Om Chetwani
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
	pid_t p;
	p=fork();
	if(p==0)
	{
		printf("Child Created!!\n");
		int i,fact=1;
		unsigned int num;
		printf("Enter a number: ");
		scanf("%u",&num);
   		for(i=1;i<=num;i++)
		{
     	 		fact=fact*i;//Calculating Factorial
  		}
  		printf("Factorial of %u is: %d\n",num,fact);
	}
	else
	{
		wait(NULL);//Waiting for child to finish
	}
}
