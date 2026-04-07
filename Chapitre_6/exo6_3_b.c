#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int *tab=malloc(sizeof(tab)*sizeof(int));
    int fd = open("tableau.txt",O_RDONLY,0764);

}