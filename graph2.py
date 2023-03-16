import numpy as np
import matplotlib.pyplot as plt
# bubble sort time -- O
time1 = [20, 25, 40, 46, 62, 82, 100, 118, 136, 160, 181, 203, 232, 260, 289, 323, 343, 384, 408, 452, 489, 522, 562, 604, 656, 708, 748, 802, 851, 903, 955, 1017, 1126, 1149, 1206]
# bubble sort time -- O1
time2 = [20, 20, 42, 46, 64, 84, 101, 120, 141, 158, 182, 202, 225, 257, 289, 322, 347, 377, 420, 463, 545, 548, 577, 613, 651, 760, 748, 862, 902, 900, 957, 1015, 1074, 1170, 1212]
# bubble sort time -- O2
time3 = [20, 21, 41, 43, 61, 80, 88, 103, 123, 141, 166, 188, 219, 241, 266, 310, 325, 360, 390, 423, 467, 503, 544, 588, 635, 680, 732, 789, 844, 905, 977, 1057, 1126, 1205, 1280]
# bubble sort time -- O3
time4 = [22, 40, 43, 60, 80, 104, 121, 141, 168, 209, 250, 278, 310, 351, 401, 447, 508, 569, 631, 705, 787, 852, 949, 1036, 1126, 1231, 1328, 1421, 1532, 1651, 1761, 1860, 1978, 2101, 2222]
number = []
for i in range(1, len(time1) + 1):
    number.append(np.log(1500 + i*250))
    time1[i-1] = np.log(time1[i-1])
    time2[i - 1] = np.log(time2[i - 1])
    time3[i - 1] = np.log(time3[i - 1])
    time4[i - 1] = np.log(time4[i - 1])


k1 = np.polyfit(number, time1, 1)
print("bubble sort time -- O")
print(k1)
x_th1 = np.arange(np.log(1000), np.log(10000), np.log(10000)/1000)
y_th1 = []
for i in range(0, len(x_th1)):
    y_th1.append(k1[0] * x_th1[i] + k1[1])
plt.figure(figsize=(10, 5))

k2 = np.polyfit(number, time2, 1)
print("bubble sort time -- O1")
print(k2)
x_th2 = np.arange(np.log(1000), np.log(10000), np.log(10000)/1000)
y_th2 = []
for i in range(0, len(x_th2)):
    y_th2.append(k2[0] * x_th2[i] + k2[1])

k3 = np.polyfit(number, time3, 1)
print("bubble sort time -- O2")
print(k3)
x_th3 = np.arange(np.log(1000), np.log(10000), np.log(10000)/1000)
y_th3 = []
for i in range(0, len(x_th3)):
    y_th3.append(k3[0] * x_th3[i] + k3[1])

k4 = np.polyfit(number, time4, 1)
print("bubble sort time -- O3")
print(k4)
x_th4 = np.arange(np.log(1000), np.log(10000), np.log(10000)/1000)
y_th4 = []
for i in range(0, len(x_th4)):
    y_th4.append(k4[0] * x_th4[i] + k4[1])


plt.figure(figsize=(10, 5))
plt.plot(x_th1, y_th1, label=r'Bubble sort time -- O')
plt.plot(x_th2, y_th2, label=r'Bubble sort time -- O_1')
plt.plot(x_th3, y_th3, label=r'Bubble sort time -- O_2')
plt.plot(x_th4, y_th4, label=r'Bubble sort time -- O_3')

plt.errorbar(number, time1, xerr=0, yerr=0, fmt=".k", label="data")
plt.errorbar(number, time2, xerr=0, yerr=0, fmt=".k")
plt.errorbar(number, time3, xerr=0, yerr=0, fmt=".k")
plt.errorbar(number, time4, xerr=0, yerr=0, fmt=".k")

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()

