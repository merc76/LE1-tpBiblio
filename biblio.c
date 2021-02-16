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
	int i=0;
	T_Code code;
	
	lireChaine("quel livre voulez vous emprunter ? (code)",code,K_MaxCode);

	while(i<ptrB->nbLivres && strcmp(code, ptrB->etagere[i].code) != 0)
	{
		i++;
	}
	if (i == ptrB->nbLivres)//si le livre n'existe pas dans la bibilio
	{
		return 0;
	}
	else if(strcmp(ptrB->etagere[i].emprunteur,"NE")!=0)//si le livre est déja emprunté
	{
		return 0;
	}
	else
	{
		afficherLivre(&ptrB->etagere[i]);
		lireChaine("votre nom svp??",ptrB->etagere[i].emprunteur,K_MaxEmp);
		return 1;
	}
}

int restituer(T_Bibliotheque *ptrB)
{
	int i = 0;
	T_Code code='\0';

	lireChaine("quel livre voulez vous rendre ? (code)",code,K_MaxCode);

    while (i < (ptrB->nbLivres) && strcmp(code, ptrB->etagere[i].code) != 0) //ptrB->nbLivres == &ptrB.nbLivres
    {
        i++;
    }
    if (i == ptrB->nbLivres || strcmp(ptrB->etagere[i].emprunteur,"NE")) //si le livre n'existe pas ou n'est as emprunté
    {
        return 0;
    }
    else 
    {
        afficherLivre(&ptrB->etagere[i]);
		strcpy(ptrB->etagere[i].emprunteur,"NE");
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
			if(strcmp(ptrB->etagere[j].titre,ptrB->etagere[j+1].titre)>0)
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
			if(strcmp(ptrB->etagere[j].auteur,ptrB->etagere[j+1].auteur)>0)
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