#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *L,*R;
};

void createChild(Node *father,int degree)
{
    Node firstChild;
    firstChild.L=fat;
    Node *temp=father;

    //wider
    for (int i = 1; i < degree; i++)
    {
        temp->R=new Node;
        cin>>temp->data;
        temp=temp->R;
    }
    temp->R=nullptr;
    
}
void createLevel(Node *firstNode)
{
    Node *cursorNode=firstNode;
    while(cursorNode->R!=nullptr)
    {
        int nextDegree;
        cin>>nextDegree;
        createChild(cursorNode,nextDegree);
        cursorNode=cursorNode->R;
    }
}



int main()
{
    

}