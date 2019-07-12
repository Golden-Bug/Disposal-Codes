size = int(input("Enter the size of array  "))
arr = []
for i in range(size):
	ele = input()
	arr.append(ele)
for index,value in enumerate(arr):
	print("The index value is {} and its value is {}".format(index,value))

print("Printing the array in reverse order")
print(arr[::-1])
