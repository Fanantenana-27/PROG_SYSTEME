#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signale()
{
    int n;
    FILE * f;
    f=fopen("/tmp/entier.txt","r");
    if(f!=NULL) {
        fscanf(f,"%d",&n);
        fclose(f);
    }
    printf("L'entier dans le fichier est : %d\n",n);
    exit(0);
}

int main()
{
    FILE * f;
    f=fopen("/tmp/pid.txt","w"); 
    if(f!=NULL){ //ecrire dans un fichier le PID 
        fprintf(f,"%d\n",getpid());
        fclose(f);
        printf("\n");
    }
    signal(SIGUSR1,signale); //Associer SIGUSR1 avec signaale
    while(1) sleep(1);
    return(0);
}