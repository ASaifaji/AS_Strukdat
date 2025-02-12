#include <stdio.h>
#include <stdlib.h>
#include "tqueue2.h"

/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul queue 2 karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 4 Oktober 2024*/
/***********************************/

int main(){
    //  Kamus
    tqueue2 A, B;
    char temp;

    //
    createQueue2(&A);
    printQueue2(A);

    if(isEmptyQueue2(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue2(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement2(A)){
        printf("\nQueue Satu Elemen");
    }

    enqueue2(&A, 'A');

    if(isEmptyQueue2(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue2(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement2(A)){
        printf("\nQueue Satu Elemen");
    }

    enqueue2(&A, 'B');
    enqueue2(&A, 'Y');
    printQueue2(A);
    viewQueue2(A);
    printf("\nBesar queue adalah : %d", sizeQueue2(A));

    dequeue2(&A, &temp);
    dequeue2(&A, &temp);
    printf("\nIsi temp : %c", temp);
    enqueue2N(&A, 5);
    printQueue2(A);
    createQueue2(&B);
    enqueue2N(&B, 5);

    printf("\nQueue A :");
    printQueue2(A);
    printf("\n\nQueue B :");
    printQueue2(B);
    if(isEqualQueue2(A, B)){
        printf("\n\nQueue Equal");
    }
    if(!(isEqualQueue2(A, B))){
        printf("\n\nQueue tidak Equal");
    }
}