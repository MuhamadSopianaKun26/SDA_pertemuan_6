/*** Identitas ***/
// Nama : Muhamad Sopiana Argiansah  
// NIM: 241524016  
// Kelas: 1A-D4
// Prodi: D4-Teknik Informatika 
// Jurusan: Teknik Komputer dan Informatika  
// Politeknik Negeri Bandung  

#include <stdlib.h>
#include <stdio.h>
#include "konversiBiner.h"

void konversi_desimal_to_biner (stack **S, int angka) {
    int tempNum;
    if (angka < 0) {
        printf("eror input");
        return;
    }else{
        while (angka != 0) {
            tempNum = angka%2;
            push (S, tempNum);
            angka = angka /2;
        }
    }

};