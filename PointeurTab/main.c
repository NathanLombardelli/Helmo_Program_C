#include <stdio.h>
#include <stdlib.h>

int main()
{
        int monTab[5];
        int i, *index = &monTab[0]; /*index = monTab*/

        for(i = 0 ; i<5; ++i)
        {
            printf("Entrer la valeur %d :", i+1);
            scanf("%d%*c",index+i);/*+1 fois la taille d'un entier*/
        }
        printf("la valeur [2] = %d ; [3] = %d",monTab[2],monTab[3]);
        return EXIT_SUCCESS;
}
