#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int tab[10],i;
    int fd=open("tableau.txt",O_CREAT|O_WRONLY|O_TRUNC,0764);
    for (i=0 ; i<10 ; i++)
    {
        printf("Tableau[%d]=",i);
        scanf("%d",&tab[i]);
        write(fd,&tab[i],sizeof(tab[i]));
    }
    close(fd);
    return(0);
}