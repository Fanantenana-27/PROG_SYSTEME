import os 
import sys

if len(sys.argv) >1 :
    tube_0=int (sys.argv[1])
    tube_1=int (sys.argv[2])
    os.close(tube_1)
    mess=os.read(tube_0,1024)
    os.close(tube_0)
    message=str(mess.decode())
    print("Message : {}".format(message))

