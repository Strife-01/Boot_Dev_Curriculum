#include <string.h>
#include "exercise.h"

int smart_append(TextBuffer* dest, const char* src) {
  if (dest == NULL || src == NULL) {
    return 1;
  }
  const size_t buffer_size = 64;
  if (dest->length + 1 == buffer_size) {
    return 1;
  }
  // account for \0
  const size_t src_length = strlen(src);
  const size_t remaining_size = buffer_size - 1 - dest->length;
  int i = dest->length;
  int final_length = dest->length;
  for (; i - dest->length < src_length && i < buffer_size - 1; i++) {
    dest->buffer[i] = src[i - dest->length];
    final_length++;
  }

  // take in considerarion full append or parial
  char isFullAppend = 1;
  if (dest->length + src_length > 64 - 1) {
    isFullAppend = 0;
  }
  
  dest->buffer[i] = '\0';
  dest->length = final_length;
  
  return isFullAppend == 1 ? 0 : 1;
}

