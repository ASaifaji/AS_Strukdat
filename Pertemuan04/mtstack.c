/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 20 september 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
/*	include tstack+boolean	*/

int main() 
{	/*	kamus main	*/
	Tstack A;	//	variabel A bertipe tStack
	char temp;

	createStack(&A);
	printStack(A);
	printf("\nindeks top : %d", top(A));
	printf("\nnilai top : %c", infotop(A));
	if(isEmptyStack(A)){
		printf("\nStack Kosong");
	}
	if(isFullStack(A)){
		printf("\nStack Penuh");
	}

	push(&A, 'A');
	push(&A, 'b');
	push(&A, 'y');
	printStack(A);
	viewStack(A);

	pop(&A, &temp);
	printf("\n%c", temp);
	push(&A, 'y');

	createStack(&A);
	pushN(&A, 10);
	printStack(A);
	if(isEmptyStack(A)){
		printf("\nStack Kosong");
	}
	if(isFullStack(A)){
		printf("\nStack Penuh");
	}
	pop(&A, &temp);
	pushBabel1(&A, 'x');
	printStack(A);
	pushBabel1(&A, 'x');
	printStack(A);

	pushZuma(&A, 'A');
	pushZuma(&A, 'b');
	printStack(A);
	pushZuma(&A, 'b');
	printStack(A);

	createStack(&A);
	printf("\nIsi kata 10 huruf palindrom");
	pushN(&A, 10);
	if(isPalindrom(A)){
		printf("Stack Palindrom");
	}
	else{
		printf("Stack tidak Palindrom");
	}

	return 0;
}