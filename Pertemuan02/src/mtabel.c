#include <stdio.h>
#include "tabel.h"
/* Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060123130099 / Abyasa Saifaji*/
/* Tanggal : Jum'at, 9 September 2024*/

int main() {
	/*kamus*/
	Tabel A;
	
	printf("createTable");
	createTable(&A);
	printf("[ %d", A.wadah[1]);
	for(int i = 2; i < 11; i++){
		printf(", %d", A.wadah[i]);
	}
	printf("]");

	printf("\nUkuran Tabel : %d", getSize(A));

	if(isEmptyTable(A)){
		printf("\nTabel Kosong");
	}

	if(isFullTable(A)){
		printf("\nTabel Penuh");
	}


	printf("\n\naddXTable loop");
	for(int i = 1; i < 11; i++){
		addXTable(&A,i);
	}

	printf("\n[ %d", A.wadah[1]);
	for(int i = 2; i < 11; i++){
		printf(", %d", A.wadah[i]);
	}
	printf("]");

	printf("\nUkuran Tabel : %d", getSize(A));
	
	if(isEmptyTable(A)){
		printf("\nTabel Kosong");
	}

	if(isFullTable(A)){
		printf("\nTabel Penuh");
	}

	printf("\n\ndelXTable(&A,6)");
	delXTable(&A,6);

	printf("\n[ %d", A.wadah[1]);
	for(int i = 2; i < 11; i++){
		printf(", %d", A.wadah[i]);
	}
	printf("]");

	printf("\nUkuran Tabel : %d", getSize(A));


	printf("\n\naddXTable(&A,5)");
	addXTable(&A, 5);

	printf("\n[ %d", A.wadah[1]);
	for(int i = 2; i < 11; i++){
		printf(", %d", A.wadah[i]);
	}
	printf("]");

	printf("\nUkuran Tabel : %d", getSize(A));

	printf("\nBanyaknya nilai 5 ada : ");
	printf("%d", countX(A,5));


	printf("\n\ndelAllXTable(&A,5)");
	delAllXTable(&A,5);

	printf("\n[ %d", A.wadah[1]);
	for(int i = 2; i < 11; i++){
		printf(", %d", A.wadah[i]);
	}
	printf("]");

	printf("\nUkuran Tabel : %d", getSize(A));

	printf("\nBilangan 7 ada di indeks : ");
	printf("%d",searchX(A,7));

	printf("\nJumlah tabel kosong ada : ");
	printf("%d", countEmpty(A));

	printf("\n\nprintTable(A)");
	printTable(A);

	printf("\n\nviewTable(A)");
	viewTable(A);

	printf("\n");
	createTable(&A);
	printTable(A);
	
	populate1(&A,10);
	printTable(A);

	// printf("\n");
	// createTable(&A);
	// printTable(A);

	// populate2(&A);
	// printTable(A);

	printf("\nJumlah semua elemen Tabel : %d", sumE1(A));
	printf("\nRata-rata elemen Tabel : %f", AverageE1(A));
	printf("\nNilai elemen terbesar : %d", getMaxE1(A));
	printf("\nNilai elemen terkecil : %d", getMinE1(A));
	printf("\nModus : %d", Modus(A));
	sortAsc(&A);
	printTable(A);
	sortDesc(&A);
	printTable(A);

	return 0;
}