/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	P = NULL;
	free(P);
}

/*********** OPERATORS ***********/

void CreateList(List1 *L){
	(*L).First = NULL;
}

boolean IsEmptyList(List1 L){
	if (L.First == NULL){
		return true;
	}
	return false;
}

void PrintList(List1 L){
	Elm *p = L.First;
	printf("\n[");
	while(p != NULL){
		printf(" %c", p->info);
		p = p->next;
	}
	printf(" ]");
}

int NbElm(List1 L){
	int count = 0;
	Elm *p = L.First;
	while(p != NULL){
		count += 1;
		p = p->next;
	}
	return count;
}

void InsertVFirst(List1 *L, infotype V){
	if(IsEmptyList(*L)){
		(*L).First = Alokasi(V);
	}
	else{
		address temp = (*L).First;
		(*L).First = Alokasi(V);
		(*L).First->next = temp;
	}
}

void InsertVLast(List1 *L, infotype V){
	if(IsEmptyList(*L)){
		(*L).First = Alokasi(V);
	}
	else{
		Elm *p = (*L).First;
		while(p != NULL){
			p = p->next;
		}
		p = Alokasi(V);
	}
}

void DeleteVFirst(List1 *L, infotype *V){
	if(!(IsEmptyList(*L))){
		(*V) = (*L).First->info;
		Elm *p = (*L).First;
		(*L).First = (*L).First->next;
		Dealokasi(p);
	}
}

void DeleteVLast(List1 *L, infotype *V){
	if(!(IsEmptyList(*L))){
		Elm *p = (*L).First;
		while(p->next != NULL){
			p = p->next;
		}
		(*V) = p;
		Dealokasi(p);
	}
}

void SearchX(List1 L, infotype X, address A){
	Elm *p = L.First;
	while(p->info != X){
		p = p->next;
	}
	A = p;
}

void UpdateX(List1 *L, infotype X, infotype Y){
	Elm *p = (*L).First;
	while(p->info != X){
		p = p->next;
	}
	p->info = Y;
}

void Invers(List1 *L){
	List1 S;
	CreateList(&S);
	Elm *p = (*L).First;
	while(p != NULL){
		InsertVFirst(&S, p->info);
		p = p->next;
	}
	(*L) = S;
	while(!(IsEmptyList(S))){
		char temp;
		DeleteVLast(&(S),&temp);
		temp = NULL;
		free(temp);
	}
}

int CountX(List1 L, infotype X){
	int count = 0;
	Elm *p = L.First;
	while(p != NULL){
		if(p->info == X){
			count += 1;
		}
		p = p->next;
	}
	return count;
}

float FrekuensiX(List1 L, infotype X){
	int count = 0;
	int size = 0;
	Elm *p = L.First;
	while(p != NULL){
		if(p->info == X){
			count += 1;
		}
		size += 1;
		p = p->next;
	}
	float freq = (float) count / size;
	return freq;
}

void SearchAllX(List1 L, infotype X){
	int count = 0;
	Elm *p = L.First;
	printf("\nX ada di indeks ke :");
	printf ('\n(');
	while(p != NULL){
		count += 1;
		if(p->info == X){
			printf(" %d", count);
		}
	}
	printf(" )");
}

void UpdateAllX(List1 *L, infotype X, infotype Y){
	Elm *p = (*L).First;
	while(p != NULL){
		if(p->info == X){
			p->info = Y;
		}
	}
}

void InsertVAfter(List1 *L, infotype V, infotype VA){
	Elm *p = (*L).First;
	while(p->info != V){
		p = p->next;
	}
	address temp = p->next;
	p->next = Alokasi(VA);
	p->next->next = temp;
}

int MaxMember(List1 L){
	int S[NbElm(L)];
	int i = 0;
	Elm *p = L.First;
	while(p != NULL){
		Elm *q = L.First;
		int count = 0;
		while(q != NULL){
			if(q->info == p->info){
				count += 1;
			}
			q = q->next;
		}
		S[i] = count;
		i += 1;
		p = p->next;
	}
	int max = 0;
	i = 0;
	for(i = 0; i <= NbElm(L); i++){
		if (max < S[i]){
			max = S[i];
		}
	}
	return max;
}

infotype Modus(List1 L){
	int S[NbElm(L)];
	int i = 0;
	Elm *p = L.First;
	while(p != NULL){
		Elm *q = L.First;
		int count = 0;
		while(q != NULL){
			if(q->info == p->info){
				count += 1;
			}
			q = q->next;
		}
		S[i] = count;
		i += 1;
		p = p->next;
	}
	int max = 0;
	int imax = 0;
	i = 0;
	for(i = 0; i <= NbElm(L); i++){
		if (max < S[i]){
			max = S[i];
			imax = i;
		}
	}
	int count = 0;
	Elm *r = L.First;
	while(count <= imax){
		r = r->next;
		count += 1;
	}
	return r->info;
}

void ConcatList(List1 L1, List1 L2, List1 *L){
	(*L).First = L1.First;
	Elm *p = (*L).First;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = L2.First;
}