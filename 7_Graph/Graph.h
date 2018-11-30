#ifndef graph_
#define graph_

#include"myNamespace.h"

#define N_matrix 100		//邻接矩阵行数上限+1
#define N_list 100			//邻接表行数上限+1
#define N_queue 50			//循环队列的大小上限
#define N_road 500			//图中边（弧）数量的上限
#define CON_Y 1
#define CON_SELF 0		//自己到自己
#define CON_N -1	//无边连接
#define Infinity_big 9999
#define F_END -1	//文件链表结尾标志

typedef char Info_type;
typedef float Value_Type;

typedef struct VertexType {	//顶点
	int no;//顶点编号
	Info_type info;//顶点信息，如顶点名称为‘A’
}VertexType;

typedef struct MGraph {//图的邻接矩阵表示
	VertexType vertex[N_matrix];//图所包含的顶点
	int num_node;				//图中顶点个=总数
	Value_Type edge[N_matrix][N_matrix];//图所包含的边(弧)的权值
	int num_edge;				//图中边（弧）总数
}MGraph;

typedef struct Arc {//图的邻接表中的弧（边）
	VertexType adjvex;//弧头（所指向的顶点）
	Value_Type weight;//弧（边）的权值
	struct Arc *next;//下一条弧（边）
}Arc;

typedef struct A_Head {//图的邻接表中的头顶点
	VertexType ver_head;//链表的头顶点的信息
	struct Arc *first;//指向下一条弧（边）
}A_Head;

typedef struct AGraph {//图的邻接表表示
	A_Head adjlist[N_list];//顶点表
	int num_node;//图中顶点总数
	int num_edge;//图中弧（边）总数
}AGraph;

typedef struct Road {
	int begin;//边的起始点
	int end;	//边的终点
	Value_Type weight;	//边的权值
}Road;

void printErrorAndExit(const string &str);
void Create_MGraph(MGraph *&mgraph, const string &str);
void Print_MGraph_Matrix(MGraph *mgraph);
void Create_AGraph(AGraph *&agraph, const string &str);
void Print_AGraph_Matrix(AGraph *mgraph);
void DFS(AGraph *agraph, int vertex, bool have_visited[]);
void DFS2(AGraph *agraph, int vertex);
void BFS(AGraph *agraph, int vertex, bool have_visited[]);
int BFS_far(AGraph *agraph, int vertex);
void DFS_NC(AGraph *agraph);
void BFS_NC(AGraph *agraph);
void DFS_istree(AGraph *agraph, int vertex, bool have_visited[], int &vn, int &en);
void Graph_istree(AGraph *agraph);
void BFS_Min_Distance(AGraph *agraph, int vertex);
Value_Type Prim(MGraph *mgraph, int v0);
int sort_edge(Road road[], MGraph *mgraph);
int getRoot(int a, int root[]);
void Kruskal(MGraph *mgraph);
void Dijstra(MGraph *mgraph, int v0, Value_Type cost[], int pre[]);
void Print_Dijstra(int obj, int pre[]);
void Dijstra_call(MGraph *mgraph, int v0, int obj);
void Floyd(MGraph *mgraph, int path[][N_matrix], Value_Type cost[][N_matrix]);
void Print_Floyd(int beg, int end, int path[][N_matrix]);
void Floyd_call(MGraph *mgraph, int beg, int end);
bool Top_Sort(AGraph *agraph, int sorted[]);

#endif // !graph_
