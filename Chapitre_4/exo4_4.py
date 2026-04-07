import os

r,w=os.pipe()
fils=os.fork()
if fils==0:
    r=str(r)
    w=str(w)
    os.environ("DESC_0")=r
    os.environ("DESC_1")=w
    os.execv("./programme_fils_1", ["programme_fils"])
if fils!=0:
    os.close(r)
    os.write(w,"Message du père")
    os.wait()

