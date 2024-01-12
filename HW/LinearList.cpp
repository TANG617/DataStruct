// 李唐 21211010
// 100%自己完成
// 这是我的心路历程：https://github.com/TANG617/CS-Learning
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
int ListLength=1;
int SearchResultNum=0;
Node SearchResult[1001];
Node TailNode;
Node L;


struct Node
{
    struct Node *next;
    struct Node *prior;
    int data;
};

Node NodeNull={.next=NULL,.prior=NULL,.data=NULL};

bool initSeqList()
{
    L.next=NULL;
    L.prior=NULL;
    return 1;
}

bool insertElement_Head(Node *L,int data)
{
   Node * temp=(Node*)malloc(sizeof(Node));
   temp->data=data;
   temp->prior=L;
   temp->next=(*L).next;
   ListLength++;
   return 1;
}
// Insert from head doesn't mean insert before head node

bool insertElement_Tail(Node *L,int data)
{
   Node * Tail=L;
   Node * temp=(Node*)malloc(sizeof(Node));
   temp->data=data;
   temp->prior=L+ListLength;
   temp->next=NULL;
   ListLength++;
   return 1;
}

bool searchData(Node *L, int data)
{
    Node cursor=*L;
    bool Found=0;
    while(cursor.next!=NULL)
    {
        if(cursor.data==data)
        {
            Found=1;
            SearchResult[SearchResultNum]=cursor;
            //if there are multiple target
            // Confusing...
            // return searchData(&cursor,data);

        }
        else
        {
            cursor=*cursor.next;
        }
        
    }
    SearchResult[SearchResultNum+1]=NodeNull;
    return Found;
    
}

bool deleteNode(Node *L,Node *TargetToDelete)
{
    int position=TargetToDelete-L;
    (L+position-1)->next=L->next;
    L->prior=(L+position+1)->prior;
    free(L);
}

Node *invertCopyData(Node *R){
    Node *NewList;
    while(R->next!=NULL)
    {
        insertElement_Tail(NewList,R->data);
        R=R->next;
    }
    return NewList;
}

bool outputList(Node *L)
{
    Node *R=L;
    while(R->next!=NULL)
    {
        printf("%d",R->data);
        R=R->next;
    }
    return 1;
}

int main()
{
    initSeqList();
    //Question 1
    int x;
    searchData(*L,x);
    for (int i = 0; SearchResult[i]!=NodeNull; i++)
    {
            deleteNode(*L,SearchResult[i]);
    }

    //Question 2
    outputList(invertCopyData(*L));
    
    


}