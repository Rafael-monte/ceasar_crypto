#include "imports.h"
#include "args_handler.h"

void apply_deslocation(ARGS_INPUT *input, char* dest);
char get_correspondent_letter(int letter_index, int deslocation, const char* ALPHABET, const int is_upper);


int main(int argc, char** argv) {
    ARGS_INPUT args_obj;
    args_obj = check_args(argc, argv);
    char newPass[MAX_INPUT_SIZE];
    apply_deslocation(&args_obj, newPass);
    puts(newPass);
    return EXIT_SUCCESS;
}

void apply_deslocation(ARGS_INPUT *input, char* dest)
{
    const char* ALPHABET="abcdefghijklmnopqrstuvwxyz";
    size_t word_size = strlen(input->pass);
    char newPass[word_size];
    for (int i = 0; i < word_size; ++i)
    {
        char current_char = input->pass[i];
        int letter_index = 0;
        int is_upper = 0;
        for (int j = 0; i < ALPHABET_SIZE; ++j)
        {
            is_upper = isupper(current_char);
            if (is_upper) {
                current_char = tolower(current_char);
            }
            if (current_char == ALPHABET[j])
            {
                letter_index = j;
                break;
            }
        }

        char correspondent = get_correspondent_letter(letter_index, input->deslocation, ALPHABET, is_upper);
        if (correspondent == CORRESPONDENT_NOT_FOUND)
        {
            fprintf(stderr, "FATAL: Cannot find correspondent for letter %c with deslocation %d\n", current_char, input->deslocation);
            exit(EXIT_FAILURE);
        }
        newPass[i]=correspondent;

    }
    strncpy(dest, newPass, word_size);
}

char get_correspondent_letter(int letter_index, int deslocation, const char* ALPHABET, const int is_upper) 
{
    int new_index = (letter_index + deslocation) % ALPHABET_SIZE;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (i == new_index)
        {

            return is_upper? toupper(ALPHABET[i]): ALPHABET[i];
        }
    }
    return CORRESPONDENT_NOT_FOUND;
}