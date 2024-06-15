#include <stdio.h>
#include <string.h>
#include "fehler.h"

void print_error(const char *message) {
    fprintf(stderr, "Fehler: %s\n", message);
}

int validate_input(const char *input) {
    int length = strlen(input);
    int i = 0, j = 0;

    // Z�hle die Anzahl der 'I' f�r die erste Zahl (Multiplikand)
    while (i < length && input[i] == 'I') {
        i++;
    }

    // �berpr�fe, ob nach den 'I' ein '#' kommt
    if (i == length || input[i] != '#') {
        return 0;
    }

    // Z�hle die Anzahl der 'I' f�r die zweite Zahl (Multiplikator)
    j = i + 1;
    while (j < length && input[j] == 'I') {
        j++;
    }

    // �berpr�fe, ob das Band korrekt endet
    if (j == length - 1 && input[j] == '#') {
        return 1;
    }

    return 0;
}
