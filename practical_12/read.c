#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
char *myfifo2="/home/photon/Christ/practical_12/myfile";
char s1[100],s2[100];
int fd;
mkfifo(myfifo2,0666);
while(1)
{
fd=open("myfile",O_RDONLY);
read(fd,s1,100);
printf("Prg2:%s\n",s1);
close(fd);
}
}

