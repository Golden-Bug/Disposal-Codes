
my_list=['']
n=input("Enter the number of elements: ")
my_list[0]=raw_input("Enter: ")
for i in range(1,n):
	a=raw_input("Enter: ")
	my_list.append(a)

num=input("Enter the index of the element you want to delete: ")

for i in range(0,n):
	if(i==num):
		my_list.pop(i)

for j in my_list:
	print(j),


