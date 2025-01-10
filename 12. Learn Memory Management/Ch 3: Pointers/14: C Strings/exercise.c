#include "exercise.h"

void concat_strings(char *str1, const char *str2) {
  int i = 0;
  int j = 0;
  //very bad if no \0 is present - infinite loop
  for (; str1[i] != '\0'; i++) {
    // nothing - after finish we will have i as the location for '\0'
  }
  for (; str2[j] != '\0'; j++) {
    str1[i + j] = str2[j];
  }
  str1[i + j] = str2[j];
}

