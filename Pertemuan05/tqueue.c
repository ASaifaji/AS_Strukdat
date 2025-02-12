/* Program   : tqueue.c */
/* Deskripsi : File body tqueue */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 27 September 2024*/

#include <stdio.h>
#include "tqueue.h"

void createQueue (tqueue *Q){
    for(int i = 0; i <= 10; i++){
        (*Q).wadah[i] = '-';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

int infoHead(tqueue Q){
    return(Q.wadah[head(Q)]);
}

int infoTail(tqueue Q){
    return(Q.wadah[tail(Q)]);
}

int sizeQueue(tqueue Q){
return tail(Q);
}

void printQueue(tqueue Q){
    printf("\n[ %c", Q.wadah[1]);
    for(int i = 2; i <= 10; i++){
        printf(", %c", Q.wadah[i]);
    }
    printf(" ]");
}

void viewQueue(tqueue Q){
    if(!isEmptyQueue(Q)){
        printf("\n[ %c", Q.wadah[1]);
        for(int i = 2; i <= tail(Q); i++){
            printf(", %c", Q.wadah[i]);
        }
        printf(" ]");
    }
    else{
        printf("\n[ ]");
    }
}

boolean isEmptyQueue(tqueue Q){
    if(head(Q) == 0 && tail(Q) == 0){
        return true;
    }
    return false;
}

boolean isFullQueue(tqueue Q){
    if(head(Q) == 1 && tail(Q) == 10){
        return true;
    }
    return false;
}

boolean isOneElement(tqueue Q){
    if(head(Q) == 1 && tail(Q) == 1){
        return true;
    }
    return false;
}

void enqueue(tqueue *Q, char e){
    if(!isFullQueue(*Q)){
        (*Q).wadah[(*Q).tail + 1] = e;
        (*Q).tail += 1;
        if((*Q).head == 0){
            (*Q).head = 1;
        }
    }
    else{
        printf("\nQueue penuh");
    }
}

void dequeue(tqueue *Q, char *e){
    (*e) = infoHead(*Q);
    if(!isOneElement(*Q)){
        for(int i = 1; i <= (*Q).tail; i++){
            (*Q).wadah[i] = (*Q).wadah[i + 1];
        }
        (*Q).tail -= 1;
    }
    else{
        (*Q).wadah[1] = '-';
        (*Q).head = 0;
        (*Q).tail = 0;
    }
}

void enqueue1(tqueue *Q, char e){
    if(!isFullQueue(*Q)){
        enqueue(&(*Q), e);
    }
    else{
        char temp;
        dequeue(&(*Q), &temp);
        enqueue(&(*Q), e);
        temp = NULL;
    }
}

int maxlength(tqueue Q1, tqueue Q2){
    if(tail(Q1) > tail(Q2)){
        return tail(Q1);
    }
    return tail(Q2);
}

void enqueue2(tqueue *Q1, tqueue *Q2, char e){
    if(tail(*Q2) > tail(*Q1)){
        enqueue(&(*Q1), e);
    }
    else{
        enqueue(&(*Q2), e);
    }
}

void dequeue2(tqueue *Q1, tqueue *Q2, char *e){
    if(tail(*Q2) < tail(*Q1)){
        dequeue(&(*Q1), &e);
    }
    else{
        dequeue(&(*Q2), &e);
    }
}