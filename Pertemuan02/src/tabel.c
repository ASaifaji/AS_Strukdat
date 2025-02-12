#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
#include <stdio.h>
#include <math.h>

/* Program   : tabel.c */
/* Deskripsi : Realisasi modul tabel */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji */
/* Tanggal   : Jum'at, 6 September 2024 */


void createTable(Tabel *T){
    for(int i = 0; i < 11; i++){
        (*T).wadah[i] = -999;
        (*T).size = 0;
    }
}

int getSize(Tabel T){
    return T.size;
}

boolean isEmptyTable(Tabel T){
    int bol = 1;
    for(int i = 1; i < 11; i++){
        if(T.wadah[i] != -999){
            bol = 0;
            return bol;
        }
    }
    return bol;
}

boolean isFullTable(Tabel T){
    for(int i = 1; i < 11; i++){
        if(T.wadah[i] == -999){
            return false;
        }
    }
    return true;
}

int searchX(Tabel T, int X){
    for(int i = 1; i < (T.size + 1); i++){
        if(T.wadah[i] == X){
            return i;
        }
    }
    return 0;
}

int countX(Tabel T, int X){
    int count = 0;
    for(int i = 1; i < (T.size + 1); i++){
        if(T.wadah[i] == X){
            count = count + 1;
        }
    }
    return count;
}

int countEmpty (Tabel T){
    int count = 0;
    for(int i = 1; i < 11; i++){
        if(T.wadah[i] == -999){
            count = count + 1;
        }
    }
    return count;
}

void addXTable(Tabel *T, int X){
    if(!(isFullTable((*T)))){
        (*T).wadah[(*T).size + 1] = X;
        (*T).size = (*T).size + 1;
    }
    else{
        printf("\nTabel sudah Penuh");
    }
}

void delXTable(Tabel *T, int X){
    for(int i = 1; i < ((*T).size + 1); i++){
        if(((*T).wadah[i] == X) && (i != 10)){
            int j; 
            j = i;
            while((j < 10) && ((*T).wadah[j] != -999)){
                (*T).wadah[j] = (*T).wadah[j + 1];
                j = j + 1;
            }
            (*T).size = (*T).size - 1;
            (*T).wadah[10] = -999;
            break;
            }
        else{
            if(((*T).wadah[i] == X) && (i == 10)){
                (*T).wadah[i] = -999;
                (*T).size = (*T).size - 1;
            }
        }
    }
}

void delAllXTable(Tabel *T, int X){
    int j, red = 0;
    for(int i = 1; i < ((*T).size + 1); i++){
        if((*T).wadah[i] == X){
            j = i;
            while((j < 11) && ((*T).wadah[j] != -999)){
                if(j == 10){
                    (*T).wadah[j] = -999;
                }
                (*T).wadah[j] = (*T).wadah[j + 1];
                j = j + 1;
            }
            red += 1;
        }
    }
    for(int i = 10 ; i > (((*T).size) - red); i--){
        (*T).wadah[i] = -999;
    }
    (*T).size -= red;
}

void printTable(Tabel T){
    printf("\n|");
    for(int i = 1; i < 11; i++){
        printf(" %d |", T.wadah[i]);
    }
    printf("\nTable size : %d", getSize(T));
}

void viewTable(Tabel T){
    if(!(isEmptyTable(T))){
        printf("\n|");
        for(int i = 1; i < (T.size + 1); i++){
            printf(" %d |", T.wadah[i]);
        }
        printf("\nTable size : %d", T.size);
    }
    else{
        printf("\nTabel kosong");
    }
}

void populate1(Tabel *T, int N){
    if((*T).size + N > 10){
        printf("\nSisa tabel kosong tidak cukup");
    }
    else{
        int x;
        for(int i = 1; i < N + 1; i++){
            printf("\nIsi tabel ke-%d integer lebih dari 0 : ", i);
            scanf("%d", &x);
            if (x > 0){
                (*T).wadah[i] = x;
            }
            else{
                printf("\nInput tidak memenuhi syarat ulangi lagi\n");
                i = i - 1;
            }
        }
        (*T).size += N;
    }
}

void populate2(Tabel *T){
    if((*T).size == 0){
       
        int x;
        for(int i = 1; i < 11; i++){
            printf("\nIsi tabel ke-%d integer lebih dari 0 : ", i);
            scanf("%d", &x);
            if (x > 0){
                (*T).wadah[i] = x;
                (*T).size += 1;
            }
            else{
                printf("\nInput tidak memenuhi syarat");
                i = i - 1;
                break;
            }
        }
    }
    else{
        int x;
        for(int i = (*T).size + 1; i < 11; i++){
            printf("\nIsi tabel ke-%d integer lebih dari 0 : ", i);
            scanf("%d", &x);
            if (x > 0){
                (*T).wadah[i] = x;
                (*T).size += 1;
            }
            else{
                printf("\nInput tidak memenuhi syarat");
                i = i - 1;
                break;
            }
        }
    }
}

int sumE1(Tabel T){
    if(!(isEmptyTable(T))){
        int sum = 0;
        for(int i = 1; i < (T.size + 1); i++){
            sum = sum + T.wadah[i];
        }
        return sum;
    }
    else{
        return 0;
    }
}

float AverageE1(Tabel T){
    float average = 0.0;
    if(!(isEmptyTable(T))){
        average = (float)sumE1(T)/T.size;
    }
    return average;
}

int getMaxE1(Tabel T){
    if(!(isEmptyTable(T))){
        int max = T.wadah[1];
        for(int i = 2; i < (T.size + 1); i++){
            if (T.wadah[i] > max){
                max = T.wadah[i];
            }
        }
        return max;
    }
    else{
        return 0;
    }
}

int getMinE1(Tabel T){
    if(!(isEmptyTable(T))){
        int min = T.wadah[1];
        for(int i = 2; i < (T.size + 1); i++){
            if (T.wadah[i] < min){
                min = T.wadah[i];
            }
        }
        return min;
    }
    else{
        return 0;
    }
}

int Modus(Tabel T){
    int Tfreq[T.size + 1];
    int temp, freq = 0;
    for(int i = 1; i < (T.size + 1); i++){
        Tfreq[i] = 0;
    }
    for(int i = 1; i < (T.size + 1); i++){
        temp = T.wadah[i];
        for(int j = 1; j < (T.size + 1); i++){
            if(T.wadah[j] == temp){
                freq += 1;
            }
        }
        Tfreq[i] = freq;
    }
    temp = Tfreq[1];
    for(int i = 2; i < (T.size + 1); i++){
        if(Tfreq[i] > temp){
            temp = Tfreq[i];
        }
    }
    return temp;
}

void sortAsc(Tabel *T){
    int i, temp;
    for(int pass = 2; pass < ((*T).size + 1); pass++){
        i = pass - 1;
        temp = (*T).wadah[pass];
        while((temp < (*T).wadah[i]) && (i > 1)){
            (*T).wadah[i + 1] = (*T).wadah[i];
            i -= 1;
        }
        if(temp < (*T).wadah[i]){
            (*T).wadah[i + 1] = (*T).wadah[i];
            (*T).wadah[i] = temp;
        }
        else{
            (*T).wadah[i + 1] = temp;
        }
    }
}

void sortDesc(Tabel *T){
    int i, temp;
    for(int pass = 2; pass < ((*T).size + 1); pass++){
        i = pass - 1;
        temp = (*T).wadah[pass];
        while((temp > (*T).wadah[i]) && (i > 1)){
            (*T).wadah[i + 1] = (*T).wadah[i];
            i -= 1;
        }
        if(temp > (*T).wadah[i]){
            (*T).wadah[i + 1] = (*T).wadah[i];
            (*T).wadah[i] = temp;
        }
        else{
            (*T).wadah[i + 1] = temp;
        }
    }
}

#endif