
num1=int(input("Enter lower limit of series: "))
num2=int(input("Enter upper limit of series: "))
s=0

for i in range(num1,num2+1):
	s=s+i

print("The sum of the series is: {}".format(s))
