from xml.dom.minidom import parse, parseString
import os
myfile=open('sample.xml')
dom=parse(myfile)
student=dom.getElementsByTagName("student")
print("-----------------------------------------------------------------------")
print("                            Student Details                           |")
print("-----------------------------------------------------------------------")
print("No. | Name\t\t| Age | Class | Roll | Section | Average Marks|")
print("-----------------------------------------------------------------------")

count=0
for i in student:
	count+=1
	age=i.getElementsByTagName("age")[0]

	classes=i.getElementsByTagName("class")[0]

	roll=i.getElementsByTagName("roll")[0]

	section=i.getElementsByTagName("section")[0]

	avg_marks=i.getElementsByTagName("avg_marks")[0]

	print(count," ","|",i.getAttribute("name")," "*(16-len(i.getAttribute("name"))),"|",age.firstChild.data," "*(2-len(age.firstChild.data)),"|",classes.firstChild.data," "*(4-len(classes.firstChild.data)),"|",roll.firstChild.data," "*(3-len(roll.firstChild.data)),"|",section.firstChild.data," "*(6-len(section.firstChild.data)),"|",avg_marks.firstChild.data," "*(11-len(avg_marks.firstChild.data)),"|")
	print("-----------------------------------------------------------------------")
