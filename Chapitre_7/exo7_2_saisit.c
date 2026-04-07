#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    int n ;
    pid_t pid;
    FILE * f;
    do {
        f=fopen("/tmp/pid.txt","r");
        if(f!=NULL) {
            fscanf(f,"%d",&n);
            fclose(f);
        }
    } while (f==NULL);
    printf("\n");
    pid=(pid_t)n;
    printf("Entrez un entier : ");
    scanf("%d",&n);
    f=fopen("/tmp/entier.txt","w");
    if (f != NULL)
    {
        fprintf(f,"%d\n",n);
        fclose(f);
    }
    kill(pid,SIGUSR1);
    system("rm /tmp/pid.txt ");
    return(0);
}