dem=[]
sup=[]
for i in range(0,3):
	x=input("Enter demand: ")
	y=input("Enter supply: ")
	dem.append(x)
	sup.append(y)

matrix = []
for i in range(0,3):
    matrix.append([])
    for j in range(0,3):
        matrix[i].append(0)

matrix1 = []
for i in range(0,3):
    matrix1.append([])
    for j in range(0,3):
        matrix1[i].append(0)

for i in range(0,3):
	for j in range(0,3):
		matrix[i][j]=input("Enter cost: ")

k=0
i=0
while(i<3 and k<3):
	matrix1[i][k]=min(dem[i],sup[i])
	x=min(dem[k],sup[i])
	while(dem[k]>0 and sup[i]>0):
		dem[k]-=x
		sup[i]-=x
	if(dem[k]<=0):
		k+=1
		continue
	if(sup[i]<=0):
		i+=1
total_cost=0
for i in range(0,3):
	for j in range(0,3):
		total_cost=total_cost+matrix[i][j]*matrix1[i][j]

print("Total transportation cost using NWC method is: {} ".format(total_cost))
	
	
		





