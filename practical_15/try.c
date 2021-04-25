#include <stdio.h>
#include <pthread.h>	
#include <semaphore.h>		//For semaphores

pthread_mutex_t mutex;

int factorial(int num)
{
    if (num <= 0)
        return 1;

    return num * factorial(num - 1);
}

void *fact()
{
	int num=0;
	pthread_mutex_lock(&mutex);
	printf("\nFactorial of a number\n");
	printf("Enter no.:");
	scanf("%d",&num);
    printf("\nFactorial of %d is:%d\n", num, factorial(num));
    pthread_mutex_unlock(&mutex);
}

void *fib()
{
	int i, n, t1 = 0, t2 = 1, nextTerm;
	pthread_mutex_lock(&mutex);
	printf("\nFIBONACCI SERIES\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) 
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,(void *)fib,NULL);
	pthread_create(&t2,NULL,(void *)fact,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	return 0;
}

