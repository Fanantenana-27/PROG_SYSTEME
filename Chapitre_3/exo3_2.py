import sys
import os

if len(sys.argv) <=1 :
    print("Entrez en agrument un chemin vers un répertoire");
    os._exit(1)
commande = "cp -r $PWD " + sys.argv[1]
os.system(commande)