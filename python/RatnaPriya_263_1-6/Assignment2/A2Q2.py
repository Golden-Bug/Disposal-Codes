
n=int(input("Enter the limit of series: "))
i=1
def sum_of_series(x=1):
	global i
	i+=1	
	if(i<=n):
		x+=i
		return sum_of_series(x)
	else:
		return x

s=sum_of_series()
print("The sum of the series: {}".format(s))

