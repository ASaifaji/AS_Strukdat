#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main(){
    List3 S;
    CreateList(&S);
    InsertVLast(&S,'S');
    InsertVLast(&S,'a');
    InsertVLast(&S,'i');
    InsertVLast(&S,'f');
    InsertVLast(&S,'a');
    InsertVLast(&S,'j');
    InsertVLast(&S,'i');
    PrintList(S);
    InsertVFirst(&S,'A');
    InsertVFirst(&S,'b');
    InsertVFirst(&S,'y');
    InsertVFirst(&S,'a');
    InsertVFirst(&S,'s');
    InsertVFirst(&S,'a');
    PrintList(S);
    printf("\n%d", NbElm(S));
    printf("\n%d", CountX(S,'a'));
    DeleteAllX(&S,'a');
    PrintList(S);

}