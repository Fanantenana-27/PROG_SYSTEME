import os 

fils = os.fork()
if fils == -1 :
    print("Erreur dans le fork\n")
    os._exit(0)
if fils==0:
    print("Je suis le fils")
else :
    print("Je suis le pere")
    