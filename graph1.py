import numpy as np
import matplotlib.pyplot as plt
# sort time - random data
# bubble sort
#time1 = [56, 149, 262, 422, 602, 799, 1081, 1308, 1648, 1982, 2518, 2859, 3404, 3839, 4259, 4938, 5472, 6095, 6897]
# insert sort
#time1 = [35, 64, 175, 259, 406, 572, 618, 941, 1170, 1381, 1606, 1644, 2176, 2569, 2913, 2829, 3362, 4078, 4438]
# shaker sort
time1 = [37, 63, 152, 241, 350, 527, 599, 716, 1086, 1270, 1546, 1696, 2111, 1966, 2285, 2738, 3170, 3609, 4128]
# sort time - best data
# bubble sort
#time2 = [33, 81, 142, 241, 347, 493, 625, 785, 976, 1175, 1404, 1649, 1910, 2209, 2498, 2830, 3167, 3586, 3966]
# insert sort
#time2 = [15, 40, 67, 110, 161, 221, 299, 375, 462, 567, 666, 787, 908, 1049, 1190, 1350, 1500, 1678, 1854]
# shaker sort
time2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# sort time - worst data
# bubble sort
#time3 = [46, 183, 373, 487, 867, 1120, 1312, 2005, 2162, 2498, 3322, 3925, 4468, 5163, 5594, 6499, 7511, 8019, 8889]
# insert sort
#time3 = [45, 112, 177, 284, 454, 706, 1051, 1111, 1633, 1933, 2549, 3051, 2923, 3688, 4206, 4365, 5244, 5851, 6210]
# shaker sort
time3 = [38, 157, 273, 392, 527, 888, 1016, 1197, 1807, 2066, 2465, 3010, 3251, 3959, 4373, 5120, 5599, 6709, 7138]

number = []
for i in range(1, len(time1) + 1):
    number.append(1000 + i*250)



plt.figure(figsize=(10, 5))
plt.plot(number, time1, 'ro', marker="D", color='b', label=r'random array')
plt.plot(number, time2, 'ro', marker="v", color='g', label=r'best array')
plt.plot(number, time3, 'ro', marker="*", label=r'worst array')

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()

