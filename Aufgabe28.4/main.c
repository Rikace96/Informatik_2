#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 10

struct Schueler {
    char name[MAX_NAME_LENGTH];
    char vorname[MAX_NAME_LENGTH];
    int note;
};

// Funktion zum Einlesen der Schülerdaten
int schuelerEingabe(struct Schueler* schueler) {
    int anzahlSchueler = 0;
    bool run = true;

    // Eingabe der Schülerdaten
    while (run){

        printf("----Eingabe des %d. Schuelers----\n", anzahlSchueler + 1);

        // Input for Name
        printf("Name: ");
        fgets(schueler[anzahlSchueler].name, sizeof(schueler[anzahlSchueler].name), stdin);

        // Remove newline character from the name
        schueler[anzahlSchueler].name[strcspn(schueler[anzahlSchueler].name, "\n")] = '\0';

        // Check if only Enter was given for Name input
        if (schueler[anzahlSchueler].name[0] == '\0') {
            break;
        }

        printf("Vorname: ");
        scanf("%s", schueler[anzahlSchueler].vorname);

        printf("Note: ");
        scanf("%d", &schueler[anzahlSchueler].note);

        // Clear the input buffer to consume the newline character
        getchar();

        anzahlSchueler++;
        printf("\n");
    }

    return anzahlSchueler;
}

// Funktion zum Ausgeben der Namensliste
void SchuelerInfoAusgabe(struct Schueler* schuelerListe, int anzahlSchueler) {
    printf("\n   Name            , Vorname            , Note\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < anzahlSchueler; i++) {
        printf("%d. %-12s    , %-18s , %d\n", i + 1, schuelerListe[i].name, schuelerListe[i].vorname, schuelerListe[i].note);
    }
}

// Funktion zum Berechnen und Ausgeben der Durchschnittsnote
void durchschnittsnoteAusgabe(struct Schueler* schuelerListe, int anzahlSchueler) {
    float durchschnittsnote = 0.0;

    for (int i = 0; i < anzahlSchueler; i++) {
        durchschnittsnote += schuelerListe[i].note;
    }

    durchschnittsnote /= anzahlSchueler;
    printf("\n....Durchschnittsnote: %.2f\n", durchschnittsnote);

}

// Funktion zum Ausgeben des Notenspiegels
void notenspiegelAusgabe(struct Schueler* schuelerListe, int anzahlSchueler) {
    printf("....Notenspiegel\n");

    for (int note = 1; note <= 6; note++) {
        printf("Note %d: ", note);

        for (int i = 0; i < anzahlSchueler; i++) {
            if (schuelerListe[i].note == note) {
                printf("*");
            }
        }

        printf("\n");
    }
}

int main() {

    // Dynamische Speicherzuweisung für das Array
    struct Schueler *schueler = (struct Schueler *)malloc(MAX_STUDENTS * sizeof(struct Schueler));

    int anzahlSchueler = schuelerEingabe(schueler);

    if(anzahlSchueler != 0){

        // Ausgabe der Namensliste
        SchuelerInfoAusgabe(schueler, anzahlSchueler);

        // Berechnung und Ausgabe der Durchschnittsnote
        durchschnittsnoteAusgabe(schueler, anzahlSchueler);

        // Ausgabe des Notenspiegels
        notenspiegelAusgabe(schueler, anzahlSchueler);
    }

    free(schueler);

    return 0;
}
