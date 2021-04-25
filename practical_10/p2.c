/*Program to demonstrate pipes in OS
 * Code Written By:Om Chetwani
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFF_SIZE 40
int main()
{
        int pipe1[2],pipe2[2];
        char r[BUFF_SIZE],str1[BUFF_SIZE],temp;
        pipe(pipe1);
        pipe(pipe2);
	int i,j;
        char str2[BUFF_SIZE]="!!nuf si ";
        pid_t p = fork();
        if(p<0)
                printf("Child not Created!!\n");
        else if(p>0)//Parent
        {
                read(pipe2[0],r,BUFF_SIZE);
                strcat(r,str2); //Concatenation
		i=0;
 		 j=strlen(r)-1;
		  while(i<j){
		temp=r[i];
		r[i]=r[j];
		r[j]=temp;
		i++;
		j--;
		  }
                //strrev(r);  //Reversing string
                write(pipe1[1],r,BUFF_SIZE);
        }
        else if(p==0)//Child
        {
                printf("Enter String:");
                fgets(str1,20,stdin);
                write(pipe2[1],str1,BUFF_SIZE);
                read(pipe1[0],str1,BUFF_SIZE);
                printf("%s",str1);
        }
        return 0;
}
