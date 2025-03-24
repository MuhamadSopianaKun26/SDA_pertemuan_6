// File: singleList.h
#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur data untuk Pemain (SINGLE LINKED LIST)
typedef struct dataPemain {
    int id; // ID pemain
    char nama[50]; // Nama pemain
    int jumlah_bermain; // Jumlah bermain
    int total_bet; // Total bet
} Pemain;

typedef struct nodePemain * address;
typedef struct nodePemain{
    Pemain orang;
    address nextnode;
} nodePemain;

typedef struct linkedlist {
    address front;
    address rear;
}linkedlist;

/********** FUNGSI OPERASI RIWAYAT PsEMAIN **********/
void CreateSingleList(linkedlist *S);
void tambah_pemain(linkedlist *S, int id, const char *nama, int jumlah_bermain, int total_bet);
void tampilkan_riwayat(linkedlist S);
void hapus_riwayat(linkedlist *S);

#endif