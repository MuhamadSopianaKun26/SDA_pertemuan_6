/*** Identitas ***/
// Nama : Muhamad Sopiana Argiansah  
// NIM: 241524016  
// Kelas: 1A-D4
// Prodi: D4-Teknik Informatika 
// Jurusan: Teknik Komputer dan Informatika  
// Politeknik Negeri Bandung  

#include <stdio.h>
#include "Tampilan.h"
#include "konversiBiner.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Untuk Windows
#else
    system("clear"); // Untuk Linux/Mac
#endif
};

void konversiDashboard (stack **S) {
    clearScreen();
    int angka;
    printf("masukan angka: ");
    scanf("%d", &angka);

    printf("\nhasil konversi %d ke biner : ", angka);
    getchar();

    konversi_desimal_to_biner(S, angka);
    printStack(*S);
    printf("\n\nTekan enter untuk kembali!");
    getchar();
};

void mainDashboard(stack **S) {
    int choice;
    int repeat = 0;
    while(repeat == 0) {
        clearScreen();
        puts("*****************************************");
        puts("*         Covert Desimal to Biner       *");
        puts("*****************************************");
        puts("\n 1. Mulai Konversi");
        puts(" 2. Riwayat Konversi");
        puts(" 3. Keluar...");
        printf("\n masukan pilihan: ");

        while (scanf("%d", &choice) != 1) {
            printf("input tidak valid! \nMasukan Angka: ");
            getchar();
        }

        switch(choice) {
            case 1:
                konversiDashboard(S);
                break;
            case 2:
                printf("ga sempet!!!!");
                break;
            case 3:
                printf("\nprogram berakhir!");
                repeat = 1;
                break;
        }
    }
};

