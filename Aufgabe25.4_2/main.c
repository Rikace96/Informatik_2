#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funktion zum �berpr�fen, ob ein String ein Palindrom ist
int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0; // Nicht ein Palindrom
        }
    }
    return 1; // Palindrom gefunden
}

// Funktion zum Extrahieren von W�rtern aus einer Zeile und �berpr�fen, ob sie Palindrome sind
void findPalindromes(char *line) {
    const char *delimiters = " \t\n"; // Trennzeichen f�r W�rter
    char *word = strtok(line, delimiters); // Erstes Wort extrahieren

    while (word != NULL) {
        if (isPalindrome(word)) {
            printf(".......%s\n", word);
        }
        word = strtok(NULL, delimiters); // N�chstes Wort extrahieren
    }
}

int main() {
    char line[1000];

    printf("Geben Sie den Text ein:\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        findPalindromes(line); // Palindrome in der Zeile finden und ausgeben
    }
    printf("\n");
    return 0;
}
