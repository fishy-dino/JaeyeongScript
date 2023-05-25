#include <stdio.h>
#include <stdlib.h>

#define READ_SIZE 512

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
  printf("%s\n", buffer);
  return 0;
}
