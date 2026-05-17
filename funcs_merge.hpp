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

#endif // !FUNCS_MERGE_HPP
