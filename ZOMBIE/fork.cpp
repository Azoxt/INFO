 #include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handler(int sig)
{
  //printf(" (!) IMPOSSIBLE (!) %d\n", sig);
}


int main(int argc, char** argv)
{
  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction (SIGUSR1, &sa, NULL);
  pid_t child_pid;
  cout << "pid de ce processus : " << getpid () << endl;
  child_pid = fork ();

  if (child_pid != 0) {
    cout << "fork à renvoyé le nombre " << child_pid << ", je suis donc le père et ce numéro est le pid du processus fils que je viens de créé." << endl;
    cout << "le mien c'est toujours : " << getpid () << endl;
    while (1)
    {
        pause();
        printf("*");
        fflush(stdout);
    }
  }
  else
  {
    cout << "fork à renvoyé le nombre 0, je suis le processus qui vient d'être créé." << endl;
    cout << "mon identifiant est : " << getpid () << endl;
    cout << "celui de mon père  est : " << getppid () << endl;
    while (1)
    {
        printf("+");
        fflush(stdout);
        kill (getppid(), SIGUSR1); //SIGURS1
        sleep(1);
    }
  }
  return 0; 
}

