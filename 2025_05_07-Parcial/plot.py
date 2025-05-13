import matplotlib.pyplot as plt
import numpy as np


# read data
N, x_sug, x_err = np.loadtxt("err_vs_h.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(N, x_err, '-o', label = 'Metodo de Newton')
ax.set_yscale('log')
ax.set_xlabel('Numero de iteraciones')
ax.set_ylabel('Error relativo')
ax.legend()
fig.savefig('Error_Metodo_Newton-Tomas_Aparicio.pdf')