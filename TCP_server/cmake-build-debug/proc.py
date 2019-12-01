import matplotlib.pyplot as plt
import numpy as np
file = open("output.txt","r")
lines = file.readlines()
data = []
i = 0
for l in lines:
	if l.find("cwnd") != -1:
		data.append(int(l[7:]))

x = np.array(data)
plt.plot(x,marker='.')
plt.show()