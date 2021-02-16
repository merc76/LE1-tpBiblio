#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
lireChaine("CODE :",(ptrL->code), K_MaxCode);
printf("ANNEE :");
scanf("%d",&(ptrL->annee));
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("code :",ptrL->code);
printf(" - ");
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EDITEUR :",ptrL->editeur);
printf(" - ");
printf("%d :",ptrL->annee);
printf("\n");
}
