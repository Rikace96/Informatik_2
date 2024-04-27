#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Funktion zur Überprüfung, ob eine Zeichenkette eine gültige duale Zahl ist
bool isValidBinary(const char *binary) {
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return false;
        }
    }
    return true;
}

// Funktion zur Umwandlung einer Zeichenkette in eine duale Zahl
unsigned int binaryToDecimal(const char *binary) {
    unsigned int decimal = 0;
    int power = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

// Funktion zur Umwandlung einer dezimalen Zahl in eine duale Zahl
char *decimalToBinary(unsigned int decimal) {
    char *binary = (char *)malloc(33 * sizeof(char));
    if (binary == NULL) {
        fprintf(stderr, "Speicherzuweisung fehlgeschlagen\n");
    }

    for (int i = 0; i < 32; i++) {
        binary[i] = '0';
    }
    binary[32] = '\0';

    int index = 31;
    while (decimal > 0) {
        binary[index--] = (decimal % 2) + '0';
        decimal /= 2;
    }

    return binary;
}

// Funktion zur Berechnung des Ergebnisses eines dualen Ausdrucks
unsigned int evaluateBinaryExpression(unsigned int operand1, char op, unsigned int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                fprintf(stderr, "Division durch Null nicht erlaubt\n");
                exit(EXIT_FAILURE);
            }
        case '&':
            return operand1 & operand2;
        case '^':
            return operand1 ^ operand2;
        default:
            fprintf(stderr, "Ungültiger Operator\n");
            return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Richtiger Aufruf: %s <operand> <operator> <operand>\n", argv[0]);
        fprintf(stderr, "\tErlaubte Operatoren sind: +, -, *, /, &, ^\n");
    }

    char *operand1_str = argv[1];
    char *op_str = argv[2];
    char *operand2_str = argv[3];

    // Überprüfen, ob Operanden gültige duale Zahlen sind
    bool operand1Valid = isValidBinary(operand1_str);
    bool operand2Valid = isValidBinary(operand2_str);
    if (!operand1Valid) {
        printf("......%s ist keine erlaubte Dualzahl\n", operand1_str);
    }
    if (!operand2Valid) {
        printf("......%s ist keine erlaubte Dualzahl\n", operand2_str);
    }

    // Überprüfen, ob der Operator gültig ist

    bool operatorValidator = ((strchr("+-*/&^", op_str[0]) == NULL) == 0);
    if (!operatorValidator){
        printf("......%s ist kein erlaubter Operator\n", op_str);
    }

    // Berechnen des Ergebnisses und Ausgabe
    if(operand1Valid && operand2Valid && operatorValidator){
        char op = op_str[0];
        unsigned int operand1 = binaryToDecimal(operand1_str);
        unsigned int operand2 = binaryToDecimal(operand2_str);
        unsigned int result = evaluateBinaryExpression(operand1, op, operand2);
        char *result_binary = decimalToBinary(result);
        printf("%s %c %s =\n........%s (%#x)\n", operand1_str, op, operand2_str, result_binary, result);
        // Speicher freigeben
        free(result_binary);
    }

    return 0;
}
