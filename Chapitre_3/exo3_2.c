#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[])
{
    char* commande=malloc(255*sizeof(char));
    if(argc<=1){
        printf("Entrez en agrument un chemin vers un répertoire\n");
        exit(1);
    }
    sprintf(commande,"cp -r $PWD %s ",argv[1]);
    system(commande);
    return(0);
}