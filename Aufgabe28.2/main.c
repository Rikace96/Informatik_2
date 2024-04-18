#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct für Dezimal Zahl
struct DezimalNummer {
    int vorKommaZahl;
    float nachKommaZahl;
};

//Dezimal Zahl einlesen
struct DezimalNummer zahlEinlesen() {
    struct DezimalNummer zahl;
    char buffer[10];
    scanf("%s", buffer);

    //Komma mit Punkt ersetzen
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ',') {
            buffer[i] = '.';
            break;
        }
    }

    char *endptr;
    float dezimal = strtod(buffer, &endptr);

    // Get nur Zahl vor Komma
    zahl.vorKommaZahl = (int)dezimal;

    // Get nur Zahl nach Komma
    zahl.nachKommaZahl = (float)((dezimal - zahl.vorKommaZahl));

    return zahl;
}

// Zahl addieren
struct DezimalNummer zahlAddieren(struct DezimalNummer num1, struct DezimalNummer num2) {
    struct DezimalNummer summe;

    // Zahl vor Komma addieren
    summe.vorKommaZahl = num1.vorKommaZahl + num2.vorKommaZahl;

    // Zahl nach Komma addieren
    summe.nachKommaZahl = num1.nachKommaZahl + num2.nachKommaZahl;

    return summe;
}

void floatZuString(float number, char *str) {
    sprintf(str, "%f", number);
}

int removeDezimal(char *str) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';

    char *endptr;
    int zahl = strtod(str, &endptr);
    return zahl;
}


int main() {
    struct DezimalNummer input, summe = {0, 0.0};
    bool run = true;
    char str[20];
    float totalSumme;
    int dezZahlOhnePunkt;

    // Zahl einlesen
    printf("Gib Deine Kommazahlen ein (Abschluss mit Leerzeile)\n");
    while (run) {
        input = zahlEinlesen();
        if (input.vorKommaZahl == 0 && input.nachKommaZahl == 0)
            break;
        summe = zahlAddieren(summe, input);
    }

    totalSumme = summe.vorKommaZahl + summe.nachKommaZahl;

    // Convert float to string
    floatZuString(summe.nachKommaZahl, str);

    //Löschen von punkt von dem Zahl
    dezZahlOhnePunkt = removeDezimal(str);

    // Ausgabe
    printf("= %f,(%d,%d).....Kontrollwert: %f\n", totalSumme, summe.vorKommaZahl, dezZahlOhnePunkt, totalSumme);

    return 0;
}
