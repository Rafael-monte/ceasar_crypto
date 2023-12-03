#include "imports.h"
#include "args_handler.h"


int main(int argc, char** argv) {
    ARGS_INPUT args_obj;
    args_obj = check_args(argc, argv);
    printf("Deslocation: %d, pass: %s\n", args_obj.deslocation, args_obj.pass);
    puts("Hello world!");
    return EXIT_SUCCESS;
}