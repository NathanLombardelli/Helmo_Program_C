#include <stdio.h>
#include <stdlib.h>
#include "cinema.h"

int main(void)
{
  int choix, numero_film, numero_acteur, indice_film, indice_acteur;
  char mot_cle[50+1];
  struct acteurs acteurs;
  struct films films;
  acteurs.nombre_acteur = 0;
  films.nombre_film = 0;

  do
  {
    choix = menu();
    switch(choix)
    {
      case 1:
       printf("*** Encoder un acteur ***\n");
       acteurs.acteur[acteurs.nombre_acteur++] = encoder_acteur();
       break;
      case 2:
       printf("*** Encoder une film ***\n");
       films.film[films.nombre_film++] = encoder_film();
       break;
      case 3:
       printf("*** Assigner une film à un acteur ***\n");
       printf("film #: "); scanf("%d%*c", &numero_film);
       printf("acteur #:"); scanf("%d%*c", &numero_acteur);
       indice_film = chercher_film(numero_film, &films);
       indice_acteur = chercher_acteur(numero_acteur, &acteurs);
       if(indice_film >= 0 && indice_acteur >=0)
        assigner_film_acteur(&films.film[indice_film], &acteurs.acteur[indice_acteur]);                     /*todo*/
       else
		printf("Numero film (indice %d) ou numero acteur (indice %d) non trouvé\n", indice_film, indice_acteur);
       break;
      case 4:
       {
         printf("*** Lister toutes les films ***\n");
         lister_film(&films);                                                                               /*todo*/
       }
       break;
      case 5:
       printf("*** Lister touste les films d'un acteur\n");
       printf("acteur #:"); scanf("%d%*c", &numero_acteur);
       indice_acteur = chercher_acteur(numero_acteur, &acteurs);
       if(indice_acteur >= 0)
         lister_films_acteur(&films,&acteurs.acteur[indice_acteur]);                                        /*todo*/
       else
         printf("Numero acteur (indice %d) non trouvé\n", indice_acteur);
       break;
       case 6:
		printf("*** Lister toutes les films contenant un mot clé\n");
        printf("Mot à chercher:"); scanf("%50[^\n]%*c", mot_cle);
        lister_film_motcle(&films,mot_cle);                                                                           /*todo*/
        break;
    }
  } while(choix != 7);

  return EXIT_SUCCESS;
}
