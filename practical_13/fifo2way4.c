# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <string.h>
void main ()
{
char *fifow1="/home/photon/Christ/practical_13/fifow1";
char *fifow2="/home/photon/Christ/practical_13/fifow1";
int fd,i,b=0,j;
char s[100],c[100],g[100]="christ";
mkfifo("fifow1",0666);
mkfifo("fifow2",0666);
printf("Waiting for the String from the client....\n");
while(1)
{
fd=open("fifow1",O_RDONLY);
read(fd,c,100);
close(fd);
printf("Received the string from the client is %s\n",c);
b=b+1;
if (b == 5)
break;
}
fd=open("fifow2",O_WRONLY);
write(fd,g,100);
close(fd);
}
