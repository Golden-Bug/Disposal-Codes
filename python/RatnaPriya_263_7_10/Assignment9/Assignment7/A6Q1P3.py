import matplotlib.pyplot as plt;
import matplotlib.pyplot as plt
 
Year= ('1st Year', '2nd Year', '3rd Year', '4th Year')
population = [103,97,77,60]

cols=['b','y','r','m']
plt.pie(population,labels=Year, colors=cols)

#plt.xlabel('Students')

#plt.ylabel('Year')

plt.title('Number of students in IIIT Kalyani')
plt.show()

