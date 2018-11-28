#ifndef graph_
#define graph_

#include"myNamespace.h"

#define N_matrix 100		//�ڽӾ�����������+1
#define N_list 100			//�ڽӱ���������+1
#define N_queue 50			//ѭ�����еĴ�С����
#define N_road 500			//ͼ�бߣ���������������
#define CON_Y 1
#define CON_SELF 0
#define CON_N -1
#define F_END -1	//�ļ������β��־

typedef char V_type;
typedef float Value_Type;

typedef struct VertexType {	//����
	int no;//������
	V_type info;//������Ϣ���綥������Ϊ��A��
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



void printErrorAndExit(const string &str);
void Create_MGraph(MGraph *&mgraph, const string &str);
void Print_MGraph_Matrix(MGraph *mgraph);
void Create_AGraph(AGraph *&agraph, const string &str);
void Print_AGraph_Matrix(AGraph *mgraph);

#endif // !graph_
