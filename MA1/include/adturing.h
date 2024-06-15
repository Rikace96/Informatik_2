#ifndef ADTURING_H
#define ADTURING_H

typedef struct {
    char band[100];
    int position;
    int zustand;
} Turingmaschine;

Turingmaschine* tm_initialisieren(char *band);
void tm_freigeben(Turingmaschine *tm);
void tm_addition(Turingmaschine *tm);

#endif
