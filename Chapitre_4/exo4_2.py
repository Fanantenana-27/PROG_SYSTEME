import os

r1 , w1=os.pipe() # Creation de r1,w1 : pour envoyer et recuperer le mot
r2 , w2 = os.pipe() #Creation de r2 ,w2 : pour envoyer et recuperer le resultat
fils=os.fork() #Creation du processus fils
if fils==-1 : #Si il y a une erreur dans la cretion du processus fils
    os._exit(0)
if fils==0:
    bufferWrite=input("Entrez un mot : ")
    os.close(r1)
    os.write(w1,bufferWrite) #Ecrire le mot dans le tube 
    os.close(w1)
    os.close(w2)
    message=os.read(r2,1024) #Lire le resultat dans le tube
    os.close(r2)
    valeurR=int(message.decode()) 
    if valeurR==1: #Affichage du résultat 
        print("Le mot {} est dans le fichier mots.txt \n".format(bufferWrite))
    elif valeurR==0:
        print("Le mot {} n'est pas dans le fichier mots.txt \n".format(bufferWrite))
else:
    os.close(w1)
    os.dup2(r1,0)
    os.close(r1)
    bufferRead=input("")
    file=open("mots.txt","r") #Ouvrir le fichier mots.txt
    chaine=file.readline()
    ret=chaine.find(bufferRead) #Chercher le mot dans le fichier
    if(ret>=0):
        valeurW=1
    else:
        valeurW=0
    file.close()
    os.close(r2)
    valeurW=str(valeurW) 
    os.dup2(w2,1) #Ecrire le résultat dans le tube 
    os.close(w2)
    print("{}".format(valeurW))
    os.wait()