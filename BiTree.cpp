//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename DataType>
class NodeType{
public:
    DataType Data;
    NodeType * lChild;
    NodeType * rChild;
    NodeType * firstSibling;
    NodeType * nextSibling;
    NodeType * parent;

    NodeType(){
        this->Data = NULL;
        this->lChild = nullptr;
        this->rChild = nullptr;
        this->firstSibling = nullptr;
        this->nextSibling = nullptr;
        this->parent = nullptr;
    }
    NodeType(DataType Data){
        this->Data = Data;
        this->lChild = nullptr;
        this->rChild = nullptr;
        this->firstSibling = nullptr;
        this->nextSibling = nullptr;
        this->parent = nullptr;
    }

};

template <typename DataType>
class BiTreeType {
public:
    int Depth;
    int numNode;
    BiTreeType():Depth(0),numNode(0) {}
    virtual void Visit(NodeType<DataType> Node){
        cout<<Node.Data<<" ";
    }
};


template <typename DataType>
class BiChildTreeType:public BiTreeType<DataType>{
public:
    NodeType<DataType> Root = NodeType(1);

    NodeType<DataType> N2 = NodeType(2);
    NodeType<DataType> N3 = NodeType(3);
    NodeType<DataType> N4 = NodeType(4);
    NodeType<DataType> N5 = NodeType(5);
    NodeType<DataType> N6 = NodeType(6);

    BiChildTreeType(){
        Root.lChild = &N2;
        Root.rChild = &N3;
        N2.rChild = &N4;
        N4.lChild = &N6;
        N3.rChild = &N5;
    }
    void Visit(NodeType<DataType> Node){
        cout<<Node.Data<<" ";
    }
    void PreOrderTraversal(NodeType<DataType> *node){
        if(node!= nullptr){
            Visit(*node);
            PreOrderTraversal(node->lChild);
            PreOrderTraversal(node->rChild);
        }

    }
    void InOrderTraversal(NodeType<DataType> *node){
        if(node!= nullptr){
            InOrderTraversal(node->lChild);
            Visit(*node);
            InOrderTraversal(node->rChild);
        }

    }
    void PostOrderTraversal(NodeType<DataType> *node){
        if(node!= nullptr){
            PostOrderTraversal(node->lChild);
            PostOrderTraversal(node->rChild);
            Visit(*node);
        }

    }
    void LevelOrderTraversal(){
        NodeType<DataType> *node = &Root;
        queue<NodeType<DataType>> Queue;
        Queue.push(*node);
        while(!Queue.empty()){
            Visit(Queue.front());
            Queue.pop();
            if(node->lChild != nullptr){
                Queue.push(*(node->lChild));
            }
            if(node->rChild != nullptr){
                Queue.push(*(node->rChild));
            }
            node = &Queue.front();
        }

    }

    void PreOrderTraversal(){
        PreOrderTraversal(&Root);
        cout<<endl;
    }
    void InOrderTraversal(){
        InOrderTraversal(&Root);
        cout<<endl;
    }
    void PostOrderTraversal(){
        PostOrderTraversal(&Root);
        cout<<endl;
    }
};


template <typename DataType>
class BiParentTreeType : public BiTreeType<DataType>{
public:

};

template <typename DataType>
class BiSiblingTreeType: public BiTreeType<DataType>{
public:
    NodeType<DataType> Root = NodeType(1);

    NodeType<DataType> N2 = NodeType(2);
    NodeType<DataType> N3 = NodeType(3);
    NodeType<DataType> N4 = NodeType(4);
    NodeType<DataType> N5 = NodeType(5);
    NodeType<DataType> N6 = NodeType(6);
    BiSiblingTreeType() : BiTreeType<DataType>(){
        Root.firstSibling = &N2;
        Root.nextSibling = &N3;
        N2.nextSibling = &N4;
        N4.firstSibling = &N6;
        N3.nextSibling = &N5;
    }

};


int main(){
    BiChildTreeType BiChildTree = BiChildTreeType<int>();
    BiSiblingTreeType BiSiblingTree = BiSiblingTreeType<int>();
//    BiTree.PreOrderTraversal();
//    BiTree.InOrderTraversal();
//    BiTree.PostOrderTraversal();
//    BiTree.LevelOrderTraversal();
}