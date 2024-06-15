#include <stdio.h>
#include <stdlib.h>
#include "muturing.h"
#include "fehler.h"
#include "bildschi.h"

int main() {
    char band[200]; // Groß genug für die Multiplikation der Zahlen und zusätzliche #
    printf("Geben Sie die Zahlen auf dem Band ein (z.B. III#IIII#): ");
    scanf("%199s", band);

    if (!validate_input(band)) {
        print_error("Ungültige Eingabe! Das Band muss mit einer # zwischen den Zahlen enden.");
        return 1;
    }

    Turingmaschine *tm = tm_initialisieren(band);
    if (!tm) {
        print_error("Fehler bei der Initialisierung der Turingmaschine!");
        return 1;
    }

    tm_multiplizieren(tm);
    print_band(tm);

    tm_freigeben(tm);
    return 0;
}
