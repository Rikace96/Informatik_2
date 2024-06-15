#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM 99

// Vergleichsfunktion für qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Funktion zum Finden des Modus
int find_mode(int arr[], int n, int *frequency) {
    int mode = arr[0];
    int max_count = 1, current_count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                mode = arr[i - 1];
            }
            current_count = 1;
        }
    }

    // Letzte Überprüfung, falls der häufigste Wert am Ende des Arrays steht
    if (current_count > max_count) {
        max_count = current_count;
        mode = arr[n - 1];
    }

    *frequency = max_count;
    return mode;
}

int main() {
    int n;
    printf("Wieviele Zufallswerte (1..10000): ");
    scanf("%d", &n);

    if (n < 1 || n > 10000) {
        printf("Ungültige Eingabe! Bitte eine Zahl zwischen 1 und 10000 eingeben.\n");
        return 1;
    }

    int arr[n];
    srand(time(NULL));

    // Zufallszahlen generieren und Array füllen
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_RANDOM + 1);
    }

    printf("\n");
    // Ausgabe der erzeugten Zufallszahlen
    printf("Erzeugte Zufallszahlen ------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
        if ((i + 1) % 15 == 0) printf("\n");
    }
    printf("\n\n");

    // Array sortieren
    qsort(arr, n, sizeof(int), compare);

    // Ausgabe der sortierten Zufallszahlen
    printf("Sortierte Zufallszahlen -----------------\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
        if ((i + 1) % 15 == 0) printf("\n");
    }
    printf("\n\n");

    // Modus finden
    int frequency;
    int mode = find_mode(arr, n, &frequency);

    // Ausgabe des Modus
    printf("....Modus: %d (Haeufigkeit: %d).....\n", mode, frequency);

    return 0;
}
