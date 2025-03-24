#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id_counter = 1;

/********** BODY FUNGSI QUEUE **********/
void CreateQueue(linkedlist *Q) {
    CreateSingleList(Q);
}

bool IsQueueEmpty(linkedlist Q) {
    return (Q.front == NULL);
}

void Enqueue(linkedlist *Q, const char *nama) {
    // Buat node baru
    tambah_pemain(Q, id_counter++, nama, 0, 0);
}

void Dequeue(linkedlist *Q, address *pemain) {
    if (!IsQueueEmpty(*Q)) {
        // Simpan data pemain yang dihapus
        address temp = Q->front;
        address check = Q->front;
        *pemain = temp;
        id_counter = 0;
        while (check != NULL) {
            check->orang.id = id_counter++;
            check = check->nextnode;
        }

        if (Q->front == Q->rear) {
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            Q->front = Q->front->nextnode;
            temp->nextnode = NULL;

        }
    } else {
        printf("Queue kosong!\n");
    }
}

void PrintQueue(linkedlist Q) {
    address temp = Q.front;
    printf("\n=== ANTRIAN PEMAIN ===\n");
    while (temp != NULL) {
        printf("ID: %d\n", temp->orang.id);
        printf("Nama: %s\n", temp->orang.nama);
        printf("Jumlah Bermain: %d\n", temp->orang.jumlah_bermain);
        printf("Total Uang: %d\n", temp->orang.total_bet);
        printf("----------------------------\n");
        temp = temp->nextnode;
    }
}