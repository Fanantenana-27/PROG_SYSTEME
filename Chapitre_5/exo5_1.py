import threading
TAILLE=10

def affichage_tableau(arg):
    for i in range(TAILLE):
        print("Tab [{}]={}".format(i,arg[i]))

tab=[3,4,12,8,0,6,34,1,7,19]
my_thread= threading.Thread(target=affichage_tableau,args=(tab,))
my_thread.start()
my_thread.join()