#ifndef __JAEYEONG_TOKENIZER_H__
#define __JAEYEONG_TOKENIZER_H__

typedef enum {
  SPIT,
  SWALLOW,
  SIBAL,
  EMOTION,
  HAMYEON_HAE,
  YEA
} Token;

static const char *keywords[] = {
  "spit", // print
  "swallow", // input
  "sibal",
  "emotion",
  "hamyeon hae",
  "yea"
};
#endif