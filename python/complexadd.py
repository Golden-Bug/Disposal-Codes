# Adding complex numbers

import math

class comp:
	def __init__(self,x,y):
		self.x=x
		self.y=y

	def __add__(self,other):
		return comp(self.x + other.x, self.y + other.y)

	def __str__(self):
		string = str(self.x)
		string = string +" " + str(self.y)+ "i"
		return string
k= input("Enter the real part of complex 1: ")
l= input("Enter the imaginary part of complex 1: ")
m= input("Enter the real part of complex 2: ")
n= input("Enter the imaginary part of complex 2: ")
complex1 = comp(k,l)
complex2 = comp(m,n)
complex3 = complex1 + complex2
print(complex3)
	



