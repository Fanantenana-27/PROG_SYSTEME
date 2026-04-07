import threading
import random
import queue
import os

q = queue.Queue()

T1=[]
T2=[]
nbr_element_T1 = 6
nbr_element_T2 = 10

def initialiser_TypeTableau(arg):
    for i in range(arg):
        arg.append(random.randint(0,99))
    q.put(arg)
def chercher_T1_dans_T2():
    inclus = True
    for elem in T1:
        if elem not in T2:
            inclus = False
            break
    if inclus == True :
        print("T1 est inclus dans T2")
    else : 
        print("T1 n'est pas inclus dans T2")

def annulation ():
    A=input("Tapez 'A' pour annuler le programme : ")
    if A=="A" :
        print("Annulation de programme")
        os._exit(0)
thread1 = threading.Thread(target=initialiser_TypeTableau,args=(nbr_element_T1,))
thread1.start()
thread1.join()
T1=q.get()
thread2 = threading.Thread(target=initialiser_TypeTableau,args=(nbr_element_T2,))
thread2.start()
thread2.join()
T2=q.get()
thread1 = threading.Thread(target=annulation)
thread1.start()
thread1.join()
thread2 = threading.Thread(target=chercher_T1_dans_T2)
thread2.start()
thread2.join()