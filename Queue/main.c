#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"
#include "tampilan.h"

int main() {
    Queue* head = NULL;
    
    // Tampilkan welcome screen dan inisialisasi antrian
    WelcomeScreen(&head);
    
    // Tampilkan menu utama dan handle semua interaksi
    LobbyScreen(&head);
    
    return 0;
}
