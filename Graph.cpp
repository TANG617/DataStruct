//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include <vector>
using namespace std;

typedef enum {Undiscovered,Discovered,Visited}Vstatus;
typedef enum {Undetermined,Tree,Cross,Forward,Backward}Estatus;



class VertexType{
public:
    int Data;
    int inDegree,outDegree;
    Vstatus Status;
    VertexType(int t_Data):Data(t_Data),inDegree(0),outDegree(0),Status(Undiscovered){}
};

class EdgeType{
public:
    int Data;
    int Weight;
    Estatus Status;
    EdgeType(int t_Data):Data(t_Data),Weight(0),Status(Undetermined){}
};

class Graph{
public:
    int numVertex;
    int numEdge;
    Graph():numVertex(0),numEdge(0){}

};






int main(){
    VertexType<int> V1 = VertexType(1);
    VertexType<int> V2 = VertexType(2);
    VertexType<int> V3 = VertexType(3);

    EdgeType<int> E1 = EdgeType(1);
    EdgeType<int> E2 = EdgeType(2);
    EdgeType<int> E3 = EdgeType(3);

    GraphMatrix M = GraphMatrix<int>();

    M.InsertVertex(V1);
    M.InsertVertex(V2);
    M.InsertVertex(V3);

}