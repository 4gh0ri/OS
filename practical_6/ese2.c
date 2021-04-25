/* Code Written By Om Chetwani
   Date of Submission:16/02/2021
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
void menu(void);
int main(int argc, char *argv[])
{
    int n;
    do
    {
        menu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:; //fork
	pid_t pid;
	pid =fork();
	if (pid>0)
	printf("\nParent Created with pid: %d",getpid());
	else 
	printf("\nChild Created with pid: %d",getpid());
            break;
        case 2:; //exec
	printf("PID of this code = %d\n", getpid());
    	char *args[] = {"test1", NULL};
    	execv("./t2", args);
            break;
        case 3:;//exit
		pid_t p = fork();
		if(p>0)
		{
		printf("\nParent Created");
		sleep(30);
		}
		else
		exit(0);

            break;
        case 4://wait
	 if (fork()== 0) 
        printf("Hello from Child \n"); 
   	 else
    	{ 
         printf("Hello from parent\n"); 
         wait(NULL); 
         printf("Child has terminated\n"); 
     	}
           break;
	case 5:;// kill
	pid_t ppcs=fork();
	pid_t id=getpid();
	if (ppcs>0)
	{
	printf("process started with pid:%d\n",id);
        }
	kill(id,SIGKILL);
	break;	
	}
    } while (n != 6);
}
void menu()
{
    printf("\n\n-----------------------------------------");
    printf("\n Demonstration of Different System Calls");
    printf("\n-----------------------------------------\n");
    printf("\n1) Fork");
    printf("\n2) exec");
    printf("\n3) exit");
    printf("\n4) wait");
    printf("\n5) kill");
    printf("\n6) Exit");
    printf("\nEnter your choice :");
}
