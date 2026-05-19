## 📊 Comparación de Rendimiento: Variaciones de Merge Sort

Este proyecto analiza el impacto en el rendimiento del algoritmo **Merge Sort** al implementar tres variantes distintas en C++ para ordenar arreglos dinámicos.

### 🔍 Métodos Comparados

* **Método Normal:** Implementación directa con funciones nativas. Permite al compilador aplicar máximas optimizaciones en tiempo de compilación.
* **Polimorfismo:** Uso de clases abstractas y estructuras de comparación virtuales. Introduce una sobrecarga debido a la búsqueda en la tabla de funciones virtuales (*vtable*).
* **Puntero a Función:** Paso dinámico de la lógica de ordenamiento a través de punteros a función tradicionales.
* **Templates:** Una solución más optimizada, no son necesarios intermediarios y hace más rápido el código.

---

## 🛠️ Guía de Uso

### Requisitos Previos
* **Compilador de C++** (compatible con C++11 o superior, como `g++`).
* **Intérprete de Python 3** (con las librerías `pandas` y `matplotlib` instaladas).

### Pasos para Ejecutar el Proyecto

Sigue estos pasos en tu terminal para compilar el benchmark y generar las métricas:

1. **Compilar el código fuente:**
Genera el archivo ejecutable compilando el código en c++.
2. **Ejecuta el ejecutable.**
Ahora ejecuta tu archivo y verás una tabla de comparación.
```bash
===========================================================================================
ELEMENTOS      M. NORMAL (ms)    POLIMORFISMO (ms)     PUNT. FUNC (ms)   TEMPLATES (ms)    
-------------------------------------------------------------------------------------------
1              0.000912          0.000197              0.000224          0.000406          
10001          2.69773           2.32515               1.77971           1.01452           
20001          1.92956           2.03942               1.71672           1.37829           
30001          2.14994           2.70876               2.63039           2.10062           
40001          2.86598           3.66158               3.67354           2.86775           
50001          3.67425           4.67497               4.54623           3.67374           
60001          4.36543           5.57303               5.60538           4.47626           
70001          5.20734           6.56581               6.63734           5.28858           
80001          6.2686            7.69801               7.74627           6.3334            
90001          6.90569           8.72931               8.61985           6.91444           
100001         7.67728           9.70441               9.5716            7.58583           
110001         8.56845           10.7102               10.5324           8.76775           
120001         9.22464           11.8658               11.5742           9.33412           
130001         10.1475           12.8363               12.7685           10.0655           
140001         11.1121           13.975                13.9572           11.1827           
150001         11.9464           15.2565               14.9407           11.8286
...      
 ```
3. **Genera la gráfica.**
Ejecuta el script de Python para procesar el CSV y renderizar las curvas de rendimiento.
![Gráfico de Rendimiento de Merge Sort](grafico_rendimiento.png)
