import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt
 
Year= ('1st Year', '2nd Year', '3rd Year', '4th Year')

population = [103,97,77,60]
bins=[50,60,70,80,90,100,110] 

plt.hist(population,bins,histtype='bar') 

plt.xlabel('Students')

plt.ylabel('Year')

plt.title('Number of students in IIIT Kalyani')
plt.show()

