#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
int compteur;
float u;

void * T1(void * arg)
{
    float u_1;
    srand(time(NULL)+rand());
    do {
        u_1=u;
        u=  (float) 1/4 * pow(u-1,2);
        printf("T1: u = %f\n",u);
        compteur++;
        if(compteur%2==0){
            sleep(1 + rand()%6);
        }
    }while (fabs(u-u_1)>0.000001);
    pthread_exit(NULL);
}
void * T2(void * arg)
{
    float u_1;
    srand(time(NULL)+rand());
    do {
        u_1=u;
        u= (float) 1/6 * pow(u-2,2);
        printf("T2: u = %f\n",u);
        compteur++;
        if(compteur%2==0){
            sleep(1 + rand()%6);
        }
    }while (fabs(u-u_1)>0.000001);
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1,t2;
    u=1; //Initialisation de u
    pthread_create(&t1,NULL,T1,NULL);
    pthread_join(t1,NULL);
    u=1; //Initialisation de u
    pthread_create(&t2,NULL,T2,NULL);
    pthread_join(t2,NULL);
    return(0);
}