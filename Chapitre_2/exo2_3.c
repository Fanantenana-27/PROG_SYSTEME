#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i,j;
    pid_t fils;
    pid_t pid_du_pere=getpid();
    for ( i = 0; i < 5; i++) {
        if(pid_du_pere != getpid()) {
            break;
        }
        fils=fork();
    }
    return(0);
}