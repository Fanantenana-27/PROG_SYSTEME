#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t fils_1,fils_2;
    fils_1=fork();      //Creation de fils 1
    if(fils_1==0) {
        printf("Je suis le fils 1\n");
        exit(0);
    }
    fils_2=fork();      //Creation de fils 2
    if (fils_2==0 ) {
        printf("Je suis le fils 2\n");
    }
    else if(fils_1!=0 && fils_2!=0) {
        printf("Je suis le père\n");
    }
    return(0);
}