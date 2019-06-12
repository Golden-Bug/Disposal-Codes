# Python overloading

import math

n=int(input("Select 0 for easy and 1 for tough"))
if n==0:
	a=12
	b=18
	print (a+b)

	x="Hello"
	z=" "
	y="Imon !"
	print(x+z+y)

if n==1:
	class point:
		
		def __init__(self,x,y):
			self.x=x
			self.y=y


		def __add__(self,other):
			return point(self.x + other.x, self.y + other.y)

		def __str__(self):
			string = str(self.x)
			string = string + "," + str(self.y)
			return string
	
	point1 = point(6,5)
	point2 = point(1,-2)
	point3 = point1 + point2
	print(point3)



	












































"""
	class Circle:
		def __init__(self,radius):
			self.radius=radius

		def setRadius(self, radius):
                        self.__radius = radius
		
		def area(self):
			return math.pi * self.radius * self.radius

		def getradius(self):
			return self.radius

		def __add__(self, another_circle):
                        return Circle( self.__radius + another_Circle.__radius )

	c1=Circle(9)
	print(c1.getradius())
	
	c2=Circle(4)
	print(c2.getradius())

	c3=c1 + c2
	print(c3.getradius())

"""
		


	
 
