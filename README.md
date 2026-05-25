## 📊 Comparación de Rendimiento: Variaciones de Merge Sort

Este proyecto analiza el impacto en el rendimiento del algoritmo **Merge Sort** al implementar tres variantes distintas en C++ para ordenar arreglos dinámicos.

### 🔍 Métodos Comparados

- **Método Normal:** Implementación directa con funciones nativas. Permite al compilador aplicar máximas optimizaciones en tiempo de compilación.
- **Polimorfismo:** Uso de clases abstractas y estructuras de comparación virtuales. Introduce una sobrecarga debido a la búsqueda en la tabla de funciones virtuales (_vtable_).
- **Puntero a Función:** Paso dinámico de la lógica de ordenamiento a través de punteros a función tradicionales.
- **Templates (Plantillas):** Uso de plantillas para mejor optimización.

---

## 🛠️ Guía de Uso

### Requisitos Previos

- **Compilador de C++** (compatible con C++11 o superior, como `g++`).
- **Intérprete de Python 3** (con las librerías `pandas` y `matplotlib` instaladas).

### Pasos para Ejecutar el Proyecto

Sigue estos pasos en tu terminal para compilar el benchmark y generar las métricas:

1. **Compilar el código fuente:**
   Genera el archivo ejecutable compilando el código en c++.
2. **Ejecuta el ejecutable.**
   Ahora ejecuta tu archivo y verás una tabla de comparación.

```bash
===========================================================================================
ELEMENTOS      M. NORMAL (ms)    POLIMORFISMO (ms)     PUNT. FUNC (ms)   TEMPLATES (ms)    INLINE (ms)       
-------------------------------------------------------------------------------------------
1              0.000185          0.00014               0.000178          2.2e-05           2.5e-05           
50001          5.38635           5.6258                4.62943           3.65295           3.73226           
100001         7.76198           10.0018               9.71021           7.74549           7.80538           
150001         11.9066           15.4083               14.9735           12.219            12.1935           
200001         16.2384           20.8897               19.9395           15.9009           16.7103           
250001         20.4638           26.4404               25.6678           20.2558           20.8286           
300001         25.1739           32.3683               31.4498           24.8568           25.5895           
350001         29.5149           39.4005               37.0368           29.2272           29.7917           
400001         33.6505           43.7355               42.3037           33.7555           34.2621           
450001         38.3047           49.64                 47.5797           37.7385           38.6687           
500001         41.8586           55.3809               52.7544           42.3259           43.4535           
550001         46.6445           61.2176               58.7233           47.706            47.7035           
600001         50.8052           65.974                64.7369           51.3077           52.7913           
650001         55.7608           73.1251               79.4563           58.9116           56.1973           
700001         59.3607           78.586                77.1384           60.2918           61.1268           
750001         64.3507           83.4855               80.955            64.1801           65.9473           
800001         68.6492           90.4509               86.4687           67.9964           69.9478           
850001         73.3404           96.0894               92.3565           73.3319           74.8236           
900001         78.3534           101.396               98.0142           79.1577           79.2006           
950001         81.2935           106.669               103.919           82.3848           84.3403           
1000001        85.8726           113.118               108.898           87.1341           88.6277           
1050001        89.2262           118.18                114.792           90.3822           92.732            
1100001        95.3284           125.893               121.431           97.4249           97.3389           
1150001        101.411           131.987               127.848           101.002           102.927           
1200001        104.928           138.657               133.369           104.673           107.567
...
```

1. **Genera la gráfica.**
   Ejecuta el script de Python para procesar el CSV y renderizar las curvas de rendimiento.
   ![Gráfico de Rendimiento de Merge Sort](grafico_rendimiento.png)
