#include "tokenizer.h"
#include "error.h"
#include "jaeyeong.h"

#define TOKLIST_SIZE 20

char* push(char* str, char c) {
  size_t len = strlen(str);
  char* newStr = (char*)malloc((len + 2) * sizeof(char));  
  strcpy(newStr, str);
  newStr[len] = c;
  newStr[len + 1] = '\0';
  return newStr;
}

int initTokArray(TokenArray* array) {
  array->data = NULL;
  array->size = 0;
  array->capacity = 0;
  return 0;
}

int pushToken(TokenArray* array, Token token) {
  if (array->size >= array->capacity) {
    size_t newCapacity = (array->capacity == 0) ? 1 : array->capacity * 2;
    Token* newData = (Token*)realloc(array->data, newCapacity * sizeof(Token));
    if (newData == NULL) return error("Memory allocation failed\n");
    array->data = newData;
    array->capacity = newCapacity;
  }
  array->data[array->size++] = token;
  return 0;
}

void freeTokenArray(TokenArray* array) {
  free(array->data);
  array->data = NULL;
  array->size = 0;
  array->capacity = 0;
}

int is_varname(char* ident) {
  int i = -1;
  while(ident[++i] != '\0') 
    if (isalnum((unsigned char)ident[i]) || ident[i] == '_') return false;
  return true;
}

int parse_token(int* index, char* line, TokenArray* array) {
  size_t llen = strlen(line);
  char* indentifier = (char*)malloc(sizeof(char) * (llen+1));
  Tokens tok = NULL;
  if (indentifier == NULL) return error("Memory allocation failed\n");
  int n = -1;
  while ((size_t)index < llen) {
    if (!isalnum((unsigned char)line[*index]) && !isspace((unsigned char)line[*index])) {
      indentifier[*index] = line[*index];
      while (tokens[++n] != NULL)
        if (tok != NULL&&(strcmp(tokens[n], indentifier) == 0)) tok = (Tokens)n;
      if (++index > 2) break;
    } else { break; }
  }
  free(indentifier);
  if (tok != NULL) return error("Unknown token: %s\n", indentifier);
  Token token = {.type = TOKEN, .value = {.token = tok}};
  pushToken(&(*array), token);
  return 0;
}

int parse_keyword(char* kw, TokenArray* array) {
  Keywords keyword = NULL;
  int n = -1;
  while (keywords[++n] != NULL)
    if (strcmp(keywords[n], kw) == 0) keyword = (Keywords)n;
  if (keyword == NULL) return error("Unknown keyword: %s\n", kw);
  Token token = {.type = KEYWORD, .value = {.keyword = keyword}};
  pushToken(&(*array), token);
  return 0;
}

int tokenize(char** line, TokenArray* array) {
  
}

int parse_spit(char** line, TokenArray** array) {

}

int tokenizer(TokenArray* array) {
  initTokArray(&(*array));
  bool is_symbol = false;
  char* symbol = (char*)malloc(10 * sizeof(char));
  return 0;
}