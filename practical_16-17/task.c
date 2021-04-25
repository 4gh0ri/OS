#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int c,x;
char str[500];
FILE *fp
void* append()
{
	sem_wait(&sem);
	c++;
	fp = fopen("/home/photon/Christ/practical_16-17/bca.txt","a");
	printf("Thread %d is entering...\n",c);
	printf("Enter Sentence:%\n");
	fgets(str,sizeof(str),stdin);
	fclose(fp);
	printf("Thread %d is exiting...\n",c);
	sem_post(&sem);
}

int main()
{
	sem_init(&sem,0,1);
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,thrd,NULL);
	pthread_create(&t2,NULL,thrd,NULL);
	pthread_create(&t3,NULL,thrd,NULL);
	pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    fp = fopen("/home/photon/Christ/practical_16-17/bca.txt","r");
    printf("---Contents of File---\n");
    fscanf(fp,"%s",str);
    printf("%s\n",str);
    fclose(fp);
    fprintf(stderr, "%s\n", );
    sem_destroy(&sem);
	return 0;
}