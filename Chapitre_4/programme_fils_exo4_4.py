import os 
import sys

if len(sys.argv) >1 :
    tube=os.environ.get("DESC_0")
    tube_0=int (tube)
    tube=os.environ.get("DESC_1")
    tube_1=int (tube)
    os.close(tube_1)
    mess=os.read(tube_0,1024)
    os.close(tube_0)
    message=str(mess.decode())
    print("Message : {}".format(message))
