#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define TAILLE_BUFFER 255

int main2(void)
{
    int n, handle;
    char buffer[TAILLE_BUFFER+1];
    handle = open("tube", O_RDONLY);/*le tube "tube" est ouvert en mode lecture */
    n = read(handle, buffer, TAILLE_BUFFER);/*les données du tube sont lues*/
    buffer[n]='\0';/*defninit le dernier octet lu sur \0 */
    close(handle);
    printf("%d octets lus. Contenu: '%s'\n", n, buffer);
    return EXIT_SUCCESS;
}
