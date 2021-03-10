#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
lireChaine("CODE :",(ptrL->code), K_MaxCode);
printf("ANNEE :");
scanf("%d",&(ptrL->annee));
strcpy(ptrL->emprunteur,"NE");//on sdéclare le livre non emprunté quand on l'enregistre
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("",ptrL->code);
printf(" - ");
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EDITEUR :",ptrL->editeur);
printf(" - ");
printf("ANNEE : %d",ptrL->annee);
printf(" - ");
afficherChaine("",(ptrL->emprunteur));
printf("\n");
}
