#ifndef __JAEYEONG_H__
#define __JAEYEONG_H__
#include <stdbool.h>
#define CODE_START "jaeyeong is cute"
#define CODE_END "jalgeoim"
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
#endif