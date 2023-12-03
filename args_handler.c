#include "args_handler.h"

ARGS_INPUT check_args(int argc, char** argv) {
    ARGS_INPUT res;
    size_t pass_size = strlen(argv[2]);
    
    if (argc != 3) {
        fprintf(stderr, "Usage: ceasar_crypto <deslocation> <password>\n");
        exit(EXIT_FAILURE);
    }
    
    int deslocation = atoi(argv[1]);
    if (!deslocation || deslocation < 0) {
        fprintf(stderr, "FATAL: Invalid deslocation provided: \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (deslocation > ALPHABET_SIZE) {
        fprintf(stdin, "WARN: deslocation bigger than necessary. Consider give a number in interval [1 - 25]\n");
    }

    res.deslocation = deslocation % ALPHABET_SIZE;

    if (pass_size > MAX_INPUT_SIZE) {
        fprintf(stdout, "WARN: provided password bigger than max input size, catching first %d chars \n", MAX_INPUT_SIZE);
    }

    strncpy(res.pass, argv[2], MAX_INPUT_SIZE);
    return res;
}