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


int afficherBibliotheque(const T_Bibliotheque  *ptrB)
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

int rechercherTitre(T_Bibliotheque *ptrB,char *recherche)
{
	int i;
	int j = 0; //compteur
	for(i = 0;i<ptrB->nbLivres;i++) //On parcourt la bibliothèque
	{
		if(	strcmp(recherche, (&(ptrB->etagere[i].titre)	)	) == 0	) //On compare avec le titre entré
		{
			afficherLivre( &(ptrB->etagere[i])  );
			j++;
		}
	}
	if(j == 0)
		{
			return 0;
		}
	else
		{
			return j;
		}
}

int rechercherAuteur(T_Bibliotheque *ptrB,char *auteur)
{
    int i = ptrB->nbLivres-1;
    int j=i;

    while (i>=0 && strcmp(auteur, (ptrB->etagere[i].auteur))!=0) //On parcourt la bibliothèque
    	i--;

    if (i<0) 
    	return i;

    else 
    	{

        while (j>=0) 
        	{
           		if (!strcmp(auteur, ptrB->etagere[j].auteur)) 
           			printf("\n %s", ptrB->etagere[j].titre);
            		j--;
        	}
    	}

    return 1;
}

int supprimerPos(T_Bibliotheque * ptrB)
{
	int i,pos=0;

	printf("position ? :   ");
	scanf("%d",&pos);

	if(pos>=ptrB->nbLivres)
	{
		return 0;
	}
	for(i=pos;i<ptrB->nbLivres;i++)
	{
		ptrB->etagere[i]=ptrB->etagere[i+1];
	}
	ptrB->nbLivres--;
	return 1;
	
}

int emprunteur(T_Bibliotheque *ptrB,const char *cd, const char *nom)
{
	int i=0;
	int j;
	while(i<ptrB->nbLivres && strcmp(cd, ptrB->etagere[i].code) != 0)
	{
		i++;
	}
	j = i;
	if (i == ptrB->nbLivres)
	{
		return 0;
	}
	else
	{
		while(j<ptrB->nbLivres)
		{
			if (strcmp(cd, ptrB->etagere[j].code) == 0)
			{
				printf("\n -%s", ptrB->etagere[j].titre);
                strcpy(ptrB->etagere[j].emprunteur,nom);
			}
			j++;
		}
	}
}

int restituer(T_Bibliotheque *ptrB,const char *cd)
{
	int i = 0;
    int j;
    char *emprunteur;
    strcpy(emprunteur,"Non emprunté");
    while (i < (ptrB->nbLivres) && strcmp(cd, ptrB->etagere[i].code) != 0) //ptrB->nbLivres == &ptrB.nbLivres
    {
        i++;
    }
    j = i;
    if (i == ptrB->nbLivres) 
    {
        return 0;
    } 
    else 
    {
    	while (j < ptrB->nbLivres) 
        {
            if (strcmp(cd, ptrB->etagere[j].code) == 0)
            {
                printf("\n -%s", ptrB->etagere[j].titre);
                strcpy(ptrB->etagere[j].emprunteur,emprunteur);
            }
            j++;
        }
    }
    return 1;
}

