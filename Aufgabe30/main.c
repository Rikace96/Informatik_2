#include <stdio.h>
#include <stdlib.h>

// Struktur für eine Adresse
struct Adresse {
    char vorname[50];
    char nachname[50];
    char strasse[50];
    char hausnummer[10];
    char postleitzahl[10];
    char wohnort[50];
    char telefon[20];
    char fax[20];
};

// Funktion zum Einlesen einer Adresse
void readAdresse(struct Adresse *adresse) {
    printf("Vorname: ");
    scanf("%s", adresse->vorname);
    printf("Nachname: ");
    scanf("%s", adresse->nachname);
    printf("Strasse: ");
    scanf("%s", adresse->strasse);
    printf("Hausnummer: ");
    scanf("%s", adresse->hausnummer);
    printf("Postleitzahl: ");
    scanf("%s", adresse->postleitzahl);
    printf("Wohnort: ");
    scanf("%s", adresse->wohnort);
    printf("Telefon: ");
    scanf("%s", adresse->telefon);
    printf("Fax: ");
    scanf("%s", adresse->fax);
}

// Funktion zum Schreiben einer Adresse in eine Datei
void writeAdresseToFile(struct Adresse *adresse, int n) {
    FILE *file = fopen("adresse.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s\n", adresse->vorname, adresse->nachname);
        fprintf(file, "%s %s\n", adresse->strasse, adresse->hausnummer);
        fprintf(file, "%s\n", adresse->postleitzahl);
        fprintf(file, "%s\n", adresse->wohnort);
        fprintf(file, "Tel. %s\n", adresse->telefon);
        fprintf(file, "Fax %s\n", adresse->fax);
        fprintf(file, "---------------------------------------\n");
    }

    fclose(file);
}

int main() {
    int n;
    struct Adresse adresse;

    printf("Dieses Programm liest eine Adresse ein und schreibt diese Adresse n-mal in die Datei 'adresse.txt'\n");
    readAdresse(&adresse);
    printf("Wie oft soll Adresse in Datei geschrieben werden: ");
    scanf("%d", &n);

    writeAdresseToFile(&adresse, n);

    printf("Adresse wurde erfolgreich %d-mal in die Datei 'adresse.txt' geschrieben.\n", n);

    return 0;
}
