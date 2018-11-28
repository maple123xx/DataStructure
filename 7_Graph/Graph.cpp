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
void DFS(AGraph *agraph, int vertex, bool have_visited[]) {
	//递归求图的深度优先遍历
	//vertex表示从哪个顶点开始遍历
	//在主函数调用它之前，需要初始化have_visited[]全为FALSE
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	Arc *p;
	have_visited[vertex] = true;
	cout << agraph->adjlist[vertex].ver_head.no << '\t';//访问
	p = agraph->adjlist[vertex].first;
	while (p)
	{
		if (have_visited[p->adjvex.no] == false) {//如果没有访问，就访问它
			DFS(agraph, p->adjvex.no, have_visited);
		}
		p = p->next;
	}
}
void DFS2(AGraph *agraph, int vertex) {
	//非递归求图的深度优先遍历，利用栈
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	Arc *p;
	int i,k,top=-1;	//初始化栈
	int stack[N_list];
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		have_visited[i] = false;	//初始化访问标记数组
	cout << vertex << '\t';		//访问
	have_visited[vertex] = true;	//标记为已访问
	stack[++top] = vertex;	//入栈
	while (top != -1) {
		k = stack[top];		//取栈顶元素
		p = agraph->adjlist[k].first;		//指向栈顶的第一条边
		while (p && have_visited[p->adjvex.no] == true)
			p = p->next;			//走到第一个没有访问过的邻接顶点或者走到链表尾
		if (p == NULL)				//到达链表尾部，说明当前顶点的所有邻接点访问完毕
			--top;					//出栈
		else
		{
			cout << p->adjvex.no << '\t';	//访问
			have_visited[p->adjvex.no] = true;	//标记为已访问
			stack[++top] = p->adjvex.no;	//入栈
		}
	}
}
void BFS(AGraph *agraph, int vertex, bool have_visited[]) {
	//利用队列求图的广度优先遍历
	//在主函数调用它之前，需要初始化have_visited[]全为FALSE
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	int ver = vertex;
	Arc *p;
	int queue[N_queue];
	int rear = 0, front = 0;
	cout << agraph->adjlist[ver].ver_head.info << ":" << ver << endl;
	have_visited[ver] = true;	//必须在入队列之前标记
	queue[++rear] = ver;
	while (rear != front) {
		ver = queue[++front];			//出队列
		p = agraph->adjlist[ver].first;	//指向第一条边
		while (p)
		{
			ver = p->adjvex.no;
			if (have_visited[ver] == false) {
				cout << agraph->adjlist[ver].ver_head.info << ":" << ver << endl;//访问
				have_visited[ver] = true;			//必须在入队列之前标记
				queue[++rear] = ver;
			}
			p = p->next;				//指向下一条边
		}
	}
}
int BFS_far(AGraph *agraph, int vertex) {
	//不带权、无向、连通图
	//求离顶点v最远的一个顶点
	//分析：广度优先算法，返回最后一个顶点
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	int i, far;
	int ver = vertex;
	Arc *p;
	int queue[N_list];
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		have_visited[i] = false;
	int rear = 0, front = 0;
	cout << agraph->adjlist[ver].ver_head.no << '\t';
	have_visited[ver] = true;//必须在入队列之前标记
	queue[++rear] = ver;
	while (rear != front) {
		far = queue[++front];
		p = agraph->adjlist[far].first;
		while (p) {
			ver = p->adjvex.no;
			if (have_visited[ver] == false) {
				cout << agraph->adjlist[ver].ver_head.no << '\t';
				have_visited[ver] = true;
				queue[++rear] = ver;
			}
			p = p->next;
		}
	}
	cout << endl;
	return far;//最后出队即为离vertex最远的顶点
}
void DFS_NC(AGraph *agraph) {
	//非连通图的深度优先遍历
	int i;
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i) {
		have_visited[i] = false;
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (have_visited[i] == false)
			DFS(agraph, i, have_visited);//对于无向图，调用DFS()的次数即为连通分量数
	}
}
void BFS_NC(AGraph *agraph) {
	//非连通图的广度优先遍历
	int i;
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i) {
		have_visited[i] = false;
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (have_visited[i] == false)
			BFS(agraph, i, have_visited);//对于无向图，调用BFS()的次数即为连通分量数
	}
}
void DFS_istree(AGraph *agraph, int vertex, bool have_visited[], int &vn, int &en) {
	if (vertex<1 || vertex>agraph->num_node)
	{
		cout << "函数DFS参数有误，ver必须为1~agra->num_node之间的正整数" << endl;
		exit(1);
	}
	Arc *p;
	cout << agraph->adjlist[vertex].ver_head.info << ":" << vertex<<'\t';
	++vn;
	have_visited[vertex] = true;
	p = agraph->adjlist[vertex].first;
	while (p)
	{
		++en;
		if (have_visited[p->adjvex.no] == false) {
			DFS_istree(agraph, p->adjvex.no, have_visited, vn, en);
		}
		p = p->next;
	}
}
void Graph_istree(AGraph *agraph) {
	//无向图，判断其是否为一棵树
	//分析：1、是否连通（能遍历到所有的点则说明连通）；2、顶点比边数多一
	int i, vn = 0, en = 0;//vn是顶点的数量，en是边的数量
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		have_visited[i] = false;
	DFS_istree(agraph, 1, have_visited, vn, en);
	if (vn == agraph->num_node && vn-1==en/2) {
		cout << "该无向图是一棵树" << endl;
		return;
	}
	else
	{
		cout << "该无向图不是一棵树" << endl;
		return;
	}
}
void BFS_Min_Distance(AGraph *agraph, int vertex) {
	//定义从顶点u到v的最短路径distance[u,v]为从u到v的任意路径中最少的边数
	//BFS算法求解非带权图的单源最短路径问题，因为BFS总是按照距离由近到远来遍历图中每个顶点的
	int distance[N_list] = { 0 };
	int i,ver=vertex;
	Arc *p;
	bool visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		visited[i] = false;
	int queue[N_list];
	int rear = 0, front = 0;
	visited[ver] = true;
	queue[++rear] = ver;
	distance[ver] = 0;
	while (rear != front) {
		ver = queue[++front];
		p = agraph->adjlist[ver].first;
		while (p) {
			if (visited[p->adjvex.no] == false) {
				visited[p->adjvex.no] = true;
				queue[++rear] = p->adjvex.no;
				distance[p->adjvex.no] = distance[ver] + 1;
			}
			p = p->next;
		}

	}
	cout << "顶点"<<vertex<<"到各顶点的最短路径为" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		cout << distance[i] << '\t';
	}
}


