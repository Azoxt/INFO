#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <signal.h> 
void handler(int sig)
{
  printf(" (!) IMPOSSIBLE (!) %d\n", sig);
}

int main ()
{
  pid_t pid = getpid();
  printf("mon pid : %d\n", (int) pid);
  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction (SIGINT, &sa, NULL);
  while (1)
  {
      printf("(!)");
      fflush(stdout);
      sleep(1);
  }
}