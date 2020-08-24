#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt

filename = "hashrecord.txt"
filename2= "hashrecord2.txt"
filename3 = "hashrecord3.txt"
filename4 = "hashrecord4.txt"

data = np.genfromtxt(filename, dtype=np.float64, delimiter=',')
data2 = np.genfromtxt(filename2, dtype=np.float64, delimiter=',')
data3 = np.genfromtxt(filename3, dtype=np.float64, delimiter=',')
data4 = np.genfromtxt(filename4, dtype=np.float64, delimiter=',')

print(data[:, 1][-1])
print()
print(data2[:, 1][-1])
print()
print(data3[:, 1][-1])
print()
print(data4[:, 1][-1])

plt.plot(data[:, 0], data[:, 1], label = "Separate Chaining with Mod Hash Function")
plt.plot(data2[:, 0], data2[:, 1], label = "Separate Chaining with Mid Square Hash Function")
plt.plot(data3[:, 0], data3[:, 1], label = "Open Addressing with Mid SquareHash Function")
plt.plot(data4[:, 0], data4[:, 1], label = "Open Adressing with Mod Hash Function")
plt.legend();
plt.xlabel('Load factor')
plt.ylabel('Collisions') 
plt.title("Load Factor vs Collisions with Size 480")

plt.show()
