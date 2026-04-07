#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int compt ; // Le compteur globale
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void * incrementer_le_compteur(void *arg)
{
    int i;
    int* limite= (int *)arg;
    compt=0;
    srand(time(NULL)+rand());
    while (1){
        pthread_mutex_lock(&my_mutex);
        compt++;
        if (compt ==*limite) break;
        pthread_mutex_unlock(&my_mutex);
        sleep(1+ rand()%6);
    }
    pthread_exit(NULL);
}

void * affichage_du_compteur(void * arg)
{
    int *limite=(int *)arg;
    while (1) {
        pthread_mutex_lock(&my_mutex);
        printf("Compteur : %d\n",compt);
        if (compt ==*limite) break;
        pthread_mutex_unlock(&my_mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(int argc , char * argv[])
{
    int limite,retour;
    pthread_t thread1 , thread2;
    if(argc==1) {
        printf("Entrez un nombre entier en argument\n");
        exit(1);
    }
    else limite=atoi(argv[1]);
    retour=pthread_create(&thread1,NULL,incrementer_le_compteur,(void *)&limite);
    if (retour != 0) exit(1);
    retour=pthread_create(&thread2,NULL,affichage_du_compteur,(void *)&limite);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return(0);
}