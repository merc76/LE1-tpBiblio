// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP6 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec code,editeur et annee)


// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre
printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
/*
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");
*/
// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse,chx;
T_Bibliotheque B; 
init(&B);
int j;
char rechercher[MAX_TITRE];	//titre donné par l'utilisateur
char auteur[MAX];
//char T_entree_t[K_MaxTit];
char T_entree_c[K_MaxCode];
char T_entree_emp[K_MaxEmp];

do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(&B);
				if (reponse==1)
					printf("Ajout reussi !!");
					else
					printf("\n Impossible d'ajouter (bibliotheque pleine)");
	break;
	case 2 : reponse=afficherBibliotheque(&B);
		if (reponse==0)	
				printf("\n La bibliotheque est vide");
	break;	
	case 3 :lireChaine("TITRE :", rechercher, MAX_TITRE );	
			j=rechercherTitre(&B,rechercher);
			if (j == 0)
			{
				printf("\n Il n'y a pas le livre : %s ",rechercher);
			}
			else
			{
				printf("\n Il y a %d exemplaire(s)",j);
			}
			
	break;
	case 4 : printf("\n Entrez le nom d'un auteur : ");
            fgets(auteur,K_MaxAut,stdin);
            auteur[strlen(auteur)-1]='\0';

            reponse=rechercherAuteur(&B, auteur);

            if (reponse<0) printf("\n L'auteur n'a pas été trouvé");

    break;
	case 5:
		reponse= supprimerPos(&B);
		if(reponse == 1)
		{
			printf("Supression réussie");
		}
		else
		{
			printf("\n Livre non supprimé erreur");
		}
		
	break;
	case 6: printf("\n Quel livre voulez-vous emprunter ? (Avec le code) : ");
    		fgets(T_entree_c, K_MaxTit, stdin);
    		T_entree_c[strlen(T_entree_c)-1]='\0';
    		printf("\n Saisissez votre nom :");
    		fgets(T_entree_emp, K_MaxTit, stdin);

    		reponse = emprunteur(&B, T_entree_c, T_entree_emp);

    		if (reponse == 1)
    		{
    			printf("\n Le livre a bien été emprunté");
    		}
    		else if (reponse == 0)
    		{
    			printf("\n Le livre n'a pas été emprunté");
    		}
    		
    		break;
    case 7: printf("\n Saisissez le code du livre :");
            fgets(T_entree_c,K_MaxTit,stdin);
            T_entree_c[strlen(T_entree_c)-1]='\0';
            reponse=restituer(&B,T_entree_c);

            if(reponse == 1)
            {
            	printf("\n Le livre a bien été rendu");
            }
            else if(reponse == 0)
            {
                printf("\n Le livre n'a pas été rendu");
            }

            break;







	}



}while(chx!=0);






return 0;

}