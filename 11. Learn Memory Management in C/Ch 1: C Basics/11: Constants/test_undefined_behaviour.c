#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// this holds an undefined behaviour
// it might be the case that x = 12 and *p = 11 but &x and p are equal
// x is a constant so its values doesn't change but the pointer is not constant 

int main(int argc, char *argv[])
{
  const int x = 12;
  int *p = &x;

  *p = 11;
  printf("%d\n", x);
  printf("%d\n", *p);
  printf("%p\n", &x);
  printf("%p\n", p);

  int y = 13;

  // Not valid
  //&x = &y;



  return EXIT_SUCCESS;
}
