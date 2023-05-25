#include <stdio.h>
#include <string.h>
#include "jaeyeong.h"

char* version(Version version) {
  char* result = (char*)malloc(sizeof(char) * 20);
  sprintf(result, "%d.%d.%d", version.major, version.minor, version.patch);
  return result;
}

int ends_with(const char* str, const char* pattern) {
  size_t str_length = strlen(str);
  size_t pattern_length = strlen(pattern);
  if (str_length < pattern_length) return 0;
  const char* end = str + (str_length - pattern_length);
  return strcmp(end, pattern) == 0;
}