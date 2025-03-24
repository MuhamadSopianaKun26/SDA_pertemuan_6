#ifndef STACKED_H
#define STACKED_H

#include <stdbool.h>

// Definisi tipe data untuk buah
typedef const char* Fruit;

// Struktur Node untuk Stack
typedef struct SlotNode * nodeP;
typedef struct SlotNode {
    Fruit fruit;
    nodeP next;
} SlotNode;

// Struktur Stack
typedef struct Slotstack{
    nodeP top;
    Fruit keyFruit;
    int size;
} SlotStack;

// Prototipe fungsi
void initStack(SlotStack *s);
void push(SlotStack *s, Fruit fruit);
void pop(SlotStack *s);
void clearStack(SlotStack *s);
bool isWin(SlotStack *s, Fruit keyFruit);
bool isEmpty(SlotStack *s);
void show_slot(SlotStack *s);

#endif