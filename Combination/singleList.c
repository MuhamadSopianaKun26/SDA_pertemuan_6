// File: singleList.c
#include "singleList.h"

/***************************************/
/*** SINGGLE LINKED LIST [DATA PEMAIN] */
/***************************************/

void CreateSingleList(linkedlist *S) {
    S->front = NULL;
    S->rear = NULL;
}

// Fungsi untuk menambahkan pemain ke linked list
void tambah_pemain(linkedlist *S, int id, const char *nama, int jumlah_bermain, int total_bet) {
    // Buat node baru
    address pemain_baru = (address)malloc(sizeof(nodePemain));
    if (pemain_baru == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    // Isi data pemain
    pemain_baru->orang.id = id;
    strcpy(pemain_baru->orang.nama, nama);
    pemain_baru->orang.jumlah_bermain = jumlah_bermain;
    pemain_baru->orang.total_bet = total_bet;
    pemain_baru->nextnode = NULL;

    // Jika linked list kosong, jadikan node baru sebagai head
    if (S->front == NULL && S->rear == NULL) {
        S->front = pemain_baru;
        S->rear = pemain_baru;
    } else {
        // Jika tidak, tambahkan node baru di awal linked list
        S->rear->nextnode = pemain_baru;
        S->rear = pemain_baru;
    }
}

// Fungsi untuk menampilkan riwayat pemain
void tampilkan_riwayat(linkedlist S) {
    address temp = S.front;
    printf("\n=== RIWAYAT PEMAIN ===\n");
    while (temp != NULL) {
        printf("ID: %d\n", temp->orang.id);
        printf("Nama: %s\n", temp->orang.nama);
        printf("Jumlah Bermain: %d\n", temp->orang.jumlah_bermain);
        printf("Total Uang: %d\n", temp->orang.total_bet);
        printf("----------------------------\n");
        temp = temp->nextnode;
    }
}

// Fungsi untuk menghapus seluruh linked list
void hapus_riwayat(linkedlist *S) {
    address temp;
    while (S->front != NULL) {
        temp = S->front;
        S->front = S->front->nextnode;
        free(temp);
    }
    printf("Riwayat pemain telah dihapus.\n");
}