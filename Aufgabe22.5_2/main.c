#include <stdio.h>

// Rekursive Funktion zur Berechnung des Binomialkoeffizienten
int binomial(int n, int k) {
    // Basisfall: k = 0 oder k = n
    if (k == 0 || k == n) {
        return 1;
    } else {
        // Anwendung der Rekursionsformel
        return binomial(n - 1, k) + binomial(n - 1, k - 1);
    }
}

int main() {
    int n, k;

    // Eingabe der Werte für n und k
    printf("Wieviele Positionen: ");
    scanf("%d", &n);
    printf("Wieviele Elemente (muss <= %d sein): ", n);
    scanf("%d", &k);

    // Überprüfung, ob k gültig ist
    if (k > n) {
        printf("Ungültige Eingabe! Die Anzahl der Elemente muss kleiner oder gleich der Anzahl der Positionen sein.\n");
        return 1;
    }

    // Berechnung und Ausgabe des Binomialkoeffizienten
    printf("/  %-1d\\\n", n);
    printf("|    | = %d\n", binomial(n, k));
    printf("\\  %-1d/\n", k);

    return 0;
}
