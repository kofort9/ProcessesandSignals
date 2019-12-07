/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n");
  exit(1); //exit after printing
}
int condition = 1;
int main(int argc, char * argv[])
{
  //signal(SIGALRM,handler); //register handler to handle SIGALRM
  //alarm(1); //Schedule a SIGALRM for 1 second
  signal(SIGINT,handler);
  while(condition); //busy wait for signal to be delivered
  return 0; //never reached
}
