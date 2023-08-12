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
    shmid=shmget(SHM_KEY, K,0666|IPC_CREAT);
    if(shmid < 0)
    {
        printf("Erreur SHM\n");
        exit(-1);
    }
    ptr= shmat(shmid, NULL, 0);
    strncpy(ptr, "HELLO !\n\0",9);
    shmdt(ptr);
    return EXIT_SUCCESS;
}
