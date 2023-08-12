#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/types.h>

#include "semadd.h"

#define SEM 12346
#define SHM 12347

struct compte
{
    char iban[16+1];
    double solde;
};
struct mem
{
    struct compte comptes[100];
    int nombre_compte;
};
int main(void)
{
    int choix, sem, shmid;
    struct mem* mem;
    struct compte compte_tmp;
    char iban1[16+1], iban2[16+1];
    shmid = shmget(SHM, sizeof(struct mem), 0666);
    if(shmid < 0)
    {
        union semun init;
        init.val = 1;
        shmid = shmget(SHM, sizeof(struct mem), 0666|IPC_CREAT);
        Synchronisation, mémoire partagée et section critique 13
        sem = sem_transf(SEM);
        semctl(sem, 0, SETVAL, init);
        mem = (struct mem*)shmat(shmid, NULL, 0);
        mem->nombre_compte = 0;
    }
    else
    {
        sem = semget(SEM, 1, 0666);
        mem = (struct mem*)shmat(shmid, NULL, 0);
    }
    do
    {
        printf("MENU\n====\n");
        printf("1. Encoder un nouveau compte\n");
        printf("2. Effectuer un transfert entre compte\n");
        printf("8. Libérer les ressources et quitter\n");
        printf("9. Quitter\n");
        printf("Votre choix ? ");
        scanf("%d%*c",&choix);
        switch(choix)
        {
        case 1:
            printf("Entrer l'iban:");
            scanf("%16[^\n]%*c", compte_tmp.iban);
            printf("Entrer le solde:");
            scanf("%lf%*c", &compte_tmp.solde);
            p(sem);
            mem->comptes[mem->nombre_compte++] = compte_tmp;
            v(sem);
            break;
        case 2:
            printf("Entrer le compte débiteur : ");
            scanf("%16[^\n]%*c", iban1);
            printf("Entrer le compte créditeur : ");
            scanf("%16[^\n]%*c", iban2);
            /* TODO: Faire le transfert entre les deux comptes */
            break;
        case 8:
            shmdt(mem);
            shmctl(shmid, IPC_RMID, NULL);
            semctl(sem, IPC_RMID, 0, NULL);
        }
    }
    while(choix < 8);
    return EXIT_SUCCESS;
}
