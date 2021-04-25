#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int count=0;
int num=965;
pthread_mutex_t loc;
void *fun()

{
	pthread_mutex_lock(&loc);
	int arr[100];
	int n = num * 2 + (rand()%100);
	int t = n;
	int k,j,m=0;
	printf("\nThread %d has started.\n",count);
	count++;
	printf("\nThread %d has started.\n",count);
	while(n!=0)
	{
	 	if(n%2==0)
		arr[j] = 0;
		else
		arr[j] = 1;
		j++;
		n = n/2;
	}
	printf("\nThe binary value of %d is : ",t);
	for(k=0,m=j-1;k<j;k++,m--)
	printf("%d",arr[m]);
	printf("\nThread %d has finished.\n\n",count);
	pthread_mutex_unlock(&loc);
}

void main()
{
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,fun,NULL);
	pthread_create(&t2,NULL,fun,NULL);
	pthread_create(&t3,NULL,fun,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}