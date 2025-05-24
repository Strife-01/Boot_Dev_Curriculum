#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char t[] = "abcde";
  printf("%lu\n", sizeof(t)/ sizeof(char));
  printf("%i\n", t[5]);
  return EXIT_SUCCESS;
}
