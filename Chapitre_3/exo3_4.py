import os

while True:
    repertoire=input("Entrez le nom d'un répertoire : ")
    commande = "cp -r $PWD " + repertoire
    os.system(commande)
    choix= input("Quitter ? [Non/Oui] : ")
    if choix == "Oui":
        break


