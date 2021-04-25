#include <stdio.h>  
//#include <iostream>  
#include <string.h>  
// Required by for routine  
#include <sys/types.h>  
#include <unistd.h>  
#include <stdlib.h>  
char string1[] = "\n Hello";  
char string2[] = " CS560.\n";  
int main(void)  
{  
pid_t PID;  
PID = fork();  
if (PID == 0) /* Child process */  printf("%s", string2);  
else /* Parent process */  
printf("%s", string1);  
exit(0); /* Executed by both processes */  } 
