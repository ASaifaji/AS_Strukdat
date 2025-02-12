/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 20 september 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

void createStack(Tstack *T){
    for(int i = 0; i < 11; i++){
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

boolean isEmptyStack(Tstack T){
    if(top(T) == 0){
        return true;
    }
    return false;
}

boolean isFullStack(Tstack T){
    if(top(T) == 10){
        return true;
    }
    return false;
}

void push(Tstack *T, char E){
    if(!(isFullStack(*T))){
        (*T).wadah[top(*T) + 1] = E;
        (*T).top += 1;
    }
}

void pop(Tstack *T, char *X){
    if(!(isEmptyStack(*T))){
        (*X) = (*T).wadah[top(*T)];
        (*T).wadah[top(*T)] = '#';
        (*T).top -= 1;
    }
}

void printStack(Tstack T){
    printf("\n[ %c", T.wadah[1]);
    for(int i = 2; i < 11; i++){
        printf(", %c",T.wadah[i]);
    }
    printf(" ]");
}

void viewStack(Tstack T){
    if(!(isEmptyStack(T))){
        printf("\n[ %c", T.wadah[1]);
        for(int i = 2; i <= top(T); i++){
            printf(", %c",T.wadah[i]);
        }
        printf(" ]");
    }
    else{
        printf("\n[ ]");
    }
}

boolean isPalindrom(Tstack T){
	int split = top(T)/2;
    for(int i = 1; i <= split; i++){
        if(T.wadah[i] != T.wadah[top(T) - i + 1]){
            return false;
        }
    }
    return true;
}

void pushN(Tstack *T, int N){
    if(isEmptyStack(*T)){
        printf("\nInput character stack\n");
        for(int i = 1; i <= N; i++){
            char x;
            scanf("\n");
            scanf("\n%c", &x);
            push(&(*T), x);
        }
    }
    else{
        printf("\nStack tidak kosong");
    }
}

void pushBabel1(Tstack *T, char E){
    if(!(isFullStack(*T))){
        push(&(*T), E);
    }
    else{
        createStack(&(*T));
    }
}

void pushZuma(Tstack *T, char E){
    if(infotop(*T) != E){
        push(&(*T), E);
    }
    else{
        (*T).wadah[top(*T)] = '#';
        (*T).top -= 1;
    }
}