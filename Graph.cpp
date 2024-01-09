//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include <vector>
using namespace std;

typedef enum {Undiscovered,Discovered,Visited}Vstatus;
typedef enum {Undetermined,Tree,Cross,Forward,Backward}Estatus;

template<typename DataType>
class VertexType{
public:
    DataType Data;
    int inDegree,outDegree;
    Vstatus Status;
    VertexType(DataType t_Data):Data(t_Data),inDegree(0),outDegree(0),Status(Undiscovered){}
};

template<typename DataType>
class EdgeType{
public:
    DataType Data;
    int Weight;
    Estatus Status;
    EdgeType(DataType t_Data):Data(t_Data),Weight(0),Status(Undetermined){}
};

class Graph{
public:
    int numVertex;
    int numEdge;
    Graph():numVertex(0),numEdge(0){}

};

template<typename DataType>
class GraphMatrix : public Graph{
private:
    vector<VertexType<DataType>> VertexList;
    vector<vector<EdgeType<DataType>*>> EdgeAdjacencyMatrix;
public:
    GraphMatrix(){}
    void InsertVertex(VertexType<DataType> &_Vertex){
        VertexList.insert(VertexList.end()+1,_Vertex);
//        VertexList.insert()
        for(int i = 0; i<numVertex ;i++) EdgeAdjacencyMatrix[i].insert(EdgeAdjacencyMatrix[i].end(),NULL);
        numVertex ++ ;
        EdgeAdjacencyMatrix.insert(vector<EdgeType<DataType>*>(numVertex,numVertex,(EdgeType<DataType>*)NULL));
    }
    VertexType<DataType> RemoveVertex(int i){
        for(int j=0;j<numVertex;j++){
            delete EdgeAdjacencyMatrix[i][j];
            VertexList[j].inDegree--;
        }
        EdgeAdjacencyMatrix.erase(EdgeAdjacencyMatrix.begin()+i);
        for (int j = 0; j < numVertex; ++j) {
            delete EdgeAdjacencyMatrix[j].erase(EdgeAdjacencyMatrix.begin()+i);
            VertexList[j].outDegree--;
        }
        VertexType<DataType> tempVertex = VertexList(i);
        VertexList.erase(VertexList.begin()+i);
        return tempVertex;
    }

    void InsertEdge(EdgeType<DataType> &_Edge, int i,int j){
        EdgeAdjacencyMatrix[i][j] = _Edge;
        numEdge ++;
        VertexList[i].outDegree++;
        VertexList[j].inDegree++;
    }
    EdgeType<DataType> RemoveEdge(int i,int j){
        EdgeType<DataType> tempEdge = EdgeAdjacencyMatrix(i,j);
        delete EdgeAdjacencyMatrix[i][j];
        EdgeAdjacencyMatrix[i][j] = NULL;
        numEdge --;
        VertexList[i].outDegree--;
        VertexList[j].inDegree--;
        return tempEdge;
    }

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