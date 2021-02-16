#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 10 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherTitre (T_Bibliotheque *ptrB, char* recherchetitre);
int rechercherAuteur (T_Bibliotheque *ptrB,char *auteur);
int supprimerPos(T_Bibliotheque * ptrB);
int emprunteur(T_Bibliotheque *ptrB,const char *cd, const char *nom);
int restituer(T_Bibliotheque *ptrB,const char *cd);

#endif