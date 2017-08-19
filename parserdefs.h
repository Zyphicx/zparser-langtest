#ifndef PARSERDEFS_H
#define PARSERDEFS_H

#include "zparser/zparser.h"

#define EQUALS 9
#define L_PAREN 10
#define R_PAREN 11
#define PLUS 12
#define MINUS 13
#define STAR 14
#define SLASH 15
#define CARET 16

TokenName tokenNames[] = 
{
    "CARET", CARET,
    "EQUALS", EQUALS,
    "IDENTIFIER", IDENTIFIER,
    "L_PAREN", L_PAREN,
    "MINUS", MINUS,
    "NUMBER", NUMBER,
    "PLUS", PLUS,
    "R_PAREN", R_PAREN,
    "SLASH", SLASH,
    "STAR", STAR,
    "STRING_LITERAL", STRING_LITERAL,
    "SYMBOL", SYMBOL,
};
const int tokenNameAmount = sizeof(tokenNames) / sizeof(tokenNames[0]);


TokenName keywords[] = 
{
    "", 0
};
const int keywordAmount = sizeof(keywords) / sizeof(keywords[0]);

#endif
