// File: main.c
#include <stdio.h>
#include <stdlib.h>
#include "tampilan.h"
#include "queue.h"
#include "stacked.h"

int main() {
    linkedlist Antrian;
    CreateQueue(&Antrian); // Inisialisasi antrian

    linkedlist Riwayat; // Gunakan List untuk riwayat pemain
    CreateSingleList(&Riwayat); // Inisialisasi linked list riwayat

    SlotStack Stack;
    initStack(&Stack); // Inisialisasi stack

    Stack.keyFruit = "[empty]";
    
    menu(&Antrian, &Riwayat, &Stack); // Panggil menu dengan parameter yang sesuai

    return 0;
}