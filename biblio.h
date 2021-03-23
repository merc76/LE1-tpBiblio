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
int rechercherTitre(const T_Bibliotheque *ptrB);
int rechercherAuteur(const T_Bibliotheque *ptrB);
int supprimerPos(T_Bibliotheque * ptrB);
int emprunter(T_Bibliotheque *ptrB);
int restituer(T_Bibliotheque *ptrB);
void triTitre(T_Bibliotheque* ptrB);
void triAuteur(T_Bibliotheque* ptrB);
void triAnnee(T_Bibliotheque* ptrB);
int afficherLivredispo(const T_Bibliotheque *ptrB);

#endif