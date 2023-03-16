import numpy as np
import matplotlib.pyplot as plt
# heap sort
time1 = [347, 346, 346, 345, 351, 354, 365, 363, 355, 367, 372, 383, 384, 386, 388, 393, 404, 419, 447, 424, 437, 447, 431, 428, 437, 443, 468, 475, 485, 465, 480, 477, 481, 502, 545, 505, 512, 534, 511, 500, 523, 549, 611, 521, 534, 545, 581, 543, 525, 546, 560, 549, 589, 547, 570, 564, 559, 571, 573, 613, 666, 624, 634, 617, 604, 610, 615, 636, 630, 617, 696, 628, 642, 672, 709, 632, 670, 686, 672, 673, 692, 696, 694, 680, 695, 686, 727, 692, 698, 854, 761, 745, 767, 763, 748, 742, 760, 753, 747, 779, 786, 764, 855, 764, 782, 775, 994, 787, 832, 825, 803, 789, 867, 830, 821, 875, 852, 828, 858, 847, 835, 854, 1000, 891, 844, 854, 885, 855, 849, 856, 870, 887, 925, 913, 932, 934, 943, 920, 916, 896, 946, 935, 989, 957, 964, 970, 943, 944, 942, 957, 964]
# comb sort
time2 = [368, 360, 363, 372, 385, 394, 457, 394, 384, 390, 395, 400, 405, 405, 414, 428, 425, 475, 428, 431, 446, 443, 442, 446, 448, 461, 459, 461, 462, 473, 474, 480, 482, 482, 486, 495, 503, 499, 502, 509, 509, 522, 527, 522, 536, 541, 545, 544, 555, 562, 563, 566, 563, 564, 576, 583, 583, 584, 587, 598, 600, 603, 601, 602, 611, 621, 621, 623, 634, 631, 640, 642, 643, 646, 659, 662, 660, 672, 682, 681, 680, 684, 684, 700, 707, 704, 711, 719, 720, 724, 727, 732, 740, 742, 745, 742, 750, 761, 760, 770, 774, 768, 779, 782, 780, 785, 796, 795, 802, 803, 805, 809, 817, 822, 830, 831, 829, 851, 864, 924, 876, 1028, 896, 1135, 1084, 1001, 1066, 980, 968, 976, 958, 959, 974, 1024, 972, 1077, 949, 960, 978, 1050, 969, 984, 1035, 980, 979, 1063, 997, 1083, 1075, 994, 1005]
# merge sort time
time3 = [437, 442, 387, 450, 453, 393, 454, 447, 326, 438, 428, 451, 480, 500, 421, 448, 449, 511, 514, 453, 526, 516, 439, 534, 518, 554, 551, 496, 568, 553, 570, 401, 579, 457, 556, 577, 580, 614, 587, 542, 639, 603, 630, 591, 605, 622, 660, 657, 573, 670, 520, 518, 683, 594, 680, 690, 706, 693, 648, 647, 712, 720, 741, 712, 735, 529, 751, 760, 763, 769, 771, 784, 801, 784, 723, 792, 802, 790, 739, 789, 803, 783, 720, 823, 712, 773, 829, 849, 761, 824, 861, 882, 887, 882, 876, 828, 869, 841, 917, 894, 819, 913, 936, 922, 922, 867, 864, 964, 901, 925, 922, 1001, 968, 969, 864, 905, 728, 829, 972, 1013, 852, 1036, 1019, 971, 1061, 1053, 1038, 1035, 1072, 883, 995, 1057, 1089, 1090, 1029, 1075, 1064, 1021, 1084, 1018, 1122, 1105, 921, 1077, 1119, 1117, 1069, 965, 1127, 1141, 1159]
number = []
for i in range(1, len(time2) + 1):
    number.append(100000 + i*1000)
    time1[i - 1] = time1[i - 1]/ ((100000 + i*1000) * np.log(100000 + i*1000))
    time2[i - 1] = time2[i - 1]/ ((100000 + i*1000) * np.log(100000 + i*1000))
    time3[i - 1] = time3[i - 1]/ ((100000 + i*1000) * np.log(100000 + i*1000))


k1 = np.polyfit(number, time1, 1)
print("Heap sort")
print(k1)
x_th1 = np.arange(100000, 260000, 260000/1000)
y_th1 = []
for i in range(0, len(x_th1)):
    y_th1.append(k1[0] * x_th1[i] + k1[1])
plt.figure(figsize=(10, 5))

k2 = np.polyfit(number, time2, 1)
print("Comb sort")
print(k2)
x_th2 = np.arange(100000, 260000, 260000/1000)
y_th2 = []
for i in range(0, len(x_th2)):
    y_th2.append(k2[0] * x_th2[i] + k2[1])

k3 = np.polyfit(number, time3, 1)
print("Merge sort")
print(k3)
x_th3 = np.arange(100000, 260000, 260000/1000)
y_th3 = []
for i in range(0, len(x_th3)):
    y_th3.append(k3[0] * x_th3[i] + k3[1])


plt.figure(figsize=(10, 5))
plt.plot(x_th1, y_th1, label=r'Heap sort')
plt.plot(x_th2, y_th2, label=r'Comb sort')
plt.plot(x_th3, y_th3, label=r'Merge sort')

plt.errorbar(number, time1, xerr=0, yerr=0, fmt=".k", label="data")
plt.errorbar(number, time2, xerr=0, yerr=0, fmt=".k")
plt.errorbar(number, time3, xerr=0, yerr=0, fmt=".k")

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$\frac{t}{N \cdot log(N)}$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()
