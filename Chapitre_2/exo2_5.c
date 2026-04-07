#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int seconde,status1,status2;
    pid_t fils_1,fils_2;
    fils_1=fork();
    srand(time(NULL)+getpid());
    if(fils_1==0 ) {
        seconde=1 + (rand() % 10);
        sleep(seconde);
        exit(seconde);
    }
    fils_2=fork();
    if(fils_2==0) {
        seconde=1 + (rand() % 10);
        sleep(seconde);
        exit(seconde);
    }
    else if(fils_1!=0 && fils_2!=0) {
        wait(&status1);
        wait(&status2);
        printf("Duree totale :  %ds\n",WEXITSTATUS(status1)+WEXITSTATUS(status2));
    }
    if(fils_1==-1 || fils_2==-1) exit(1);
    return(0);
}