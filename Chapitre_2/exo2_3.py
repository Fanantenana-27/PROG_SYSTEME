import os

pid_du_pere=os.getpid()
for i in range(5):
    if pid_du_pere != os.getpid() :
        break
    fils=os.fork()

