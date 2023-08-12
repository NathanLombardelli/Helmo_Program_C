#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    int nb, fd;
    char *buffer = "Hello";
    mkfifo("tube", 0777);/*création tube nommé*/
    fd = open("tube", O_WRONLY);/*le tube est ouvert en mode écriture seulement */
    nb = write(fd, buffer, strlen(buffer));/*la chaine hello est env dans le tube*/
    printf("%d octets écrits. Contenu: '%s'\n", nb, buffer);/*le nombre d'octets ainsi que le contenu du buffer sont afficher*/
    close(fd);/*on ferme le tube*/
    return EXIT_SUCCESS;
}
