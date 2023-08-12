#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{
    pid_t pid;
    switch(fork())
    {
    case -1:
        printf("Impossible de me cloner\n");
        exit(-1);
    case 0:
        printf("Je suis le fils %u\n", getpid());
        if(execl("/usr/bin/ls", "/usr/bin/ls", "-l", NULL))
        {
            printf("Erreur avec execl()\n");
            perror("execl ");
            exit(-1);
        }
        break;
    default:
        pid = wait(NULL);
        printf("Mon fils %u a terminé\n", pid);
    }
    return EXIT_SUCCESS;
}

