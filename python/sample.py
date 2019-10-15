from tkinter import *
top =Tk()
'''
label = Label(top, text = "Kya Haal hai ?" )
label.pack()  ''' 

#defing on click event
def printname(event):
	label = Label(root, text= "Hey whatsup bro, i am doing something very interesting.")
    #this creates a new label to the GUI
	label.pack() 

#Frame
topframe = Frame(top)
topframe.pack()
bottomframe = Frame(top)
bottomframe.pack(side = BOTTOM)
#button
button1 = Button(topframe ,text ="Button 1", fg = "red")
button2 = Button(topframe ,text ="Button 2" ,fg = "blue")
button3 = Button(topframe ,text ="Button 3" ,fg = "purple")
button4 = Button(bottomframe ,text ="Press Me" ,fg = "green")
button1.pack()
button2.pack()
button3.pack()
button4.bind(printname)
button4.pack()
# Labels
one = Label(top,text="Hey !",bg="orange",fg ="black")
one.pack()
two = Label(top,text="Oh Yes !",bg="black",fg ="white")
two.pack(fill=X)
three = Label(top,text="U Look GOOD !",bg="blue",fg ="white")
three.pack(side=LEFT,fill=Y)


top.mainloop()







