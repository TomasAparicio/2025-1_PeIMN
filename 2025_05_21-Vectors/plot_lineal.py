import numpy as np
import matplotlib.pyplot as plt
from scipy import constants

# Constantes físicas
e = 1.602176634e-19  # Carga fundamental en C
h_expected = constants.h  # Valor esperado de h (6.62607015e-34 J·s)

# Leer los resultados del archivo de salida de C++
# Asumo que el archivo se llama "resultados.txt" y contiene una sola línea con los valores
with open('Regresion_lineal.txt', 'r') as f:
    data = f.readline().split()
    h_estimated = float(data[0])
    phi = float(data[1])
    err = float(data[2])
    m = float(data[3])
    b = float(data[4])
    d_m = float(data[5])
    d_b = float(data[6])

h_error = d_m*e
phi_error = d_b
# Leer los datos experimentales originales
# Asumo que están en 'millikan.txt' con dos columnas: frecuencia (Hz) y voltaje (V)
freq, voltage = np.loadtxt('data.txt', unpack=True)

# Crear la línea de ajuste
fit_line = m * freq + b

# Crear la figura
plt.figure(figsize=(10, 8))

# Graficar datos experimentales
plt.scatter(freq, voltage, color='blue', label='Datos experimentales', zorder=3)

# Graficar línea de ajuste
plt.plot(freq, fit_line, color='red', linewidth=2,
         label=f'Ajuste lineal: V = ({m:.3e} ± {d_m:.1e}) V·s ν + ({b:.3f} ± {d_b:.1e})V')

# Añadir información sobre h y phi
plt.title('Experimento del efecto fotoeléctrico: Voltaje en función de la frecuencia\n'
          f'h estimado = ({1e34*h_estimated:.3f} ± {1e34*h_error:.3f}) × 10⁻³⁴ J·s (h esperado: {h_expected:.3e} J·s)\n'
          f'Función de trabajo φ = ({phi:.3f} ± {phi_error:.3f}) V\n'
          f'Error relativo: {err:.2%}',
          pad=20, fontsize=12)

# Etiquetas de ejes con formato científico
plt.xlabel('Frecuencia ν (×10¹⁵ Hz)', fontsize=12)
plt.ylabel('Voltaje V (V)', fontsize=12)

# Escalar los valores de frecuencia para mostrarlos en 10^15 Hz
xticks = plt.xticks()[0]
plt.xticks(xticks, [f'{x/1e15:.1f}' for x in xticks])

# Configuración de la cuadrícula y leyenda
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=11, framealpha=1)

# Ajustar márgenes para que quepa todo el texto
plt.tight_layout()

# Guardar la figura en PDF
plt.savefig('ajuste.pdf', dpi=300, bbox_inches='tight')
plt.show()