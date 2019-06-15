
def fibo(n):
	if(n<=1):
		return n
	else:
		return fibo(n-2)+fibo(n-1)

num=int(input("Enter a number:"))

while(num<0):
	num=int(input("Enter number greater than zero:"))
f=fibo(num-1)
print("The fibonacci number corresponding to the number is {}".format(f))

