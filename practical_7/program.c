#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main()
{
float t=8, r=8,result;time_t t1; 
  /* Intializes random number generator */   
srand((unsigned) time(&t1));
float randmP = rand() %100;
for (int i=i;i<=t;++i)
randmP = randmP + (randmP*r)/100;   
 printf("Final Payment = %f\n",randmP); 
return 0;
}
