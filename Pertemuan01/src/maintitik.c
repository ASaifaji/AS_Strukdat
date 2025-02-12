/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include "titik.c" // Kalo di VSCode harus titik.c, ga bisa pake titik.h

int main() {


	//kamus main
	Titik A, B;
	

	//algoritma
	printf("Halo, ini driver modul Titik \n");


	//Test Konstruktor
	makeTitik(&A);
	printf("\nInisialisasi [%d , %d]", getAbsis(A), getOrdinat(A));


	//Test Mutator dan Dekonstruktor
	setAbsis(&A,3);
	printf("\nNilai absis = %d", getAbsis(A));

	setOrdinat(&A, 4);
	printf("\nNilai Ordinat = %d", getOrdinat(A));


	//Test Fungsi Predikat
	if (isOrigin(A)){
		printf("\nTitik berada di perpotongan antara sumbu x dan sumbu y (0,0)");
	}
	else{
		printf("\nTitik tidak berada di perpotongan antara sumbu x dan sumbu y (0,0)");
	}

	setAbsis(&A, 0);			//Mengganti Kondisi titik
	setOrdinat(&A, 0);
	printf("\nTitik diubah menjadi [%d , %d]", getAbsis(A), getOrdinat(A));

	if (isOrigin(A)){
		printf("\nTitik berada di perpotongan antara sumbu x dan sumbu y (0,0)");
	}
	else{
		printf("\nTitik tidak berada di perpotongan antara sumbu x dan sumbu y (0,0)");
	}


	//Test Subrutin Geser
	geserXY(&A, 4, 2);
	printf("\nTitik digeser menjadi [%d , %d]", getAbsis(A), getOrdinat(A));


	//Test Subrutin Refleksi dan Kuadran
	refleksiSumbuX(&A);
	printf("\nTitik direfleksi menjadi [%d , %d]", getAbsis(A), getOrdinat(A));

	refleksiSumbuY(&A);
	printf("\nTitik direfleksi menjadi [%d , %d]", getAbsis(A), getOrdinat(A));

	printf("\nTitik Berada di Kuadran %d", Kuadran(A));

	refleksiSumbuX(&A);
	printf("\nTitik direfleksi menjadi [%d , %d]", getAbsis(A), getOrdinat(A));
	printf("\nTitik Berada di Kuadran %d", Kuadran(A));

	refleksiSumbuY(&A);
	printf("\nTitik direfleksi menjadi [%d , %d]", getAbsis(A), getOrdinat(A));
	printf("\nTitik Berada di Kuadran %d", Kuadran(A));

	refleksiSumbuX(&A);
	printf("\nTitik direfleksi menjadi [%d , %d]", getAbsis(A), getOrdinat(A));
	printf("\nTitik Berada di Kuadran %d", Kuadran(A));


	//Test  Subrutin Jarak
	makeTitik(&B);
	setAbsis(&B, 2);
	setOrdinat(&B, 2);

	printf("\nTitik A berada di [%d , %d]", getAbsis(A), getOrdinat(A));
	printf("\nTitik B berada di [%d , %d]", getAbsis(B), getOrdinat(B));

	printf("\nJarak kedua titik adalah %.2f satuan jarak", Jarak(A,B));
	
	return 0;
}
