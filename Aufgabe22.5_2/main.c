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

    // Eingabe der Werte f�r n und k
    printf("Wieviele Positionen: ");
    scanf("%d", &n);
    printf("Wieviele Elemente (muss <= %d sein): ", n);
    scanf("%d", &k);

    // �berpr�fung, ob k g�ltig ist
    if (k > n) {
        printf("Ung�ltige Eingabe! Die Anzahl der Elemente muss kleiner oder gleich der Anzahl der Positionen sein.\n");
        return 1;
    }

    // Berechnung und Ausgabe des Binomialkoeffizienten
    printf("/  %-1d\\\n", n);
    printf("|    | = %d\n", binomial(n, k));
    printf("\\  %-1d/\n", k);

    return 0;
}
