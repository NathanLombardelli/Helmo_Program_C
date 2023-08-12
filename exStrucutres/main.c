#include <stdio.h>
#include <stdlib.h>
#include "UE.h"

int main()
{
    struct unite_enseignement UnEn;

    UnEn = encodageUE();

    int nbAArate = 0;

    if(UnEn.activite[0].note < 10){
        nbAArate += 1;
    }
    if(UnEn.activite[1].note < 10){
        nbAArate += 1;
    }
    if(UnEn.activite[2].note < 10){
        nbAArate += 1;
    }

    printf(">> Nombre d'AA en échec : %i\n",nbAArate);
    printf(">> La moyenne pour cette UE = %f\n",UnEn.cote);
    return EXIT_SUCCESS;
}
