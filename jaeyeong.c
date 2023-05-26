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

int starts_with(const char* str, const char* prefix) {
  size_t str_len = strlen(str);
  size_t prefix_len = strlen(prefix);
  if (prefix_len > str_len) return 0;
  return strncmp(str, prefix, prefix_len) == 0;
}

void trim(char** str) {
  size_t len = strlen(str);
  size_t start = 0;
  while (start < len && isspace((unsigned char)str[start])) start++;
  size_t end = len - 1;
  while (end >= start && isspace((unsigned char)str[end])) end--;
  size_t trimmed_len = end - start + 1;
  memmove(str, str + start, trimmed_len);
  str[trimmed_len] = '\0';
}