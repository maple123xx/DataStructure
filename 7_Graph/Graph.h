#ifndef graph_
#define graph_

#include"myNamespace.h"

#define N_matrix 100		//邻接矩阵行数上限+1
#define N_list 100			//邻接表行数上限+1
#define N_queue 50			//循环队列的大小上限
#define N_road 500			//图中边（弧）数量的上限
#define CON_Y 1
#define CON_SELF 0
#define CON_N -1
#define F_END -1	//文件链表结尾标志

typedef char V_type;
typedef float Value_Type;

typedef struct VertexType {	//顶点
	int no;//顶点编号
	V_type info;//顶点信息，如顶点名称为‘A’
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



void printErrorAndExit(const string &str);
void Create_MGraph(MGraph *&mgraph, const string &str);
void Print_MGraph_Matrix(MGraph *mgraph);
void Create_AGraph(AGraph *&agraph, const string &str);
void Print_AGraph_Matrix(AGraph *mgraph);

#endif // !graph_
