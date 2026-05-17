#include "funcs_arrays.hpp"
#include "funcs_merge.hpp"
#include <assert.h>
#include <chrono>
#include <fstream> // para los archivo_csv
#include <iomanip> //para imprimir
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  ulong arr_size = 1;
  assert(arr_size > 0);

  Ascending asc;
  Descending desc;
  Comparator *comp = nullptr;
  comp = &asc;

  // Crear el archivo.csv
  ofstream archivo_csv("tiempos_merge.csv");
  archivo_csv << "Elementos, Normal, Polimorfismo, Puntero_funcion\n";

  // =======================================================================
  // IMPRESIÓN DE LA CABECERA DE LA TABLA (Se hace una sola vez fuera del
  // bucle)
  // =======================================================================
  cout << endl;
  cout << setfill('=') << setw(72) << "" << endl; // Línea decorativa superior
  cout << setfill(' '); // Reestablece el relleno a espacios en blanco

  // Definimos los nombres de las columnas con un ancho fijo de caracteres
  cout << left << setw(15) << "ELEMENTOS" << left << setw(18)
       << "M. NORMAL (ms)" << left << setw(22) << "POLIMORFISMO (ms)" << left
       << setw(15) << "PUNT. FUNC (ms)" << endl;

  cout << setfill('-') << setw(72) << "" << endl; // Línea divisoria
  cout << setfill(' ');                           // Reestablece el relleno
  // =======================================================================

  while (arr_size <= 2000001) {
    int *data1 = new int[arr_size];
    int *data2 = new int[arr_size];
    int *data3 = new int[arr_size];

    rand_arr(arr_size, data1);

    for (ulong i = 0; i < arr_size; i++) {
      *(data2 + i) = *(data1 + i);
      *(data3 + i) = *(data1 + i);
    }

    // METODO NORMAL
    auto inicio1 = chrono::high_resolution_clock::now();

    mergeSort_asc(data1, 0, arr_size - 1);

    auto fin1 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo1 = fin1 - inicio1;

    // METODO POLIMORFISMO
    auto inicio2 = chrono::high_resolution_clock::now();

    mergeSort_polim(data2, 0, arr_size - 1, comp);

    auto fin2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo2 = fin2 - inicio2;

    // METODO PUNTERO A FUNCION
    auto inicio3 = chrono::high_resolution_clock::now();

    mergeSort_pf(data3, 0, arr_size - 1, ascending_function);

    auto fin3 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo3 = fin3 - inicio3;

    // =======================================================================
    // IMPRESIÓN FORMATEADA DE FILAS (Mismo ancho 'setw' que la cabecera)
    // =======================================================================
    cout << left << setw(15) << arr_size << left << setw(18) << tiempo1.count()
         << left << setw(22) << tiempo2.count() << left << setw(15)
         << tiempo3.count() << endl;
    // =======================================================================

    // Guardamos los datos puros en el archivo CSV
    archivo_csv << arr_size << "," << tiempo1.count() << "," << tiempo2.count()
                << "," << tiempo3.count() << "\n";

    delete[] data1;
    delete[] data2;
    delete[] data3;

    arr_size += 10000;
  }

  // Línea decorativa inferior al finalizar todo el bucle
  cout << setfill('=') << setw(72) << "" << endl;
  cout << endl;

  // Cerrar archivo
  archivo_csv.close();
  cout << "Datos exportador :) \n";

  return 0;
}
