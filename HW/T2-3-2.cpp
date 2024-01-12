#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *L,*R;
    int sub_degree;
};
//Example Data:
// R 3 A 2 B 0 C 1 D 0 E 0 F 3 G 0 H 0 K 0

Node* CreateFirstChild(Node *father,int data)
{
    Node *firstNode = new Node;
    father->L=firstNode;
    firstNode->data=data;
    return firstNode;

}
Node* CreateBrother(Node *priorNode,int data)
{
    Node *nextNode=new Node;
    priorNode->R=nextNode;
    nextNode->data=data;
    return nextNode;
}
void CreateSubTree(Node *rootNode)//创建一个节点的所有子结点
{
    while(1)
    {
        // char rootValue='\0';
        // int rootDegree=0;
        // cin>>rootValue>>rootDegree;
        Node *TEMP;
        TEMP = CreateFirstChild(rootNode,rootValue);
        for (int i = 0; i < rootDegree-1; i++)
        {
            char brotherValue;
            cin>>brotherValue;
            TEMP=CreateBrother(TEMP,brotherValue);
        }
        TEMP->R=nullptr;
    }
}
void LevelOrder(Node *rootNode)
{
    Node *TEMP=rootNode;
    while(TEMP->R!=nullptr)
    {   
        // Visit(TEMP);
        char newValue;
        int newDegree;
        cin>>newValue>>newDegree;



        TEMP=TEMP->R;
    }
}

int main()
{

    
}