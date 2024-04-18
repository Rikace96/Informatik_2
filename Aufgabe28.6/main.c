#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Binärbaum definieren
struct BinaerBaum {
    char wort[50];
    int zaehler;
    struct BinaerBaum *left;
    struct BinaerBaum *right;
};

typedef struct BinaerBaum BinaerBaum;

BinaerBaum *knoten = NULL;

//Erstellung von Knoten
BinaerBaum* knotenErstellen(char* wort) {

    //Memory Allocation
    BinaerBaum* neuKnoten = (BinaerBaum*)malloc(sizeof(BinaerBaum));
    if (neuKnoten == NULL) {
        printf("Fehler: Speicher konnte nicht allokiert werden.\n");
        exit(1);
    }
    strcpy(neuKnoten->wort, wort);
    neuKnoten->zaehler = 1;
    neuKnoten->left = NULL;
    neuKnoten->right = NULL;
    return neuKnoten;
}

//löschen von Zeichnen von Wörter -> Die Umlaute werden auch gelöscht
void zeichenLoeschen(char* wort) {
    int i, j = 0;
    for (i = 0; wort[i] != '\0'; ++i) {
        if(isalpha(wort[i]) || wort[i] == 'ä' || wort[i] == 'ö' || wort[i] == 'ü' || wort[i] == 'Ä' || wort[i] == 'Ö' || wort[i] == 'Ü') {
            wort[j++] = tolower(wort[i]);
        }
    }
    wort[j] = '\0';
}

// Wort in dem Baum einfuegen
void wortEinfuegen(char* wort) {
    zeichenLoeschen(wort);

    BinaerBaum* current = knoten;
    BinaerBaum* parent = NULL;

    while (current != NULL) {
        if (strcmp(wort, current->wort) == 0) {
            current->zaehler++;
            return;
        } else if (strcmp(wort, current->wort) < 0) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    BinaerBaum* neuKnoten = knotenErstellen(wort);
    if (parent == NULL) {
        knoten = neuKnoten;
    } else if (strcmp(wort, parent->wort) < 0) {
        parent->left = neuKnoten;
    } else {
        parent->right = neuKnoten;
    }
}

//Wort und das Vorkommen von Wert ausgeben
void wortAusgeben(BinaerBaum* knoten) {
    if (knoten != NULL) {
        wortAusgeben(knoten->left);
        printf("%-15s : %d\n", knoten->wort, knoten->zaehler);
        wortAusgeben(knoten->right);
    }
}

//MEmory befreien
void baumBefreien(BinaerBaum* knoten) {
    if (knoten != NULL) {
        baumBefreien(knoten->left);
        baumBefreien(knoten->right);
        free(knoten);
    }
}

int main() {
    char wort[50];

    while (scanf("%s", wort) != EOF) {
        zeichenLoeschen(wort);
        wortEinfuegen(wort);
    }

    wortAusgeben(knoten);

    baumBefreien(knoten);

    return 0;
}
