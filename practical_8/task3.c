#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
void menu(void);
int main(int argc, char *argv[])
{
	    //exec
            printf("PID of this code = %d\n", getpid());
            char *args[] = {"exec", NULL};
            execv("./exec", args);
}
