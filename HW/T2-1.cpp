#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
// queue<BiTreeNode> VistQueue;
//  Not necessary for Queue
struct BiTreeNode{
    int data;
    bool visited;
    BiTreeNode *Lchild,*Rchild;

};

class Recursive 
{

    public:
        BiTreeNode BiTree;
        void PreOrder(BiTreeNode Node)
        {
            if(BiTree.Lchild!=NULL || BiTree.Rchild!=NULL)
            {
                Vist(&Node);
                PreOrder(*Node.Lchild);
                PreOrder(*Node.Rchild);
            }
        }
        void InOrder(BiTreeNode Node)
        {
            if(BiTree.Lchild!=NULL || BiTree.Rchild!=NULL)
            {
                InOrder(*Node.Lchild);
                Vist(&Node);
                InOrder(*Node.Rchild);
            }
        }
        void PostOrder(BiTreeNode Node)
        {
            if(BiTree.Lchild!=NULL || BiTree.Rchild!=NULL)
            {
                PostOrder(*Node.Lchild);
                PostOrder(*Node.Rchild);
                Vist(&Node);
            }
        }
};

Recursive abc;
abc.preorder



void AddLeftNode(BiTreeNode &FatherNode,int data)
{
    BiTreeNode *Child;
    Child=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    
}
void Vist(BiTreeNode *NodeToVisit)
{
    NodeToVisit->visited=1;
    Operation(*NodeToVisit);
}

void Operation(BiTreeNode Node)
{

}

int main()
{

}