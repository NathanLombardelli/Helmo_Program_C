#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SHM_KEY 2324
#define K 1024
int main(void)
{
    int shmid;
    char* ptr;
    shmid = shmget(SHM_KEY,K,0666);
    if(shmid < 0)
    {
        printf("Erreur SHM\n");
        exit(-1);
    }
    ptr= shmat(shmid, NULL, 0);
    printf("Contenu : %s\n", ptr);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return EXIT_SUCCESS;
}
