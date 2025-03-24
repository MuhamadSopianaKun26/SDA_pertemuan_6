// File: tampilan.h
#ifndef TAMPILAN_H
#define TAMPILAN_H

#include "singleList.h"
#include "queue.h"
#include "stacked.h"
#include "slot.h"

void menu(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack);
void clearScreen();
void pilihan_menu(int *choice, linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack);
void daftar_slot(linkedlist *Q, linkedlist *Riwayat);
void mulai_slot(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack);
void riwayat_pemain(linkedlist *Riwayat);
void isi_slot(SlotStack *Stack);

#endif