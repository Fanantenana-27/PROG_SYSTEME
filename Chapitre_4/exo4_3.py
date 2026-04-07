import os

r,w=os.pipe()
fils=os.fork()
if fils==0:
    r=str(r)
    w=str(w)
    os.execv("./programme_fils", ["programme_fils",r,w])
if fils!=0:
    os.close(r)
    os.write(w,"Message du père")
    os.wait()



