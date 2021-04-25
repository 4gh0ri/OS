#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *s1(void *str1)
{
char *c1;
c1=(char *)str1;
for(int i=0;i<4;i++)
{
sleep(1);
printf("Thread=%d %s \n",i,c1);
}
}
void *s2(void *str2)
{
char *c1;
c1=(char *)str2;
for(int i=0;i<4;i++)
{
sleep(1);
printf("Thread2=%d %s \n",i,c1);
}
}
void main()
{
pthread_t t1,t2;
char *ch1="First Thread";
char *ch2="Second Thread";
pthread_create(&t1,NULL,s1,(void *)ch1);
pthread_create(&t2,NULL,s2,(void *)ch2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
