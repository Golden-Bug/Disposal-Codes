
def perimeter(length,breadth):
	perimeter=2*(length + breadth)
	return perimeter

def area(length,breadth):
	area=length*breadth
	return area

l= int(input("Enter length of rectangle:"))

b= int(input("Enter breadth of rectangle:"))

p=perimeter(l,b)

a=area(l,b)

print("Perimeter of rectangle is {p} and area of the rectangle is {a}".format(p=p,a=a))
	
