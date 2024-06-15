#include <stdio.h>
#include "fehler.h"

void print_error(const char *message) {
    fprintf(stderr, "Fehler: %s\n", message);
}

int validate_input(const char *input) {
    int length = strlen(input);
    return length > 0 && input[length - 1] == '#';
}
