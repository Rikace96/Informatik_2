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

    // Finden der zweiten Zahl (Multiplikator)
    int j = len1 + 1;
    while (tm->band[j] == 'I') {
        j++;
    }
    int len2 = j - (len1 + 1);

    // Konvertiere die Zahlen von römisch in dezimal
    int multiplikand = len1;
    int multiplikator = len2;

    // Berechne das Produkt
    int produkt = multiplikand * multiplikator;

    // Fülle das Band mit dem Ergebnis
    int k = 0;
    while (k < produkt) {
        tm->band[len1 + 1 + len2 + k] = 'I';
        k++;
    }
    tm->band[len1 + 1 + len2 + k] = '#';
    tm->band[len1 + 1 + len2 + k + 1] = '\0';
}
