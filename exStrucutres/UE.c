#include<stdio.h>
#include<stdlib.h>
#include "UE.h"


struct unite_enseignement encodageUE(void)
{
    struct unite_enseignement UE;
    int nbTotH;
    float pourcentageAA1;
    float pourcentageAA2;
    float pourcentageAA3;

    printf("Encodage d'une unité d'enseignement\n");
    printf("Entrer le nombre de crédit :");
    scanf("%i%*c",&UE.nbCredit);
    printf("Entrer le nom du responsable de l'UE :");
    fgets(UE.responsable,60+1,stdin);

    UE.activite[0] = encodeAA();
    UE.activite[1] = encodeAA();
    UE.activite[2] = encodeAA();

     nbTotH = UE.activite[0].nbHeur+UE.activite[1].nbHeur+UE.activite[2].nbHeur;

    pourcentageAA1 = UE.activite[0].nbHeur/nbTotH;
    pourcentageAA2 = UE.activite[1].nbHeur/nbTotH;
    pourcentageAA3 = UE.activite[2].nbHeur/nbTotH;


    UE.cote = ((UE.activite[0].note/20)*pourcentageAA1 + (UE.activite[1].note/20)*pourcentageAA2 + (UE.activite[2].note/20)*pourcentageAA3)/3;

    return UE;
}


struct activite_apprentissage encodeAA(void)
{

    struct activite_apprentissage AA;

    printf("Encodage d'une AA\n");
    printf("Entrer le nom de l'activité :");
    fgets(AA.nom,100+1,stdin);
    printf("Entrer le nombre d'heure :");
    scanf("%i%*c",&AA.nbHeur);
    printf("Entrer la cote de l'activité (/20):");
    scanf("%f%*c",&AA.note);

    return AA;
}
