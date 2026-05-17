## 📊 Comparación de Rendimiento: Variaciones de Merge Sort

Este proyecto analiza el impacto en el rendimiento del algoritmo **Merge Sort** al implementar tres variantes distintas en C++ para ordenar arreglos dinámicos.

### 🔍 Métodos Comparados

* **Método Normal:** Implementación directa con funciones nativas. Permite al compilador aplicar máximas optimizaciones en tiempo de compilación.
* **Polimorfismo:** Uso de clases abstractas y estructuras de comparación virtuales. Introduce una sobrecarga debido a la búsqueda en la tabla de funciones virtuales (*vtable*).
* **Puntero a Función:** Paso dinámico de la lógica de ordenamiento a través de punteros a función tradicionales.

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
========================================================================
ELEMENTOS      M. NORMAL (ms)    POLIMORFISMO (ms)     PUNT. FUNC (ms)
------------------------------------------------------------------------
1              0.000495          0.000285              0.000253       
10001          2.38113           2.03051               1.46067        
20001          1.53728           2.31408               2.2594         
30001          2.1765            2.70739               2.60631        
40001          2.90025           3.68435               3.58985        
50001          3.64734           4.69439               4.52327        
60001          4.39444           5.76596               5.44713        
70001          5.2017            6.70918               6.45205        
80001          5.95293           7.82213               7.44747        
 ```
3. **Genera la gráfica.**
Ejecuta el script de Python para procesar el CSV y renderizar las curvas de rendimiento.
![Gráfico de Rendimiento de Merge Sort](grafico_rendimiento.png)
