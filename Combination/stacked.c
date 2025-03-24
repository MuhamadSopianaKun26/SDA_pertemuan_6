#include "stacked.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Inisialisasi stack kosong
void initStack(SlotStack *s) {
    s->top = NULL;
    s->size = 0;
}

// Cek apakah stack kosong
bool isEmpty(SlotStack *s) {
    return (s->top == NULL);
}

// Tambahkan elemen ke stack
void push(SlotStack *s, Fruit fruit) {
    SlotNode *newNode = (SlotNode*)malloc(sizeof(SlotNode));
    if (newNode == NULL) exit(EXIT_FAILURE); // Handle alloc error
    
    newNode->fruit = fruit;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Hapus elemen teratas
void pop(SlotStack *s) {
    if (isEmpty(s)) return;
    
    SlotNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
}

// Kosongkan seluruh stack
void clearStack(SlotStack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

// Cek kemenangan (3 buah teratas sama dengan keyFruit)
bool isWin(SlotStack *s, Fruit keyFruit) {
    if (s->size < 3) return false;
    
    SlotNode *current = s->top;
    for (int i = 0; i < 3; i++) {
        if (strcmp(current->fruit, keyFruit) != 0) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void show_slot(SlotStack *s) {
    SlotNode *current = s->top;
    while (current != NULL) {
        printf("%s\n", current->fruit);
        current = current->next;
    }
}
