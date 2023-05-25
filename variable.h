#ifndef __JAEYEONG_VARIABLE_H__
#define __JAEYEONG_VARIABLE_H__
#include "value.h"
typedef struct {
  char* name;
  ValueType type;
  union {
    int int_value;
    bool bool_value;
    char* string_value;
    char char_value;
  } value;
} Variable;
#endif