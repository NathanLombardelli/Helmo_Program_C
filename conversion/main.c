#include <stdio.h>
#include <stdlib.h>

#include "fctConv.h"

int main()
{
    int reponse = 0;
    float conv;
    while(reponse != 5)
    {

        menu();
        scanf("%i%*c",&reponse);
        switch(reponse)
        {
        case 1:
            printf("valeur a convertir :");
            scanf("%f%*c",&conv);
            printf("resultat : %f \n",convertTemperature(conv,0));
            printf("\n");
            break;
        case 2:
            printf("valeur a convertir :");
            scanf("%f%*c",&conv);
            printf("resultat : %f \n",convertTemperature(conv,1));
            printf("\n");
            break;
        case 3:
            printf("valeur a convertir :");
            scanf("%f%*c",&conv);
            printf("resultat : %f \n",convertDistance(conv,0));
            printf("\n");
            break;
        case 4:
            printf("valeur a convertir :");
            scanf("%f%*c",&conv);
            printf("resultat : %f \n",convertDistance(conv,1));
            printf("\n");
            break;


        }

    }


    return EXIT_SUCCESS;
}

int menu(void)
{
    printf("MENU \n");
    printf("1. Conversion °F => °C \n");
    printf("2. Conversion °C => °F \n");
    printf("3. Conversion in => cm \n");
    printf("4. Conversion cm => in \n");
    printf("5. Quitter \n");
    printf("Votre choix? \n");

    return 0;
}


