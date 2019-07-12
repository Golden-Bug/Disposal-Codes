
def tribo(n):
	if(n<=1):
		return n
	else:
		return tribo(n-3)+tribo(n-2)+tribo(n-1)

n=int(input("Enter the limit of series: "))

f=tribo(n)

print("The sum of the tribonacci series is: {}".format(f))

