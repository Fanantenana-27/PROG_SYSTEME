#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define N 100

double tableau[N];
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void * remplacer_chaque_valeur(void * arg)
{
    int i;
    srand(time(NULL) + rand());
    for (i=1;i<N-1;i++) {
        pthread_mutex_lock(&my_mutex);
        tableau[i]=(tableau[i-1]+tableau[i]+tableau[i+1])/3;
        pthread_mutex_unlock(&my_mutex);
    }
    sleep(1+rand()%4);
    pthread_exit(NULL);
}
void * affichage_tableau(void * arg)
{
    int i;
    for(i=0;i<N;i++) {
        pthread_mutex_lock(&my_mutex);
        printf("Tableau[%d]=%lf\n",i,tableau[i]);
        pthread_mutex_unlock(&my_mutex);
        sleep(4);
    }
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t thread1,thread2;
    srand(time(NULL));
    tableau[0]=0;
    tableau[99]=0;
    for (i=1;i<N-1;i++) { //Initialiser les valeurs du tableau 
        tableau[i]=(double)( rand()%101);
    }
    pthread_create(&thread1,NULL,remplacer_chaque_valeur,NULL);
    pthread_create(&thread2,NULL,affichage_tableau,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return(0);
}