#include "funct.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void sort(int* Arr, int len) {
  int aux;
  int j;

  for (size_t i = 0; i < len; i++) {
    j = i;

    while ((j > 0) && (Arr[j] < Arr[j - 1])) {

      aux = Arr[j - 1];
      Arr[j - 1] = Arr[j];
      Arr[j] = aux;

      j = j - 1;
    }
  }
}

void print_arr(int* Arr, int len) {
  for (size_t i = 0; i < len; i++) {
    printf("A[%li] = %i\n", i, Arr[i]);
  }
}

int median(int* Arr, int len) {
  int* aux = Arr;

  sort(aux, len);

  return aux[len / 2];
}

void test(void) {

  int A[9] = {rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1,
              rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1,
              rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1};

  printf("Arreglo sin ordenar:\n\n");

  print_arr(A, 9);

  sort(A, 9);

  printf("Arreglo ordenado:\n\n");

  print_arr(A, 9);

  printf("Mediana del arreglo = %i\n", median(A, 9));
}
