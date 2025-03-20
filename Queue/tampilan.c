#include "tampilan.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Untuk Windows
    #else
        system("clear"); // Untuk Linux/Mac
    #endif
};

void WelcomeScreen(Queue** q) {
    clearScreen();

    printf ("=============================================\n");
    printf ("=    WELLCOME TO BANK KORUPTOR INDONESIA    =\n");
    printf ("=============================================\n\n");
    printf ("-> Please input the number of Teller to exist : ");

    inputLineNumber(q);

    int totalQueues = countQueues(*q);
    printf ("\nthere's %d teller to serve the corruptor.\npress enter to continue!", totalQueues);
    getchar();
};

void LobbyScreen(Queue** q) {
    int choice, tellerChoice;
    char nama[50];
    Queue* selectedTeller = NULL;
    
    do {
        clearScreen();
        printf ("=================================\n");
        printf ("=           Lobby Page          =\n");
        printf ("=================================\n\n");

        displayAllQueues(*q);

        printf("=== MAIN MENU ===\n");
        printf("1. Add Customer to Line\n");
        printf("2. Serve Customer\n");
        printf("3. Exit\n");
        printf("==================\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &choice);
        getchar(); // membersihkan buffer
        
        switch(choice) {
            case 1:
                clearScreen();
                printf("\n=== ADD CUSTOMER TO LINE ===\n");
                printf("Number of teller available: %d\n", countQueues(*q));
                printf("Choose teller number (1-%d): ", countQueues(*q));
                scanf("%d", &tellerChoice);
                getchar();
                
                if (tellerChoice < 1 || tellerChoice > countQueues(*q)) {
                    printf("Error: Teller number is not valid!\n");
                    printf("\nPress Enter to continue...");
                    getchar();
                    break;
                }
                
                // Mencari teller yang dipilih
                selectedTeller = *q;
                for (int i = 1; i < tellerChoice; i++) {
                    selectedTeller = selectedTeller->nextQueue;
                }
                
                printf("\nInput customer name: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // menghapus newline
                enqueue(selectedTeller, nama);
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 2:
                clearScreen();
                printf("\n=== SERVE CUSTOMER ===\n");
                printf("Number of teller available: %d\n", countQueues(*q));
                printf("Choose teller number (1-%d): ", countQueues(*q));
                scanf("%d", &tellerChoice);
                getchar();
                
                if (tellerChoice < 1 || tellerChoice > countQueues(*q)) {
                    printf("Error: Teller number is not valid!\n");
                    printf("\nPress Enter to continue...");
                    getchar();
                    break;
                }
                
                // Mencari teller yang dipilih
                selectedTeller = *q;
                for (int i = 1; i < tellerChoice; i++) {
                    selectedTeller = selectedTeller->nextQueue;
                }
                
                dequeue(selectedTeller);
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 3:
                printf("\nThank you for using this program!\n");
                freeAllQueues(*q);
                break;
                
            default:
                printf("\nError: Invalid choice!\n");
                printf("Press Enter to continue...");
                getchar();
        }
    } while(choice != 4);
};

void ShowAllLine(Queue** q) {
    clearScreen();
    printf("=== Lines ===\n");
    displayAllQueues(*q);
    printf("\nPress Enter to continue...");
    getchar();
};