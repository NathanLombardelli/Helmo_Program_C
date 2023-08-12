#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char mot[100+1] = "";
    char motInv[100+1] = "";



    printf("Saisiser le mot a inverser : \n"); scanf("%100[^\n]%*c",mot);

    int motTaille = strlen(mot);

    int cont = 0;
    for(int i = motTaille-1;i >= 0;i--)
    {
        motInv[cont] = mot[i];
        cont++;
    }

    printf("Votre Mot inverser : %s \n",motInv);
    return EXIT_SUCCESS;
}
