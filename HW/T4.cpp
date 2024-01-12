//CS tree
#include<iostream>
using namespace std;
int a[100];
char b[100];
typedef char ElemType;
typedef struct Point
{
    ElemType data;
    int degree;
}Point;
typedef struct CSNode
{
    Point data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
typedef CSTree QCSElemType;
typedef struct QCSNode
{
    QCSElemType data;
    struct QCSNode *next;
}QCSNode,*QueueCS;
typedef struct
{
    QueueCS front;
    QueueCS rear;
}LinkQueueCS;
int InitQueueCS(LinkQueueCS *Q)
{
    (*Q).front=(*Q).rear=(QueueCS)malloc(sizeof(QCSNode));
    if (!(*Q).front) return 0;
    (*Q).front->next=NULL;return 1;
}
int QueueCSEmpty(LinkQueueCS Q)
{
    if (Q.front==Q.rear) return 1;
    else return 0;
}
int InsertQueueCS(LinkQueueCS *Q,QCSElemType e)
{
    QueueCS p=(QueueCS)malloc(sizeof(QCSNode));
    if (!p) return 0;
    p->data=e;p->next=NULL;
    (*Q).rear->next=p;(*Q).rear=p;
    return 1;
}
int DeleteQueueCS(LinkQueueCS *Q,QCSElemType *e)
{
    QueueCS p;
    if ((*Q).front==(*Q).rear) return 0;
    p=(*Q).front->next;*e=p->data;
    (*Q).front->next=p->next;
    if ((*Q).rear==p) (*Q).rear=(*Q).front;
    free(p);return 1;
}
int InitTree(CSTree *T)
{
    *T=NULL;return 1;
}
void CreateTree(CSTree *T,int degree[],ElemType data[])
{
    int i,j,k;
    CSTree p,q;
    LinkQueueCS Q;
    InitQueueCS(&Q);
    *T=(CSTree)malloc(sizeof(CSNode));
    (*T)->data.degree=degree[0];
    (*T)->data.data=data[0];
    (*T)->firstchild=(*T)->nextsibling=NULL;
    InsertQueueCS(&Q,*T);
    for (i=1;i<7;i++)
    {
        DeleteQueueCS(&Q,&p);
        for (j=1;j<=degree[i];j++)
        {
            q=(CSTree)malloc(sizeof(CSNode));
            q->data.degree=degree[i+j];
            q->data.data=data[i+j];
            q->firstchild=q->nextsibling=NULL;
            if (j==1) p->firstchild=q;
            else k->nextsibling=q;
            k=q;

            InsertQueueCS(&Q,q);
        }
        i=i+degree[i];
    }
}
void PreOrderTraverse(CSTree T)
{
    if (T)
    {
        cout<<T->data.data;
        PreOrderTraverse(T->firstchild);
        PreOrderTraverse(T->nextsibling);
    }
}
int main()
{
    CSTree T;
    int degree[7]={2,3,0,2,0,0,0};
    char data[7]={'A','B','C','D','E','F','G'};
    CreateTree(&T,degree,data);
    PreOrderTraverse(T);
    return 0;
}
