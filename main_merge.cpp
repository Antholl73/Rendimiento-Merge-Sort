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

  SAscending ascen;

  // Crear el archivo.csv
  ofstream archivo_csv("tiempos_merge.csv");
  archivo_csv
      << "Elementos, Normal, Polimorfismo, Puntero_funcion, Templates\n";

  // =======================================================================
  // IMPRESIÓN DE LA CABECERA DE LA TABLA
  // =======================================================================
  cout << endl;
  cout << setfill('=') << setw(91) << "" << endl;
  cout << setfill(' ');

  cout << left << setw(15) << "ELEMENTOS" << left << setw(18)
       << "M. NORMAL (ms)" << left << setw(22) << "POLIMORFISMO (ms)" << left
       << setw(18) << "PUNT. FUNC (ms)" << left << setw(18) << "TEMPLATES (ms)"
       << endl;

  cout << setfill('-') << setw(91) << "" << endl;
  cout << setfill(' ');
  // =======================================================================

  while (arr_size <= 2000001) {
    int *data1 = new int[arr_size];
    int *data2 = new int[arr_size];
    int *data3 = new int[arr_size];
    int *data4 = new int[arr_size];

    rand_arr(arr_size, data1);

    for (ulong i = 0; i < arr_size; i++) {
      *(data2 + i) = *(data1 + i);
      *(data3 + i) = *(data1 + i);
      *(data4 + i) = *(data1 + i);
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

    // METODO TEMPLATES
    auto inicio4 = chrono::high_resolution_clock::now();

    mergeSort_temp(data4, 0, arr_size - 1, ascen);

    auto fin4 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo4 = fin4 - inicio4;

    // =======================================================================
    // IMPRESIÓN FORMATEADA DE FILAS
    // =======================================================================
    cout << left << setw(15) << arr_size << left << setw(18) << tiempo1.count()
         << left << setw(22) << tiempo2.count() << left << setw(18)
         << tiempo3.count() << left << setw(18) << tiempo4.count() << endl;
    // =======================================================================

    // Guardamos los datos puros en el archivo CSV
    archivo_csv << arr_size << "," << tiempo1.count() << "," << tiempo2.count()
                << "," << tiempo3.count() << "," << tiempo4.count() << "\n";

    delete[] data1;
    delete[] data2;
    delete[] data3;
    delete[] data4;

    arr_size += 10000;
  }

  // Línea decorativa inferior al finalizar todo el bucle
  cout << setfill('=') << setw(91) << "" << endl;
  cout << endl;

  // Cerrar archivo
  archivo_csv.close();
  cout << "Datos exportados :) \n";

  return 0;
}
