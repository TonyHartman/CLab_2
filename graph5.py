import numpy as np
import matplotlib.pyplot as plt
# sort time - random data
# heap sort
#time1 = [50, 52, 59, 60, 60, 60, 61, 71, 80, 80, 80, 80, 86, 100, 100, 100, 100, 101, 105, 115, 117, 120, 121, 122, 124, 137, 140, 140, 141, 151, 160]
# comb sort
#time1 = [54, 60, 60, 60, 60, 64, 74, 80, 80, 80, 80, 82, 99, 100, 100, 100, 100, 108, 120, 120, 120, 120, 123, 137, 141, 140, 142, 142, 151, 160, 164]
# merge sort
time1 = [69, 70, 79, 78, 78, 81, 99, 96, 94, 97, 85, 118, 110, 110, 118, 135, 138, 126, 138, 137, 150, 148, 157, 160, 178, 172, 182, 182, 176, 194, 196]
# sort time - best data
# heap sort
#time2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# comb sort
#time2 = [26, 22, 23, 38, 40, 40, 40, 40, 40, 41, 40, 40, 45, 55, 60, 60, 60, 60, 60, 60, 60, 62, 65, 77, 80, 80, 82, 80, 80, 80, 83]
# merge sort
time2 = [28, 41, 44, 42, 47, 27, 53, 40, 50, 44, 57, 65, 73, 42, 71, 77, 45, 75, 65, 97, 78, 100, 76, 64, 112, 106, 103, 84, 121, 87, 125]
# sort time - worst data
# heap sort
#time3 = [84, 70, 76, 80, 81, 80, 98, 99, 103, 100, 108, 115, 122, 120, 120, 127, 137, 140, 140, 142, 145, 153, 159, 168, 168, 176, 179, 180, 190, 199, 203]
# comb sort
#time3 = [21, 21, 20, 20, 20, 40, 32, 40, 40, 40, 40, 40, 40, 40, 40, 41, 44, 48, 60, 60, 60, 60, 60, 60, 63, 65, 62, 62, 67, 74, 80]
# merge sort
time3 = [35, 20, 41, 21, 51, 38, 50, 50, 59, 40, 56, 70, 80, 57, 68, 51, 75, 79, 87, 96, 66, 64, 60, 93, 82, 100, 60, 109, 92, 101, 80]

number = []
for i in range(1, len(time1) + 1):
    number.append(20000 + i*1000)



plt.figure(figsize=(10, 5))
plt.plot(number, time1, 'ro', marker="D", color='b', label=r'random array')
plt.plot(number, time2, 'ro', marker="v", color='g', label=r'best array')
plt.plot(number, time3, 'ro', marker="*", label=r'?worst array?')

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()

