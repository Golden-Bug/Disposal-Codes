
my_list=['']
n=input("Enter the number of elements: ")
my_list[0]=raw_input("Enter: ")
for i in range(1,n):
	a=raw_input("Enter: ")
	my_list.append(a)

ele=raw_input("Enter the element you want to delete: ")

for i in my_list:
	if(ele==i):
		my_list.remove(i)
		break

for j in my_list:
	print(j),


