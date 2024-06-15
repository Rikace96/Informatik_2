#ifndef DOTURING_H
#define DOTURING_H

typedef struct {
    char band[200];
    int position;
    int zustand;
} Turingmaschine;

Turingmaschine* tm_initialisieren(char *band);
void tm_freigeben(Turingmaschine *tm);
void tm_verdoppeln(Turingmaschine *tm);

#endif
