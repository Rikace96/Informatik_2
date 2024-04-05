#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funktion zum Überprüfen, ob eine Zeichenkette eine gültige Dualzahl ist
int isValidBinary(const char *binary) {
    while (*binary) {
        if (*binary != '0' && *binary != '1') {
            return 0; // Keine gültige Dualzahl
        }
        binary++;
    }
    return 1; // Gültige Dualzahl
}

// Funktion zum Konvertieren einer Dualzahl in eine Dezimalzahl
unsigned long long binaryToDecimal(const char *binary) {
    unsigned long long decimal = 0;
    while (*binary) {
        decimal = decimal * 2 + (*binary - '0');
        binary++;
    }
    return decimal;
}

int main(int argc, char *argv[]) {
    // Überprüfen, ob genügend Argumente übergeben wurden
    if (argc != 4) {
        printf("Richtiger Aufruf: %s <operand> <operator> <operand>\n", argv[0]);
        printf("Erlaubte Operatoren sind: +, -, *, /, &, ^\n");
        return 1;
    }

    // Überprüfen, ob der Operator gültig ist
    char *operators = "+-*/&^";
    if (strchr(operators, argv[2][0]) == NULL) {
        printf("%s ist kein erlaubter Operator\n", argv[2]);
        return 1;
    }

    // Überprüfen, ob die Operanden gültige Dualzahlen sind
    if (!isValidBinary(argv[1]) || !isValidBinary(argv[3])) {
        printf("%s ist keine erlaubte Dualzahl\n", !isValidBinary(argv[1]) ? argv[1] : argv[3]);
        return 1;
    }

    // Konvertieren der Dualzahlen in Dezimalzahlen
    unsigned long long operand1 = binaryToDecimal(argv[1]);
    unsigned long long operand2 = binaryToDecimal(argv[3]);

    // Berechnen des Ergebnisses entsprechend dem Operator
    unsigned long long result;
    switch (argv[2][0]) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                printf("Division durch Null ist nicht erlaubt\n");
                return 1;
            }
            result = operand1 / operand2;
            break;
        case '&':
            result = operand1 & operand2;
            break;
        case '^':
            result = operand1 ^ operand2;
            break;
        default:
            printf("Ungültiger Operator: %c\n", argv[2][0]);
            return 1;
    }

    // Ausgabe des Ergebnisses in Dualform
    printf("%s %c %s = ......%llu (0x%llx)\n", argv[1], argv[2][0], argv[3], result, result);

    return 0;
}
