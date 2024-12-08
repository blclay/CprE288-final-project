import matplotlib.pyplot as plt
import numpy as np

r = np.arange(0,2,0.01)
theta = 2*np.pi*r

plt.subplots(subplot_kw={'projection':'polar'})
plt.plot(theta, r)
# plt.set_rmax(2)
# plt.set_rticks([0.5,1,1.5,2])
# plt.set_rlabel_position(-22.5)
plt.grid(True)

plt.suptitle("A line plot on a polar axis", va ='bottom')
plt.show
