#ifndef graph_
#define graph_

#include"myNamespace.h"

#define N_matrix 100		//�ڽӾ�����������+1
#define N_list 100			//�ڽӱ���������+1
#define N_queue 50			//ѭ�����еĴ�С����
#define N_road 500			//ͼ�бߣ���������������
#define CON_Y 1
#define CON_SELF 0		//�Լ����Լ�
#define CON_N -1	//�ޱ�����
#define Infinity_big 9999
#define F_END -1	//�ļ������β��־

typedef char Info_type;
typedef float Value_Type;

typedef struct VertexType {	//����
	int no;//������
	Info_type info;//������Ϣ���綥������Ϊ��A��
}VertexType;

typedef struct MGraph {//ͼ���ڽӾ����ʾ
	VertexType vertex[N_matrix];//ͼ�������Ķ���
	int num_node;				//ͼ�ж����=����
	Value_Type edge[N_matrix][N_matrix];//ͼ�������ı�(��)��Ȩֵ
	int num_edge;				//ͼ�бߣ���������
}MGraph;

typedef struct Arc {//ͼ���ڽӱ��еĻ����ߣ�
	VertexType adjvex;//��ͷ����ָ��Ķ��㣩
	Value_Type weight;//�����ߣ���Ȩֵ
	struct Arc *next;//��һ�������ߣ�
}Arc;

typedef struct A_Head {//ͼ���ڽӱ��е�ͷ����
	VertexType ver_head;//�����ͷ�������Ϣ
	struct Arc *first;//ָ����һ�������ߣ�
}A_Head;

typedef struct AGraph {//ͼ���ڽӱ��ʾ
	A_Head adjlist[N_list];//�����
	int num_node;//ͼ�ж�������
	int num_edge;//ͼ�л����ߣ�����
}AGraph;

typedef struct Road {
	int begin;//�ߵ���ʼ��
	int end;	//�ߵ��յ�
	Value_Type weight;	//�ߵ�Ȩֵ
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
bool TopSort_Critical(AGraph *agraph, Value_Type ve[], int stack2[], int &top);
Value_Type max_ve(Value_Type ve[], int n);
void Critical_Path(AGraph *agraph);

#endif // !graph_
