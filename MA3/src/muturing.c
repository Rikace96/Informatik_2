#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "muturing.h"
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

void tm_multiplizieren(Turingmaschine *tm) {
    // Finden der ersten Zahl (Multiplikand)
    int i = 0;
    while (tm->band[i] == 'I') {
        i++;
    }
    int len1 = i;

    // Ersetze die ersten 'I' vor der ersten '#' durch 'A'
    for (int k = 0; k < len1; k++) {
        tm->band[k] = 'A';
    }

    // Füge das Trennzeichen '#' nach der ersten Zahl ein
    tm->band[len1] = '#';

    // Berechne die Länge der zweiten Zahl (Multiplikator)
    int j = len1 + 1;
    int len2 = 0;
    while (tm->band[j] == 'I') {
        len2++;
        j++;
    }

    // Berechne das Produkt der zweiten Zahl (Multiplikator)
    int multiplikator = len2;

    // Füge den Multiplikator (als 'I') nach der ersten Zahl ein
    for (int k = 0; k < multiplikator; k++) {
        tm->band[len1 + 1 + k] = 'I';
    }

    // Füge das Trennzeichen '#' nach dem Multiplikator ein
    tm->band[len1 + 1 + multiplikator] = '#';

    // Füge das Produkt (als 'I') am Ende des Bands ein
    int k = len1 + 1 + multiplikator + 1;
    int produkt = len1 * multiplikator;
    while (produkt > 0) {
        tm->band[k++] = 'I';
        produkt--;
    }

    // Füge ein zusätzliches '#' am Ende des Bands ein
    tm->band[k++] = '#';
    tm->band[k] = '\0';
}
