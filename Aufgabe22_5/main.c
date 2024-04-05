#include <stdio.h>

//Berechnung der Quersumme einer Zahl
int quersumme(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + quersumme(n / 10);
    }
}
//Umkehren einer Zahl
int umdrehen(int n) {
    static int reversedNum = 0;

    if (n == 0) {
        return reversedNum;
    } else {
        reversedNum = reversedNum * 10 + (n % 10);
        return umdrehen(n / 10);
    }
}

int main() {
    int zahl;

    printf("Gib eine Zahl ein: ");
    if (scanf("%d", &zahl) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine ganze Zahl ein.\n");
        while (getchar() != '\n');  //Puffer leeren
    }

    printf("----Quersumme: %d\n", quersumme(zahl));

    printf("----umgedreht: %d\n", umdrehen(zahl));

    return 0;
}
