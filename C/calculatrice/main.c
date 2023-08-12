#include <stdio.h>
#include <stdlib.h>
#include "fct.h"
/*Prototype de fonction*/



int main(void)
{
    float n1,n2,result;
    char operation;
    printf("Calculatrice simple : \n");
    printf("Entrez l'operqtion a realiser : ");
    scanf("%f %c %f%*c", &n1, &operation, &n2);

    switch(operation)
    {
    case '+':
        result = ajoute(n1,n2);
        break;

    case '-':
        result = soustrait(n1,n2);
        break;

    case '*':
        result = multiplie(n1,n2);
        break;

    case '/':
        result = divise(n1,n2);
        break;

    }

    printf("===> %f %c %f = %f\n",n1,operation,n2,result);
    return EXIT_SUCCESS;

}


