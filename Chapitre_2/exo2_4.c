#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i,j;
    pid_t fils_1,fils_2,fils_3,fils_4,fils_5;
    pid_t pid_du_pere=getpid();
    //Creation de 5 fils
    for ( i = 0; i < 5; i++) {
        if(pid_du_pere != getpid()) {
            break;
        }
        switch (i) {
        case 0:
            fils_1=fork();
            break;
        case 1:
            fils_2=fork();
            break;
        case 2 :
            fils_3=fork();
            break;
        case 3:
            fils_4=fork();
            break;
        case 4:
            fils_5=fork();
            break;
        default:
            break;
        }

    }
    //Affichage 
    if(fils_1==0) printf("Je suis le fils 1 \n");
    else if(fils_2==0) printf("Je suis le fils 2\n");
    else if(fils_3==0) printf("Je suis le fils 3\n");
    else if(fils_4==0) printf("Je suis le fils 4\n");
    else if(fils_5==0) printf("Je suis le fils 5\n");
    return(0);
}