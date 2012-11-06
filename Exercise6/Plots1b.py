"""Plots1b.py
    TASK:       Generate a plot form the given Data file 
    
		Has to be changed for more data in the data file 
"""
__author__ = "Marion Baumgartner (marion.baumgartner@uzh.ch)"
__date__ = "$Date: 28/09/2012 $"


from numpy import *
import matplotlib.pyplot as plt
from matplotlib.ticker import LogLocator

time, array_size = loadtxt('dataTask1b.dat', unpack=True)

array_size=array_size/1024
fig = plt.figure(1, [5,4])
ax = fig.add_subplot(111)

ax.plot(array_size[0:15],time[0:15],"b-",label=r'$N=%g$'%(1))
ax.plot(array_size[0:15],time[0:15],"ro")

ax.plot(array_size[16:30],time[16:30],"g-",label=r'$N=%g$'%(16))
ax.plot(array_size[16:30],time[16:30],"ro")

ax.plot(array_size[31:45],time[31:45],"y-",label=r'$N=%g$'%(64))
ax.plot(array_size[31:45],time[31:45],"ro")
ax.set_xscale('log')
# This is default, so play with it
plt.legend(loc='upper left')
ax.set_xscale('log',basex=2)
ax.grid(True)
plt.xlabel("array size in KB")
plt.ylabel("time in sec")
#ax.xaxis.set_major_locator(LogLocator(base = 2.0))
plt.savefig("CacheSize.png")
plt.show()
