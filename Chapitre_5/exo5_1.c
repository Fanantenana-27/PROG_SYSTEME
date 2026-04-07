#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAILLE 10

void * affichage_tableau(void * arg)
{
    int i ,n;
    int * t=(int * ) arg;
    for (i=0;i<TAILLE;i++){ //Affichage du tableau
        printf("Tab[%d] = %d\n",i,t[i]);
    }
    pthread_exit(NULL); //Terminer le thread
}
int main()
{
    int retour;
    int tab[TAILLE]={3,4,12,8,0,6,34,1,7,19};
    pthread_t my_thread; //Declaration
    retour=pthread_create(&my_thread,NULL,affichage_tableau,(void*)tab); //Création d'un thread 
    if(retour!=0) exit(1); //S'il y a une erreur dans la creation du thread , on sort du programme
    pthread_join(my_thread,NULL); //Attendre la fin du thread
    return(0);
}