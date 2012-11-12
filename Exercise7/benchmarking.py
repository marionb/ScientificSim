"""benchmarking.py
    TASK:       Generate a plot form the Data file times.dat
"""
__author__ = "Marion Baumgartner (marion.baumgartner@uzh.ch)"
__date__ = "$Date: 12/11/2012 $"


from numpy import *
import matplotlib.pyplot as plt
#from matplotlib.ticker import LogLocator

inList, rmList, inVec, rmVec, inSet, rmSet = loadtxt('times.dat', unpack=True)

for i in range(1,len(inList)):
    inList[i]+=inList[i-1]
    rmList[i]+=rmList[i-1]
    
    inVec[i]+=inVec[i-1]
    rmVec[i]+=rmVec[i-1]
    
    inSet[i]+=inSet[i-1]
    rmSet[i]+=rmSet[i-1]
    

fig = plt.figure(1, [5,4])
ax = fig.add_subplot(121)
ay = fig.add_subplot(122)

plt.suptitle("Time for Inserting/Removinh a new Element in a Random Position")

ax.plot(inList,range(len(inList)),"b-",label=r'values from a List')
ax.plot(inVec,range(len(inList)),"r-.",label=r'values from a Vector')
ax.plot(inSet,range(len(inList)),linestyle='--', color='g',label=r'values from a Set')


ay.plot(rmList,range(len(rmList)),"b-",label=r'values from a List')
ay.plot(rmVec,range(len(rmList)),"r-.",label=r'values from a Vector')
ay.plot(rmSet,range(len(rmList)),linestyle='--', color='g',label=r'values from a Set')



# This is default, so play with it
ax.legend(loc='upper left')
ay.legend(loc='upper left')
#ax.set_xscale('log',basex=2)
ax.grid(True)
ay.grid(True)

xLabel = ax.set_xlabel("k (amount of repetionions of the insertion)")
yLabel = ax.set_ylabel("time in $10e-6*$sec to insert an element")
title = ax.set_title("random insertion")

xLabel = ay.set_xlabel("k (amount of repetionions of the delitions)")
yLabel = ay.set_ylabel("time in $10e-6*$sec to delet an element")
title = ay.set_title("random deletion")


#ax.xaxis.set_major_locator(LogLocator(base = 2.0))
#plt.savefig("BenchmarkingInsert.png")
plt.show()
