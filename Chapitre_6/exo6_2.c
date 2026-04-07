#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>

int main (int argc , char* argv[])
{
    char * fichier =malloc(1000 * sizeof(char));
    DIR *dir ;
    struct dirent * ent ;
    struct stat st;
    if (argc != 2)
    {
        printf("Exemple : %s nom_repertoire\n",argv[0]);
        exit(1);
    }
    dir = opendir(argv[1]); //Ouverture du répertoire
    if (dir==NULL) exit(1);
    while ((ent=readdir(dir)) != NULL) //on parcourt la liste
    {
        sprintf(fichier,"%s/%s",argv[1],ent->d_name);
        if(stat(fichier,&st)!=0) exit(1);
        if(st.st_size>=1000000 ) printf("%s (UID : %d)\n",ent->d_name,st.st_uid);
    }
    return(0);
}