#ifndef __JAEYEONG_TOKENIZER_H__
#define __JAEYEONG_TOKENIZER_H__
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "value.h"

typedef enum {
  TOKEN,
  KEYWORD,
  VALUE,
  SYMBOL
} TokenTypes;

typedef enum {
  QUESTION,
  SEMI
} Tokens;

static const char *tokens[] = {
  "?",
  ";"
};

typedef enum {
  SPIT,
  SWALLOW,
  SIBAL,
  EMOTION,
  HAMYEON_HAE,
  YEA
} Keywords;

static const char *keywords[] = {
  "spit", // print
  "swallow", // input
  "sibal",
  "emotion",
  "hamyeon hae",
  "yea"
};

typedef struct {
  TokenTypes type;
  union {
    Tokens token;
    Keywords keyword;
    Value value;
    char* symbol;
  } value;
} Token;

typedef struct {
  Token* data;
  size_t size;
  size_t capacity;
} TokenArray;

int initTokArray(TokenArray* array);
int pushToken(TokenArray* array, Token token);
void freeTokenArray(TokenArray* array);
int tokenize(char* line, TokenArray* array);
int parse_spit(char* line, TokenArray* array);
#endif