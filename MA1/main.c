#include <stdio.h>
#include <stdlib.h>
#include "adturing.h"
#include "fehler.h"
#include "bildschi.h"

int main() {
    char band[100];
    printf("Geben Sie eine binäre Zahl ein (z.B. 1100#): ");
    scanf("%99s", band);

    if (!validate_input(band)) {
        print_error("Ungültige Eingabe! Das Band muss mit einer # enden.");
        return 1;
    }

    Turingmaschine *tm = tm_initialisieren(band);
    if (!tm) {
        print_error("Fehler bei der Initialisierung der Turingmaschine!");
        return 1;
    }

    tm_addition(tm);
    print_band(tm);

    tm_freigeben(tm);
    return 0;
}
