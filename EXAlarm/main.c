#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sighandler(int signum);
int main(void)
{
    int result;
    if(signal(SIGALRM, sighandler) == SIG_ERR)
    {
        printf("Erreur sur la gestion du signal\n");
        exit(-1);
    }
    while(1)
    {
        alarm(5);
        printf("Calculer 2+2 =");
        scanf("%d%*c",&result);
        alarm(0); /* Réponse reçue, arret du chronomètre */
        if(result == 4)
            printf("Correct\n");
        else
            printf("Incorrect\n");
    }
    return EXIT_SUCCESS;
}
void sighandler(int signum)
{
    printf("Temps imparti écoulé\n");
    exit(0);
}
