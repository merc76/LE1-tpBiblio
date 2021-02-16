# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
				afficherLivre(&(ptrB->etagere[i]));		
			}		
		return 1;
		}
}

int rechercherTitre(const T_Bibliotheque *ptrB)
{
	T_Titre title;
	int i,cptLivre=0;

	lireChaine("Titre ?",title,MAX_TITRE);

	for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp(ptrB->etagere[i].titre,title) == 0)
		{
			afficherLivre(&(ptrB->etagere[i]));
			printf("   position : %d \n",i);
			cptLivre++;
		}
	}
	return cptLivre;
}

int rechercherAuteur(const T_Bibliotheque *ptrB)
{
	T_Aut author;
	int i,cpt;

	lireChaine("auteur ?",author,K_MaxAut);

	for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp(ptrB->etagere[i].auteur,author) == 0)
		{
			afficherLivre(&(ptrB->etagere[i]));
			printf("   position : %d \n",i);
			cpt++;
		}
	}
	return cpt;
}












/*
	j'ai voulu procéder par dichotomie mais je me suis rendu compte que les livres n'etait pas forcément trier je laisse donc ceci en commentaire

	
	titlePos=rechercheDicho(ptrB,ptrB->nbLivres,title,0);

	if(titlePos>=0)
	{
		afficherLivre(&(ptrB->etagere[titlePos]));
		return 1;
	}
	return titlePos;

int rechercheDicho(const T_Bibliotheque *ptrB, int taille, const T_Titre valeur,int debut)
{
    int milieu=(taille+debut)/2;//milieu du tableau ou on travail
    //if(milieu%2!=0); milieu-=0.5;//si le tabeleau est de taille impaire le milieu prend la valeur inférieur la 
                                //plus proche du milieu réel plus besoin de le faire car milieu est un int
    if(strcmp((ptrB->etagere[milieu].titre),valeur) == 0)
    {
		printf("%d",milieu);
        return milieu; //si on trouve la valeurs
    }
    else if(taille<debut) //si le tableau ne contient pas notre valeur
    {
		printf("eeee");
        return -1;
    }
    else if(strcmp((ptrB->etagere[milieu].titre),valeur) < 0)
    {
		printf("fff");
        rechercheDicho(ptrB,milieu,valeur,debut); //on recherche dans la partie inférieur du tableau restant
    }
    else
    {
		printf("ggg");
        rechercheDicho(ptrB,taille,valeur,milieu+1);//on recherche dans la partie sup du tableau
    }
	return -1;
}

*/