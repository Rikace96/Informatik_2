#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Funktion zur Überprüfung, ob eine Farbe eine der Grundfarben ist
bool isPrimaryColor(const char *color) {
    return (strcmp(color, "Gruen") == 0 || strcmp(color, "Rot") == 0 || strcmp(color, "Violett") == 0);
}

// Funktion zur Bestimmung der Mischfarbe
const char* mixColors(const char *color1, const char *color2) {
    if (strcmp(color1, color2) == 0) {
        return color1; // Wenn beide Farben gleich sind, ist die Mischfarbe einfach diese Farbe selbst
    } else if ((strcmp(color1, "Gruen") == 0 && strcmp(color2, "Rot") == 0) || (strcmp(color1, "Rot") == 0 && strcmp(color2, "Gruen") == 0)) {
        return "Gelb"; // Mischung von Grün und Rot ergibt Gelb
    } else if ((strcmp(color1, "Gruen") == 0 && strcmp(color2, "Violett") == 0) || (strcmp(color1, "Violett") == 0 && strcmp(color2, "Gruen") == 0)) {
        return "Blau"; // Mischung von Grün und Violett ergibt Blau
    } else {
        return "Purpur"; // Mischung von Rot und Violett ergibt Purpur
    }
}

int main() {
    char color1[20];
    char color2[20];

    printf("Erste Grundfarbe (Gruen Rot Violett): ");
    scanf("%s", color1);

    // Überprüfung der ersten Grundfarbe
    while (!isPrimaryColor(color1)) {
        printf("Unbekannte Grundfarbe %s (Neue Eingabe machen)\n", color1);
        printf("Erste Grundfarbe (Gruen Rot Violett): ");
        scanf("%s", color1);
    }

    printf("Zweite Grundfarbe (Gruen Rot Violett): ");
    scanf("%s", color2);

    // Überprüfung der zweiten Grundfarbe
    while (!isPrimaryColor(color2)) {
        printf("Unbekannte Grundfarbe %s (Neue Eingabe machen)\n", color2);
        printf("Zweite Grundfarbe (Gruen Rot Violett): ");
        scanf("%s", color2);
    }

    // Bestimmung der Mischfarbe und Ausgabe
    const char* mixColor = mixColors(color1, color2);
    printf("Die Mischfarbe ist dann %s\n", mixColor);

    return 0;
}
