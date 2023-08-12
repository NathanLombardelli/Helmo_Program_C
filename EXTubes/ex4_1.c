#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TAILLE_BUFFER 255
#define LECTURE 0
#define ECRITURE 1
#define NB_DESCRIPTEUR 2




int main()
{
    int tube[NB_DESCRIPTEUR];
    char buffer[TAILLE_BUFFER+1];
    pipe(tube);  /*création d'un tube unidirectionnel entre un père et son fils*/
    switch(fork())
    {
    case -1 :/*erreur fork*/
        printf("Erreur fork()\n");
        exit(-1);
    case 0 :/*processus fils*/
        close(tube[ECRITURE]);/*ferme l'extrémité du tube qui n'est pas utile(ecriture)*/
        read(tube[LECTURE], buffer, TAILLE_BUFFER);/*lit les informations depuis le tube*/
        close(tube[LECTURE]);/*ferme le tube de lecture */
        printf("Message : %s", buffer);
        break;
    default: /*processus père*/
        /*write(tube, buffer, strlen(buffer));*/
        close(tube[LECTURE]);/*fermeture des descripteurs plus utile*/
        close(tube[ECRITURE]);
       /* printf("Un petit message envoye\n");*//*message env dans le tube*/
       /* fflush(stdout);/*provoque l'écriture en vidant les buffers*/
        wait(NULL);/*attend */
        break;
    }

    return EXIT_SUCCESS;
}
