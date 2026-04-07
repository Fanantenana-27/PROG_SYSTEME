#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 256

int main()
{
    int tube_1[2],tube_2[2],valeurW,n;
    pid_t fils;
    FILE * f;
    char bufferRead[256], bufferWrite[256],chaine[255],valeurR[256];
    if(pipe(tube_1)!=0) exit(1); // Creation d'un tube_1 : pour envoyer et recuperer le mot
    if(pipe(tube_2)!=0) exit(1); // Creation d'un tube_1 : pour envoyer et recuperer le resultat
    fils=fork(); //Creation du processus fils
    if (fils == -1) exit(0); //Si il y a une erreur dans la cretion du processus fils
    if(fils==0) {
        printf("Entrez un mot : "); 
        scanf("%s",bufferWrite);
        close(tube_1[0]);
        write(tube_1[1],bufferWrite,BUFFER_SIZE); //Ecrire le mot dans le tube 
        close(tube_2[1]);
        read(tube_2[0],valeurR,BUFFER_SIZE); //Lire le resultat dans le tube
        n=atoi(valeurR);
        if(n==1) { //Affichage du résultat 
            printf("Le mot %s est dans le fichier mots.txt \n",bufferWrite);
        }
        else if(n==0) {
            printf("Le mot %s n'est pas dans le fichier mots.txt \n",bufferWrite);
        }
    }
    else {
        dup2(tube_1[0], STDIN_FILENO); //Lier la sortie tube[0] du tube à stdin
        close(tube_1[1]);
        scanf("%s",bufferRead); //Lire le mot dans le tube
        printf("\n");
        f=fopen("mots.txt","r"); //Ouvrir le fichier mots.txt
        if(f!=NULL) {
            fgets(chaine,255,f);
            if(strstr(chaine,bufferRead)!=NULL) valeurW=1; //Chercher le mot dans le fichier
            else valeurW=0;
            fclose(f);
        }
        dup2(tube_2[1], STDOUT_FILENO); //Lier l’entrée tube[1] du tube à stdout
        close(tube_2[0]);
        printf("\n%d\n",valeurW); //Ecrire le résultat dans le tube 
        wait(NULL);
    }
    return(0);
}
