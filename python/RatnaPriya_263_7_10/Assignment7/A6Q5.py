import re

x=input("Enter your favourite pet in the form 'pet:name_of_pet' : ")

pattern='pet:\w\w\w'

match=re.match(pattern,x)

print("Using match method: {}".format(match.group(0)))

search=re.search(pattern,x)

print("Using search method: {}".format(match.group(0)))

