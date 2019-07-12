
n=int(input("Enter the limit of series: "))
i=1
def sum_of_series(x):
	global i
	if(i<=n):
		i+=1
		return x+sum_of_series(x+1)
	else:
		return x

s=sum_of_series(0)
print("The sum of the series: {}".format(s))
