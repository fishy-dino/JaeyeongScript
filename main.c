#include <stdio.h>
#include <stdlib.h>
#include "jaeyeong.h"

#define READ_SIZE 512

void replace(char *str, char find, char replace) {
  while(*str) {
    if (*str == find) str = replace;
    str++;
  }
}

char** split(char *str, const char *delimiter, int *count) {
  int bufferSize = 10;
  int tokenCount = 0;
  char **tokens = malloc(bufferSize * sizeof(char*));
  char *token = strtok(str, delimiter);
   while (token != NULL) {
    tokens[tokenCount] = token;
    tokenCount++;
    if (tokenCount >= bufferSize) {
      bufferSize += 10;
      tokens = realloc(tokens, bufferSize * sizeof(char*));
    }
    token = strtok(NULL, delimiter);
  }
  *count = tokenCount;
  return tokens;
}

int main(int argc, char* argv[]) {
  unsigned int size = 0;
	unsigned int length = 0;
  char *version = "v0.1.0";
  char *buffer = NULL;
  char *fname = NULL;
	FILE *file = NULL;
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error: Unable to open file %s\n", argv[1]);
    return 1;
  }
  while (!feof(file)) {
		size += READ_SIZE;
		buffer = realloc(buffer, sizeof(char) * size);
		length += fread((buffer + size) - READ_SIZE, 1, READ_SIZE, file);
  }
  if (fclose(file) != 0) {
    printf("Error: Unable to close file %s\n", argv[1]);
    if (buffer) free(buffer);
    return 1;
  }
  if (!buffer) return 1;
	buffer[length] = '\0';

  replace(buffer, ';', '\n');
  int tc, last = 0;
  char **lines = split(buffer, "\n", &tc);
  for (int i = 0; i < tc; i++)
    if (lines[i] != '\0') last = 1;
  if (lines[0] != CODE_START || lines[last] != CODE_END) {
    printf("Error: Invalid file format\n");
    if (buffer) free(buffer);
    if (lines) free(lines);
    return 1;
  }
  free(lines);
  return 0;
}
