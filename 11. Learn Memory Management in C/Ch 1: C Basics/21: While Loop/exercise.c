#include <stdio.h>
#include "exercise.h"

void print_numbers_reverse(int start, int end) {
  int i = start;
  while (i >= end) {
    printf("%i\n", i);
    i--;
  }
}

