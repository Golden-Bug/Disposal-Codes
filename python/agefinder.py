# Gives the age
from datetime import date
	
def calculate_age(dtob):
            today = date.today()
	    return today.year - dtob.year - ((today.month, today.day) < (dtob.month, dtob.day))
a= int(input("Enter the year of birth : "))
b= int(input("Enter the month of birth : "))
c= int(input("Enter the date of birth : "))

print(calculate_age(date(a,b,c)))




























"""import datetime
def calcuate_age(birth):
	today=date.today()
	try:
		birthday = born.replace(year=today.year)
	except ValueError:
		birthday = born.replace(year=today.year,day=born.day-1)

	if birthday>today:
		return today.year -born.year - 1
	else:
		return today.year -born.year


k = input("Enter your birthday")
"""
	

