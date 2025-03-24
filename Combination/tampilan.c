// File: tampilan.c
#include "tampilan.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Untuk Windows
#else
    system("clear"); // Untuk Linux/Mac
#endif
}

void menu(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack) {
    int choice;
    while (choice != 5) {
        clearScreen();

        puts("#==========================================#");
        puts("#============ GACOR SLOT GAME =============#");
        puts("#==========================================#");
        puts("#                                          #");
        puts("#------------- 1. Daftar Slot  ------------#");
        puts("#------------- 2. Mulai Slot  -------------#");
        puts("#------------- 3. Riwayat Pemain  ---------#");
        puts("#------------- 4. Cek Slot  ---------------#");
        puts("#------------- 5. Keluar  -----------------#");
        puts("#                                          #");
        puts("#==========================================#");
        printf(" => pilih opsi : ");
        pilihan_menu(&choice, Q, Riwayat, Stack);
    }

    printf("\n ---- terima kasih telah bermain, salam Gacor King ---- ");
    printf("\n             ---- hindari perjudian ----                 \n\n\n");
}

void pilihan_menu(int *choice, linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack) {
    scanf("%d", &*choice);
    getchar();
    switch (*choice)
    {
    case 1:
        daftar_slot(Q, Riwayat);
        break;

    case 2 :
        mulai_slot(Q, Riwayat, Stack);
        break;

    case 3:
        riwayat_pemain(Riwayat);
        break;

    case 4:
        isi_slot(Stack);
        break;
    
    case 5:
        break;
    }
}

void daftar_slot(linkedlist *Q, linkedlist *Riwayat) {
    clearScreen();
    char nama[50]; // Gunakan array statis untuk menyimpan nama
    int id;
    puts("#==========================================#");
    puts("#============  DAFTAR ANTRIAN  ============#");
    puts("#==========================================#");
    printf("\n ==> masukan nama : ");
    scanf("%s", nama);
    getchar();

    // Masukkan nama ke antrian (Queue)
    Enqueue(Q, nama);

    printf("Antrian anda bermain ke: %d\n", Q->rear->orang.id);

    PrintQueue(*Q);

    printf("Tekan ENTER untuk kembali ke menu");
    getchar();

}

void mulai_slot(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack) {
    clearScreen();
    playSlot(Q, Riwayat, Stack);
    // Implementasi mulai slot
}

void riwayat_pemain(linkedlist *Riwayat) {
    clearScreen();
    puts("#==========================================#");
    puts("#============  Riwayat Pemain  ============#");
    puts("#==========================================#");

    printf("\n");
    tampilkan_riwayat(*Riwayat);
    printf("\n");   
    printf("Tekan ENTER untuk kembali ke menu");
    getchar();

    // Implementasi riwayat pemain
}

void isi_slot(SlotStack *Stack) {
    clearScreen();
    puts("#==========================================#");
    puts("#============     Cek Slot     ============#");
    puts("#==========================================#");

    printf("\n");
    show_slot(Stack);
    printf("Tekan ENTER untuk kembali ke menu");
    getchar();
    // Implementasi papan pemenang
}