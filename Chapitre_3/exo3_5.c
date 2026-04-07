#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char * choix = malloc(255*sizeof(char));
    char * fichier = malloc(255*sizeof(char));
    pid_t processus;
    while (1)
    {
        printf("Entrez un nom de fichier : ");
        scanf("%s",fichier);
        processus=fork();
        if(processus==0)
        {
            execl("/usr/bin/emacs","emacs",fichier,NULL);
        }
        printf("Quitter ? [Non/Oui] : ");
        scanf("%s",choix);
        if(strcmp(choix,"Oui")==0) {
            break;
        }
    }
    return(0);
}