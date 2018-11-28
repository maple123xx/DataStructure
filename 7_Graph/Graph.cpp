#include"Graph.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
void Create_MGraph(MGraph *&mgraph, const string &str) {
	//由距离矩阵建立邻接矩阵表示的图
	//文件的第一个数据是图中顶点总数
	//接下来是顶点的编号与名称信息（从1开始编号）
	//接下来是距离矩阵，有连接则为正值，自己到自己的距离为0，无连接则为-1
	//注意：若是无向图，则依此函数计算后，边的总数为实际数量的2倍
	try
	{
		int i, j;
		Value_Type k;	//边权值
		ifstream ins(str);
		if (!ins) { throw exception(); }
		mgraph->num_edge = 0;//初始化弧（边）的数量为0
		ins >> mgraph->num_node;//读第一行，代表节点个数
		if (mgraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= mgraph->num_node; ++i) {
			ins >> mgraph->vertex[i].info;
			ins >> mgraph->vertex[i].no;
		}
		for (i = 1; i <= mgraph->num_node; ++i) {
			for (j = 1; j <= mgraph->num_node; ++j) {
				ins >> k;
				if (k > CON_SELF && i != j) {//有连接时
					mgraph->edge[i][j]=k;
					++mgraph->num_edge;//边数加1
				}
				else if(i==j)			//到自己的距离为0
				{
					mgraph->edge[i][j] = CON_SELF;
				}
				else                  //无连接
				{
					mgraph->edge[i][j] = CON_N;
				}
			}
		}
	}
	catch (...)
	{
		printErrorAndExit("Create_MGraph");
	}
}
void Print_MGraph_Matrix(MGraph *mgraph) {//由MGraph类型参数打印邻接矩阵表示的图
	int i, j;
	cout << "图中的顶点及其编号为：" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		cout << mgraph->vertex[i].info << ":" << mgraph->vertex[i].no << '\t';
	}
	cout << endl << "图中的弧（边）共有" << mgraph->num_edge << "条，距离矩阵如下：" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		for (j = 1; j <= mgraph->num_node; ++j) {
			cout.width(6);
			cout << mgraph->edge[i][j];
		}
		cout << endl;
	}
}
void Create_AGraph(AGraph *&agraph, const string &str) {
	//由邻接表类型的文件建立图的邻接表
	//文件的第一个数据为结点总数num_node
	//文件的第2行是顶点信息，如名称'A'，（默认编号从1开始递增）
	//文件的第3行到第num_node+2行均为链表，每个链表的第一个数据是弧尾顶点的序号，其余数据是弧头顶点的序号以及弧的权重，最后一个数据为-1，表示链表结束
	//例如：6,5,7.2,8,3.6,3,10.8,-1——表示三条弧(6,5,7.2),(6,8,3.6),(6,3,10.8)
	//从1开始编号
	//若为无向图，则num_edge为实际值的两倍
	try
	{
		int i, k;
		Arc *p;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		agraph->num_edge = 0;//初始化弧（边）数量为0
		ins >> agraph->num_node;
		if (agraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= agraph->num_node; ++i) {
			agraph->adjlist[i].ver_head.no = i;//令第i个链表的头顶点的序号为i
			ins >> agraph->adjlist[i].ver_head.info;//从1～agraph->num_node依次读取顶点信息，如名称‘A’
			agraph->adjlist[i].first = NULL;//重要
		}
		for (i = 1; i <= agraph->num_node; ++i) {
			ins >> k;
			if (i != k) {
				cout << "文件格式有误，链表的头顶点应该从1开始递增排列" << endl;
				exit(1);
			}
			ins >> k;
			while (k != F_END) {
				++agraph->num_edge;//弧（边）数量自增
				p = (Arc *)malloc(sizeof(Arc));//分配内存，新增一条弧
				p->adjvex = agraph->adjlist[k].ver_head;//弧头
				ins >> p->weight;						//弧的权值
				p->next = agraph->adjlist[i].first;		//头插法
				agraph->adjlist[i].first = p;
				ins >> k;						//读取下一条弧的信息
			}
		}
	}
	catch (...)
	{
		printErrorAndExit("Create_AGraph");
	}
}
void Print_AGraph_Matrix(AGraph *agraph) {//由AGraph类型参数打印邻接矩阵表示的图
	int i;
	Arc *p;
	cout << "图中的顶点信息为：" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		cout << agraph->adjlist[i].ver_head.info << " 编号为：" << agraph->adjlist[i].ver_head.no << '\t';
	}
	cout << endl << "图中的弧（边）共有" << agraph->num_edge << "条，具体信息如下："<<endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			cout << "(" << i << "," << p->adjvex.no << ":" << p->weight << ")" << '\t';
			p = p->next;
		}
		cout << "结束" << endl;
	}
}
