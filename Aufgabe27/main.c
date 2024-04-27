#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Funktion zur Berechnung der Primzahlen bis zur angegebenen Grenze
void sieveOfEratosthenes(int n) {
    // Dynamischer Speicher für die Primzahlen
    int *primes = (int *)malloc(100 * sizeof(int));
    if (primes == NULL) {
        printf("Speicher konnte nicht allokiert werden.\n");
        exit(1);
    }

    // Index für die nächste verfügbare Position im primes-Array
    int count = 0;

    // Array zum Markieren der zusammengesetzten Zahlen
    bool *composite = (bool *)malloc((n + 1) * sizeof(bool));
    if (composite == NULL) {
        printf("Speicher konnte nicht allokiert werden.\n");
        exit(1);
    }

    // Initialisierung des composite-Arrays
    for (int i = 2; i <= n; i++) {
        composite[i] = false;
    }

    // Sieb des Eratosthenes Algorithmus
    for (int p = 2; p * p <= n; p++) {
        if (composite[p] == false) {
            // Wenn p eine Primzahl ist, markiere alle Vielfachen von p als zusammengesetzt
            for (int i = p * p; i <= n; i += p) {
                composite[i] = true;
            }
        }
    }

    // Hinzufügen der Primzahlen zum primes-Array
    for (int p = 2; p <= n; p++) {
        if (composite[p] == false) {
            primes[count++] = p;
            // Speicherplatz überprüfen und ggf. erweitern
            if (count % 100 == 0) {
                primes = (int *)realloc(primes, (count + 100) * sizeof(int));
                if (primes == NULL) {
                    printf("Speicher konnte nicht erweitert werden.\n");
                    exit(1);
                }
            }
        }
    }

    // Ausgabe der Primzahlen
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("%8d ", primes[i]);
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
    printf("\n\n");

    // Speicher freigeben
    free(primes);
    free(composite);
}

int main() {
    int n;

    do {
        printf("Bis wohin sollen die Primzahlen berechnet werden (Ende=0) ? ");
        scanf("%d", &n);
        if (n <= 0)
            break;
        sieveOfEratosthenes(n);
    } while (n != 0);

    return 0;
}
