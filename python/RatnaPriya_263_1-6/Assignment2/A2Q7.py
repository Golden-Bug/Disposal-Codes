
x=int(input("Enter limit of series: "))
d=x
def func(n,x):
	if x>0:	
		x-=1
		n+=3
		return func(n,x)
	else:
		return n

m=func(0,x)

print("The {}th multiple of 3 is: {}".format(d,m))



