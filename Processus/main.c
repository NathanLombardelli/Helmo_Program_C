#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{

    pid_t pid;
    printf("[pere]je suis %u",getpid());

    switch(pid = fork())
    {
    case -1:
        printf("Erreur fork()\n");
        exit(-1);

    case 0:
        sleep(10);
        printf("[fils]Je suis le nouveau né %u. PID de papa %u\n",
               getpid(), getppid());

        /*fils du fils*/
        switch(pid = fork())
        {
        case -1:
            printf("Erreur fork()\n");
            exit(-1);
        case 0:
            printf("[fils-fils] je suis le petit fils %u mon papa est %u",getpid(),getppid());
            break;
        case 1:
            printf("[fils] je suis %u  et mon pere est %u",getpid(),getppid());
        }


        /************************/
        break;

    default:

        printf("[pere]J'ai créé le fils %u\n", pid);
        sleep(20); /*le supprimer fait terminer le prg avant la creation du fils.*/
        wait(0);
    }
    return EXIT_SUCCESS;
}

