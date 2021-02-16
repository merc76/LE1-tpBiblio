#ifndef ES_H   //compilation conditionnelle
#define ES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *lire(char *lachaine,int nbMAXcaracAsaisir);
char *lireChaine(const char *, char * , int );
void afficherChaine(const char *,const char *);
void lireEntier(const char *nomChamp,int *a);
void afficherEntier(const char*nomChamp, int val);


#endif
