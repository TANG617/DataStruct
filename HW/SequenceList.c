#include<stdio.h>
#include<stdlib.h>
#define initSize 100
typedef struct{
    int *data;
    int maxSize,currentLength;
}SeqList;
SeqList L;
//Operations
int listInsert(SeqList & L ,int Position,int Data);
int listDelete(SeqList & L ,int Position);

int main()
{
// Init SequenceList
L.data=(int*)malloc(sizeof(int)*initSize);




}