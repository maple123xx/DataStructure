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
		if (!have_visited[p->adjvex.no]) {//如果没有访问，就访问它
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
Value_Type Prim(MGraph *mgraph, int v0) {
	//普里姆算法，求无向、连通图的最小生成树
	//找与v0连接的最小权值（比如是v1），然后找与v0、v1连接的最小权值，以此类推
	int i,k,choose,pre[N_matrix];//pre[N_matrix]是每一轮输出最小权值的弧尾，choose为每一轮选中的与pre连接的有最小权值的弧头
	bool visited[N_matrix];//标记已经访问过的顶点
	Value_Type sum=0, min,lowcost[N_matrix];//lowcost数组保存每一轮的权值，选出一个最小的，下一轮就更新lowcost数组
	for (i = 1; i <= mgraph->num_node; ++i) {//初始化
		visited[i] = false;
		if (mgraph->edge[v0][i] > CON_SELF) {
			lowcost[i] = mgraph->edge[v0][i];
			pre[i] = v0;
		}
		else
		{
			lowcost[i] = Infinity_big;
			pre[i] = CON_N;
		}
	}
	visited[v0] = true;//访问第一个顶点
	for (k = 1; k < mgraph->num_node; ++k) {
		min = Infinity_big;
		for (i = 1; i <= mgraph->num_node; ++i) {//找到第一轮的最小权值和顶点
			if (visited[i] == false && min > lowcost[i]) {
				min = lowcost[i];
				choose = i;
			}
		}
		cout << "(" << pre[choose] << "," << choose << ")" << '\t';
		sum += min;
		visited[choose] = true;//加入到已访问的顶点中
		for (i = 1; i <= mgraph->num_node; ++i) {//更新lowcost和pre
			if (visited[i] == false && mgraph->edge[choose][i] > CON_SELF && mgraph->edge[choose][i] < lowcost[i]) {
				lowcost[i] = mgraph->edge[choose][i];
				pre[i] = choose;
			}
		}
	}
	return sum;
}
int sort_edge(Road road[], MGraph *mgraph) {
	//将矩阵的权值按从小到大排序
	int i,j,k=0;
	for (i = 1; i < mgraph->num_node; ++i) {
		for (j = i + 1; j <= mgraph->num_node; ++j) {
			if (mgraph->edge[i][j] > CON_SELF) {
				road[k].begin = i;
				road[k].end = j;
				road[k].weight = mgraph->edge[i][j];
				++k;
			}
		}
	}
	for (i = 0; i < k - 1; ++i) {//有k条有权值的边
		for (j = i + 1; j < k; ++j) {
			if (road[j].weight < road[i].weight)
				std::swap(road[i],road[j]);//不要只交换权值
		}
	}
	for (i = 0; i < k; ++i)
		cout << road[i].weight << '\t';
	return k;
}
int getRoot(int a, int root[]) {//并查集，查找某个元素的根并返回
	while (root[a] != a)
		a = root[a];
	return a;
}
void Kruskal(MGraph *mgraph) {
	//克鲁斯卡尔算法，求无向、连通图的最小生成树
	//先将权值按从小到大排序，然后每次取一个边，若不构成回路，则加入
	int i,a,b;
	Value_Type sum = 0;
	Road road[N_matrix];
	int num_sorted = sort_edge(road, mgraph);//返回排序后有权值的边的总数
	int root[N_road];
	for (i = 1; i <= mgraph->num_node; ++i) {
		root[i] = i;		//初始化一个并查集，root数组存储元素的根，初始化就是它自己
	}
	cout << "边访问的顺序为：" << endl;
	for (i = 0; i < num_sorted; ++i) {
		a = getRoot(road[i].begin, root);
		b = getRoot(road[i].end, root);
		if (a != b) {		//判断a,b这两个顶点的根是不是一样，若一样，再把这条边加入就会导致有回路
			root[b] = a;	//把a赋值给b的根，使这两个顶点有相同的根
			cout << "(" << road[i].begin << "," << road[i].end << ")" << '\t';//访问
			sum += road[i].weight;
		}
	}
	cout << "最小生成树的权值和为：" << sum << endl;
}
void Dijstra(MGraph *mgraph, int v0, Value_Type cost[], int pre[]) {
	//迪杰斯特拉算法求带权连通图的单源最短路径（有向或无向都可以）
	//若边上带有负权值，Dijstra算法失效
	//求点v0到图中其余所有点的最短路径及距离
	int i,j,k;
	bool visited[N_list];
	Value_Type min;
	for (i = 1; i <= mgraph->num_node; ++i) {
		visited[i] = false;				//初始化各数组
		if (mgraph->edge[v0][i] > CON_SELF) {
			cost[i] = mgraph->edge[v0][i];
			pre[i] = v0;
		}
		else
		{
			cost[i] = Infinity_big;		//与v0无直接连接
			pre[i] = CON_N;
		}
	}
	visited[v0] = true;					//顶点v0已访问
	for (i = 1; i < mgraph->num_node; ++i) {
		min = Infinity_big;
		for (j = 1; j <= mgraph->num_node; ++j) {
			if (visited[j] == false && min > cost[j]) {	//求已访问点到剩余点的最短距离
				min = cost[j];
				k = j;
			}
		}
		visited[k] = true;				//访问顶点k
		for (j = 1; j <= mgraph->num_node; ++j) {
			if (visited[j] == false && mgraph->edge[k][j] > CON_SELF && cost[j] > cost[k] + mgraph->edge[k][j]) {//mgra.edge[k][j]>CON_SELF重要
				cost[j] = cost[k] + mgraph->edge[k][j];
				pre[j] = k;
			}
		}
	}
}
void Print_Dijstra(int obj, int pre[]) {
	//打印从顶点v0到顶点obj的最短路径，迪杰斯特拉的子算法
	int stack[N_matrix];
	int i = obj, top = -1;
	while (i != CON_N) {
		stack[++top] = i;
		i = pre[i];
	}
	cout << "从起点到终点的最短路径为" << endl;
	while (top != -1)
	{
		cout << stack[top--] << '\t';
	}
	cout << endl;
}
void Dijstra_call(MGraph *mgraph, int v0, int obj) {//求v0到任意终点obj的最短路径
	//调用迪杰斯特拉算法
	if (v0<1 || v0>mgraph->num_node || obj<1 || obj>mgraph->num_node)
	{
		cout << "起点、终点的序号必须在1~mgra.num_node之间" << endl;
		exit(1);
	}
	Value_Type cost[N_matrix];
	int pre[N_matrix];
	Dijstra(mgraph, v0, cost, pre);
	Print_Dijstra(obj, pre);
	cout << v0 << "到" << obj << "的最短路径为" << cost[obj] << endl;
}
void Floyd(MGraph *mgraph, int path[][N_matrix], Value_Type cost[][N_matrix]) {
	//弗洛伊德算法求带权连通图的单源最短路径（有向或无向都可以）
	//每次新加入一个顶点，看经过这个顶点，最短路径会不会变小
	//Floyd算法允许图中带有负权值的边，但不允许有包含带负权值的边组成的回路
	int i, j, k;
	for (i = 1; i <= mgraph->num_node; ++i) {
		for (j = 1; j <= mgraph->num_node; ++j) {
			path[i][j] = CON_N;
			if (mgraph->edge[i][j] > CON_SELF && i != j) {
				cost[i][j] = mgraph->edge[i][j];
			}
			else if (i == j) {
				cost[i][j] = CON_SELF;
			}
			else
			{
				cost[i][j] = Infinity_big;
			}
		}
	}
	for (k = 1; k <= mgraph->num_node; ++k) {
		for (i = 1; i <= mgraph->num_node; ++i) {
			for (j = 1; j <= mgraph->num_node; ++j) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
void Print_Floyd(int beg, int end, int path[][N_matrix]) {
	//输出从顶点beg到顶点end的最短路径，弗洛伊德算法的子函数
	if (path[beg][end] == CON_N) {
		cout << "(" << beg << "," << end << ")" << '\t';
		return;
	}
	Print_Floyd(beg, path[beg][end], path);
	Print_Floyd(path[beg][end], end, path);
}
void Floyd_call(MGraph *mgraph, int beg, int end) {
	if (beg<1 || beg>mgraph->num_node || end<1 || end>mgraph->num_node) {
		cout << "输入顶点不合法" << endl;
		return;
	}
	int path[N_matrix][N_matrix];
	Value_Type cost[N_matrix][N_matrix];
	Floyd(mgraph, path, cost);
	Print_Floyd(beg, end, path);
	cout << beg << "到" << end << "的最短路径为" << cost[beg][end] << endl;
}
bool Top_Sort(AGraph *agraph, int sorted[]) {
	//有向无环图的拓扑排序
	//首先找一个入度为0的顶点，然后删除它以及以它出发的边，接着找第二个入度为0的顶点，依此类推
	int i, k, t = 0, sum_n = 0;//sum_n是已参加拓扑排序的顶点总数
	int in[N_list] = {0};				//入度数组，初始化为0
	int stack[N_list];
	int top = -1;
	Arc *p;
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			++in[p->adjvex.no];			//入度数组第一次更新
			p = p->next;
		}
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (in[i] == 0) {
			stack[++top] = i;			//入度为0则入栈
		}
	}
	while (top != -1) {
		k = stack[top--];		//出栈
		sorted[t++] = k;		//相当于访问
		++sum_n;		//访问过，已参加拓扑排序的顶点总数+1
		p = agraph->adjlist[k].first;
		while (p) {
			--in[p->adjvex.no];		//相当于删除由它引出的弧
			if (in[p->adjvex.no] == 0) {	//入度为0就入栈
				stack[++top] = p->adjvex.no;
			}
			p = p->next;
		}
	} 
	if (sum_n == agraph->num_node) {
		return true;
	}
	else {
		return false;
	}
}
void Top_Sort_DFS(AGraph *agraph) {
	//利用DFS做拓扑排序
	int i, j;
	bool visited[N_list] = { false };
	int time = 0;
	int finishTime[N_list] = { 0 };
	for (int i = 1; i <= agraph->num_node; ++i) {
		if(!visited[i])
			Top_Sort_DFS_Core(agraph, i, visited, time, finishTime);	//因为不知道从哪个顶点开始，所以任意开始，time会记录
	}
	int max;
	cout << "拓扑排序为：" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		max = 1;	//max是最大值的索引
		for (j = 1; j <= agraph->num_node; ++j) {
			if (finishTime[j] > finishTime[max]) {
				max = j;
			}
		}
		cout << max << '\t';
		finishTime[max] -= 10;	//将每一轮的最大值减掉10（或者其他数，大于agraph->num_node）即可，下一轮就不会选到它了
	}

}
void Top_Sort_DFS_Core(AGraph *agraph, int v, bool visited[], int &time, int finishTime[]) {
	//利用DFS做拓扑排序，假设u是v的祖先，则在调用DFS访问u时，一定递归的对v调用DFS访问了，也就是说v的DFS函数结束时间要小于u
	//按结束时间从大到小排序，就是一个拓扑排序
	Arc *p;
	visited[v] = true;
	p = agraph->adjlist[v].first;
	while (p) {
		if (!visited[p->adjvex.no])
			Top_Sort_DFS_Core(agraph, p->adjvex.no, visited, time, finishTime);
		p = p->next;
	}
	++time;
	finishTime[v] = time;
}
bool TopSort_Critical(AGraph *agraph, Value_Type ve[], int stack2[], int &top2) {
	//适用于求有向图的关键路径的拓扑排序
	//结果保存在栈stack2[]中，下标从0开始，对stack2[]进行出栈操作能得到逆拓扑排序
	//事件的最早发生时间保存在数组ve[]中
	//拓扑排序成功则返回true，否则返回false
	top2 = -1;
	int i,k,sum_n=0;
	Arc *p;
	int in[N_list];
	int stack1[N_list];
	int top1 = -1;
	for (i = 1; i <= agraph->num_node; ++i) {
		in[i] = 0;			//初始化入度
		ve[i] = 0;			//初始化事件最早发生时间
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			++in[p->adjvex.no];
			p = p->next;
		}
	}
	for (i = 1; i < agraph->num_node; ++i) {
		if (in[i] == 0)
			stack1[++top1] = i;
	}
	while (top1 != -1) {
		k = stack1[top1--];
		stack2[++top2] = k;
		++sum_n;				//已参加拓扑排序的顶点总数
		p = agraph->adjlist[k].first;
		while (p) {
			if (ve[k] + p->weight > ve[p->adjvex.no])//求每个事件的最早发生时间
				ve[p->adjvex.no] = ve[k] + p->weight;
			--in[p->adjvex.no];
			if (in[p->adjvex.no] == 0)
				stack1[++top1] = p->adjvex.no;
			p = p->next;
		}
	}
	if (sum_n == agraph->num_node)
		return true;
	else
		return false;
}
Value_Type max_ve(Value_Type ve[], int n) {//求最大值
	Value_Type max = -9999;
	for (int i = 1; i <= n; ++i) {
		if (ve[i] > max)
			max = ve[i];
	}
	return max;
}
void Critical_Path(AGraph *agraph) {
	int i, k;
	Arc *p;
	Value_Type min, ve[N_list], vl[N_list];//ve是最早开始时间的数组，vl是最迟开始时间的数组
	Value_Type e, l;
	int stack2[N_list];
	int top2 = -1;
	if (!TopSort_Critical(agraph, ve, stack2, top2)) {
		cout << "图中有回路，拓扑排序失败！" << endl;
		exit(0);
	}
	min = max_ve(ve, agraph->num_node);
	for (i = 1; i <= agraph->num_node; ++i) {
		vl[i] = min;		//初始化事件最晚发生时间为事件最早发生时间的最大值
	}
	while (top2 != -1) {
		k = stack2[top2--];		//从最后一个事件开始
		p = agraph->adjlist[k].first;
		while(p){
			if (vl[p->adjvex.no] - p->weight < vl[k]) {//求事件的最迟发生时间
				vl[k] = vl[p->adjvex.no] - p->weight;
			}
			p = p->next;
		}
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			e = ve[i];		//活动最早开始时间
			l = vl[p->adjvex.no]-p->weight;	//活动最晚开始时间
			if (e == l) {	//e和l相等的是关键活动
				cout << "(" << i << "," << p->adjvex.no << ")" << "是关键活动" << endl;
			}
			p = p->next;
		}
	}
	cout << endl;
}

void ConvertA_M(AGraph *agraph, MGraph *mgraph) {
	//将邻接表方式表示的图转换成邻接矩阵表示
	int i, j;
	Arc *p;
	mgraph->num_node = agraph->num_node;
	mgraph->num_edge = 0;
	for (i = 1; i <= agraph->num_node; ++i) {
		mgraph->vertex[i].info = agraph->adjlist[i].ver_head.info;
		mgraph->vertex[i].no = agraph->adjlist[i].ver_head.no;
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			mgraph->edge[i][p->adjvex.no] = p->weight;
			++mgraph->num_edge;
			p = p->next;
		}
	}
	for (i = 1; i <= mgraph->num_node; ++i) {
		for (j = 1; j <= mgraph->num_node; ++j) {
			if (mgraph->edge[i][j] > 0);
			else if (i == j)			//到自己的距离为0
				mgraph->edge[i][j] = CON_SELF;
			else                  //无连接
				mgraph->edge[i][j] = CON_N;
		}
	}
}
bool Exist_Path_DFS(AGraph *agraph, int i, int j, bool visited[]) {
	//判断顶点i，j是否有边连接,用DFS
	if (i<1 || j<1 || i>agraph->num_node || j>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	if (i == j)		//递归退出条件
		return true;
	Arc *p;
	visited[i] = true;
	p = agraph->adjlist[i].first;
	while (p) {
		if (!visited[p->adjvex.no] && Exist_Path_DFS(agraph, p->adjvex.no, j, visited))
			return true;
		p = p->next;
	}
	return false;
}
bool Exist_Path_DFS2(AGraph *agraph, int i, int j) {
	//判断顶点i，j是否有边连接,用非递归的DFS
	if (i<1 || j<1 || i>agraph->num_node || j>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	Arc *p;
	int s, k, top = -1;	//初始化栈
	int stack[N_list];
	bool have_visited[N_list];
	for (s = 1; s <= agraph->num_node; ++s)
		have_visited[s] = false;	//初始化访问标记数组
	have_visited[i] = true;	//标记为已访问
	stack[++top] = i;	//入栈
	while (top != -1) {
		k = stack[top];		//取栈顶元素
		if (k == j)
			return true;
		p = agraph->adjlist[k].first;		//指向栈顶的第一条边
		while (p && have_visited[p->adjvex.no] == true)
			p = p->next;			//走到第一个没有访问过的邻接顶点或者走到链表尾
		if (p == NULL)				//到达链表尾部，说明当前顶点的所有邻接点访问完毕
			--top;					//出栈
		else
		{
			have_visited[p->adjvex.no] = true;	//标记为已访问
			stack[++top] = p->adjvex.no;	//入栈
		}
	}
	return false;
}
bool Exist_Path_BFS(AGraph *agraph, int i, int j, bool have_visited[]) {
	//判断顶点i，j是否有边连接,用BFS
	if (i<1 || j<1 || i>agraph->num_node || j>agraph->num_node) {
		cout << "顶点必须为1到agraph->num_node之间的数" << endl;
		exit(1);
	}
	if (i == j)
		return true;
	int queue[N_list];
	int rear = 0, front = 0;
	int ver = i;
	queue[++rear] = ver;
	have_visited[ver] = true;
	Arc *p;
	while (rear != front) {
		ver = queue[++front];
		p = agraph->adjlist[ver].first;
		while (p) {
			if (p->adjvex.no == j)
				return true;
			if (!have_visited[p->adjvex.no]) {
				have_visited[p->adjvex.no] = true;
				queue[++rear] = p->adjvex.no;
			}
			p = p->next;
		}
	}
	return false;
}
void Path_U_V(AGraph *agraph, int u, int v, int path[], int paths[][N_list], int &pathnum,int &d, bool visited[]) {
	//输出从u到v的所有路径
	//path表示某条路径，paths表示所有路径，pathnum是路径数量，d表示第d个位置
	int i;
	Arc *p;
	path[++d] = u;
	visited[u] = true;
	if (u == v) {	//找到终点了
		for (i = 0; i <= d; ++i) {
			paths[pathnum][i] = path[i];
		}
		++pathnum;
	}
	p = agraph->adjlist[u].first;
	while (p) {
		if (!visited[p->adjvex.no])
			Path_U_V(agraph, p->adjvex.no, v, path, paths, pathnum, d, visited);
		p = p->next;
	}
	visited[u] = false;	//回退，使得下次还可能访问到它
	--d;	//回退
}
bool Adjacent(AGraph *agraph, int x, int y) {
	//判断图中是否有边（x,y）,只需判断(x,y)，就算在在无向图中也不用判断(y,x)，因为（x，y）都没有，怎么会有（y,x）
	Arc *p = agraph->adjlist[x].first;
	while (p&&p->adjvex.no!=y) {
		p = p->next;
	}
	if (p)
		return true;
	return false;
}
void Neighbors(AGraph *agraph, int x) {
	//列出所有与顶点x邻接的边
	Arc *p = agraph->adjlist[x].first;
	while (p) {
		cout << p->adjvex.no << '\t';
		p = p->next;
	}
	cout << endl;
}
void InsertVertex(AGraph *&agraph, int x) {
	//插入节点6，以及边（6，1，2），（6，2，3），（3，6，4），最后面的是权值
	Arc *p;
	++agraph->num_node;
	agraph->num_edge += 3;
	agraph->adjlist[x].ver_head.no = x;
	agraph->adjlist[x].ver_head.info = 'F';
	agraph->adjlist[x].first = NULL;

	p = (Arc *)malloc(sizeof(Arc));
	p->adjvex = agraph->adjlist[1].ver_head;
	p->weight = 2;
	p->next = agraph->adjlist[x].first;
	agraph->adjlist[x].first = p;

	p = (Arc *)malloc(sizeof(Arc));
	p->adjvex = agraph->adjlist[2].ver_head;
	p->weight = 3;
	p->next = agraph->adjlist[x].first;
	agraph->adjlist[x].first = p;

	p = (Arc *)malloc(sizeof(Arc));
	p->adjvex = agraph->adjlist[6].ver_head;
	p->weight = 4;
	p->next = agraph->adjlist[3].first;
	agraph->adjlist[3].first = p;
}
void DeleteVertex(AGraph *&agraph, int x) {
	//从图中删除顶点x及其相关的边
	int i;
	Arc *p = agraph->adjlist[x].first;
	while (p) {	//删除从x出发的边
		Arc *q = p->next;
		free(p);
		--agraph->num_edge;
		if (!q) {
			p = NULL;
			break;
		}
		p = q;
	}
	agraph->adjlist[x].first = NULL;
	for (i = 1; i <= agraph->num_node; ++i) {	//输出
		if (i == x)
			continue;
		cout << agraph->adjlist[i].ver_head.info << " 编号为：" << agraph->adjlist[i].ver_head.no << '\t';
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (i == x)
			continue;
		Arc *p= agraph->adjlist[i].first;
		while (p) {
			if (p->adjvex.no == x) {
				if (p == agraph->adjlist[i].first) {	//p是第一条边
					agraph->adjlist[i].first = agraph->adjlist[i].first->next;
					free(p);
					p = NULL;
				}
				else {
					Arc *q = agraph->adjlist[i].first;
					while (q->next != p) {
						q = q->next;
					}
					q->next = p->next;
					free(p);
					p = NULL;
				}
				--agraph->num_edge;
			}
			if(p)
				p = p->next;
		}
	}
	cout << endl << "图中的弧（边）共有" << agraph->num_edge << "条，具体信息如下：" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			cout << "(" << i << "," << p->adjvex.no << ":" << p->weight << ")" << '\t';
			p = p->next;
		}
		cout << "结束" << endl;
	}
}
void RemoveEdge(AGraph *&agraph, int x, int y) {
	//删除边（x,y）,若是无向图的话，还要删除（y,x）
	Arc *p = agraph->adjlist[x].first;
	while (p&&p->adjvex.no != y) {
		p = p->next;
	}
	if (p == agraph->adjlist[x].first) {	//p是第一个顶点
		agraph->adjlist[x].first = agraph->adjlist[x].first->next;
		free(p);
		p = NULL;
	}
	else{
		Arc *q = agraph->adjlist[x].first;
		while (q->next != p) {
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
	--agraph->num_edge;
	//反着来一遍
	p = agraph->adjlist[y].first;
	while (p&&p->adjvex.no != x) {
		p = p->next;
	}
	if (p == agraph->adjlist[y].first) {	//p是第一个顶点
		agraph->adjlist[y].first = agraph->adjlist[y].first->next;
		free(p);
		p = NULL;
	}
	else {
		Arc *q = agraph->adjlist[y].first;
		while (q->next != p) {
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
	--agraph->num_edge;
}

