import os 

pid_du_pere=os.getpid()
#Creation de 5 fils
for i in range(5):
    if pid_du_pere != os.getpid():
        break
    if i==0:
        fils_1 = os.fork()
    elif i==1:
        fils_2=os.fork()
    elif i==2:
        fils_3=os.fork()
    elif i==3:
        fils_4=os.fork()
    elif i==4:
        fils_5=os.fork()

#Affichage 
if fils_1==0:
    print("Je suis le fils 1")
elif fils_2==0:
    print("Je suis le fils 2")
elif fils_3==0:
    print("Je suis le fils 3")
elif fils_4==0:
    print("Je suis le fils 4")
elif fils_5==0:
    print("Je suis le fils 5")

