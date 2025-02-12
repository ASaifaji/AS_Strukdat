/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.c"
int main(){
    address k;
    infotype a = 'a';
    List2 l;

    k = Alokasi(a);
    printf("\n%p", k);
    printf("\n%c", k->info);
    Dealokasi(&k);
    CreateList(&l);
    printf("\n%p", l.First);
    printf("\n%d", IsEmptyList(l));
    return 0;
}
