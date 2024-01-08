//
// Created by 李唐 on 2024/1/8.
//

#include "iostream"
using namespace std;

template <typename DataType> class NodeType{
public:    
    DataType Data;
    NodeType * prevNode;
    NodeType * nextNode;
    NodeType(){
        this->Data = NULL;
        this->prevNode = nullptr;
        this->nextNode = nullptr;
    }

    NodeType(DataType Data){
        this->Data = Data;
        this->prevNode = nullptr;
        this->nextNode = nullptr;
    }


};

template<typename DataType> class NodeListType{
public:
    NodeType<DataType> HeadNode, TailNode;
    int Size = 0;
//    NodeType<DataType> cursorNode;

    NodeListType(NodeType<DataType>  &RootNode){
        HeadNode = RootNode;
        TailNode = RootNode;
//        HeadNode.nextNode = &TailNode;
//        TailNode.prevNode = &HeadNode;
//        cursorNode = HeadNode;
    }


    void HeadInsert(NodeType<DataType>  &Node){
        this->Size++;
        HeadNode.nextNode->prevNode = &Node;
        Node.nextNode = HeadNode.nextNode;
        HeadNode.nextNode = &Node;
        Node.prevNode = &HeadNode;
    }

    void TailInsert(NodeType<DataType>  &Node){
        this->Size++;
        if(Size == 1) HeadNode.nextNode = &Node;
        TailNode.nextNode = &Node;
        Node.prevNode = &TailNode;
        TailNode = Node;
    }

    void Traversal() {
        NodeType<DataType> cursor = HeadNode;
        while(cursor.nextNode != nullptr){
            cout<<cursor.Data<<endl;
            cursor = *cursor.nextNode;
        }
    }

    NodeType<DataType> Search(NodeType<DataType>  &Node){

    }
};
int main()
{
    NodeType RootNode = NodeType<int>(1);
    NodeType NewNode2 = NodeType<int>(2);
    NodeType NewNode3 = NodeType<int>(3);
    NodeListType NodeList = NodeListType<int>(RootNode);
    NodeList.TailInsert(NewNode2);
    NodeList.TailInsert(NewNode3);
    NodeList.Traversal();
}
