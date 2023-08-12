#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "cinema.h"


/* === LES FONCTIONS CI-DESSOUS VOUS SONT FOURNIES ET NE DOIVENT
 * === PAS ETRE MODIFIEES
 */

/* Affiche le menu et retourne le choix de l'utilisateur */
int menu(void)
{
  int choix;
  printf("MENU\n\n  1. Ajouter un acteur\n  2. Encoder un film\n  3. Assigner un film à un acteur\n  4. Lister les films\n  5. Lister les films d'un acteur\n  6. Lister les films contenant un mot clé\n  7. Quitter\n\n\nVotre Choix ?");
  scanf("%d%*c", &choix);
  return choix;
}

/* Encode un nouveau acteur et retourne la structure contenant toutes les informations */
struct acteur encoder_acteur(void)
{
  struct acteur un_acteur;
  printf("Numero : "); scanf("%d%*c", &un_acteur.numero);
  printf("Nom: "); scanf("%50[^\n]%*c", un_acteur.nom);
  printf("Prenom: "); scanf("%50[^\n]%*c", un_acteur.prenom);
  printf("Année de naissance : "); scanf("%d%*c", &un_acteur.birthYear);
  printf("Année de mort (-1 si toujours vivant): "); scanf("%d%*c", &un_acteur.deathYear);
  return un_acteur;
}


/* Encode une nouvelle film et retourne la structure contenant toutes les informations
 * ATTENTION: le pointeur vers l'acteur est positionné sur NULL (car film par encore assignée)
 */
struct film encoder_film(void)
{
  struct film un_film;
  printf("Numero: "); scanf("%d%*c", &un_film.numero);
  printf("Statut (1:Pre-production, 2:En tournage, 3:Post-production, 4:Commercialisé): "); scanf("%d%*c", &un_film.statut);
  printf("Titre: "); scanf("%50[^\n]%*c", un_film.titre);
  printf("Année de parution : "); scanf("%d%*c", &un_film.year);
  printf("Synopsis: "); scanf("%250[^\n]%*c", un_film.synopsis);
  un_film.acteurPrincipal = NULL;
  return un_film;
}

/* ======== TOUTES LES FONCTIONS CI-DESSOUS DOIVENT ETRE
 * ======== COMPLETEES. IL EST INTERDIT DE MODIFIER
 * ======== LE NOM DE LA FONCTION, LES PARAMETRES OU LEUR
 * ======== TYPE OU LE TYPE DE RETOUR DE CETTE FONCTION.
 *
 * ======== EN CAS DE NON-RESPECT, VOUS N'OBTIENDREZ PAS
 * ======== LES POINTS LIES A CETTE FONCTIONNALITE
 */


/* Cette fonction affiche le statut du film comme une chaine de caractères en fonction de la valeur.
* 1: Pré-Production
* 2: En tournage
* 3: Post-Production
* 4: Commercialisé
*/
void affiche_statut_film(struct film* un_film)
{

    switch(un_film->statut){

        case 1:
            printf("Pré-Production\n");
        break;
        case 2:
            printf("En tournage\n");
        break;
        case 3:
            printf("Post-Production\n");
        break;
        case 4:
            printf("Commercialisé\n");
        break;
        default:
            printf("Status invalide\n");
        break;
        }

}

/* Cette fonction doit afficher les informations du film
 * dont on passe le pointeur en paramètre.
 *
 * Afficher toutes les informations du film.
 * Pour afficher le statut, référez-vous à la fonction utilitaire affiche_statut_film
 * Pour afficher les acteurs, respectez le format suivant "nom prenom (date de naissance-date de mort)" (rien si pas mort)
 */
 void afficher_information_film(struct film* un_film)
{

    printf("numéro du film : %d \n",un_film->numero);
    printf("Titre : %s \n",un_film->titre);
    printf("Date de sortie : %d \n",un_film->year);
    printf("Status : ");affiche_statut_film(un_film);
    printf("Date de sortie : %s \n",un_film->synopsis);
    printf("Acteurs principal : ");printf("%s %s (%d-%d) \n",un_film->acteurPrincipal->nom,un_film->acteurPrincipal->prenom,un_film->acteurPrincipal->birthYear,un_film->acteurPrincipal->deathYear);

}

/* Cette fonction recherche un film dont on passe le numéro
 * dans le tableau des films
 *
 * Si le film est trouvé, l'indice de sa position dans le tableau
 *    doit être retourné
 * Si le film n'est pas trouvé, la valeur -1 doit être retournée.
 */
int chercher_film(int numero, struct films* films)
{
    int i;
    for(i = 0 ; i<films->nombre_film ;++i)
    {
        if(films->film[i].numero == numero)
        {
            return i;
        }

    }
  return -1;
}

/* Cette fonction recherche un acteur dont on passe le numero
 * dans le tableau des acteurs
 *
 * Si l'acteur est trouvé, l'indice de sa position dans le tableau
 *    doit être retourné
 * Si l'acteur n'est pas trouvé, la valeur -1 doit être retournée
 */
int chercher_acteur(int numero, struct acteurs* acteurs)
{

    int i;
    for(i = 0 ; i<acteurs->nombre_acteur ;++i)
    {
        if(acteurs->acteur[i].numero == numero)
        {
            return i;
        }

    }
    return -1;
}

/* Cette fonction permet d'assigner un film à un acteur.
 *
 * On passe le pointeur vers le film à assigner
 *          le pointeur vers l'acteur
 *
 */
void assigner_film_acteur(struct film* un_film, struct acteur* un_acteur)
{

    un_film->acteurPrincipal = un_acteur;

}

/* Cette fonction permet de lister tous les films
 *
 * Elle reçoit un pointeur vers tous les films
 * !! Veiller à utiliser la fonction afficher_information_film()
 * !!   pour afficher un film donnée
 */
void lister_film(struct films* films)
{

    int i;
    for(i = 0 ; i<films->nombre_film ;i++)
    {

        afficher_information_film(&films->film[i]);

    }


}

/* Cette fonction permet de lister tous les films assignés à un acteur
 *
 * Elle reçoit un pointeur vers tous les films
 *             un pointeur vers l'acteur
 * !! Veillez à utiliser la fonction afficher_information_film()
 * !!   pour afficher un film donnée
 */
void lister_films_acteur(struct films* films, struct acteur* un_acteur)
{
        int i;
        for(i = 0 ; i<films->nombre_film ;i++)
    {

        if(films->film[i].acteurPrincipal == un_acteur)
        {

            afficher_information_film(&films->film[i]);

        }

    }



}

/* Cette fonction permet de lister tous les films dont le titre
 * contient le mot clé précisé
 *
 * Elle reçoit un pointeur vers tous les films
 *             le mot clé à chercher
 * !! Veillez à utiliser la fonction afficher_information_film()
 * !!   pour afficher un film donnée
 */
void lister_film_motcle(struct films* films, char motcle[])
{
    int i;
    char *p;
    for(i = 0 ; i<films->nombre_film ;i++)
    {
        p = strstr(films->film[i].titre,motcle);

        if(p!= NULL){
            afficher_information_film(&films->film[i]);
        }
    }

}
