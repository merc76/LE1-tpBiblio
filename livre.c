#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
lireEntier("ANNEE  :",&(ptrL->annee));
strcpy(ptrL->emprunteur.nomemprunteur,"Non emprunte");
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf("\n");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf("\n");
afficherChaine("CODE :",ptrL->code);
printf("\n");
afficherChaine("EDITEUR :", (ptrL->editeur));
printf("\n");
afficherEntier("ANNEE :",(ptrL->annee));
printf("\n");
if(! strcmp(ptrL->emprunteur.nomemprunteur,"Non emprunte"))
{
    afficherChaine("EMPRUNT :","En cours d'emprunt");//ici car on ne veut pas forcément donner le nom de l'emprunteur a tous les clients
}
else
{
    afficherChaine("EMPRUNT :","Disponible");
}

printf("\n\n");

}

