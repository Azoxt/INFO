#include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;


int main(int argc, char** argv)
{
    cout << "OK" << endl;
    cout << getpid() << endl;
    pause ();
    kill (getpid(), SIGKILL );
}
