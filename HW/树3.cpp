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
	Point P[20];
	int num=strlen(data);
	for (int i=1; i<=num; ++i)
	{
		P[i].data=data[i-1];
		P[i].degree=degree[i-1];	
	}
	CSTree p,p1;
	LinkQueueCS q;
	InitQueueCS(&q);
	int record=0;
	if (num)
	{
		*T=(CSTree)malloc(sizeof(CSNode));
		(*T)->data=P[1];
		(*T)->nextsibling=NULL;
		InsertQueueCS(&q,*T);
		record=1;
		while (!QueueCSEmpty(q))
		{
			DeleteQueueCS(&q,&p);
			if ((p->data).degree>0)
			{
				p1=p->firstchild=(CSTree)malloc(sizeof(CSNode));
				p1->data=P[++record];
				for (int i=1; i<(p->data).degree; ++i)
				{
					p1->nextsibling=(CSTree)malloc(sizeof(CSNode));
					InsertQueueCS(&q,p1);
					p1=p1->nextsibling;
					p1->data=P[++record];	
				}
				p1->nextsibling=NULL;
				InsertQueueCS(&q,p1);
			}
			else p->firstchild=NULL;
		}
	}
	else *T=NULL;
}
int TreeCSDepth(CSTree T)
{
	int depthval,h1,h2;
	if (!T) return depthval=0;
	h1=TreeCSDepth(T->firstchild);
	h2=TreeCSDepth(T->nextsibling);
	return depthval=h1+1>h2?h1+1:h2;	
}
int visit(ElemType e)
{
	printf("%c",e);return 1;	
}
int main()
{
	// 8
	// 3 2 1 0 0 1 0 0
	// abcdefgh
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	scanf("%s",b);
	CSTree CST;
	InitTree(&CST);
	CreateTree(&CST,a,b);
	printf("%d",TreeCSDepth(CST)); 
}
