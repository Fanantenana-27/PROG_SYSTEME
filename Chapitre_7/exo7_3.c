#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void fonc_signale()
{
    printf("\nLe processus de pid (%d) est tué\n",getpid());
    kill(getpid(),SIGKILL);
}

int main()
{
    int i,choix;
    pid_t fils[5];
    pid_t pid_du_pere=getpid();
    for ( i = 0; i < 5; i++) { //Creation de 5 fils
        if(pid_du_pere != getpid()) {
            break;
        }
        fils[i]=fork();
    }
    signal(SIGUSR1,fonc_signale); //Associer SIGUSR1 à fonc_signale
    if (fils[0]==0 || fils[1]==0 || fils[2]==0 || fils[3]==0 || fils[4]==0) { //Dans les fils
        i=0;
        while (1) i++;
    }
    else if(fils[0] !=0 && fils[1] !=0 && fils[2] !=0 && fils[3] !=0 && fils[4] !=0) { //Dans le pere
        i=0;
        while (1) {
            printf("1 - Endormir un ﬁls\n2 - Réveiller un ﬁls\n3 - Terminer un ﬁls \n");
            printf("Choix : ");
            scanf("%d",&choix);
            if(choix==1) {
                kill(fils[i],SIGSTOP);
            }
            else if(choix==2) {
                kill(fils[i],SIGCONT);
            }
            else if (choix==3) {
                kill(fils[i],SIGUSR1);
                i++;
            }
            if(i==5) break;
        }
    }
    return(0);
}