n=input("Enter number of students: ")

list1=[]
list2=[]
list3=[]
list4=[]

for i in range(n):
	x= raw_input("Enter name of student: ")
	list1.append(x)
	y= raw_input("Enter age of student: ")
	list2.append(y)
	z= raw_input("Enter city of student: ")
	list3.append(z)
	w= raw_input("Enter height of student: ")
	list4.append(w)

d={'name':list1,'age':list2,'city':list3,'height':list4}
print "*********Details of all students in the class*********"
for i in range(n):
	print "Name\t",d['name'][i],
	print "Age\t",d['age'][i],
	print "City\t",d['city'][i],
	print "Height\t",d['height'][i]
	print "\n"



	
	
	
