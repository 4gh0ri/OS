#include <stdio.h>
#include <stdlib.h>

int mutex = 1;  
// Number of full slots as 0
int full = 0;
  
// Number of empty slots as size
// of buffer
int empty = 10, x = 0;
  
// Function for producer
void producer()
{
    // Decrease mutex value by 1
    --mutex;
  
    // Increase the number of full
    // slots by 1
    ++full;
  
    // Decrease the number of empty
    // slots by 1
    --empty;
  
    // Item produced
    x++;
    printf("\nProducer produces "
           "item %d",
           x);
  
    // Increase mutex value by 1
    ++mutex;
}
  
// Function for consumer
void consumer()
{
    // Decrease mutex value by 1
    --mutex;
  
    // Decrease the number of full
    // slots by 1
    --full;
  
    // Increase the number of empty
    // slots by 1
    ++empty;
    printf("\nConsumer consumes "
           "item %d",
           x);
    x--;
  
    // Increase mutex value by 1
    ++mutex;
}
  
int main()
{
    int n, i;
    printf("\n1.Producer"
           "\n2.Consumer"
           "\n3.Exit");

#pragma omp critical
  
    for (i = 1; i > 0; i++) {
  
        printf("\nEnter your choice:");
        scanf("%d", &n);
  
        // Switch Cases
        switch (n) {
        case 1:
  
            // If mutex is 1 and empty
            // is non-zero, then it is
            // possible to produce
            if ((mutex == 1)
                && (empty != 0)) {
                producer();
            }
  
            // Otherwise, print buffer
            // is full
            else {
                printf("Buffer is full!");
            }
            break;
  
        case 2:
  
            // If mutex is 1 and full
            // is non-zero, then it is
            // possible to consume
            if ((mutex == 1)
                && (full != 0)) {
                consumer();
            }
  
            // Otherwise, print Buffer
            // is empty
            else {
                printf("\nBuffer is empty!");
            }
            break;
  
        // Exit Condition
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
