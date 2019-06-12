# Program for displaying the piechart using Matplotlib


import matplotlib.pyplot as plt ; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt

objects =('1st Year','2nd Year','3rd Year','4th Year')
y_pos=np.arange(len(objects))
performance=[103,97,77,60]

plt.bar(y_pos,performance,align='center',alpha=0.5)
plt.xticks(y_pos,objects)
plt.ylabel('Students')
plt.title('Class of Different year')

plt.show()
