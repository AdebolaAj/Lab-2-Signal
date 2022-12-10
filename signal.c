/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

bool go_on = true;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  go_on = false;
  // exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  //Schedule a SIGALRM for 1 second
  while(1) { //busy wait for signal to be delivered
    alarm(1);
    while(go_on);
    printf("Turning was right!\n");
    go_on = true;
  }
  return 0; //never reached
}
