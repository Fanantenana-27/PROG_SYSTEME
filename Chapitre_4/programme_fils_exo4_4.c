#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAILLE 256

int main()
{
    int tube_0,tube_1;
    char *tube;
    char message[256];
    tube=getenv("DESC_0");
    tube_0=atoi(tube);
    tube=getenv("DESC_1");
    tube_1=atoi(tube);
    close (tube_1);
    read(tube_0,message,TAILLE);
    printf("Message : %s\n",message);
    return(0);
}