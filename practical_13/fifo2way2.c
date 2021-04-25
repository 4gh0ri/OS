#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
void main ()
{
char *fifo1="/home/photon/Christ/practical_13/fifow1";
char *fifo2="/home/photon/Christ/practical_13/fifow2";
int fd,j=0;
char s[100],c[100];
mkfifo("fifow1",0666);
mkfifo("fifow2",0666);
while(1)
{
fd=open("fifow1",O_WRONLY);
printf("Enter a string:");
fgets(s,100,stdin);
write(fd,s,100);
close(fd);
fd=open("fifow2",O_RDONLY);
read(fd,s,100);
close(fd);
printf("Received the string from the server is =%s \n",s);
}
}
