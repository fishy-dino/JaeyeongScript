#ifndef __JAEYEONG_VARIABLE_H__
#define __JAEYEONG_VARIABLE_H__
#include "value.h"
typedef struct {
  char* name;
  Value value;
} Variable;
#endif