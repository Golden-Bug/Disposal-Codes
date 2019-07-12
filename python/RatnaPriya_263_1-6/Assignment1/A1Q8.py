
def gcd(n1,n2):
	i=1
	while(i<=n1 and i<=n2):
		if(n1%i==0 and n2%i==0):
			g=i
		i+=1
	return g

num1=int(input("Enter 1st number: "))
num2=int(input("Enter 2nd number: "))

gcd=gcd(num1,num2)
print("The gcd of {} and {} is {}".format(num1,num2,gcd))

