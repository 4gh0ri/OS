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
fd=open("myfile",O_WRONLY);
printf("\nPlease enter your input=");
fgets(s1,100,stdin);
write(fd,s1,100);
close(fd);
}
}
