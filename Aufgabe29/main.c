#include <stdio.h>

// Definition von Enums für Säuren und Basen
typedef enum {
    SALZSAEURE,
    SCHWEFELSAEURE,
    SALPETERSAEURE,
    KOHLENSAEURE,
    ANZAHL_SAEUREN
} Saeuren;

typedef enum {
    NATRONLAUGE,
    KALILAUGE,
    KALKWASSER,
    ANZAHL_BASEN
} Basen;

// Funktion zur Rückgabe der Namen der Säuren
const char* saeurenName(Saeuren saeure) {
    switch (saeure) {
        case SALZSAEURE: return "Salzsäure";
        case SCHWEFELSAEURE: return "Schwefelsäure";
        case SALPETERSAEURE: return "Salpetersäure";
        case KOHLENSAEURE: return "Kohlensäure";
        default: return "Unbekannte Säure";
    }
}

// Funktion zur Rückgabe der Namen der Basen
const char* basenName(Basen base) {
    switch (base) {
        case NATRONLAUGE: return "Natronlauge";
        case KALILAUGE: return "Kalilauge";
        case KALKWASSER: return "Kalkwasser";
        default: return "Unbekannte Base";
    }
}

int main() {
    // Definition der Mischtabelle
    const char* mischtabelle[ANZAHL_BASEN][ANZAHL_SAEUREN] = {
        {"Natriumchlorid", "Natriumsulfat", "Natriumnitrat", "Natriumcarbonat"},
        {"Kaliumchlorid", "Kaliumsulfat", "Kaliumnitrat", "Kaliumcarbonat"},
        {"Calciumchlorid", "Calciumsulfat", "Calciumnitrat", "Calciumcarbonat"}
    };

    // Ausgabe der Tabelle
    printf("           ||");
    for (int s = 0; s < ANZAHL_SAEUREN; s++) {
        printf(" %15s |", saeurenName(s));
    }
    printf("\n");

    printf("-----------||");
    for (int s = 0; s < ANZAHL_SAEUREN; s++) {
        printf("-----------------|");
    }
    printf("\n");

    for (int b = 0; b < ANZAHL_BASEN; b++) {
        printf("%11s||", basenName(b));
        for (int s = 0; s < ANZAHL_SAEUREN; s++) {
            printf(" %15s |", mischtabelle[b][s]);
        }
        printf("\n");
    }

    return 0;
}
