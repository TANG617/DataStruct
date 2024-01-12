#include<iostream>
#include<stack>

using namespace std;
struct Node
{
    int data;
    Node *Lchild,*Rchild;
};

extern stack<Node> ToBeVisited;
class BTree
{
public:
    Node *CreateNode()
    {
        Node *newNode=new Node;
        int data;
        cin>>data;
        if(data==0)
        {
            return NULL;
        }
        newNode->data=data;
        newNode->Lchild=CreateNode();
        newNode->Rchild=CreateNode();
        return newNode;

    }
    bool isEmptyNode(Node t)
    {
        if(t.Lchild==NULL&&t.Rchild==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    void Visit(Node *t)
    {
        cout<<t->data<<endl;
    }
    Node *rootNode;


};
class BTree_Cycle :public BTree{
public:
    void InOrder(Node t)
    {
        Node ptr=t;
        while(!isEmptyNode(ptr)||!ToBeVisited.empty())
        {
            if(!isEmptyNode(ptr)){
                ToBeVisited.push(ptr);
                ptr=*ptr.Lchild;
            }
            else{
                ToBeVisited.push(ptr);
                Visit(&ptr);
                ptr=*ptr.Rchild;
            }
        }
    }

    void PreOrder(Node t)
    {
        Node ptr=t;
        while(!isEmptyNode(ptr)||!ToBeVisited.empty())
        {
            if(!isEmptyNode(ptr)){
                Visit(&ptr);
                ToBeVisited.push(ptr);
                ptr=*ptr.Lchild;
            }
            else{
                ToBeVisited.pop();
                ptr=*ptr.Rchild;
            }
        }
    }
};

class BTree_Recursive :public BTree
{
    
public:
    
    void PreOrder(Node *t)
    {
        if(t)
        {
            Visit(t);
            PreOrder(t->Lchild);
            PreOrder(t->Rchild);
            
        }
    }
    void InOrder(Node *t)
    {
        if(t)
        {
            InOrder(t->Lchild);
            Visit(t);
            InOrder(t->Rchild);
        }
    }
    void PostOrder(Node *t)
    {
        if(t)
        {
            PostOrder(t->Lchild);
            PostOrder(t->Rchild);
            Visit(t);
        }

    }

    
};









int main()
{
    BTree_Recursive Tree_R;
    Tree_R.rootNode=Tree_R.CreateNode();
    BTree_Cycle Tree_C;


}