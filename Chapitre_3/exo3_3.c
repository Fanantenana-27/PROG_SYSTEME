#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char * fichier ;
    fichier=malloc(255*sizeof(char));
    printf("Entrez un nom de fichier : ");
    scanf("%s",fichier);
    execl("/usr/bin/emacs","emacs",fichier,NULL);
    return(0);
}