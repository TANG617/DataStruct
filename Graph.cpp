//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef enum {Undiscovered,Discovered,Visited}Vstatus;
typedef enum {Undetermined,Tree,Cross,Forward,Backward}Estatus;



class VertexType{
public:
    int Data;
    int inDegree,outDegree;
    Vstatus Status;
    VertexType():Data(-1),inDegree(0),outDegree(0),Status(Undiscovered){}
    VertexType(int t_Data):Data(t_Data),inDegree(0),outDegree(0),Status(Undiscovered){}
};

class EdgeType{
public:
    int Data;
    int Weight;
    int FromIndex,ToIndex;
    Estatus Status;
    EdgeType():Data(-1),Weight(0),Status(Undetermined),FromIndex(-1),ToIndex(-1){}
    EdgeType(int _Data,int _From,int _To):Data(_Data),Weight(0),Status(Undetermined),FromIndex(_From),ToIndex(_To){}
};

class GraphType{
public:
    int numVertex;
    int numEdge;
    GraphType():numVertex(0),numEdge(0){}
    VertexType GetFirstVertex(){
    }
    VertexType GetNextVertex(){
    }



};

class GraphAdjacencyMatrix : public GraphType{
private:
    vector<VertexType> VertexList;
    vector<vector<EdgeType>> EdgeMatrix;

public:
    GraphAdjacencyMatrix() {}

    void Push(EdgeType &_Edge){

        EdgeMatrix[_Edge.FromIndex][_Edge.ToIndex] = _Edge;
        numEdge ++;

    }
    void Push(VertexType &_Vertex){
//        VertexList[numVertex] = _Vertex;
        vector<EdgeType> _nullEdgeVec;
        EdgeType _nullEdge;


        for (int i = 0; i < numVertex+1; ++i) {

            _nullEdgeVec.push_back(_nullEdge);
        }
        for(int i = 0;i<numVertex;i++)
        {
            (EdgeMatrix.begin()+i)->push_back(_nullEdge);
        }
        EdgeMatrix.push_back(_nullEdgeVec);

        VertexList.push_back(_Vertex);
        numVertex++;

    }

    void Remove(int FromIndex,int ToIndex){
        EdgeMatrix[FromIndex][ToIndex] = EdgeType();
//        EdgeMatrix[FromIndex][ToIndex].Exist = NotExisted;
    }

    void Remove(int VertexIndex){
        VertexList.erase(VertexList.begin() + VertexIndex);
        for (int i = 0; i < numVertex; ++i) {
            EdgeMatrix[i].erase(EdgeMatrix[i].begin()+VertexIndex);
        }

        EdgeMatrix.erase(EdgeMatrix.begin()+VertexIndex);
        numVertex--;
    }

    void Visit(VertexType _Vertex){
        cout<<_Vertex.Data<<endl;
    }

    void BFS(int RootIndex){
        queue <int> VertexIndexQueue;
        for (int i = 0; i < numVertex; ++i) {
            if(VertexList[i].Status == Undiscovered && EdgeMatrix[RootIndex][i].Data != -1)
            {
                VertexIndexQueue.push(i);


            }
        }
        Visit(VertexList[RootIndex]);
        VertexList[RootIndex].Status = Visited;

        while(!VertexIndexQueue.empty()){
            for (int i = 0; i < numVertex; ++i) {
                if(VertexList[i].Status == Undiscovered && EdgeMatrix[VertexIndexQueue.front()][i].Data != -1)
                {
                    VertexIndexQueue.push(i);

                }

            }
            Visit(VertexList[VertexIndexQueue.front()]);
            VertexList[VertexIndexQueue.front()].Status = Visited;
            VertexIndexQueue.pop();
        }
    }
};

class GraphAdjacencyList : public GraphType{
public:
    vector<vector<VertexType>> AdjacencyList;
    GraphAdjacencyList(){
    }
    void Push(VertexType &_Vertex){
        vector<VertexType> _tempVec;
        _tempVec.push_back(_Vertex);
        AdjacencyList.push_back(_tempVec);
    }

    void Push(EdgeType &_Edge){
        AdjacencyList[_Edge.FromIndex].push_back(AdjacencyList[_Edge.ToIndex][0]);
    }

    //TODO:func remove
};




int main(){
    VertexType V1 = VertexType(1);
    VertexType V2 = VertexType(2);
    VertexType V3 = VertexType(3);

    EdgeType E1 = EdgeType(1,0,1);
    EdgeType E2 = EdgeType(2,1,2);
    EdgeType E3 = EdgeType(3,2,0);

//    GraphAdjacencyMatrix M = GraphAdjacencyMatrix();
    GraphAdjacencyList M = GraphAdjacencyList();
    M.Push(V1);
    M.Push(V2);
    M.Push(V3);

    M.Push(E1);
    M.Push(E2);
    M.Push(E3);
//
//    M.Remove(2);
//    M.Remove(0,1);

}