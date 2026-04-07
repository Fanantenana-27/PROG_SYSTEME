#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int ret,i;
    int *tab=malloc(sizeof(tab)*sizeof(int));
    int fd = open("tableau.txt",O_RDONLY,0764);
    i=0;
    do
    {
        ret=read(fd,&tab[i],sizeof(int)) ;
        printf("tab[%d]=%d\n",i,tab[i]);
        i++;
    } while (ret > 0);    
    return(0);
}
