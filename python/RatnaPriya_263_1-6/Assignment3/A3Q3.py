def space(n):
	print(" "*n,"1")
	for i in range(1,n+1):
		x=i
		y=1
		m=1
		k=n-i
		while(k>=0):
			print(" ",end="")
			k-=1
		print("1",end=" ")
		for j in range(1,i+1):			
			m=int(m*(x/y))
			print(m,end=" ")
			x-=1
			y+=1
		print("\n",end="")

num=int(input("Enter limit of series: "))
space(num)
