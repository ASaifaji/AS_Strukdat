/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 27 september 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"

int main(){
    tqueue A, B;
    char temp;

    createQueue(&A);
    printQueue(A);
    printf("\n%c", infoHead(A));
    printf("\n%c", infoTail(A));

    if(isEmptyQueue(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement(A)){
        printf("\nQueue satu elemen");
    }

    enqueue(&A, 'a');

    if(isEmptyQueue(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement(A)){
        printf("\nQueue satu elemen");
    }

    enqueue(&A, 'b');
    enqueue(&A, 'y');

    if(isEmptyQueue(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement(A)){
        printf("\nQueue satu elemen");
    }

    viewQueue(A);
    dequeue(&A, &temp);
    viewQueue(A);
    enqueue(&A, 'a');
    enqueue(&A, 's');
    enqueue(&A, 'a');
    enqueue(&A, 's');
    enqueue(&A, 'a');
    enqueue(&A, 'i');
    enqueue(&A, 'f');
    enqueue(&A, 'a');

    if(isEmptyQueue(A)){
        printf("\nQueue Kosong");
    }
    if(isFullQueue(A)){
        printf("\nQueue Penuh");
    }
    if(isOneElement(A)){
        printf("\nQueue satu elemen");
    }

    printQueue(A);
    enqueue1(&A, '1');
    printQueue(A);

    createQueue(&B);
    enqueue(&B, 'e');
    enqueue(&B, 'n');
    enqueue(&B, 'z');
    enqueue(&B, 'o');

    printQueue(A);
    printQueue(B);

    printf("\n%d", maxlength(A, B));
    enqueue2(&A, &B, 'k');
    dequeue2(&A, &B, temp);
    printQueue(A);
    printQueue(B);
    printf("\n%c", temp);
    printf("\n%d", maxlength(A, B));

    return 0;
}