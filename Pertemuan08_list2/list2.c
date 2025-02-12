/* File : List2.c */
/* Deskripsi : Realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130099 / Abyasa Saifaji */
/* Tanggal : Jum'at, 8 November 2024*/
 #include <stdio.h>
 #include <stdlib.h>
 #include "list2.h"

address Alokasi(infotype E){
    address p;
    p = (address) malloc(sizeof(Elm));
    if (p != NULL) { //ruang memori tersedia
		info(p) = E;
		next(p) = NULL;
	}
    return p;
}

void Dealokasi(address *P){
    (*P)->info = NULL;
    (*P) = NULL;
    free(*P);
}

void CreateList(List2 *L){
    First(*L) = NULL;
}

boolean IsEmptyList(List2 L){
    if(First(L) == NULL){
        return true;
    }
    return false;
}

boolean IsOneElm(List2 L){
    if(First(L)->next == First(L)){
        return true;
    }
    return false;
}

void PrintList(List2 L){
    address p;
    p = First(L);
    printf("\n[");
    while(p->next != First(L) ){
        printf(" %c", info(p));
        p = p->next
    }
    printf(" %c", info(p));
    printf(" ]");
}

int NbElm(List2 L){
    if(!(IsEmptyList(L))){
        address p;
        int count = 0;
        p = First(L);
        while(p->next != First(L)){
            count += 1;
            p = p->next;
        }
        count += 1;
        return count;
    }
    return 0;
}

void InsertVFirst(List2 *L, infotype V){
    if(IsEmptyList(*L)){
        (*L).First = Alokasi(V);
        (*L).First->next = First(L);
    }
    else{
        address temp;
        temp = (*L).First;
        (*L).First = Alokasi(V);
        (*L).First->next = temp;
    }
}

void InsertVLast(List2 *L, infotype V){
    if(IsEmptyList(*L)){
        (*L).First = Alokasi(V);
        (*L).First->next = First(L);
    }
    else{
        address last = (*L).First;
        while(last->next != (*L).First){
            last = last->next;
        }
        last->next = Alokasi(V);
        last->next->next = First(L);
    }
}

void DeleteVFirst(List2 *L, infotype *V){
    if(!(IsEmptyList(*L))){
        if(IsOneElm(*L)){
            Dealokasi(&(*L)->First);
            CreateList(&(*L));
        }
        else{
            address temp;
            temp = (*L).First;
            (*L).First = (*L).First->next;
            Dealokasi(&temp);
        }
    }
}

void DeleteVLast(List2 *L, infotype *V){
    if(!(IsEmptyList(*L))){
        if(IsOneElm(*L)){
            Dealokasi(&(*L).First);
            CreateList(&(*L));
        }
        else{
            address beforelast;
            beforelast = (*L).First;
            while(beforelast->next->next != (*L).First){
                beforelast = beforelast->next;
            }
            address temp;
            temp = beforelast->next;
            beforelast->next = (*L).First;
            Dealokasi(&temp);
        }
    }
}

void DeleteX(List2 *L, infotype X){
    if(!(IsEmptyList(*L))){
        if(IsOneElm(*L) && (*L).First->info == X){
            Dealokasi(&(*L).First);
            CreateList(&(*L));
        }
        else{
            address beforeX;
            beforeX = (*L).First;
            while(beforeX->next != (*L).First && beforeX->next->info == X){
                beforeX = beforeX->next;
            }
            if(beforeX->next->info == X){
                address temp;
                temp = beforeX->next;
                beforeX->next = (*L).First;
                Dealokasi(&temp);
            }
        }
    }
}

void SearchX(List2 L, infotype X, address *A){
    if(!(IsEmptyList(L))){
        address p;
        p = L.First;
        while(p->next != L.First && p->info == X){
            p = p->next;
        }
        if(p->info == X){
            (*A) = p;
        }
    }
}

void UpdateX(List2 *L, infotype X, infotype Y){
    if(!(IsEmptyList(*L))){
        address p;
        SearchX((*L), X, &p);
        p->info = Y;
    }
}

void Invers(List2 *L){
    if(!(IsEmptyList(*L)) && !(IsOneElm(*L))){
        address p, last;
        p = (*L).First;
        last = (*L).First;
        while(last->next != (*L).First){
            last = last->next;
        }
        while(p->next != (*L).First){
            address temp;
            temp = (*L).First;
            (*L).First = p->next;
            (*L).First->next = temp;
            last->next = (*L).First;
            p->next = p->next->next;
        }
    }
}

int CountX(List2 L, infotype X){
    int count = 0;
    if(!(IsEmptyList(L))){
        address p;
        p = L.First;
        while(p->next != L.First){
            if(p->info == X){
                count += 1;
            }
            p = p->next;
        }
        if(p->info == X){
            count += 1;
        }
        return count;
    }
    return count;
}

float FrekuensiX(List2 L, infotype X){
    int size = NbElm(L);
    float freq = size / CountX(L, X);
    return freq;
}

int CountVocal(List2 L){
    char vocal[] = "aAiIuUeEoO";
    int count = 0;
    for(int i = 0; i <= 9; i++){
        count += CountX(L,vocal[i]);
    }
    return count;
}

int CountNG(List2 L){
    int count = 0;
    if(!(IsEmptyList(L))){
        address p;
        p = L.First;
        while(p->next != L.First){
            if((p->info == 'N' && p->next->info == 'G') || (p->info == 'n' && p->next->info == 'g') || (p->info == 'N' && p->next->info == 'g') || (p->info == 'n' && p->next->info == 'G')){
                count += 1;
            }
            p = p->next;
        }
        if((p->info == 'N' && p->next->info == 'G') || (p->info == 'n' && p->next->info == 'g') || (p->info == 'N' && p->next->info == 'g') || (p->info == 'n' && p->next->info == 'G')){
            count += 1;
        }
        return count;
    }
    return count;
}

void InsertVAfterX(List2 *L, infotype X, infotype V){
    address addX, temp;
    addX = NULL
    SearchX(*L, X, &addX);
    if(addX != NULL){
        temp = addX->next;
        addX->next = Alokasi(V);
        addX->next->next = temp;
    }
}

void InsertVBeforeX(List2 *L, infotype X, infotype V){
    address addX, p;
    addX = NULL
    SearchX((*L), X, &addX);
    if(addX != NULL){
        if(addX == (*L)First){
            InsertVFirst(&(*L), V);
        }
        p = (*L).First;
        while(p->next != addX){
            p = p->next;
        }
        p->next = Alokasi(V);
        p->next->next = addX;
    }
}

void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    address addX, temp;
    addX = NULL;
    SearchX((*L), X, &addX);
    if(addX != NULL){
        temp = addX->next;
        addX->next = addX->next->next;
        Dealokasi(&temp);
    }
}

void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    address addX, befX, bebefX, temp;
    addX = NULL;
    SearchX((*L), X, &addX);
    if(addX != NULL){
        befX = L->First;
        while(befX->next != addX){
            befX = befX->next;
        }
        if(befX == L->First){
            DeleteVFirst(&(*L), &(temp));
        }
        bebefX = L->First;
        while(bebefX->next != befX){
            bebefX = bebefX->next;
        }
        bebefX->next = addX;
        Dealokasi(befX);
    }
}

DeleteAllX(List2 *L, infotype X){
    for(int i = 1; i <= CountX((*L), X); i++){
        DeleteX(&(*L), X);
    }
}

SearchAllX(List2 L, infotype X){
    int pos[NbElm(L)];
    for(int i = 0; i < NbElm(L); i++){
        pos[i] = NULL;
    }
    address p;
    p = L.First;
    int j = 0;
    for(int i = 1; i <= NbElm;(L); i++){
        if(p->info == X){
            pos[j] = i;
            j += 1;
        }
    }
    printf("\n %d", pos[0]);
    j = 1;
    while(pos[j] != NULL){
        printf(", %d", pos[j]);
    }
}

int MaxMember(List2 L){
    address p;
    int max = 0;
    p = L.First;
    for(int i = 1; i <= NbElm(L); i++){
        int count;
        count = CountX(L, p->info);
        if(count > max){
            max = count;
        }
        p = p->next;
    }
    return max;
}

char Modus(List2 L){
    address p, modus;
    int max = 0;
    modus = NULL;
    p = L.First;
    for(int i = 1; i <= NbElm(L); i++){
        int count;
        count = CountX(L, p->info);
        if(count > max){
            max = count;
            modus = p;
        }
        p = p->next;
    }
    if(modus != NULL){
        return modus;
    }
}

void ConcatList(List2 L1, List2 L2, List2 *L){
    (*L).First = L1.First;
    address p, p2;
    p = (*L).First;
    while(p->next != (*L).First){
        p = p->next;
    }
    p2 = L2.First;
    p->next = L2.First;
    p = p->next;
    while(p->next != L2.First){
        p = p->next;
    }
    p->next = (*L).First;
}

void SplitList(List2 L, List2 *L1, List2 *L2){
    (*L1).First = L.First;
    address p;
    for(int i = 1; i <= NbElm(L)/2; i++){
        p = p->next;
    }
    (*L2).First = p;
    p->next =(*L1).First;
    p = (*L2).First;
    while(p->next != L.First){
        p = p->next;
    }
    p->next = (*L2).First;
}

void CopyList(List2 L1, List2 *L2){
    (*L2).First = L1.First;
}