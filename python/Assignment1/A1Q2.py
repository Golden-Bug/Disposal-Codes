
def fibo(n):
	if(n<=1):
		return n
	else:
		return fibo(n-2)+fibo(n-1)

num=int(input("Enter a number:"))

while(num<0):
	num=int(input("Enter number greater than zero:"))

print("The Fibonacci series is: ")
for i in range(0,num):
	print(fibo(i)),
