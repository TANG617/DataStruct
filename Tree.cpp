//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include "queue"
#include "vector"
using namespace std;

template<typename DataType>
class NodeType{
public:
    vector<NodeType<DataType>> ChildList;
    DataType Data;
    NodeType() : Data(NULL){}
    NodeType(DataType _Data) : Data(_Data){}
    void getChildNum() {return ChildList.size();}

};

template<typename DataType>
class TreeType {
public:
    NodeType<DataType> Root;
//    int Depth;
    TreeType(NodeType<DataType> RootNode) : Root(RootNode){}
    void Attach(NodeType<DataType> &sourceRoot, NodeType<DataType> &targetParent){
        targetParent.ChildList.push_back(sourceRoot);
//        Depth += sourceRoot
    }
};

int main(){

    NodeType<int> Root;
    NodeType<int> V1 = NodeType<int>(1);
    NodeType<int> V2 = NodeType<int>(2);
    NodeType<int> V3 = NodeType<int>(3);
    NodeType<int> V4 = NodeType<int>(4);
    NodeType<int> V5 = NodeType<int>(5);
    NodeType<int> V6 = NodeType<int>(6);
    TreeType Tree = TreeType<int>(Root);
    Tree.Root.ChildList.push_back(V1);
    Tree.Root.ChildList.push_back(V2);
    Tree.Root.ChildList.push_back(V3);
    Tree.Root.ChildList[0].ChildList.push_back(V4);
    Tree.Root.ChildList[0].ChildList.push_back(V5);
    Tree.Root.ChildList[1].ChildList.push_back(V5);
}