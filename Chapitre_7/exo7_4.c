#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int i;

void segmentation()
{
    printf("Retapez i : ");
    scanf("%d",&i);
}

int main()
{
    int n,*tab;
    printf("Entrez la taille du tableau : ");
    scanf("%d",&n);
    tab=malloc(n * sizeof(int));
    for ( i=0 ;i<n ;i++) {
        printf("Tab[%d] = ",i);
        scanf("%d",&tab[i]);
    }
    printf("Tapez i pour afficher Tab[i] : ");
    scanf("%d",&i);
    signal(SIGSEGV,segmentation);
    printf("Tab[%d]=%d\n",i,tab[i]);
    return(0);    
}