import matplotlib.pyplot as plt
import numpy as np


# read data
N, Err_Trapecio, Err_Simpson, Err_r_Trapecio, Err_r_Simpson  = np.loadtxt("C:\Laboratorios\2025-1_PeIMN\2025_05_09-Integracion_Numerica/err_vs_N.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(N, Err_Trapecio, '-v', label = 'Trapecio')
ax.plot(N, Err_Simpson, '-^', label = 'Simpson')
ax.plot(N, Err_r_Trapecio, '-<', label = 'Richardson-Trapecio')
ax.plot(N, Err_r_Simpson, '->', label = 'Richardson-Simpson')

ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('Numero de iteraciones')
ax.set_ylabel('Error relativo')
ax.legend()
fig.savefig('Error_integrales.pdf')