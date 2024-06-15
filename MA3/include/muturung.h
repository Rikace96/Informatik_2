#ifndef MUTURING_H
#define MUTURING_H

typedef struct {
    char band[200];
    int position;
    int zustand;
} Turingmaschine;

Turingmaschine* tm_initialisieren(char *band);
void tm_freigeben(Turingmaschine *tm);
void tm_multiplizieren(Turingmaschine *tm);

#endif
