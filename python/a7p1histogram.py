# Program for histogram using Matplotlib

import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

x = [103,97,77,60]
num_bins = 4
n, bins, patches = plt.hist(x, num_bins, facecolor='gold', alpha=0.5)
plt.show()

