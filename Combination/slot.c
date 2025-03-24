#include "slot.h"
// Daftar buah yang tersedia
const char *fruits[] = {"Apple", "Orange", "Grape", "Cherry", "Lemon"};
const int TOTAL_FRUITS = 5;

Fruit getRandomFruit () {
    return fruits[rand() % TOTAL_FRUITS];
}

boolean isSameFruit(SlotStack *s, Fruit keyFruit) {
    return (strcmp(s->top->fruit, keyFruit) == 0);
}

void  spinSlot (linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack) {

}

void playSlot(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack) {
    if (IsQueueEmpty(*Q)) {
        printf("Antrian kosong! Tidak ada pemain yang bisa bermain.\n");
        getchar();
        return;
    }

    // 1. Ambil pemain dari antrian
    address currentPlayer = NULL;
    currentPlayer = Q->front;

    Dequeue(Q, &currentPlayer);
    printf("\n=== Giliran %s ===\n", currentPlayer->orang.nama);

    // 2. Tentukan buah kunci (hanya di awal permainan atau saat stack kosong)
    if (strcmp(Stack->keyFruit, "[empty]") == 0) {
        Stack->keyFruit = getRandomFruit();
        
    }
    printf("Buah Kunci: %s\n", Stack->keyFruit);
    // 3. Pemain melakukan spin
    printf("Tekan Enter untuk spin...");
    getchar();
    
    Fruit result = getRandomFruit();
    printf("Hasil Spin: %s\n", result);

    // 4. Cek kesamaan dengan buah kunci
    if (strcmp(result, Stack->keyFruit) == 0) {
        printf("Sesuai! ");
        if (strcmp(Stack->top->fruit, Stack->keyFruit) != 0){
            pop(Stack);
        }
        push(Stack, result);
        
        // 5. Cek kondisi menang
        if (isWin(Stack, Stack->keyFruit)) {
            printf("%s MENANG! 🎉\n", currentPlayer->orang.nama);
            
            // Tambahkan ke riwayat pemenang
            tambah_pemain(Riwayat, currentPlayer->orang.id, currentPlayer->orang.nama, 
                         currentPlayer->orang.jumlah_bermain + 1, 
                         currentPlayer->orang.total_bet + 100); // Contoh: tambah 100 poin
            
            clearStack(Stack); // Reset stack setelah menang
        } else {
            printf("Lanjut spin posisi berikutnya.\n");
            // Pemain tetap di antrian untuk spin lagi
            Enqueue(Q, currentPlayer->orang.nama);
        }
    } else {

        tambah_pemain(Riwayat, currentPlayer->orang.id, currentPlayer->orang.nama, 
                currentPlayer->orang.jumlah_bermain + 1, 
                currentPlayer->orang.total_bet + 0);
        pop(Stack);
        push(Stack, result);
        printf("Tidak sesuai! Giliran pemain berikutnya.\n");
        // Kembalikan pemain ke antrian
        Enqueue(Q, currentPlayer->orang.nama);
    }
    free(currentPlayer);
    printf("Tekan Enter untuk melanjutkan...");
    getchar();
}
