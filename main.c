// -*- coding: utf-8 -*-
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#ifdef __unix__
  #include <unistd.h>
#endif
#include "jaeyeong.c"
#include "error.c"

#define READ_SIZE 512

void replace(char *str, char find, char replace);
char** split(char *str, const char *delimiter, int *count);
int argv_help(char* argv[], ProgramOption* opt);

int main(int argc, char* argv[]) {
  int tmp;
  ProgramOption option;
  option.version = (Version){0, 1, 0};
  if ((tmp = argv_help(argv, &option)) == 0) return tmp;
  if (option.file == NULL) return error("Error: No input file\n");
  unsigned int size = 0, length = 0;
  char *version = "v0.1.0", *buffer = NULL, *fname = NULL;
	FILE *file = NULL;
  if (argc < 2) return error("Usage: %s <filename>\n", argv[0]);
  file = fopen(argv[1], "r");
  if (file == NULL) return error("Error: Unable to open file %s\n", argv[1]);
  while (!feof(file)) {
		size += READ_SIZE;
		buffer = realloc(buffer, sizeof(char) * size);
		length += fread((buffer + size) - READ_SIZE, 1, READ_SIZE, file);
  }
  if (fclose(file) != 0) {
    if (buffer) free(buffer);
    return error("Error: Unable to close file %s\n", argv[1]);
  }
  if (!buffer) return 1;
	buffer[length] = '\0';
  replace(buffer, ';', '\n');
  int tc, last = 0;
  char **lines = split(buffer, "\n", &tc);
  for (int i = 0; i < tc; i++) if (lines[i] != '\0') last = 1;
  if (lines[0] != CODE_START || lines[last] != CODE_END) {
    if (buffer) free(buffer);
    if (lines) free(lines);
    return error("Error: Invalid file format\n");
  }
  free(lines);
  return 0;
}

int argv_help(char* argv[], ProgramOption* opt) {
  opt->file = NULL;
  int index = 0;
  while (argv[index] != NULL) {
    char* value = argv[index];
    if (strcmp(value, "--version") == 0) {
      char* ver = version(opt->version);
      printf("jaeyeong v%s\n", ver);
      free(ver);
      return 0;
    } else if (strcmp(value, "--help") == 0) {
      printf("Usage: %s [options] <filename>\n", argv[0]);
      printf("Options:\n");
      printf("  --version\t\tPrint version information\n");
      printf("  --help\t\tPrint this help message\n");
      return 0;
    } else if ((opt->file != NULL) && ends_with(argv[index], ".jaeyeong")) {
      opt->file = argv[index];
    }
    index++;
  }
  return 1;
}

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