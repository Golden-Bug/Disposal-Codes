# Printing list of functions in re module that contains the word "find"
# In sorted order

import re
mylist=[]
for entry in dir(re):
	if "find" in entry:
		mylist.append(entry)

mylist.sort()
print mylist
