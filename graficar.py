import pandas as pd
import matplotlib.pyplot as plt

try:
    # 1. Leer los datos del CSV generado por tu programa de C++
    df = pd.read_csv('tiempos_merge.csv')
    
    # Limpiamos posibles espacios en blanco en los nombres de las columnas
    df.columns = df.columns.str.strip()

    # 2. Configurar el tamaño y estilo del gráfico
    plt.figure(figsize=(10, 6))
    
    # 3. Dibujar las curvas para cada método
    # Usamos marcadores diferentes para que se distingan claramente
    plt.plot(df['Elementos'], df['Normal'], label='Método Normal', linewidth=1)
    plt.plot(df['Elementos'], df['Polimorfismo'], label='Polimorfismo', linewidth=1)
    plt.plot(df['Elementos'], df['Puntero_funcion'], label='Puntero a Función', linewidth=1)

    # 4. Añadir títulos y etiquetas a los ejes
    plt.title('Comparativa de Rendimiento: Variaciones de Merge Sort', fontsize=14, fontweight='bold')
    plt.xlabel('Número de Elementos (N)', fontsize=12)
    plt.ylabel('Tiempo de Ejecución (ms)', fontsize=12)
    
    # 5. Activar la cuadrícula y la leyenda
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend(fontsize=11)

    # 6. Guardar el gráfico como imagen en la carpeta
    plt.savefig('grafico_rendimiento.png', dpi=300, bbox_inches='tight')
    print(">> [OK] ¡Gráfico guardado con éxito como 'grafico_rendimiento.png'!")
    
    # 7. Mostrar el gráfico en pantalla
    plt.show()

except FileNotFoundError:
    print(">> [ERROR] No se encontró el archivo 'tiempos_merge.csv'.")
    print("   Asegúrate de ejecutar primero tu programa de C++ (./programa_merge) para generarlo.")
