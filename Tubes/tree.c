#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


bintree Alokasi(infotype E){
    bintree T;

    T = (bintree) malloc(sizeof(node));
    if(T != NULL){
        T->info  = E;
        T->left  = NULL;
        T->right = NULL;
    }
    return T;
}

void adddaun(bintree *T, infotype P){
    bintree A, current;
    A = Alokasi(P);
    if(A != NULL){
        if(*T = NULL){
            *T = A;
        }
        else{
            current = *T;
            if(P.kelas = true){
                while(left(current) != NULL){
                    current = left(current);
                }
                left(current) = A;
            }
            else{
                if(P.kelas = false){
                    while(right(current) != NULL){
                        current = right(current);
                    }
                    right(current) = A;
                }
            }
        }
    }
}

void printTree(bintree T){
    if(T = NULL){
        printf("()");
    }else{
        printf("%c", info(T));
        printTree(T->left);
        printTree(T->right);
    }
}


int main(){
    //kamus lokal
    bintree a;
    pesanan kiri;
    //algoritma
    kiri.kelas = 1;
    kiri.NIK = 10;
    adddaun(&a, kiri);
    printTree(a);
}