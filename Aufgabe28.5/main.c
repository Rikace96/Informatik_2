#include <stdio.h>

// Struktur für die Zeit
struct zeit {
    int tag;
    int std;
    int min;
    int sek;
};

// Funktion, die eine Zeit in Sekunden umwandelt
unsigned long zeit_in_sek(struct zeit z) {
    return z.tag * 86400 + z.std * 3600 + z.min * 60 + z.sek;
}

// Funktion, die Sekunden in eine Zeit umwandelt
struct zeit sek_in_zeit(unsigned long sek) {
    struct zeit z;

    z.tag = sek / 86400;
    sek %= 86400;

    z.std = sek / 3600;
    sek %= 3600;

    z.min = sek / 60;
    z.sek = sek % 60;

    return z;
}

int main() {
    struct zeit zeit1, zeit2, summe;

    // Eingabe der ersten Zeit
    printf("Gib 1. Zeit ein: (tt.hh.mm.ss): ");
    scanf("%d.%d.%d.%d", &zeit1.tag, &zeit1.std, &zeit1.min, &zeit1.sek);

    // Eingabe der zweiten Zeit
    printf("Gib 2. Zeit ein: (tt.hh.mm.ss): ");
    scanf("%d.%d.%d.%d", &zeit2.tag, &zeit2.std, &zeit2.min, &zeit2.sek);

    // Berechnung der Gesamtzeit in Sekunden
    unsigned long gesamtsekunden = zeit_in_sek(zeit1) + zeit_in_sek(zeit2);

    // Umwandlung der Gesamtzeit in die Zeit-Struktur
    summe = sek_in_zeit(gesamtsekunden);

    // Ausgabe der Ergebnisse
    printf("\n...... = %d Tage, %d:%d.%d; %lu Gesamtsekunden\n", summe.tag, summe.std, summe.min, summe.sek, gesamtsekunden);

    return 0;
}
