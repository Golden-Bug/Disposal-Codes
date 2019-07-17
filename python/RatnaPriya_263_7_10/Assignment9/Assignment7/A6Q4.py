import re

x=input("Enter email address: ")

if(re.search(r'\w*@[\w.-_]*\.[a-z]',x)):
	print("Email address is valid")

else:
	print("Email address is not valid")
	
