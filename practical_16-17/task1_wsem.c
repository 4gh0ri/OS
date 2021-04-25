#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;//Declaring Semaphore
int c,x,totalhits=0;
void* thrd()
{
	c++;
	totalhits++;
	printf("Thread %d is entering...\n",c);
	printf("Total Website hit so far =%d\n",totalhits);
	if (c == 10)
	x=0;
}

int main()
{
	pthread_t t1,t2,t3;
	//Creating Threads
	pthread_create(&t1,NULL,thrd,NULL);
	pthread_create(&t2,NULL,thrd,NULL);
	pthread_create(&t3,NULL,thrd,NULL);
	pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
	return 0;
}