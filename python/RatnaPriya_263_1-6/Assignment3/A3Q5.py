
count=0
my_list=[]
n=input("Enter the number of elements: ")
for i in range(n):
	a=raw_input("Enter: ")
	my_list.append(a)

ele=raw_input("Enter element to count occurences: ")

for j in range(0,n):
	if(my_list[j]==ele):
		count+=1

print("{} has occured in the array {} time/s".format(ele,count))
