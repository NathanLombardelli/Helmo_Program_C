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
    switch(fork())
    {
    case -1:
        printf("Erreur fork()\n");
        exit(-1);
    case 0:
        printf("Je suis le fils %d\n", getpid()) ;
        while(1)
        {
            sleep(5);
            kill(getppid(), SIGUSR1);
        }
    default:
        while(1)
        {
            printf("Je suis le père\n");
            sleep(1);
        }
    }
    return EXIT_SUCCESS;
}
void sighandler(int signum)
{
    printf("SIGUSR1 reçu\n");
}
