import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt
 
Year= ('1st Year', '2nd Year', '3rd Year', '4th Year')
y_pos = np.arange(len(Year))
population = [103,97,77,60]
 
plt.barh(y_pos, population, align='center')

plt.yticks(y_pos, Year)

plt.xlabel('Students')

plt.ylabel('Year')

plt.title('Number of students in IIIT Kalyani')
plt.show()
