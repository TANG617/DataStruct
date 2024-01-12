#include <iostream>
using namespace std;
#define MVNUM 100				
#define MAXINT 32767				
 
int visited[MVNUM] = { 0 };			
int visit[MVNUM] = { 0 };			

typedef struct
{
	char vexs[MVNUM];			
	int arr[MVNUM][MVNUM];			
	int vexnum, arcnum;			
}AMGraph;							
typedef struct
{
	int* base;				
	int front;				
	int rear;				
}sqQueue;
 
int initGraph(AMGraph& G);			
void showGraph(AMGraph G);			
int locatVex(AMGraph G, char u);		//定位顶点在邻接矩阵的下标
int createGraph(AMGraph& G);			
void dfsAM(AMGraph G,int i);			//深度优先搜索遍历
void bfsAM(AMGraph G, int i);			//广度优先搜索遍历
int initQueue(sqQueue& Q);			
int enQueue(sqQueue& Q, int i);			
int firstVEX(AMGraph G, int u);				
int nextVEX(AMGraph G,int w ,int u);	


int initGraph(AMGraph& G)
{
	cout << "please input the VEXnum and EDGEnum!" << endl;
	cin >> G.vexnum >> G.arcnum;			
	cout << "please input data of VEX!" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >>G.vexs[i];			
	}
	
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arr[i][j] = MAXINT;		//邻接矩阵的初值都为无穷大
		}	
	}
		
	return 1;
}
void showGraph(AMGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.arr[i][j] == MAXINT)	
				cout << "∞" << " ";
			else
				cout << " " << G.arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
 
int locateVex(AMGraph G, char u)
{
	for (int i = 0; i < G.vexnum; i++)	
	{
		if (u == G.vexs[i])			//如果u的值和顶点数据匹配，就返回顶点在矩阵中的下标
			return i;
	}
	return -1;
}
 
int createGraph(AMGraph& G)
{
	int i = 0; int j = 0;int w = 0;			//i,j代表顶点下标,w代表权值
	char v1 = 0; char v2 = 0;			    //v1,v2为顶点数据
	cout << "please input w of v1 to v2 in graph!" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;			
		i = locateVex(G, v1);			//找到v1在顶点表的下标，并返回赋值给i
		j = locateVex(G, v2);
		G.arr[i][j] = w;
		G.arr[j][i] = G.arr[i][j];		//无向图的矩阵是对称矩阵
	}
 
	cout << endl;
	return 1;
}
 
void dfsAM(AMGraph G, int i)
{//随机选一个顶点下标，这里为0
	cout << G.vexs[i]<<" ";			//输出0下标在顶点表的值	
	visited[i] = 1;				//辅助数组对应下标i的值置为1
	for (int j = 0; j < G.vexnum; j++)
	{
		if (G.arr[i][j] != MAXINT && (!visited[j]))	//只要是邻接的顶点并且没有访问过
		{						//不然就退回，也是递归结束条件
			dfsAM(G, j);				//递归使用函数
		}
	}
}
int initQueue(sqQueue& Q)
{
	Q.base = (int *)malloc(sizeof(int) * MVNUM);	
	Q.front = Q.rear = 0;	//队头和对尾下标都置为0
	return 1;
}
int enQueue(sqQueue& Q, int i)
{
	if ((Q.rear + 1) % MVNUM == Q.front)			//队满
		return 0;
	Q.base[Q.rear] = i;					//先赋值再加
	Q.rear = (Q.rear + 1) % MVNUM;
	return 1;
}
 
int deQueue(sqQueue& Q, int &u)
{
	if (Q.rear == Q.front)					
		return 0;
	u = Q.base[Q.front];					//要删的值给u然后再加
	Q.front = (Q.front + 1) % MVNUM;
	return 1;
}
 
int firstVEX(AMGraph G, int u)
{

	for (int i = 0; i < G.vexnum; i++)		
	{
		if (G.arr[u][i] != MAXINT && visit[i] == 0) 
		{
			return i;
		}
	}
	return MAXINT;
}
 
int nextVEX(AMGraph G, int w, int u)
{//在邻接矩阵u行w+1列开始遍历，如果找到不等于无穷的，
//并且没有访问过的就返回列的下标，否则就返回无穷
	for (int i = w + 1; i < G.vexnum; i++)
	{
		if (G.arr[u][i] != MAXINT && visit[i] == 0)
		{
			return i;
		}	
	}
	return MAXINT;
}
 
void bfsAM(AMGraph G, int i)
{//随机选一个顶点下标，这里为0
	cout << G.vexs[i] << " ";		//输出i下标在顶点表的值	
	visit[i] = 1;				//辅助数值对应下标i的值置为1
	sqQueue Q;					
	initQueue(Q);
	enQueue(Q, i);				//i为矩阵中顶点的行下标，让它入队(顶点表的下标和矩阵的列下标，行下标一致，本算法中说谁的下标都一样)
	while (Q.rear != Q.front)		//队不为空
	{
		int u = 0;			//接收矩阵中顶点的行下标，因为是邻接矩阵
		deQueue(Q,u);			//出队并让u接收矩阵中顶点的行下标
		for (int w = firstVEX(G, u); w != MAXINT; w = nextVEX(G, w, u))
		{//注意在一次循环中u不变
			if (!visit[w])
			{
				cout << G.vexs[w] << " ";
				visit[w] = 1;
				enQueue(Q, w);
			}
		}
	}
	
}

 
int main()
{
	AMGraph G;							
	initGraph(G);
	createGraph(G);
	showGraph(G);
	cout << "the result of dfs is:";
	dfsAM(G,0);
	cout << endl;
	cout << "the result of bfs is:";
	bfsAM(G,0);
}
