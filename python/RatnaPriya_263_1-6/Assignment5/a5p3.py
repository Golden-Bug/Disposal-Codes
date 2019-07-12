num_students = int(raw_input("Please enter number of students:"))
print "you entered %s students" %num_students
student_info = {}
student_data = ['Math marks : ', 'Physics marks : ', 'Chemistry marks : ']
for i in range(0,num_students):
    student_name = raw_input("Name :")
    student_info[student_name] = {}
    for entry in student_data:
        student_info[student_name][entry] = int(raw_input(entry)) #storing the marks entered as integers to perform arithmetic operations later on.
#print student_info
print"Please enter student name ?"
name = raw_input("Student name : ")
if name in student_info.keys():
    print "Average student marks : ", str(sum(student_info[name].values())/3.0)
else:
    print"please enter valid name"
