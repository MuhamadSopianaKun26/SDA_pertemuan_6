#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

typedef struct queueNode* address;
typedef struct queueNode{
    char nama[50];
    int lineNumber;
    address next;
} Node;
typedef struct Queue{
    address front;
    address last;
    int count;
    struct Queue* nextQueue;
} Queue;


// Fungsi-fungsi dasar Queue //

// Inisialisasi queue
void initQueue(Queue* q);
// Memeriksa apakah queue kosong
int isEmpty(Queue* q);
// memeriksa apakah queue sudah penuh
int isFull(Queue* q);
// Menambahkan pelanggan ke dalam antrian
void enqueue(Queue* q, char* nama);
// Melayani pelanggan dari antrian
int dequeue(Queue* q);
// Menampilkan daftar antrian
void displayQueue(Queue* q);

void displayAllQueues(Queue* head);
void inputLineNumber (Queue* *head);
int countQueues(Queue* head);
void freeQueue(Queue* q);
void freeAllQueues(Queue* head);
#endif 