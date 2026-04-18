//
// Created by mfbut on 4/3/2021.
//

#include <cstdio>
#include <cstdlib>
#include "formatting.h"



void print_ar(int* ar, int len) {
  /**
 * Prints out the values stored in the array
 * @param ar: the arrays containing the values to print
 * @param len: the number of elements in the array
 */
  for(int i = 0; i < len; ++i){
    printf("%d ", ar[i]);
  }
}

int* parse_args(int argc, char** argv) {
  if (argc <= 1) {
    return nullptr;   // no numbers
  }

  int len = argc - 1;
  int* result = new int[len];

  for (int i = 0; i < len; i++) {
    char* endptr;
    long value = strtol(argv[i + 1], &endptr, 10);

    // invalid input → return nullptr
    if (*endptr != '\0') {
      delete[] result;
      return nullptr;
    }

    result[i] = static_cast<int>(value);
  }

  return result;
}
