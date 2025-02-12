#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tqueue2.h"

/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul queue karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 4 Oktober 2024*/
/***********************************/


boolean isEmptyQueue2(tqueue2 Q){
    if(head2(Q) == 0 && tail2(Q) == 0){
        return true;
    }
    return false;
}

boolean isFullQueue2(tqueue2 Q){
    if(head2(Q) == 1 && tail2(Q) == 5){
        return true;
    }
    return false;
}

boolean isOneElement2(tqueue2 Q){
    if(head2(Q) == 1 && tail2(Q) == 1){
        return true;
    }
    return false;
}

void createQueue2(tqueue2 *Q){
    for(int i = 0; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

int head2(tqueue2 Q){
    return Q.head;
}

int tail2(tqueue2 Q){
    return Q.tail;
}

char infoHead2(tqueue2 Q){
    return Q.wadah[head2(Q)];
}

char infoTail2(tqueue2 Q){
    return Q.wadah[tail2(Q)];
}

int sizeQueue2(tqueue2 Q){
    return (fabs(head2(Q) - tail2(Q)) + 1);
}

void printQueue2(tqueue2 Q){
    printf("\n[ %c", Q.wadah[1]);
    for(int i = 2; i <= 5; i++){
        printf(", %c", Q.wadah[i]);
    }
    printf(" ]");
}

void viewQueue2(tqueue2 Q){
    printf("\n[ %c", Q.wadah[head2(Q)]);
    for(int i = (head2(Q) + 1); i <= tail2(Q); i++){
        printf(", %c", Q.wadah[i]);
    }
    printf(" ]");
}

boolean isTailStop(tqueue2 Q){
    if(tail2(Q) == 5){
        return true;
    }
    return false;
}

void resetHead(tqueue2 *Q){
    if(isTailStop(*Q)){
        int count = 0;
        for(int i = 0; i <= 5 - head2(*Q); i++){
            (*Q).wadah[i + 1] = (*Q).wadah[head2(*Q) + i];
            count += 1;
        }
        (*Q).head = 1;
        (*Q).tail = count;
    }
    else{
        printf("\nTail belum mencapai akhir, resetHead tidak berhasil");
    }
}

void enqueue2(tqueue2 *Q, char E){
    if(isEmptyQueue2(*Q)){
        (*Q).wadah[1] = E;
        (*Q).head = 1;
        (*Q).tail = 1;
    }
    else{
        if(isTailStop(*Q)){
            printf("\nTail mencapai akhir / Queue Penuh, enqueue tidak berhasil");
        }
        else{
            (*Q).wadah[tail2(*Q) + 1] = E;
            (*Q).tail += 1;
        }
    }
}

void dequeue2(tqueue2 *Q, char *E){
    if(isEmptyQueue2(*Q)){
        printf("\nQueue Kosong, dequeue tidak berhasil");
    }
    else{
        (*E) = (*Q).wadah[head2(*Q)];
        (*Q).wadah[head2(*Q)] = '#';
        (*Q).head += 1;
    }
}

void enqueue2N(tqueue2 *Q, int N){
    if(isFullQueue2(*Q)){
        printf("\nQueue Penuh, enqueueN tidak berhasil");
    }
    else{
        for (int i = 1; i <= N; i++){
            char input;
            if(isFullQueue2(*Q)){
                printf("\nQueue Penuh, enqueueN dihentikan");
                break;
            }
            if(isTailStop(*Q)){
                resetHead(&(*Q));
                printf("\nMasukkan nilai : ");
                scanf("\n");
                scanf("%c", &input);
                enqueue2(&(*Q), input);
            }
            else{
                printf("\nMasukkan nilai : ");
                scanf("\n");
                scanf("%c", &input);
                enqueue2(&(*Q), input);
            }
        }
    }
}

boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2){
    for(int i = 1; i<= 5; i++){
        if(Q1.wadah[i] != Q2.wadah[i]){
            return false;
        }
    }
    return true;
}