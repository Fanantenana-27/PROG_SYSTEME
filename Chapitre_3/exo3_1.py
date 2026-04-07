import sys
import os

if (len(sys.argv)<=2):
    print("Entrez deux arguments (qui sont des nombres entiers) en lignes de commande")
    os._exit(1)
a=int(sys.argv[1])
b=int(sys.argv[2])
print("Somme de {} et {} : {}".format(a,b,a+b))
