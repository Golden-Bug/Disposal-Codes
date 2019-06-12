# Program to Comparison of two bargraph

import numpy as np
import matplotlib.pyplot as plt
 
# data to plot
n_groups = 4
c1 = (500,700,1500,890)
c2 = (485,730,1600,960)
 
# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8
 
rects1 = plt.bar(index, c1, bar_width,
                 alpha=opacity,
                 color='gold',
                 label='C1')
 
rects2 = plt.bar(index + bar_width,c2, bar_width,
                 alpha=opacity,
                 color='lightcoral',
                 label='C2')
 
plt.xlabel('Years')
plt.ylabel('Cities')
plt.title('Population')
plt.xticks(index + bar_width, ('y1', 'y2', 'y3', 'y4'))
plt.legend()
 
plt.tight_layout()
plt.show()
