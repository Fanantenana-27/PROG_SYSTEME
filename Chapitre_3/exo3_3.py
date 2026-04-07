import os

fichier=input("Entrez un nom de fichier : ")
os.execl("/usr/bin/emacs","emacs",fichier)
