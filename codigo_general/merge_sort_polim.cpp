#include <assert.h>
#include <chrono>
#include <iostream>
#include <random>
using namespace std;
typedef unsigned long ulong;

class Comparator {
public:
  virtual bool compare(int a, int b) = 0;
};

class Ascending : public Comparator {
public:
  bool compare(int a, int b) override { return a <= b; }
};

class Descending : public Comparator {
public:
  bool compare(int a, int b) override { return a >= b; }
};

void merge(int *array, ulong init, ulong mid, ulong end, Comparator *comp) {
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
    if (comp->compare(*(l_array + i), *(r_array + j))) {
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

void mergeSort(int *array, ulong init, ulong end, Comparator *comp) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort(array, init, mid, comp);
    mergeSort(array, mid + 1, end, comp);
    merge(array, init, mid, end, comp);
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

  Ascending as;
  Descending des;

  Comparator *comp = nullptr;

  // cout << "ORIGINAL:";
  // cout << endl;
  //  printArray(arr_size, data);

  comp = &des;
  mergeSort(data, 0, arr_size - 1, comp);

  // cout << "ORDENADO:";
  // cout << endl;
  //  printArray(arr_size, data);

  delete[] data;

  auto fin = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> tiempo = fin - inicio;

  cout << "tiempo: " << tiempo.count() << " milisegundos";

  return 0;
}
