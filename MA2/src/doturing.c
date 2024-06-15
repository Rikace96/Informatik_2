#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doturing.h"
#include "fehler.h"

Turingmaschine* tm_initialisieren(char *band) {
    Turingmaschine *tm = (Turingmaschine *)malloc(sizeof(Turingmaschine));
    if (!tm) {
        return NULL;
    }
    strcpy(tm->band, band);
    tm->position = 0; // Startposition: Anfang des Bandes
    tm->zustand = 0; // Anfangszustand
    return tm;
}

void tm_freigeben(Turingmaschine *tm) {
    free(tm);
}

void tm_verdoppeln(Turingmaschine *tm) {
    int original_length = 0;

    // Zähle die Anzahl der 'I' auf dem Band
    while (tm->band[original_length] == 'I') {
        original_length++;
    }

    // Berechne die Länge des neuen Bandes
    int new_length = 2 * original_length;
    char new_band[200]; // temporäres Band für die neuen Striche
    int i;

    // Schritt 1: Fülle die linke Hälfte des neuen Bandes mit #
    for (i = 0; i < original_length + 1; i++) {
        new_band[i] = '#';
    }

    // Schritt 2: Füge die verdoppelten 'I' an das Ende des neuen Bandes
    for (i = 0; i < new_length; i++) {
        new_band[original_length + 1 + i] = 'I';
    }

    // Schritt 3: Setze das abschließende #
    new_band[original_length + 1 + new_length] = '#';
    new_band[original_length + 1 + new_length + 1] = '\0';

    // Kopiere das neue Band in das ursprüngliche Band
    strcpy(tm->band, new_band);
}
