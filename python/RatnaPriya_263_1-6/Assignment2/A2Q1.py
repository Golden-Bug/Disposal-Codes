
def fact(n):
	if(n<=1):
		return 1
	else:
		return n*fact(n-1)

num=int(input("Enter a number: "))

while(num<0):
	num=int(input("Enter a number greater than 0: "))
f=fact(num)
print("The factorial of the number is: {}".format(f))
