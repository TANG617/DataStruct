//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
//        cout<<_Vertex.Data<<endl;
        printf("%c\n",_Vertex.Data);
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
            if (VertexList[VertexIndexQueue.front()].Status == Undiscovered){
                Visit(VertexList[VertexIndexQueue.front()]);
                VertexList[VertexIndexQueue.front()].Status = Visited;

            }
            for (int i = 0; i < numVertex; ++i) {
                if(VertexList[i].Status == Undiscovered && EdgeMatrix[VertexIndexQueue.front()][i].Data != -1)
                {
                    VertexIndexQueue.push(i);

                }

            }
            VertexIndexQueue.pop();

        }
    }

    void DFS(int RootIndex){
        stack <int> VertexIndexStack;
        VertexIndexStack.push(RootIndex);
        while(!VertexIndexStack.empty()){
            if (VertexList[VertexIndexStack.top()].Status == Discovered){
                Visit(VertexList[VertexIndexStack.top()]);
                VertexList[VertexIndexStack.top()].Status = Visited;
                VertexIndexStack.pop();
            }
            for (int i = 0; i < numVertex; ++i) {
                if(EdgeMatrix[VertexIndexStack.top()][i].Data != -1 && VertexList[i].Status == Undiscovered)
                {
                    VertexIndexStack.push(i);
                    VertexList[i].Status = Discovered;
                }
            }

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
    GraphAdjacencyMatrix M = GraphAdjacencyMatrix();
//    GraphAdjacencyList M = GraphAdjacencyList();

    VertexType VA = VertexType('A'); // 0
    VertexType VB = VertexType('B'); // 1
    VertexType VC = VertexType('C'); // 2
    VertexType VD = VertexType('D'); // 3
    VertexType VE = VertexType('E'); // 4
    VertexType VF = VertexType('F'); // 5
    VertexType VG = VertexType('G'); // 6
    VertexType VH = VertexType('H'); // 7
    VertexType VI = VertexType('I'); // 8
    VertexType VJ = VertexType('J'); // 9
    VertexType VK = VertexType('K'); // 10
    VertexType VL = VertexType('L'); // 11
    VertexType VM = VertexType('M'); // 12
    VertexType VN = VertexType('N'); // 13
    VertexType VO = VertexType('O'); // 14

    M.Push(VA);
    M.Push(VB);
    M.Push(VC);
    M.Push(VD);
    M.Push(VE);
    M.Push(VF);
    M.Push(VG);
    M.Push(VH);
    M.Push(VI);
    M.Push(VJ);
    M.Push(VK);
    M.Push(VL);
    M.Push(VM);
    M.Push(VN);
    M.Push(VO);

// 创建并添加24条边
    EdgeType E0 = EdgeType(1, 0, 1);
    EdgeType E1 = EdgeType(1, 0, 2);
    EdgeType E2 = EdgeType(1, 1, 3);
    EdgeType E3 = EdgeType(1, 1, 4);
    EdgeType E4 = EdgeType(1, 2, 5);
    EdgeType E5 = EdgeType(1, 2, 6);
    EdgeType E6 = EdgeType(1, 3, 7);
    EdgeType E7 = EdgeType(1, 3, 8);
    EdgeType E8 = EdgeType(1, 4, 9);
    EdgeType E9 = EdgeType(1, 4, 10);
    EdgeType E10 = EdgeType(1, 4, 11);
    EdgeType E11 = EdgeType(1, 5, 12);
    EdgeType E12 = EdgeType(1, 6, 13);
    EdgeType E13 = EdgeType(1, 6, 14);
//    EdgeType E14 = EdgeType(1, 14, 0);
//    EdgeType E15 = EdgeType(1, 0, 2);
//    EdgeType E16 = EdgeType(1, 1, 3);
//    EdgeType E17 = EdgeType(1, 2, 4);
//    EdgeType E18 = EdgeType(1, 3, 5);
//    EdgeType E19 = EdgeType(1, 4, 6);
//    EdgeType E20 = EdgeType(1, 5, 7); // F -> H
//    EdgeType E21 = EdgeType(1, 6, 8); // G -> I
//    EdgeType E22 = EdgeType(1, 7, 9); // H -> J
//    EdgeType E23 = EdgeType(1, 8, 10); // I -> K

    M.Push(E0);
    M.Push(E1);
    M.Push(E2);
    M.Push(E3);
    M.Push(E4);
    M.Push(E5);
    M.Push(E6);
    M.Push(E7);
    M.Push(E8);
    M.Push(E9);
    M.Push(E10);
    M.Push(E11);
    M.Push(E12);
    M.Push(E13);
//    M.Push(E14);
//    M.Push(E15);
//    M.Push(E16);
//    M.Push(E17);
//    M.Push(E18);
//    M.Push(E19);
//    M.Push(E20);
//    M.Push(E21);
//    M.Push(E22);
//    M.Push(E23);

    M.DFS(0);
//
//    M.Remove(2);
//    M.Remove(0,1);

}