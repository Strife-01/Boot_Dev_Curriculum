#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *intPtr;
  char *charPtr;
  double *doublePtr;
  printf("Size of int pointer: %zu bytes\n", sizeof(intPtr));
  printf("Size of char pointer: %zu bytes\n", sizeof(charPtr));
  printf("Size of double pointer: %zu bytes\n", sizeof(doublePtr));
// Size of int pointer: 8 bytes
// Size of char pointer: 8 bytes
// Size of double pointer: 8 bytes
  printf("%lu\n", sizeof(int*));
  return EXIT_SUCCESS;
}
