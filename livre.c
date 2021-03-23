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
printf("\n\n");
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
if(strcmp(ptrL->emprunteur.nomemprunteur,"Non emprunte"))
{
    afficherChaine("EMPRUNT :","En cours d'emprunt");//ici car on ne veut pas forcément donner le nom de l'emprunteur a tous les clients
}
else
{
    afficherChaine("EMPRUNT :","Disponible");
}

printf("\n\n");

}

void afficherEmp(const T_livre *ptrL)
{
    static char dayTab[7][8] = {"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
	static char monthTab[12][10] = {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};

    afficherChaine("\n",ptrL->emprunteur.nomemprunteur);
    afficherChaine(":",&dayTab[ptrL->emprunteur.lejour][0]);
    afficherEntier("",ptrL->emprunteur.ledate);
    afficherChaine("",&monthTab[ptrL->emprunteur.lemois][0]);
    afficherEntier("",ptrL->emprunteur.lannee);
}

void saisirEmprunteur(T_livre *ptrL)
{
    time_t t = time(NULL);//current timestamp
	struct tm tm = *localtime(&t);//current time


    lireChaine("votre nom svp : ",(ptrL->emprunteur.nomemprunteur), K_MaxEmp);

	ptrL->emprunteur.lannee = tm.tm_year+1900;
	ptrL->emprunteur.ledate = tm.tm_mday;
	ptrL->emprunteur.lejour=tm.tm_wday -1;
	ptrL->emprunteur.lemois = tm.tm_mon;
}