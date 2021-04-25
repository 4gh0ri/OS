#include<stdio.h>
#include<sys/wait.h>
int
main ()
{
  int p1, p2;
  p1 = fork ();
  if (p1 == -1)
    {
      printf ("Error");
      return 0;
    }
  else
    {
      printf ("parent is % d \n", getppid ());
      printf ("child is % d \n", getpid ());
    }
  p2 = fork ();
  printf ("parent is % d \n", getppid ());
  printf ("child is % d \n", getpid ());
}
