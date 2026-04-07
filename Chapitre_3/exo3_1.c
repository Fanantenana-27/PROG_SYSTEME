#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int a,b;
    if(argc<=2) {
        printf("Entrez deux arguments (qui sont des nombres entiers) en lignes de commande\n");
        exit(1);
    }
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    printf("Somme de %d et %d : %d\n",a,b,a+b);
    return(0);
}