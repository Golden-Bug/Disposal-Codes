
x=int(input("enter a positive number: "))
d=x
count=0
def digits(x):
	global count
	count+=1
	if(x>10):
		digits(x/10)

digits(x)
print("{} is a {} digit number".format(d,count))


	
