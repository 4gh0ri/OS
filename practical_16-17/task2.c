/*   Demonstrate the implementation of Semaphore for thread synchronization
     in the following scenario:
There is a resource that we want to allow only one thread at a time to 
manipulate. For example, we have a file that we only want to be written into
only by one thread at a time, to avoid corrupting its contents. Create three
threads which want to simultaneously access a file “bca.txt” for writing some
contents into the file. Implement Semaphore for Mutual Exclusion so that only
one thread at a time will be allowed to access the file for writing whereas the
other thread will be made to wait.(File should have the content of all threads)

Code Written By:4ghori*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t sem; //Declaring Semaphore
int c;
char str[1000], ch;
FILE *fp;
//Function For appending
void *append()
{
    sem_wait(&sem);
    c++;
    fp = fopen("/home/photon/Christ/practical_16-17/bca.txt", "a+"); //Opening file in append mode
    printf("Thread %d is entering...\n", c);
    printf("Enter Sentence:");
    fgets(str, sizeof(str), stdin);
    fputs(str, fp);
    fclose(fp);
    printf("Thread %d is exiting...\n\n", c);
    sem_post(&sem);
}
//Function for printing data from file
void readFile(FILE *fp)
{
    char ch;
    do
    {
        ch = fgetc(fp);
        putchar(ch);

    } while (ch != EOF);
}
int main()
{
    sem_init(&sem, 0, 1); //Intialising semaphore
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, append, NULL);
    pthread_create(&t2, NULL, append, NULL);
    pthread_create(&t3, NULL, append, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("\n---Contents of File---\n");
    fp = fopen("/home/photon/Christ/practical_16-17/bca.txt", "rt");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
    }
    readFile(fp);
    fclose(fp);
    sem_destroy(&sem);
    return 0;
}
