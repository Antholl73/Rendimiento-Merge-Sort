#include "funcs_arrays.hpp"
#include <iostream>
#include <random>
using namespace std;

void rand_arr(ulong size, int *array) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 100000);

  for (ulong i = 0; i < size; i++) {
    *(array + i) = dis(gen);
  }
}

void print_arr(ulong size, int *array) {
  for (ulong i = 0; i < size; i++) {
    cout << *(array + i) << " ";
  }
  cout << endl;
}
