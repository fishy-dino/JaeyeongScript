#ifndef __JAEYEONG_VALUE_H__
#define __JAEYEONG_VALUE_H__
#include <stdbool.h>

typedef enum {
  INTEGER,
  STRING,
  CHARACTER,
  FLOAT,
  BOOLEAN
} ValueType;

typedef struct {
  ValueType kind;
  union {
    int int_value;
    bool bool_value;
    char* string_value;
    char char_value;
  } value;
} Value;
#endif