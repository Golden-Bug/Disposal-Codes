
my_list=['']
n=input("Enter the number of elements: ")
my_list[0]=input("Enter: ")
for i in range(1,n):
	a=input("Enter: ")
	my_list.append(a)
s=0
for j in my_list:
	s=s+j

mean=float(s/n)

my_list.sort()
if(n%2!=0):
	x=int(n/2)
	median=my_list[x]
else:
	median=(my_list[n/2]+my_list[(n/2)-1])/2

occ=0
max_occ=0

for j in my_list:
	for k in my_list:
		if(k==j):
			occ+=1
	if(max_occ<occ):
		max_occ=occ
		mode=j
	occ=0

print(" {} is the mean, {} is the median and {} is the mode".format(mean,median,mode))


