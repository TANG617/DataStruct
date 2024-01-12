#include<stdio.h>

#define MAXSIZE 1001
struct List{
    int list[MAXSIZE];
    // int cursor;
    int front,rear;
}Queue;

void UpdateCycleCursor(int *cursor,int operation)
{
    
    if((*cursor+operation)>0)
    {
        *cursor=(*cursor+operation)%MAXSIZE;
        if (*cursor==0)
        {
            *cursor=MAXSIZE;
        }
        //When it's just can be divided, we use the last number of element nor the 0
        
    }
    else
    {
        *cursor=(*cursor+operation+MAXSIZE);
    }
    // Queue.front=(Queue.front+1)%MAXSIZE;
    // Queue.rear=(Queue.rear+1)%MAXSIZE;
    //Update the cursor status after every operation
}

void init(List &Queue)
{
    Queue.front=2;
    Queue.rear=1;
}
//Use a spacer to check whether it's full or empty
bool isEmpty(List L)
{
    return Queue.front==Queue.rear?1:0;
}
bool isFull(List L)
{
    return Queue.front==Queue.rear+1?1:0;
}


bool PushBack(List &L,int data)
{
    
    if(isFull) return 0;
    else
    {
        Queue.list[Queue.rear++]=data;
    }
}

int main()
{

}