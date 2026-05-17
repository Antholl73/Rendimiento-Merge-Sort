#include <assert.h>
#include <chrono>
#include <iostream>
#include <random>
#include <ratio>
using namespace std;
typedef unsigned long ulong;

void merge_asc(int *array, ulong init, ulong mid, ulong end) {
  ulong l_size = mid - init + 1;
  ulong r_size = end - mid;

  int *l_array = new int[l_size];
  int *r_array = new int[r_size];

  for (ulong i = 0; i < l_size; i++) {
    *(l_array + i) = *(array + init + i);
  }
  for (ulong j = 0; j < r_size; j++) {
    *(r_array + j) = *(array + mid + 1 + j);
  }

  ulong i = 0, j = 0, k = init;
  while (i < l_size && j < r_size) {
    if (*(l_array + i) <= *(r_array + j)) {
      *(array + k) = *(l_array + i);
      i++;
    } else {
      *(array + k) = *(r_array + j);
      j++;
    }
    k++;
  }

  while (i < l_size) {
    *(array + k) = *(l_array + i);
    i++;
    k++;
  }

  while (j < r_size) {
    *(array + k) = *(r_array + j);
    j++;
    k++;
  }

  delete[] l_array;
  delete[] r_array;
}

void merge_desc(int *array, ulong init, ulong mid, ulong end) {
  ulong l_size = mid - init + 1;
  ulong r_size = end - mid;

  int *l_array = new int[l_size];
  int *r_array = new int[r_size];

  for (ulong i = 0; i < l_size; i++) {
    *(l_array + i) = *(array + init + i);
  }
  for (ulong j = 0; j < r_size; j++) {
    *(r_array + j) = *(array + mid + 1 + j);
  }

  ulong i = 0, j = 0, k = init;
  while (i < l_size && j < r_size) {
    if (*(l_array + i) >= *(r_array + j)) {
      *(array + k) = *(l_array + i);
      i++;
    } else {
      *(array + k) = *(r_array + j);
      j++;
    }
    k++;
  }

  while (i < l_size) {
    *(array + k) = *(l_array + i);
    i++;
    k++;
  }

  while (j < r_size) {
    *(array + k) = *(r_array + j);
    j++;
    k++;
  }

  delete[] l_array;
  delete[] r_array;
}

void mergeSort_asc(int *array, ulong init, ulong end) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_asc(array, init, mid);
    mergeSort_asc(array, mid + 1, end);
    merge_asc(array, init, mid, end);
  }
}

void mergeSort_desc(int *array, ulong init, ulong end) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_desc(array, init, mid);
    mergeSort_desc(array, mid + 1, end);
    merge_desc(array, init, mid, end);
  }
}

void ran_arr(int *array, ulong size) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 100000);

  for (ulong i = 0; i < size; i++) {
    *(array + i) = dis(gen);
  }
}

void printArray(ulong size, int *array) {
  for (int i = 0; i < size; i++) {
    cout << *(array + i) << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {

  auto inicio = chrono::high_resolution_clock::now();

  ulong arr_size = 10000000;
  int *data = new int[arr_size];

  ran_arr(data, arr_size);
  // cout << "ORIGINAL: ";
  // cout << endl;
  //  printArray(arr_size, data);

  mergeSort_desc(data, 0, arr_size - 1);

  // cout << "ORDENADO: ";
  // cout << endl;
  //  printArray(arr_size, data);

  delete[] data;

  auto fin = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> tiempo = fin - inicio;

  cout << "tiempo: " << tiempo.count() << " milisegundos";
  return 0;
}
