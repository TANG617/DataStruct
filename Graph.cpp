//
// Created by 李唐 on 2024/1/8.
//
typedef enum {Undiscovered,Discovered,Visited}Vstatus;
typedef enum {Undetermined,Tree,Cross,Forward,Backward}Estatus;

template<typename DataType>
class VertexType{
public:
    DataType Data;
    int inDegree,outDegree;
    Vstatus Status;
    VertexType(DataType _Data):Data(_Data),inDegree(0),outDegree(0),Status(Undiscovered){}
};

template<typename DataType>
class EdgeType{
    DataType Data;
    int Weight;
    Estatus Status;
    EdgeType(DataType _Data):Data(_Data),Weight(0),Status(Undetermined){}
};

class Graph{
private:
    void Reset(){
    }
public:
    int numVertex;
    int numEdge;

};

int main(){
    VertexType<int> Vertex = VertexType(1);
}