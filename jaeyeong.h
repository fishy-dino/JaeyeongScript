#ifndef __JAEYEONG_H__
#define __JAEYEONG_H__
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CODE_START "jaeyeong is cute"
#define CODE_END "jalgeoim"

static const char *loves[] = {
  "yoonseokyeol",
  "emotion",
  "beakjoon"
};

typedef struct {
  int major;
  int minor;
  int patch;
} Version;

typedef struct {
  bool debug;
  Version version;
  char* file;
} ProgramOption;

int starts_with(const char* str, const char* prefix);
int ends_with(const char* str, const char* pattern);
char* version(Version version);
void trim(char** str);
#endif