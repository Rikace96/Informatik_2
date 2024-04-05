#include <stdio.h>
#include <stdarg.h>

int vielmax(int num, ...) {

    va_list args;
    int max, currentNumber;

    //Initialization
    va_start(args, num);

    //Erste Argument als Maximum setzen
    max = va_arg(args, int);

    // Iteration durch die Zahlen
    for (int i = 1; i < num; i++) {

        //Wechseln auf dem nächsten Argument
        currentNumber = va_arg(args, int);

        //Überprüfung von MaxZahl
        if (currentNumber > max) {
            max = currentNumber;
        }
    }
    va_end(args);

    return max;
}

int main() {
    printf("Testprogramm fuer Funktion vielmax()\n");
    printf("====================================\n\n");

    int maximum = vielmax(6, 12, 17, 3, 6, 24, 8);
    printf("Das Maximum der Zahlen 12, 17, 3, 6, 24, 8, 25 ist: %d\n", maximum);

    maximum = vielmax(4, 105, 77, 3, 54);
    printf("Das Maximum der Zahlen 105, 77, 3, 54 ist: %d\n", maximum);

    return 0;
}
