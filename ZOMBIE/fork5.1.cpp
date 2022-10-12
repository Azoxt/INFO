#include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

int main(int argc, char** argv)
{
  int i;
/*
  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction (SIGUSR1, &sa, NULL);
*/
  i = fork();
  pid_t child_pid;
  pid_t child_pid2;
  child_pid = fork();
  child_pid2 = fork();


  cout << "PID du Pere : " << i << endl;
  cout << "PID du fils : " << child_pid << endl;
  cout << "PID du fils : " << child_pid2 << endl;    
/*
  if (child_pid <= 0; i++)
  {

  }
*/
} 