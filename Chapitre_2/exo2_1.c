#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t fils;
    fils=fork();
    if(fils==-1){
       printf("Erreur dans le fork\n");
        exit(0);
    }
    if(fils==0){
        printf("Je suis le fils\n");
    }
    else {
        printf("Je suis le pere\n");
    }
    return(0);
}