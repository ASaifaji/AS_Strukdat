#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

address Alokasi(infotype E){
    address p;
    p = (address) malloc(sizeof(Elm));
    if (p != NULL) { //ruang memori tersedia
        prev(p) = NULL;
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

void CreateList(List3 *L){
    First(*L) = NULL;
}

boolean IsEmptyList(List3 L){
    if(First(L) == NULL){
        return true;
    }
    return false;
}

void PrintList(List3 L){
    address p;
    p = First(L);
    printf("\n[");
    while(p->next != NULL ){
        printf(" %c", info(p));
        p = p->next;
    }
    printf(" %c", info(p));
    printf(" ]");
}

int NbElm(List3 L){
    int count = 0;
    if(!(IsEmptyList(L))){
        address p;
        p = First(L);
        while(p != NULL){
            p = p->next;
            count += 1;
        }
    }
    return count;
}

void InsertVFirst(List3 *L, infotype V){
    if(IsEmptyList(*L)){
        (*L).First = Alokasi(V);
    }
    else{
        address temp;
        temp = (*L).First;
        (*L).First = Alokasi(V);
        (*L).First->next = temp;
        temp->prev = (*L).First;
    }
}

void InsertVLast(List3 *L, infotype V){
    if(IsEmptyList(*L)){
        (*L).First = Alokasi(V);
    }
    else{
        address p;
        p = First(*L);
        while(p->next != NULL){
            p = p->next;
        }
        p->next = Alokasi(V);
        p->next->prev = p;
    }
}

void DeleteVFirst(List3 *L, infotype *V){
    if(!(IsEmptyList(*L))){
        if((*L).First->next == NULL){
            (*V) = (*L).First->info;
            Dealokasi(&(*L).First);
            CreateList(&(*L));
        }
        else{
            address temp;
            temp = (*L).First;
            (*L).First = (*L).First->next;
            (*L).First->prev = NULL;
            (*V) = temp->info;
            Dealokasi(&temp);
        }
    }
}

void DeleteVLast(List3 *L, infotype *V){
    if(!(IsEmptyList(*L))){
        if((*L).First->next == NULL){
            (*V) = (*L).First->info;
            Dealokasi(&(*L).First);
            CreateList(&(*L));
        }
        else{
            address beforelast;
            beforelast = (*L).First;
            while(beforelast->next->next != NULL){
                beforelast = beforelast->next;
            }
            address temp;
            temp = beforelast->next;
            beforelast->next = NULL;
            (*V) = temp->info;
            Dealokasi(&temp);
        }
    }
}

void DeleteX(List3 *L, infotype X){
    if(!(IsEmptyList(*L))){
        address p;
        SearchX((*L), X, &p);
        if(p != NULL){
            p->prev->next = p->next;
            p->next->prev = p->prev;
            Dealokasi(&p);
        }
    }
}

void SearchX(List3 L, infotype X, address *A){
    (*A) = NULL;
    if(!(IsEmptyList(L))){
        address p;
        p = L.First;
        while(p->next != NULL && p->info != X){
            p = p->next;
        }
        if(p->info == X){
            (*A) = p;
        }
    }
}

void UpdateX(List3 *L, infotype X, infotype Y){
    if(!(IsEmptyList(*L))){
        address p;
        SearchX((*L), X, &p);
        if(p != NULL){
            p->info = Y;
        }
    }
}

void Invers(List3 *L){
    if(!(IsEmptyList(*L)) && (*L).First != NULL){
        address p;
        p = (*L).First;
        while(p->next != NULL){
            InsertVFirst(&(*L), p->next->info);
            address temp;
            temp = p->next;
            p->next = p->next->next;
            if(p->next != NULL){
                p->next->prev = p;
            }
            Dealokasi(&temp);
        }
    }
}

void InsertVAfterX(List3 *L, infotype X, infotype V){
    if(!(IsEmptyList(*L))){
        address p;
        SearchX((*L), X, &p);
        address temp;
        temp = p->next;
        p->next = Alokasi(V);
        p->next->prev = p;
        p->next->next = temp;
        p->next->next->prev = p->next;
    }
}

void InsertVBeforeX(List3 *L, infotype X, infotype V){
    if(!(IsEmptyList(*L))){
        address p;
        SearchX((*L), X, &p);
        address temp;
        temp = p->prev;
        p->prev = Alokasi(V);
        p->prev->next = p;
        p->prev->prev = temp;
        p->prev->prev->next = p->prev;
    }
}

void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    if(!(IsEmptyList(*L)) && (*L).First->next != NULL){
        address p;
        SearchX((*L), X, &p);
        (*V) = p->next->info;
        address temp;
        temp = p->next;
        p->next = p->next->next;
        p->next->prev = p;
        Dealokasi(&temp);
    }
}

void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    if(!(IsEmptyList(*L)) && (*L).First->next != NULL){
        address p;
        SearchX((*L), X, &p);
        (*V) = p->prev->info;
        address temp;
        temp = p->prev;
        p->prev = p->prev->prev;
        p->prev->next = p;
        Dealokasi(&temp);
    }
}

int CountX(List3 L, infotype X){
    int count = 0;
    if(!(IsEmptyList(L))){
        address p;
        p = L.First;
        while(p != NULL){
            if(p->info == X){
                count += 1;
            }
            p = p->next;
        }
    }
    return count;
}

float FrekuensiX(List3 L, infotype X){
    float freq = (float)CountX(L,X)/NbElm(L);
    return freq;
}

int MaxMember(List3 L){
    char mod;
    int max = 0;
    address p;
    p = L.First;
    while(p != NULL){
        if(CountX(L,p->info) > max){
            mod = p->info;
            max = CountX(L,p->info);
        }
    }
    return max;
}

char Modus(List3 L){
    char mod;
    int max = 0;
    address p;
    p = L.First;
    while(p != NULL){
        if(CountX(L,p->info) > max){
            mod = p->info;
            max = CountX(L,p->info);
        }
    }
    return mod;
}

int CountVocal(List3 L){
    int count = 0;
    count += CountX(L, 'A');
    count += CountX(L, 'I');
    count += CountX(L, 'U');
    count += CountX(L, 'E');
    count += CountX(L, 'O');
    count += CountX(L, 'a');
    count += CountX(L, 'i');
    count += CountX(L, 'u');
    count += CountX(L, 'e');
    count += CountX(L, 'o');
}

int CountNG(List3 L){
    int count = 0;
    if(!(IsEmptyList(L))){
        address p;
        p - L.First;
        while(p != NULL){
            if((p->info == 'N' && p->next->info == 'G') || (p->info == 'n' && p->next->info == 'g') || (p->info == 'n' && p->next->info == 'G') || (p->info == 'N' && p->next->info == 'g')){
                count += 1;
            }
            p = p->next;
        }
    }
    return count;
}

void SearchAllX(List3 L, infotype X){
    printf("\n[");
    if(!(IsEmptyList(L))){
        int i = 0;
        address p;
        p = L.First;
        while(p != NULL){
            i += 1;
            if(p->info == X){
                printf(" %d", i);
            }
        }
    }
    printf(" ]");
}

void DeleteAllX(List3 *L, infotype X){
    while(CountX((*L), X) != 0){
        DeleteX(&(*L), X);
    }
}

void ConcatList(List3 L1, List3 L2, List3 *L){
    (*L).First = L1.First;
    address p;
    p = (*L).First;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = L2.First;
    L2.First->prev = p;
}

void SplitList(List3 L, List3 *L1, List3 *L2){
    address p;
    p = L.First;
    for(int i = 0; i <= NbElm(L)/2; i++){
        p = p->next;
    }
    address last;
    last = p->prev;
    (*L2).First = p;
    (*L2).First->prev = NULL;
    (*L1).First = L.First;
    last->next = NULL;
}

void CopyList(List3 L1, List3 *L2){
    address p;
    p = L1.First;
    while(p != NULL){
        InsertVLast(&(*L2),p->info);
        p = p->next;
    }
}