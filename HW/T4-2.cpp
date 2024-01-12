#include<iostream> 
using  namespace std; 

#define MAXVEX  100 
#define INFINITY   65535
typedef  int EdgeType; 
typedef  char VertexType;

int visited[MAXVEX] = { 0 };     //辅助数组
 
void dfsAM(EdgeType G, int i)
{//随机选一个顶点下标，这里为0
	cout << G.vexs[i]<<" ";		//输出0下标在顶点表的值	
	visited[i] = 1;				//辅助数组对应下标i的值置为1
	for (int j = 0; j < G.vexnum; j++)
	{
		if (G.arr[i][j] != MAXINT && (!visited[j]))	//只要是邻接的顶点并且没有访问过
		{											//不然就退回，也是递归结束条件
			dfsAM(G, j);							//递归使用函数
        }
	}
}


typedef  struct 
{ 
    VertexType vexs[MAXVEX]; /* 顶点表 */ 
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵，可看作边表 */ 
    int numNodes, numEdges; /* 图中当前的顶点数和边数  */ 
} MGraph; 
/* 建立无向网图的邻接矩阵表示 */ 
void CreateMGraph(MGraph *Gp) 
{ 
     int i, j, k, w; 
    cout <<  "请输入顶点数和边数（空格分隔）：" << endl; 
    cin >> Gp->numNodes >> Gp->numEdges; 
    cout <<  "请输入顶点信息（空格分隔）：" << endl; 
     for (i =  0; i < Gp->numNodes; i++) 
        cin >> Gp->vexs[i]; 
     for (i =  0; i < Gp->numNodes; i++) 
    { 
         for (j =  0; j < Gp->numNodes; j++) 
        { 
             if (i == j) 
                Gp->arc[i][j] =  0; /* 顶点没有到自己的边*/ 
             else 
                Gp->arc[i][j] = INFINITY; /* 邻接矩阵初始化 */ 
        } 
    } 

     for (k =  0; k < Gp->numEdges; k++) 
    { 
        cout <<  "请输入边（vi, vj)的上标i，下标j和权值w（空格分隔）:" << endl; 
        cin >> i >> j >> w; 
        Gp->arc[i][j] = w; 
        Gp->arc[j][i] = Gp->arc[i][j]; /* 因为是无向图，矩阵对称 */ 
    } 
} 

int main( void) 
{ 
    MGraph MG; 
    CreateMGraph(&MG); 

     return  0; 
}
