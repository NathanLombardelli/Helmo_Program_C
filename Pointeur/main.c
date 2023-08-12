#include <stdio.h>
#include <stdlib.h>

int main()
{
   int monEntier = 5;
   int *monPointeur;

   monPointeur = &monEntier;
   (*monPointeur)++;
   printf("monEntier=%d, monPointeur=%p, *monPointeur=%d",monEntier,monPointeur,*monPointeur);
   return EXIT_SUCCESS;
}
