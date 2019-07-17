import matplotlib.pyplot as plt
import numpy as np

x=['y1', 'y2', 'y3', 'y4']

y1=[500,700,1500,890]

y2=[485,730,1600,950]

X = np.arange(4)
plt.bar(X + 1.00, y1, color = 'b', width = -0.25,align='edge')
plt.bar(X + 1.25, y2, color = 'g', width = -0.25,align='edge')

plt.title("Population of two cities")

plt.xlabel("Year")
plt.ylabel("Population")
plt.show()
