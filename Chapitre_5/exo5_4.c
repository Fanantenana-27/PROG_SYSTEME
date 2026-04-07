#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

int *T1,*T2; //Variable Globale
typedef struct { 
    int T1;
    int T2;
}NbrElement;

void* initialiser_TypeTableau(void * arg)
{
    int i;
    int *nbr_element=(int *)arg;
    int * tab=malloc(*nbr_element*sizeof(int));
    srand(time(NULL) + rand());
    for(i=0;i<*nbr_element;i++) { //Initialiser le tableau dans TypeTableau
        tab[i]=(rand()%100);
    }
    pthread_exit((void *)tab);
}
void* chercher_T1_dans_T2(void*arg)
{
    int i ,j; 
    NbrElement * nbr_element=(NbrElement *)arg;
    j=0;
    for(i=0;i<nbr_element->T2-1;i++) { //Verification si T1 inclus dans T2
        if(T2[i]==T1[j] ) {
            if(j==nbr_element->T1-1) break;
            if(T2[i+1]==T2[j+1]) j++;
            else  j=0;
        }
    }
    if(j==nbr_element->T1-1)    printf("T1 est inclus dans T2 \n");
    else    printf("T1 n'est pas inclus dans T2 \n");
    pthread_exit(NULL);
}
void * annulation(void*arg) //Fonction qui puisse terminer le programme
{
    char *A=malloc(sizeof(A)*sizeof(char));
    printf("Tapez 'A' pour annuler le programme : ");
    scanf("%s",A);
    if(strcmp(A,"A")==0) {
        printf("Annulation de programme \n");
        exit(0);
    }
    pthread_exit(NULL);
}

int main()
{
    int retour;
    NbrElement nbr_element;
    pthread_t thread1,thread2;
    nbr_element.T1=6;
    nbr_element.T2=10;
    retour=pthread_create(&thread1,NULL,initialiser_TypeTableau,(void*)&nbr_element.T1);  //Génération aleatoire du tableau T1
    if(retour!=0) exit(1); //Sortir le programme s'il y a une erreur dans la creation de thread
    retour=pthread_create(&thread2,NULL,initialiser_TypeTableau,(void *)&nbr_element.T2); //Génération aleatoire du tableau T2
    if(retour!=0) exit(1); //Sortir le programme s'il y a une erreur dans la creation de thread
    pthread_join(thread1,(void *)&T1); 
    pthread_join(thread2,(void *)&T2);
    pthread_create(&thread1,NULL,annulation,NULL); //Création de thread qui puisse terminer le programme
    pthread_join(thread1,NULL);
    pthread_create(&thread2,NULL,chercher_T1_dans_T2,(void *)&nbr_element); //Verification si T1 inclus dans T2
    pthread_join(thread2,NULL);
    return(0);
}