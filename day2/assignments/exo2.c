#include<stdio.h>
#include<stdlib.h>
struct cellule
{
    int element;
    struct cellule * suivant;
};
typedef struct cellule cellule
typedef cellule * liste;


void recherche(double x, liste L)
{
    
