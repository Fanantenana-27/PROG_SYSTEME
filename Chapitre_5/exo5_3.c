#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct
{
    int *tab;
    int nbr_element;
    int x;
}TypeTableau;

void* initialiser_TypeTableau(void * arg)
{
    int i;
    TypeTableau *t=(TypeTableau *)arg;
    t->tab=malloc(t->nbr_element*sizeof(int));
    srand(time(NULL));
    for(i=0;i<t->nbr_element;i++) //Initialiser le tableau dans TypeTableau
    {
        t->tab[i]=(rand()%100);
    }
    pthread_exit((void *)t);
}

void* chercher_x_dans_tableau(void * arg)
{
    int i;
    int *retour = malloc(sizeof(int));
    TypeTableau *t = (TypeTableau*)arg;
    *retour=0;
    for(i=0;i<t->nbr_element;i++) { //Verifier si x est dans le tableau TypeTableau ou pas
        if(t->tab[i]==t->x) {
            *retour=1;
            break;
        }
    }
    pthread_exit((void *) retour);
}

int main()
{
    int retour,i,*ret;
    TypeTableau *t=malloc(sizeof(t)*sizeof(TypeTableau));
    pthread_t thread_1, thread_2;
    t->nbr_element=10;
    retour=pthread_create(&thread_1,NULL,initialiser_TypeTableau,(void *)t); //Création de thread 1
    if(retour!=0)exit(1); //S'il y a une erreur dans la creation du thread , on sort du programme
    printf("Entrez un entier x : ");
    scanf("%d",&t->x);
    pthread_join(thread_1,(void * )&t); //Attend le thread 1 et recupere TypeTableau
    retour=pthread_create(&thread_2,NULL,chercher_x_dans_tableau,(void *)t); //Création de thread 1
    if(retour!=0)exit(1); //S'il y a une erreur dans la creation du thread , on sort du programme
    pthread_join(thread_2,(void ** )&ret); //Attend le thread 2 et recupere la valeur qui  verifie si x est le tableau de TypeTableau ou pas 
    if(*ret==1){
        printf("L’élément x est dans le tableau\n");
    }
    else {
        printf("L’élément x n'est pas dans le tableau\n");
    }
    return(0);
}

