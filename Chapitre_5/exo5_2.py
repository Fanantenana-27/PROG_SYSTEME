import threading
import random
import queue

q=queue.Queue()

TAILLE=10

def allouer_initilaiser_tableau(arg):
    for i in range(TAILLE):
        arg.append(random.randint(0,99))
    q.put(arg)
tab=[]
my_thread = threading.Thread(target=allouer_initilaiser_tableau,args=(tab,))
my_thread.start()
my_thread.join()
tab=q.get()

