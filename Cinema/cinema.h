#ifndef CINEMA_H_INCLUDED
#define CINEMA_H_INCLUDED

struct acteur {
  int numero;
  int birthYear;
  int deathYear;
  char nom[50+1];
  char prenom[50+1];
};

struct film {
  int numero;
  int statut;
  int year;
  char titre[50+1];
  char synopsis[250+1];
  struct acteur* acteurPrincipal;
};

struct acteurs {
  int nombre_acteur;
  struct acteur acteur[200];
};

struct films {
  int nombre_film;
  struct film film[100];
};

int menu(void);
struct acteur encoder_acteur(void);
struct film encoder_film(void);

void afficher_information_film(struct film* un_film);
int chercher_acteur(int numero, struct acteurs* acteurs);
int chercher_film(int numero, struct films* films);
void assigner_film_acteur(struct film* un_film, struct acteur* un_acteur);
void lister_film(struct films* films);
void lister_films_acteur(struct films* films, struct acteur* un_acteur);
void lister_film_motcle(struct films* films, char motcle[]);

#endif 
/*CINEMA_H_INCLUDED*/
