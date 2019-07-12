
r=input("Enter number of rows: ")
c=input("Enter number of columns: ")

matrix = []
for i in range(0,r):
    matrix.append([])
    for j in range(0,c):
        matrix[i].append(0)

for i in range(0,r):
	for j in range(0,c):
		matrix[i][j]=input()

for i in range(0,r):
	for j in range(0,c):
		print(matrix[i][j]),
	print("\n"),
