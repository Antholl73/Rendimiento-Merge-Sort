#ifndef FUNCS_MERGE_HPP
#define FUNCS_MERGE_HPP

typedef unsigned long ulong;

class Comparator {
public:
  virtual bool compare(int a, int b) = 0;
  virtual ~Comparator() = default;
};

class Ascending : public Comparator {
public:
  bool compare(int a, int b) override;
};

class Descending : public Comparator {
public:
  bool compare(int a, int b) override;
};

bool ascending_function(int a, int b);
bool descending_function(int a, int b);

void merge_asc(int *array, ulong init, ulong mid, ulong end);
void mergeSort_asc(int *array, ulong init, ulong end);

void merge_desc(int *array, ulong init, ulong mid, ulong end);
void mergeSort_desc(int *array, ulong init, ulong end);

void merge_polim(int *array, ulong init, ulong mid, ulong end,
                 Comparator *comp);
void mergeSort_polim(int *array, ulong init, ulong end, Comparator *comp);

void merge_pf(int *array, ulong init, ulong mid, ulong end,
              bool (*compare)(int, int));
void mergeSort_pf(int *array, ulong init, ulong end, bool (*compare)(int, int));

// METODO TEMPLATES
struct SAscending {
  bool compare_t(int a, int b) const { return a <= b; }
};
struct SDescending {
  bool compare_t(int a, int b) const { return a >= b; }
};

template <typename compareType>
void merge_temp(int *array, ulong init, ulong mid, ulong end, compareType C) {
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
    if (C.compare_t(*(l_array + i), *(r_array + j))) {
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

template <typename compareType>
void mergeSort_temp(int *array, ulong init, ulong end, compareType compare) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_temp(array, init, mid, compare);
    mergeSort_temp(array, mid + 1, end, compare);
    merge_temp(array, init, mid, end, compare);
  }
}

// METODO TEMPLATES 2
struct TAscending {
  inline bool compare_t2(int a, int b) const { return a <= b; }
};

struct TDescending {
  inline bool compare_t2(int a, int b) const { return a >= b; }
};
template <typename compareType>
inline void merge_temp_2(int *array, ulong init, ulong mid, ulong end,
                         compareType C) {
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
    if (C.compare_t2(*(l_array + i), *(r_array + j))) {
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

template <typename compareType>
inline void mergeSort_temp_2(int *array, ulong init, ulong end,
                             compareType compare) {
  if (init < end) {
    ulong mid = init + (end - init) / 2;
    mergeSort_temp_2(array, init, mid, compare);
    mergeSort_temp_2(array, mid + 1, end, compare);
    merge_temp_2(array, init, mid, end, compare);
  }
}

#endif // !FUNCS_MERGE_HPP
