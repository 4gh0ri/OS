// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is not waiting
// when child process exits. 

#include <stdio.h>  //printf
#include <stdlib.h> //exit
#include <sys/types.h> //fork
#include <unistd.h> //fork and sleep

int main() 
{ 
    // Fork returns process id 
    // in parent process 
    pid_t child_pid = fork(); 
 
    // Parent process didn't use wait 
    // so the child becomes a zombie process

    // Parent process 
    if (child_pid > 0){ 
        sleep(1); //sleep for 1 second
        printf("\nI don't wait for my child");
    }
    else // Child process 
        if(child_pid == 0){ 
            printf("My parent doesn't wait me");
            exit(0);
        }
        else{
            //error occurred
        }
    
    return 0; 
}
