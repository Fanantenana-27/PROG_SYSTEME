import os
import random
import time

fils_1=os.fork()
if fils_1==0:
    seconde=random.randint(1,10)
    time.sleep(seconde)
    os._exit(seconde)
fils_2=os.fork()
if fils_2==0:
    seconde=random.randint(1,10)
    time.sleep(seconde)
    os._exit(seconde)
if fils_1 !=0 and fils_2!=0:
    pid , status1=os.wait()
    pid , status2=os.wait()
    print("Durée totale : {}".format(os.WEXITSTATUS(status1)+os.WEXITSTATUS(status2)))
if fils_1 == -1 or fils_2 == -1:
    os._exit(1)