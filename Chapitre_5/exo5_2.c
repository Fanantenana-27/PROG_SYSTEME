#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define TAILLE 10

void * allouer_initilaiser_tableau(void * arg)
{
    int i;
    int * tab = (int *)arg;
    tab=malloc(TAILLE*sizeof(int)); //Allouer le tableau d'entier 
    srand(time(NULL));
    for(i=0;i<TAILLE;i++) //Initialiser le tebleau
    {
        tab[i]=(rand()%100);
    }
    pthread_exit((void *)tab); //Retourner le tableau
}
int main()
{
    int * tab,retour,i;
    pthread_t my_thread;
    retour=pthread_create(&my_thread,NULL,allouer_initilaiser_tableau,(void*) tab); //Création du thread
    if (retour!=0) exit(-1); //S'il y a une erreur dans la creation du thread , on sort du programme
    pthread_join(my_thread,(void*)&tab); //Récuperation de tableau
    return(0);
}