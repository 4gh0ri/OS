#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem; //Declaring Semaphore
int c,x,totalhits=0;
//Function For counting hits
void* thrd()
{
	sem_wait(&sem); //Lock
	c++;
	totalhits++;
	printf("Thread %d is entering...\n",c);
	printf("Total Website hit so far =%d\n",totalhits);
	if (c == 10)
	x=0;
	sem_post(&sem); //unlock
}

int main()
{
	sem_init(&sem,0,1); //Initialising Semaphore
	pthread_t t1,t2,t3;
	//Creating Threads
	pthread_create(&t1,NULL,thrd,NULL);
	pthread_create(&t2,NULL,thrd,NULL);
	pthread_create(&t3,NULL,thrd,NULL);
	pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    sem_destroy(&sem);
	return 0;
}