import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

# Plot the half-ball
u = np.linspace(0, np.pi, 100)
v = np.linspace(0, np.pi, 100)
x = 10 * np.outer(np.cos(u), np.sin(v))
y = 8 * np.outer(np.sin(u), np.sin(v))
z = 5 * np.outer(np.ones(np.size(u)), np.cos(v))

# Create data
data =  np.exp((x/10)**2 + (y/8)**2 + (z/5)**2)
colors = plt.cm.autumn((data - 1) / (np.max(data) - 1))

ax.plot_surface(x, y, z, facecolors=colors, rstride=1, cstride=1, antialiased=True)



# Create data
data =  np.exp((x/10)**2 + (z/5)**2)
colors = plt.cm.autumn((data - 1) / (np.max(data) - 1))

# Plot the intersection
ax.plot_surface(x, 0, z, facecolors=colors, rstride=1, cstride=1, antialiased=True)



ax.set_aspect('equal')

plt.show()