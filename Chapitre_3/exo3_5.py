import os

while True :
    fichier = input("Entrez un nom de fichier : ")
    processus=os.fork()
    if processus==0:
        os.execl("/usr/bin/emacs","emacs",fichier)
    choix = input("Quitter ? [Non/Oui] : ")
    if choix=="Oui":
        break
