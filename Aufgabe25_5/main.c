#include <stdio.h>

int main() {
    int tag, monat, jahr;
    int jh, ja, schaltjahr;
    int wochentag;
    int jh_koeff[4] = { 4, 2, 0, 5 };
    int monat_koeff[12] = { 2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0 };

    //Eingabe des Datums
    printf("Gib Datum ein (tt.mm.jjjj): ");
    scanf("%d.%d.%d", &tag, &monat, &jahr);

    //Berechnung des Jahrhunderts und des Jahres im Jahrhundert
    jh = jahr / 100;
    ja = jahr % 100;

    //Überprüfung, ob es sich um ein Schaltjahr handelt
    if (monat > 2) {
        schaltjahr = 0;
    } else {
        if (jahr % 400 == 0) {
            schaltjahr = 1;
        } else {
            if (jahr % 100 == 0) {
                schaltjahr = 0;
            } else {
                if (jahr % 4 == 0) {
                    schaltjahr = 1;
                } else {
                    schaltjahr = 0;
                }
            }
        }
    }

    // Berechnung des Wochentags
    wochentag = (tag + monat_koeff[monat - 1] - schaltjahr + jh_koeff[jh % 4] + ja + ja / 4) % 7;

    // Ausgabe des Wochentags
    switch (wochentag) {
        case 0:
            printf("Das Datum %d.%d.%d ist ein Sonntag\n", tag, monat, jahr);
            break;
        case 1:
            printf("Das Datum %d.%d.%d ist ein Montag\n", tag, monat, jahr);
            break;
        case 2:
            printf("Das Datum %d.%d.%d ist ein Dienstag\n", tag, monat, jahr);
            break;
        case 3:
            printf("Das Datum %d.%d.%d ist ein Mittwoch\n", tag, monat, jahr);
            break;
        case 4:
            printf("Das Datum %d.%d.%d ist ein Donnerstag\n", tag, monat, jahr);
            break;
        case 5:
            printf("Das Datum %d.%d.%d ist ein Freitag\n", tag, monat, jahr);
            break;
        case 6:
            printf("Das Datum %d.%d.%d ist ein Samstag\n", tag, monat, jahr);
            break;
        default:
            printf("Ungültiger Wochentag\n");
            break;
    }

    return 0;
}
