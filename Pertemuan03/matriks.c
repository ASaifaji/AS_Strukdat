/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : */
/***********************************/
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* include matriks.h & boolean.h */

void initMatriks (Matriks *M){
    for(int i = 0; i < 11; i++){
        for(int j =0; j < 11; j++){
            (*M).cell[i][j] = -999;
            (*M).nbaris = 0;
            (*M).nkolom =0;
        }
    }
}

int getNBaris(Matriks M){
    return M.nbaris;
}

int getNKolom(Matriks M){
    return M.nkolom;
}

boolean isEmptyMatriks(Matriks M){
    if(M.nbaris == 0 && M.nkolom == 0){
        return true;
    }
    else{
        return false;
    }
}

boolean isFullMatriks(Matriks M){
    for(int i = 1; i < 11; i++){
        for(int j = 1; j < 11; j++){
            if(M.cell[i][j] == -999){
                return false;
            }
        }
    }
    return true;
}

void searchX(Matriks M, int X, int *row, int *col){
    if(isEmptyMatriks(M)){
        (*row) = -999;
        (*col) = -999;
    }
    else{
        (*row) = -999;
        (*col) = -999;
        for(int i = 1; i < M.nbaris + 1; i++){
            for(int j = 1; j < M.nkolom + 1; j++){
                if(M.cell[i][j] == X){
                    (*row) = i;
                    (*col) = j;
                }
            }
        }
    }
}

int countX(Matriks M, int X){
    if(isEmptyMatriks(M)){
        return 0;
    }
    else{
        int count = 0;
        for(int i = 1; i < M.nbaris + 1; i++){
            for(int j = 1; j < M.nkolom + 1; j++){
                if(M.cell[i][j] == X){
                    count += 1;
                }
            }
        }
        return count;
    }
}

void addX(Matriks *M, int X, int row, int col){
    if((*M).cell[row][col] == -999){
        (*M).cell[row][col] = X;
        if((*M).nbaris < row){
            (*M).nbaris = row;
        }
        if((*M).nkolom < col){
            (*M).nkolom = col;
        }
    }
    else{
        printf("Sudah terisi");
    }
}

void editX (Matriks *M, int X, int row, int col){
    (*M).cell[row][col] = X;
    if((*M).nbaris < row){
        (*M).nbaris = row;
    }
    if((*M).nkolom < col){
        (*M).nkolom = col;
    }
}

void delX(Matriks *M, int X){
    int row, col;
    searchX((*M), X, row, col);
    (*M).cell[row][col] = -999;
    for(int i = 10; i > 0; i--){
        for(int j = 10; j > 0; j--){
            if((*M).cell[i][j] != -999){
                (*M).nbaris = i;
                break;
            }
        }
    }
    for(int j = 10; j > 0; j--){
        for(int i = 10; i > 0; i++){
            if((*M).cell[i][j] != -999){
                (*M).nkolom = j;
                break;
            }
        }
    }
}

void isiMatriksRandom(Matriks *M, int x, int y){
    for(int i = 1; i < x + 1; i++){
        for(int j = 1; j < y + 1; j++){
            (*M).cell[i][j] = rand();
            if((*M).cell[i][j] < 0){
                (*M).cell[i][j] = (*M).cell[i][j] * -1;
            }
        }
    }
    (*M).nbaris = x;
    (*M).nkolom = y;
}

void isMatriksIdentitas(Matriks *M, int n){
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 11; j++){
            if(i == j){
                (*M).cell[i][j] = 0;
            }
            else{
                (*M).cell[i][j] = 1;
            }
        }
    }
}

void populateMatriks(Matriks *M, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("\nIsi matriks[%d][%d] : ", i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
}

void printMatriks(Matriks M){
    printf("_________________________");
    printf("\n");
    for(int i = 1; i < 11; i++){
        for(int i = 1; i < 11; i++){
            printf("  %d");
        }
        printf("\n");
    }
}