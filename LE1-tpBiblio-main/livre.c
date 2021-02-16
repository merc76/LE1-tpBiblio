#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
lireEntier("ANNEE :", &(ptrL->annee ));
lireChaine("EMPRUNTEUR :", (ptrL->emprunteur ), MAX);
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE:", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR:", (ptrL->auteur));
printf(" - ");
afficherChaine("CODE:",(ptrL->code));
printf(" - ");
afficherChaine("EDITEUR:", (ptrL->editeur));
printf(" - ");
afficherEntier("ANNEE:",(ptrL->annee));
printf(" - ");
afficherChaine("EMPRUNTEUR :",(ptrL->emprunteur));
printf("\n");
}
