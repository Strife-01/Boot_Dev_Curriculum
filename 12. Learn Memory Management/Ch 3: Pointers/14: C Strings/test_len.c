#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char str[] = "abc";
  printf("%zu\n", sizeof(str));
  return EXIT_SUCCESS;
}
