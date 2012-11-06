import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import LogLocator

fig = plt.figure(1, [5,4])
ax = fig.add_subplot(111)

ax.plot( range(1,100) , range(1,100) ,  color='#aaaaff')
ax.set_xscale('log',basex=2)
# This is default, so play with it
x.xaxis.set_major_locator(LogLocator(base = 2))
plt.show()