#include<stdio.h>  
#include<stdlib.h>  
#include<sys/types.h>  
#include<sys/stat.h>  
#include<unistd.h>  
#include<errno.h>  
int main (int argc, char *argv[]) 
{
pid_t pid;
pid = fork ();
printf ("1st Fork\n");
printf ("Process ID : %d, Parent Process ID : %d\n", getpid (),getppid ());
pid = fork ();
printf ("2nd Fork\n");
printf ("Process ID : %d, Parent Process ID : %d\n", getpid (),getppid ());
pid = fork ();
printf ("3rd Fork\n");
printf ("Process ID : %d, Parent Process ID : %d\n", getpid (),getppid ());
return 0;
}
