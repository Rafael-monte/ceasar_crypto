#include "imports.h"
#include <stdio.h>
#ifndef INVALID_ARGS
    #define INVALID_ARGS -17
#endif
#ifndef VALID_ARGS
    #define VALID_ARGS 0
#endif

typedef struct {
    int deslocation;
    char pass[MAX_INPUT_SIZE + 1];
} ARGS_INPUT;

ARGS_INPUT check_args(int argc, char** argv);