/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123130099 / Abyasa Saifaji*/
/* Tanggal   : Jum'at, 20 september 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
/*	include tstack+boolean	*/

int main() 
{	/*	kamus main	*/
	int session = 1;	//	Status Sesi
	int init = 0;	//	Status Inisialisasi
	char syntax[20];	//	Variabel string untuk input
	Tstack A;	//	variabel A bertipe tStack
	int printview = 1;

	setup(syntax);

	while(session != 0){
		input(A, printview);
	}

	printf("\n\n[Process Exited]");
	return 0;
}

void setup(syntax){
	printf("Aplikasi Driver Modul Stack \"mytst\"");
	printf("\nversion 1.0");
	printf("\nKetik HELP untuk daftar modul");
	input(syntax);
}

void input(syntax){
	scanf("\nmytst> %s", syntax);
}

void run(Tstack A, char syntax[20], int printview, int init){
	if (strcmp(syntax,"Help") == 0 || strcmp(syntax, "HELP") == 0 || strcmp(syntax,"help") == 0){
		s_help(syntax);
	}
	else if(strcmp(syntax,"Createstack") == 0 || strcmp(syntax, "CREATESTACK") == 0 || strcmp(syntax,"createstack") == 0){
		s_createStack(A, init);
	}
	else if(strcmp(syntax,"Top") == 0 || strcmp(syntax, "TOP") == 0 || strcmp(syntax,"top") == 0){
		s_top(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Infotop") == 0 || strcmp(syntax, "INFOTOP") == 0 || strcmp(syntax,"infotop") == 0){
		s_infotop(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Isemptystack") == 0 || strcmp(syntax, "ISEMPTYSTACK") == 0 || strcmp(syntax,"isemptystack") == 0){
		s_isEmptyStack(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Isfullstack") == 0 || strcmp(syntax, "ISFULLSTACK") == 0 || strcmp(syntax,"isfullstack") == 0){
		s_isFullStack(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Push") == 0 || strcmp(syntax, "PUSH") == 0 || strcmp(syntax,"push") == 0){
		s_push(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Pop") == 0 || strcmp(syntax, "POP") == 0 || strcmp(syntax,"pop") == 0){
		s_pop(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Printstack") == 0 || strcmp(syntax, "PRINTSTACK") == 0 || strcmp(syntax,"printstack") == 0){
		s_printStack(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Viewstack") == 0 || strcmp(syntax, "VIEWSTACK") == 0 || strcmp(syntax,"viewstack") == 0){
		s_viewStack(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Pushn") == 0 || strcmp(syntax, "PUSHN") == 0 || strcmp(syntax,"pushn") == 0){
		s_pushN(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Pushbabel1") == 0 || strcmp(syntax, "PUSHBABEL1") == 0 || strcmp(syntax,"pushbabel1") == 0){
		s_pushBabel1(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Pushzuma") == 0 || strcmp(syntax, "PUSHZUMA") == 0 || strcmp(syntax,"pushzuma") == 0){
		s_pushZuma(A, syntax, printview, init);
	}
	else if(strcmp(syntax,"Ispalindrom") == 0 || strcmp(syntax, "ISPALINDROM") == 0 || strcmp(syntax,"ispalindrom") == 0){
		s_isPalindrom(A, syntax, printview, init);
	}
}

void s_help(char syntax[20]){
	memset(syntax,0,strlen(syntax));	//	Hapus isi str syntax
	printf("\n\n");
	printf("\nDaftar Modul :\n");
	printf("\n	HELP			Memberikan List fungsi dalam modul driver");
	printf("\n	CREATESTACK		Menginisialisasi Stack");
	printf("\n	TOP				Mengembalikan indeks nilai teratas Stack");
	printf("\n	INFOTOP			Mengembalikan Nilai teratas Stack");
	printf("\n	ISEMPTYSTACK	Mengecek apakah Stack Kosong");
	printf("\n	ISFULLSTACK		Mengecek apakah Stack Penuh");
	printf("\n	PUSH			Memasukan Nilai kedalam Stack");
	printf("\n	POP				Mengambil Nilai teratas didalam Stack");
	printf("\n	PRINTSTACK		Menampilkan keseluruhan isi Stack");
	printf("\n	VIEWSTACK		Menampilkan isi Stack yang terisi");
	printf("\n	PUSHN			Mengisi elemen top baru N kali dari keyboard");
	printf("\n	PUSHBABEL1		Memasukan nilai ke top atau menghapus semua elemen apabila Stack penuh");
	printf("\n	PUSHZUMA		Memasukan nilai ke top atau menghapus top apabila sama dengan nilai");
	printf("\n	ISPALINDROM		Mengecek apakah sebuah Stack palindrom");
	printf("\n\n");
	printf("Input-nya CASE-SENSITIVE, gunakan huruf pertama kapital, atau semua huruf kapital, atau semua huruf tidak kapital");
}

void s_createStack(Tstack A, int init){
	createStack(&A);
	init = 1;
	printf("\nStack Berhasil Dibuat");
}

void s_top(Tstack A, char syntax[20], int printview, int init){
	printf("Indeks Top Stack = %d", top(A));
}

void s_infotop(Tstack A,);