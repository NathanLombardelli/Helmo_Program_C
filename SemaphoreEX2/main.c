#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "semadd.h"

#define SEM1 1293
#define SEM2 1294
#define MAX_TAMPON 100

int sem1, sem2;
int tampon[MAX_TAMPON];
void* producteur(void* arg)
{
    int i, queue=0, mess_prod;
    srand(SEM1);
    for(i=0; i<20; ++i)
        Synchronisation, mémoire partagée et section critique 9
    {
        sleep(rand()%3);
        mess_prod = rand() % 100;
        printf("Product %d\n", mess_prod);
        p(sem1);
        tampon[queue]= mess_prod;
        v(sem2);
        queue++;
    }
    pthread_exit(NULL);
}
void* consommateur(void* arg)
{
    int tete=0, mess_cons, i;
    srand(SEM2);
    for(i=0; i<20; ++i)
    {
        p(sem2);
        mess_cons = tampon[tete];
        v(sem1);
        tete++;
        printf("\t\tConsomm %d\n", mess_cons);
        sleep(rand()%3);
    }
    pthread_exit(NULL);
}
int main(void)
{
    pthread_t tid1, tid2;
    /* Création des sémaphores */
    if((sem1 = sem_transf(SEM1)) == -1)
        printf("Erreur sem_transf SEM1\n");
    if((sem2 = sem_transf(SEM2)) == -1)
        printf("Erreur sem_transf SEM2\n");
    /* Création des threads */
    if((pthread_create(&tid1, NULL, producteur, NULL)) == -1)
    {
        printf("Erreur création thread1\n");
        exit(-1);
    }
    if((pthread_create(&tid2, NULL, consommateur, NULL)) == -1)
    {
        printf("Erreur création thread 2\n");
        exit(-1);
    }
    v(sem1);
    /* Attente des terminaisons des threads */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    /* Libération des ressources et fin */
    semctl(sem1, 0, IPC_RMID, NULL);
    semctl(sem2, 0, IPC_RMID, NULL);
    return EXIT_SUCCESS;
}
