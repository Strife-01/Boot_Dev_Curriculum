#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

char *get_full_greeting(char *greeting, char *name, int size) {
  char *full_greeting = (char *)malloc(sizeof(char) * size);
  if (full_greeting == NULL) {
    return NULL;
  }
  snprintf(full_greeting, size, "%s %s", greeting, name);
  return full_greeting;
}

