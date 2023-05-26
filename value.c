#include "value.h"

int is_int(Value value) { return value.kind == INTEGER; }
int is_float(Value value) { return value.kind == FLOAT; }
int is_string(Value value) { return value.kind == STRING; }
int is_char(Value value) { return value.kind == CHARACTER; }
int is_bool(Value value) { return value.kind == BOOLEAN; }