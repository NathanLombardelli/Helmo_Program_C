#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sighandler(int signum);

int main(void)
{
    if(signal(SIGUSR1, sighandler) == SIG_ERR)
    {
        printf("Erreur sur la gestion du signal\n");
        exit(-1);
    }
    while(1)
    {
        sleep(1);
        printf("Hello\n");
    }
    return EXIT_SUCCESS;
}

void sighandler(int signum)
{
    printf("SIGUSR1 reçu\n");
}
