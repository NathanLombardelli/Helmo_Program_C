#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, dim, *monTableau;
    float moyenne =0.0;

    printf("Entrer le nombre de valeur: "); scanf("%d%*c", &dim);

    monTableau = (int*)malloc(dim * sizeof(int));/* alloue une zone mémoire de taille : nombre d'element * la taille du type voulus(revoie un pointeur vers cette zone mémoire)*/

    for(i =0 ; i<dim ;++i){

    printf("Entrer la valeur %d: ", (i+1));
    scanf("%d%*c", &monTableau[i]);
    moyenne = moyenne + monTableau[i];

    }
    printf("La moyenne des valeurs entrées est : %.2f" , (moyenne/dim));

    free(monTableau);/* il faut liberer la place memoire a la fin ?*/

    return EXIT_SUCCESS;
}
