# Storing Roll numbers by  Dictionaries - User Defined

n=input("Enter the number of students you want to store with their information ")
Students = dict(raw_input().split() for _ in range(n))
print Students
