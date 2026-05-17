#include "funcs_merge.hpp"

// METODO NORMAL
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
void mergeSort_asc(int *array, ulong init, ulong end) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_asc(array, init, mid);
    mergeSort_asc(array, mid + 1, end);
    merge_asc(array, init, mid, end);
  }
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
void mergeSort_desc(int *array, ulong init, ulong end) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_desc(array, init, mid);
    mergeSort_desc(array, mid + 1, end);
    merge_desc(array, init, mid, end);
  }
}

// METODO POLIMORFISMO

bool Ascending::compare(int a, int b) { return a <= b; }
bool Descending::compare(int a, int b) { return a >= b; }

void merge_polim(int *array, ulong init, ulong mid, ulong end,
                 Comparator *comp) {
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
void mergeSort_polim(int *array, ulong init, ulong end, Comparator *comp) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_polim(array, init, mid, comp);
    mergeSort_polim(array, mid + 1, end, comp);
    merge_polim(array, init, mid, end, comp);
  }
}

// METODO PUNTERO A FUNCION
bool ascending_function(int a, int b) { return a <= b; }
bool descending_function(int a, int b) { return a >= b; }

void merge_pf(int *array, ulong init, ulong mid, ulong end,
              bool (*compare)(int, int)) {
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
    if (compare(*(l_array + i), *(r_array + j))) {
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
void mergeSort_pf(int *array, ulong init, ulong end,
                  bool (*compare)(int, int)) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_pf(array, init, mid, compare);
    mergeSort_pf(array, mid + 1, end, compare);
    merge_pf(array, init, mid, end, compare);
  }
}
