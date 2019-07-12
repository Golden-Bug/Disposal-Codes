import sys
a=[]
x=input("Enter 1 for integer and 0 for other input: ")
if(x==1):
	c=input("Enter number: ")
elif(x==0):
	c=raw_input("Enter input: ")
else:
	print "Wrong input"
a.append(c)
print("Length of an {} array element is {} bytes".format(type(c), sys.getsizeof(type(a[0])())))
