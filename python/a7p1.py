# Program for displaying the piechart using Matplotlib


import matplotlib.pyplot as plt

#Data to plots

labels = '1st Year','2nd Year','3rd Year','4th Year'
sizes =[103,97,77,60]
colors = ['gold','green','lightskyblue','lightcoral']
 
# Plot
plt.pie(sizes, labels=labels, colors=colors,
        autopct='%1.1f%%', shadow=True, startangle=140)
 
plt.axis('equal')
plt.show()



