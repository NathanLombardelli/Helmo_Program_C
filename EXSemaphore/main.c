#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "semadd.h"

#define SEM1 12345
#define SEM2 23456

int main(void)
{
    int sem1, sem2, i;
    sem1=sem_transf(SEM1);
    sem2=sem_transf(SEM2);
    switch(fork())
    {
    case -1:
        printf("Erreur fork()\n");
        exit(-1);
    case 0:
        printf("Je suis le fils %d\n", getpid()) ;
        for(i=0; i<5; ++i)
        {
            printf("[FILS] Valeur de i : %d\n",i);
            sleep(5);
            v(sem2);
            p(sem1);
        }
    default:
        for(i=0; i<5; ++i)
        {
            p(sem2);
            printf("[PERE] Je suis le père\n");
            sleep(5);
            v(sem1);
        }
    }
    return EXIT_SUCCESS;
}
