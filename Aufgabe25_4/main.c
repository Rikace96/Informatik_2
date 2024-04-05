#include <stdio.h>
#include <string.h>

int main() {
    char eingabe[1001];
    char zu_loeschendes_zeichen;

    //Eingabe der Zeichenkette
    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    fgets(eingabe, sizeof(eingabe), stdin);

    //Entfernen des Zeilenumbruchs
    if (strlen(eingabe) > 0 && eingabe[strlen(eingabe) - 1] == '\n') {
        eingabe[strlen(eingabe) - 1] = '\0';
    }

    //Eingabe des zu löschenden Zeichens
    printf("\nGeben Sie das zu loeschende Zeichen ein: ");
    scanf("%c", &zu_loeschendes_zeichen);

    printf("\n......Die neue Zeichenkette ist dann:\n");
    //Löschen des Zeichens
    for (int i = 0; eingabe[i] != '\0'; ++i) {
        if (eingabe[i] != zu_loeschendes_zeichen) {
            printf("%c", eingabe[i]);
        }
    }

    printf("\n");

    return 0;
}
