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
	int i,cpt=0;

	lireChaine("auteur ?",author,K_MaxAut);

	for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp(ptrB->etagere[i].auteur,author) == 0)
		{
			afficherLivre(&(ptrB->etagere[i]));
			printf("position : %d \n",i);
			cpt++;
		}
	}
	return cpt;
}

int supprimerPos(T_Bibliotheque * ptrB)
{
	int i,pos=0;

	printf("position ? :   ");
	scanf("%d",&pos);

	if(pos-1>=ptrB->nbLivres)
	{
		return 0;
	}
	for(i=pos-1;i<ptrB->nbLivres;i++)
	{
		ptrB->etagere[i]=ptrB->etagere[i+1];
	}
	ptrB->nbLivres--;
	return 1;
	
}

int emprunter(T_Bibliotheque *ptrB)
{
	T_Code code;
	int i=0;
	
	lireChaine("quel livre voulez vous emprunter ? (code)",code,K_MaxCode);

	while(i<ptrB->nbLivres && strcmp(code, ptrB->etagere[i].code) != 0)
	{
		i++;
	}
	if (i == ptrB->nbLivres)//si le livre n'existe pas dans la bibilio
	{
		return 0;
	}
	else if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"Non emprunte"))//si le livre est déja emprunté
	{
		return 2;
	}
	else
	{
		afficherLivre(&ptrB->etagere[i]);
		saisirEmprunteur(&ptrB->etagere[i]);


		afficherEmp(&ptrB->etagere[i]);

		return 1;
	}
}

int restituer(T_Bibliotheque *ptrB)
{
	int i = 0;
	T_Code code="";

	lireChaine("quel livre voulez vous rendre ? (code)",code,K_MaxCode);

    while(i < (ptrB->nbLivres) && strcmp(code, ptrB->etagere[i].code) != 0) //ptrB->nbLivres == &ptrB.nbLivres
    {
        i++;
    }
    if(i == ptrB->nbLivres || !strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"Non emprunte")) //si le livre n'existe pas ou n'est as emprunté
    {
        return 0;
    }
    else 
    {
        afficherLivre(&ptrB->etagere[i]);
		strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,"Non emprunte");
    }
    return 1;
}

void triTitre(T_Bibliotheque* ptrB)
{
	int i,j;
	T_livre swap;

	for(i=1;i<ptrB->nbLivres;i++)
	{
		for(j=0;j<ptrB->nbLivres-1;j++)
		{
			if(strcasecmp(ptrB->etagere[j].titre,ptrB->etagere[j+1].titre)>0)
			{
				swap = ptrB->etagere[j];
				ptrB->etagere[j]=ptrB->etagere[j+1];
				ptrB->etagere[j+1]=swap;
			}
		}
	}
}

void triAuteur(T_Bibliotheque* ptrB)
{
	int i,j;
	T_livre swap;

	for(i=1;i<ptrB->nbLivres;i++)
	{
		for(j=0;j<ptrB->nbLivres-1;j++)
		{
			if(strcasecmp(ptrB->etagere[j].auteur,ptrB->etagere[j+1].auteur)>0)
			{
				swap = ptrB->etagere[j];
				ptrB->etagere[j]=ptrB->etagere[j+1];
				ptrB->etagere[j+1]=swap;
			}
		}
	}
}

void triAnnee(T_Bibliotheque* ptrB)
{
	int i,j;
	T_livre swap;

	for(i=1;i<ptrB->nbLivres;i++)
	{
		for(j=0;j<ptrB->nbLivres-1;j++)
		{
			if(ptrB->etagere[j].annee > ptrB->etagere[j+1].annee)
			{
				swap = ptrB->etagere[j];
				ptrB->etagere[j]=ptrB->etagere[j+1];
				ptrB->etagere[j+1]=swap;
			}
		}
	}
}

int  afficherLivredispo(const T_Bibliotheque  *ptrB)
{
	int i;
	if(ptrB->nbLivres==0)
	{
	    return 0;
	}
	else
    {
        for(i=0;i<ptrB->nbLivres;i++)
        {
            if(ptrB->etagere[i].emprunteur.nomemprunteur[0] == '\0' || !strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"Non emprunte"))
            { 
                afficherLivre( &(ptrB->etagere[i]));
            }
    	}
        return 1;
    }
}

int afficherRetard(const T_Bibliotheque  *ptrB)
{
	int i=0;
	int nbLivreRetard=0;
	long int delay=0;//compte le nb de jours d'emprunt d'un livre
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);//current time

	for(i=0; i<ptrB->nbLivres; i++)
	{
		if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"Non emprunte"))//si le livre est bel et bien en cours d'emprunt
		{
			//ici on utilisera une méthode particulière, on compte le nombre de jour depuis le 1 janvier 0000 pour aujourdh'ui et pour le jour
			//de l'emprunt puis on les soustrait. Ainsi on obtient le nombre de jours depuis lequel le livre cible
			//a été emprunté.
			delay=(tm.tm_yday+1 + ((tm.tm_year+1900)*365)) - (((ptrB->etagere[i].emprunteur.lannee) *365) + (convertDMtoDY(ptrB->etagere[i].emprunteur.ledate,ptrB->etagere[i].emprunteur.lemois)));
			if(delay > 7)
			{
				afficherLivre(&ptrB->etagere[i]);
				afficherEmp(&ptrB->etagere[i]);
				printf("\nen retard de %ld jour(s)",delay-7);//on rajoute le nombre de jours de retard
				nbLivreRetard++;
			}
		}
	}
	return nbLivreRetard;
}

/***********************************************************************************************************************************/
// fonction qui convertie une date au format JJ/MM en nombre de jours prend le nombre de jour et de mois en entrées en renvoie
// le nombre de jours écoulé depuis le 1er janvier de l'année.
// (ne marche que sur un an et ne prend pas en compte les années bisexctiles)
/***********************************************************************************************************************************/
int convertDMtoDY(const int numD,const int numM)
{
	int days=0;
	int i=0;

	for(i=0; i<12; i++)
	{
		switch (i)
		{
			case 1://fevrier
				days += 28;//on ajoute le nombre de jours que contient le mois 
			break;
			case 2://mars
				days += 31;
			break;
			case 3://avril
				days += 30;
			break;
			case 4:
				days += 31;
			break;
			case 5:
				days += 30;
			break;
			case 6:
				days += 31;
			break;
			case 7:
				days += 31;
			break;
			case 8:
				days += 30;
			break;
			case 9:
				days += 31;
			break;
			case 10:
				days += 30;
			break;
		}
		if(numM == i)//si on arrive au mois de l'emprunt
		{
			return (days+numD);//on ajoute le nombre de jour passé depuis le debut dumois en cours
		}
	}
	return  0;//si il ya un bug mais ne devrait pas arriver
	
}