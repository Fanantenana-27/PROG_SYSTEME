#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * choix = malloc(255*sizeof(char));
    char* repertoire = malloc(255*sizeof(char));
    char* commande = malloc(255 * sizeof(char));
    while (1)
    {
        printf("Entrez le nom d'un répertoire : ");
        scanf("%s",repertoire);
        sprintf(commande,"cp -r $PWD %s",repertoire);
        system(commande);
        printf("Quitter ? [Non/Oui] : ");
        scanf("%s",choix);
        if(strcmp(choix,"Oui")==0) {
            break;
        }
    }
    return(0);
}

