#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define TAILLE 256

int main()
{
    int tube[2];
    pid_t  fils;
    char descripteur_0[256],descripteur_1[256],message[256];
    if (pipe(tube) != 0) exit(0); //Création d'un tube,
    fils=fork(); //Création d'un processus fils
    if(fils==0){ //Dans le fils
        sprintf(descripteur_0,"%d",tube[0]);
        sprintf(descripteur_1,"%d",tube[1]);
        char *arg[]={"programme_fils",descripteur_0,descripteur_1,NULL}; //exevc et transmission de descripteurs en arguments de programme fils
        execv("./programme_fils",arg);
    }
    if(fils!=0)
    {
        close(tube[0]);
        write(tube[1],"Message du père",17);
        wait(NULL);
    }
    return(0);
}