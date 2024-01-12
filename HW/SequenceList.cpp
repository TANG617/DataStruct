#include<stdio.h>
#include<stdlib.h>
#define initSize 100
typedef struct{
    int *data;
    int maxSize,currentLength;
}SeqList;
SeqList L;
//Operations
bool listInsert(SeqList &L,int insertPosition,int insertData);
bool listDelete(SeqList &L,int deletePosition);
int  listLocate(SeqList &L,int targetData);

//All the position start at ZERO
int main()
{
// Init SequenceList
L.data=(int*)malloc(sizeof(int)*initSize);




}
bool listInsert(SeqList &L,int insertPosition,int insertData)//Insert a data BEFORE insertPosition
{
    // Check whether legal
    if(insertPosition<0 ||insertPosition>L.currentLength+1)
    {
        return false;
    }
    // Move element
    for(int i=L.currentLength;i>=insertPosition;i--)
    {
        L.data[i]=L.data[i-1];
    }
    L.data[insertPosition-1]=insertData;
    L.currentLength++;
    return true;
}
bool listDelete(SeqList &L,int deletePosition,int &e)
{
    //Check whether legal
    if(deletePosition>L.currentLength || deletePosition<0)
    {
        return false;
    }
    e=L.data[deletePosition-1];
    for(int i=deletePosition;i<L.currentLength;i++)
    {
        L.data[i-1]=L.data[i];
    }
    L.currentLength--;
    return true;
}
int locateElement(SeqList L,int e)
{

}