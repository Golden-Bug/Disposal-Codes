import sys
from Tkinter import *
import time

def tick():
	time_string = time.strftime("%H:%M:%S %P")
	clock.config(text=time_string)
	clock.after(200,tick)

root = Tk
clock=Label(root,font=("times",100,"bold"),bg="red")
clock.grid(row=1,column=2)
tick()
root.mainloop()
