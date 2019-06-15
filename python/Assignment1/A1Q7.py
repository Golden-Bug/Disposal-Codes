
num=int(input("Enter a number: "))
s=0
d=num
while(d>0):
	r=d%10
	s=s*10+r
	d=d//10

if(s==num):
	print("{} is a palindrome number".format(num))
else:
	print("{} is not a palindrome number".format(num))
