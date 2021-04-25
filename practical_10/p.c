#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{

       pid_t pid;

       char buf[50],a[50],s1[50],s2[50],c[100],d[100],e[100];

       int mypipe[2],pipe2[2],i,j;

       pipe(mypipe);

       pipe(pipe2);

       pid=fork();
      
       if(pid==0)

       {

              printf("Child Process\n");

              printf("\nEnter String : ");

              fgets(a,50,stdin);

              write(pipe2[1],a,50);

              read(mypipe[0],d,100);

              printf("\nString : %s\n",d);

       }

      

       else

       {

              printf("Parent Process\n");

              read(pipe2[0],s1,50);

              printf("\nEnter String2 : ");

              fgets(s2,50,stdin);

             

              // length of s1 is stored in i

              for (i = 0; s1[i]!='\0';++i)

              {

              c[i]=s1[i];

              }

 

              j=0;

      

              while(s2[j]!='\0')

              {

                     c[i]=s2[j];

                     i++;

                     j++;

              }

             

              c[i]='\0';

              j=0;

 

              for(i=i-1;i>=0;i--)

              {

                     e[j]=c[i];

                     j++;

              }

             

              e[j]='\0';

             

              write(mypipe[1],e,100);

       }

}

 


