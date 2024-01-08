//
// Created by 李唐 on 2024/1/8.
//

#include "iostream"
using namespace std;

template <typename DataType>
class NodeType{
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

template<typename DataType>
class NodeListType{
public:
    NodeType<DataType> *headNode, *tailNode;
    int Size = 1;

    NodeListType(NodeType<DataType>  &RootNode){
        headNode = &RootNode;
        tailNode = &RootNode;
    }


    void HeadInsert(NodeType<DataType>  &Node){
        Node.prevNode = headNode;
        Node.nextNode = headNode->nextNode;

        if(headNode->nextNode!= nullptr) headNode->nextNode->prevNode = &Node;
        headNode->nextNode = &Node;
        Size++;
    }

    void TailInsert(NodeType<DataType>  &Node){
        Node.prevNode = tailNode;
        tailNode->nextNode = &Node;
        tailNode = &Node;
        Size++;
    }

    NodeType<DataType>* index(int i){
        NodeType<DataType> *cursor = headNode;
        int index = 0;
        if(index == i) return cursor;
        do{
            cursor = cursor->nextNode;
            index++;
            if(index == i) return cursor;
        }while(cursor->nextNode != nullptr);
        return nullptr;
    }

    void Detele(int i){
        NodeType<DataType> *deleteNode = this->index(i);
        if(deleteNode != nullptr){
            if(deleteNode->nextNode != nullptr){
                deleteNode->nextNode->prevNode = deleteNode->prevNode;
            }
            else{
                tailNode = deleteNode->prevNode;
            }

            if(deleteNode->prevNode != nullptr){
                deleteNode->prevNode->nextNode = deleteNode->nextNode;
            }
            else{
                headNode = deleteNode->nextNode;
            }
            Size--;
        }
    }
    void Detele(NodeType<DataType> *node){
        NodeType<DataType> *deleteNode = node;
        if(deleteNode != nullptr){
            if(deleteNode->nextNode != nullptr){
                deleteNode->nextNode->prevNode = deleteNode->prevNode;
            }
            else{
                tailNode = deleteNode->prevNode;
            }

            if(deleteNode->prevNode != nullptr){
                deleteNode->prevNode->nextNode = deleteNode->nextNode;
            }
            else{
                headNode = deleteNode->nextNode;
            }
            Size--;
        }
    }

    void Traversal() {
        NodeType<DataType> *cursor = headNode;
        cout<<cursor->Data<<endl;
        do{
            cursor = cursor->nextNode;
            cout<<cursor->Data<<endl;
        }while(cursor->nextNode != nullptr);
    }

    NodeType<DataType> Search(NodeType<DataType>  &Node){

    }
};

template<typename DataType>
class StackType : public NodeListType<DataType>{
public:
    NodeType<DataType> *top,*bottom;
    StackType(NodeType<DataType>& RootNode) : NodeListType<DataType>(RootNode) {
        top = this->tailNode;
        bottom = this->tailNode;
    }

    NodeType<DataType> *pop(){
        NodeType<DataType> *temp;
        temp = top;
        this->Detele(top);
        return temp;
    }

    void Push(NodeType<DataType> &Node){
        this->TailInsert(Node);
        top = &Node;
    }
};

template<typename DataType>
class QueueType : public NodeListType<DataType>{
public:
    NodeType<DataType> *front,*rear;
    QueueType(NodeType<DataType> & RootNode) : NodeListType<DataType>(RootNode){
        front = this->headNode;
        rear = this->tailNode;
    }

    void Enter(NodeType<DataType> & Node){
        this->TailInsert(Node);
        rear = &Node;
    }

    NodeType<DataType> Exit(){
        NodeType<DataType> *temp;
        temp = front;
        this->Detele(front);
        return temp;
    }
};
//TODO:String
template<typename DataType>
class StringType : public NodeListType<DataType> {
public:
};

int main()
{
    NodeType RootNode = NodeType<int>(1);
    NodeType NewNode2 = NodeType<int>(2);
    NodeType NewNode3 = NodeType<int>(3);
//    NodeListType NodeList = NodeListType<int>(RootNode);
//    NodeList.TailInsert(NewNode2);
//    NodeList.TailInsert(NewNode3);
//    NodeList.Traversal();
//    cout<<NodeList.index(2)->Data;
//    cout<<endl;
//    NodeList.Detele(0);
//    NodeList.Traversal();

    StackType Stack = StackType<int>(RootNode);
    Stack.Push(NewNode2);
//    cout<<endl<<Stack.pop()->Data<<endl<<endl;
    Stack.Push(NewNode3);
    cout<<"Size"<<Stack.Size<<endl;
    Stack.Traversal();
}
