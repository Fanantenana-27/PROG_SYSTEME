import threading
import random

tab=[]
nbr_element=10
x=0
result={}

def initialiser_TypeTableau():
    for i in range (nbr_element):
        tab.append(random.randint(0,99))
def  chercher_x_dans_tableau(arg):
    retour=False
    for x in tab:
        if arg==x:
            retour=True
            break
    result["retour"]=retour

x=input("Entrez un entier x : ")
x=int(x)
thread_1 = threading.Thread(target=initialiser_TypeTableau)
thread_2 = threading.Thread(target=chercher_x_dans_tableau,args=(x,))
thread_1.start()
thread_2.start()
thread_1.join()
thread_2.join()
if result["retour"]==1:
    print("L’élément x est dans le tableau")
else:
    print("L’élément x n' est pas dans le tableau")
