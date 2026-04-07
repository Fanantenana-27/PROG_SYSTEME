import os

fils_1 = os.fork()      #Creation de fils 1
if fils_1 == 0 :
    print("Je suis le fils 1")
    os._exit(0)
fils_2=os.fork()        #Creation de fils 2
if fils_2==0 :
    print("Je suis le fils 2")
elif fils_1 != 0 and fils_2 != 0 :
    print("Je suis le père")