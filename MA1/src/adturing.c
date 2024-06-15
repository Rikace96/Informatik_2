#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adturing.h"
#include "fehler.h"

Turingmaschine* tm_initialisieren(char *band) {
    Turingmaschine *tm = (Turingmaschine *)malloc(sizeof(Turingmaschine));
    if (!tm) {
        return NULL;
    }
    strcpy(tm->band, band);
    tm->position = strlen(band) - 2; // Startposition: Vor dem #
    tm->zustand = 0; // Anfangszustand
    return tm;
}

void tm_freigeben(Turingmaschine *tm) {
    free(tm);
}

void tm_addition(Turingmaschine *tm) {
    int carry = 1; // Wir starten mit dem Übertrag 1
    while (tm->position >= 0) {
        if (tm->band[tm->position] == '0') {
            tm->band[tm->position] = '1';
            carry = 0;
            break;
        } else if (tm->band[tm->position] == '1') {
            tm->band[tm->position] = '0';
            carry = 1;
        }
        tm->position--;
    }

    if (carry) {
        // Wenn wir hier sind, müssen wir eine 1 am Anfang einfügen
        for (int i = strlen(tm->band); i > 0; i--) {
            tm->band[i] = tm->band[i - 1];
        }
        tm->band[0] = '1';
    }
}
