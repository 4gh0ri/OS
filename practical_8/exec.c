#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("exec called\n");
    printf("New process started with same PID:%d\n",getpid());
    //printf("PID: %d\n", getpid());
    return 0;
}
