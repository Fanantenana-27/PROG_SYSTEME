#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAILLE 256

int main(int argc , char *argv[])
{
    int tube_0,tube_1;
    char message[256];
    if(argc > 1)
    {
        tube_0=atoi(argv[1]);
        tube_1=atoi(argv[2]);
        close (tube_1);
        read(tube_0,message,TAILLE);
        printf("Message : %s\n",message);
    }
    return(0);
}