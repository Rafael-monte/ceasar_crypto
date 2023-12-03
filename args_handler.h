#include "imports.h"

typedef struct {
    int deslocation;
    char pass[MAX_INPUT_SIZE + 1];
} ARGS_INPUT;

ARGS_INPUT check_args(int argc, char** argv);