#include <stdio.h>
//#include <iostream.h>
#include <string.h>		// Required by for routine
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void main () 
{
int pid;
pid = fork ();
  
if (pid < 0)
    {				// error occurred
    fprintf (stderr,"Fork failed! \n");
    exit (-1);
    }
else if (pid == 0)
{				// child process
 printf ("I am the child, return from fork = %d \n", pid);
}
  else
{				//parent process 
printf ("I am the parent, return from fork, child pid =%d \n", pid);
printf ("Parent exiting! \n");
exit (0);
}
}
