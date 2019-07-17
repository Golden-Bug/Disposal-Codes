import re

list1=[]
for word in dir(re):
	if 'find' in word:
		list1.append(word)
list1.sort()
print(list1)
