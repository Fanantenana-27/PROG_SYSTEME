#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    int i;
    char choix;
    pid_t fils;
    fils=fork();
    if(fils==-1) exit(1);
    if(fils == 0) {
        while (1)  i++;//Boucle infini
    }
    else {
        while (1)  {
            printf("Appuiez sur la touche 's' (endort le ﬁls)\n");
            printf("Appuiez sur la touche 'r' (redémare le ﬁls)\n");
            printf("Appuiez sur la touche 'q', (tue le ﬁls avant de terminer le programme.\n");
            printf("Choix : ");
            scanf(" %c",&choix);
            if(choix=='s' ) kill(fils,SIGSTOP);
            else if (choix == 'r') kill(fils,SIGCONT);
            else if (choix == 'q') {
                kill(fils,SIGKILL);
                exit(0);
            }
        }
    }
    return(0);
}