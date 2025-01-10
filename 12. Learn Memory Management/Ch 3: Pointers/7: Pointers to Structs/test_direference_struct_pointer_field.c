#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *p;
}test_t;

int main(int argc, char *argv[])
{
  int x = 12;
  test_t t = {
    .p = &x
  };

  // this is not the same as (*t).p
  // here will get the value of t.p which is a pointer and then it will dereference
  *t.p = 10;

  printf("%d\n", x);

  return EXIT_SUCCESS;
}
