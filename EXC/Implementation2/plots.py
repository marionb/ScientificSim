
from numpy import *
import matplotlib as mpl
import matplotlib.pyplot as plt


popu, PopuSizeAge8, badGeneProb1, badGeneProb6, badGeneProb12, badGeneProb20, death= loadtxt('data2.dat',unpack=True)
popu0, PopuSizeAge08, badGeneProb01, badGeneProb06, badGeneProb102, badGeneProb020, death0= loadtxt('data0.dat',unpack=True)
time=10*arange(1,51)

fig1=plt.figure()
ax=fig1.add_subplot(1,2,1) 
ax.loglog(time,popu,'ro',label="mutation rate = 2")
ax.loglog(time,popu0,'g+',label="mutation rate = 0")
ax.legend(loc="lower right")
plt.xlabel("generations")
plt.ylabel("number of animals")

ay=fig1.add_subplot(1,2,2) 
ay.plot(time,popu,'ro',label="mutation rate = 2")
ay.plot(time,popu0,'g+',label="mutation rate = 0")
ay.legend(loc="lower right")
ay.ticklabel_format(style='sci', scilimits=(0,0), axis='y')
plt.xlabel("generations")
#plt.ylabel("number of animals")
plt.savefig("popuVSGener.png")

fig2=plt.figure()
plt.plot(time, death,'ro')
plt.xlabel("generations")
plt.ylabel("average age at death")
plt.savefig("DeathStat.png")

fig3=plt.figure()
ax = plt.subplot(1,1,1)
p1,=ax.plot(time, badGeneProb1,'ro',label="gene Probability $1$")
p2, =ax.plot(time, badGeneProb6,'g.',label="gene Probability $6$")
p3, =ax.plot(time, badGeneProb12,'y^',label="gene Probability $12$")
p4, =ax.plot(time, badGeneProb20,'cx', label="gene Probability $20$")
#ax.legend([p2, p1], ["line 2", "line 1"])
lg=ax.legend(loc="lower right")
plt.xlabel("generations")
plt.ylabel("probability for bad geens")
plt.savefig("badGenes.png")

avgAge=[]
mut_rate=[0,1,2,3,5,10,15]
avgAge.append(float(sum(death)) / len(death))
for i in [0,1,3,5,10,15]:
    datname='data%d.dat'%(i)
    print datname
    deathi= loadtxt(datname, unpack=True, usecols=[6])
    avgAge.append(float(sum(deathi)) / len(deathi))
    
fig4=plt.figure()
plt.plot(mut_rate, avgAge,'co')
plt.xlabel("mutation rates")
plt.ylabel("average age at death")
plt.savefig("mutRate.png")