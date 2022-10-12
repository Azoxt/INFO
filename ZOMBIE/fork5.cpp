 #include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

/*
int main(int argc, char** argv)
{
  int pid;
  int i = 1;
  int NombreZombies  = 5; // Nombre de zombies à crée
  int VitesseCreation = 1; // Vitesse de creation des zombies

  for (i; i <= NombreZombies; i++)
  {
    pid = fork();
  if (pid == 0) // processus fils
    {
      printf("Creation du NombreZombies : %d\n", i);
      exit(1);
    }
  else // processus pere
    {
      sleep(VitesseCreation);
    }
  }
  return 0; 
}

*/
int main(int argc, char** argv)
{
  int pid;
  int i = 1;
  int NombreZombies  = 5; // Nombre de zombies à crée
  int VitesseCreation = 1; // Vitesse de creation des zombies

  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction (SIGUSR1, &sa, NULL);
  pid_t child_pid;
  cout << "pid de ce processus : " << getpid () << endl;
  child_pid = fork ();
  if (child_pid <= NombreZombies; i++) {
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