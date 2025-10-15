import numpy as np
import matplotlib.pyplot as plt

data0 =np.loadtxt('output.txt')  # Quake III or
data1 =np.loadtxt('output1.txt') #using 1/sqrtf(x)
x1_value = data0[:,0]
x2_value = data1[:,0]
y1_value = data0[:,1]
y2_value = data1[:,1]
plt.figure(figsize=(10, 8))
plt.scatter(x1_value,y1_value,color='r',s=20, alpha=0.6,linewidths= 0.3)
plt.title("Alogorithm in Quake III compared with 1.0 / sqrt(x)",fontsize=20)

plt.xlabel('Input Value x from 0 to 10**6', fontsize=25)
plt.ylabel('Relative Error', fontsize=25)
plt.legend(fontsize=11)
plt.tick_params(axis='x', labelsize=20)  # x轴刻度
plt.tick_params(axis='y', labelsize=20)
plt.show()

plt.figure(figsize=(10, 8))
plt.scatter(x2_value,y2_value,color='b',s=20 ,alpha=0.6,linewidths= 0.3)
plt.title(" 1.0f / sqrt(x)f compared with 1.0 / sqrt(x)",fontsize=25)
plt.xlabel('Input Value x from 0 to 10**6', fontsize=25)
plt.ylabel('Relative Error which is 10**(-8)', fontsize=25)
plt.legend(fontsize=11)
plt.tick_params(axis='x', labelsize=20)  # x轴刻度
plt.tick_params(axis='y', labelsize=20)
plt.show()