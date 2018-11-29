#include"Graph.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
void Create_MGraph(MGraph *&mgraph, const string &str) {
	//�ɾ���������ڽӾ����ʾ��ͼ
	//�ļ��ĵ�һ��������ͼ�ж�������
	//�������Ƕ���ı����������Ϣ����1��ʼ��ţ�
	//�������Ǿ��������������Ϊ��ֵ���Լ����Լ��ľ���Ϊ0����������Ϊ-1
	//ע�⣺��������ͼ�������˺�������󣬱ߵ�����Ϊʵ��������2��
	try
	{
		int i, j;
		Value_Type k;	//��Ȩֵ
		ifstream ins(str);
		if (!ins) { throw exception(); }
		mgraph->num_edge = 0;//��ʼ�������ߣ�������Ϊ0
		ins >> mgraph->num_node;//����һ�У�����ڵ����
		if (mgraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= mgraph->num_node; ++i) {
			ins >> mgraph->vertex[i].info;
			ins >> mgraph->vertex[i].no;
		}
		for (i = 1; i <= mgraph->num_node; ++i) {
			for (j = 1; j <= mgraph->num_node; ++j) {
				ins >> k;
				if (k > CON_SELF && i != j) {//������ʱ
					mgraph->edge[i][j]=k;
					++mgraph->num_edge;//������1
				}
				else if(i==j)			//���Լ��ľ���Ϊ0
				{
					mgraph->edge[i][j] = CON_SELF;
				}
				else                  //������
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
void Print_MGraph_Matrix(MGraph *mgraph) {//��MGraph���Ͳ�����ӡ�ڽӾ����ʾ��ͼ
	int i, j;
	cout << "ͼ�еĶ��㼰����Ϊ��" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		cout << mgraph->vertex[i].info << ":" << mgraph->vertex[i].no << '\t';
	}
	cout << endl << "ͼ�еĻ����ߣ�����" << mgraph->num_edge << "��������������£�" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		for (j = 1; j <= mgraph->num_node; ++j) {
			cout.width(6);
			cout << mgraph->edge[i][j];
		}
		cout << endl;
	}
}
void Create_AGraph(AGraph *&agraph, const string &str) {
	//���ڽӱ����͵��ļ�����ͼ���ڽӱ�
	//�ļ��ĵ�һ������Ϊ�������num_node
	//�ļ��ĵ�2���Ƕ�����Ϣ��������'A'����Ĭ�ϱ�Ŵ�1��ʼ������
	//�ļ��ĵ�3�е���num_node+2�о�Ϊ����ÿ������ĵ�һ�������ǻ�β�������ţ����������ǻ�ͷ���������Լ�����Ȩ�أ����һ������Ϊ-1����ʾ�������
	//���磺6,5,7.2,8,3.6,3,10.8,-1������ʾ������(6,5,7.2),(6,8,3.6),(6,3,10.8)
	//��1��ʼ���
	//��Ϊ����ͼ����num_edgeΪʵ��ֵ������
	try
	{
		int i, k;
		Arc *p;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		agraph->num_edge = 0;//��ʼ�������ߣ�����Ϊ0
		ins >> agraph->num_node;
		if (agraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= agraph->num_node; ++i) {
			agraph->adjlist[i].ver_head.no = i;//���i�������ͷ��������Ϊi
			ins >> agraph->adjlist[i].ver_head.info;//��1��agraph->num_node���ζ�ȡ������Ϣ�������ơ�A��
			agraph->adjlist[i].first = NULL;//��Ҫ
		}
		for (i = 1; i <= agraph->num_node; ++i) {
			ins >> k;
			if (i != k) {
				cout << "�ļ���ʽ���������ͷ����Ӧ�ô�1��ʼ��������" << endl;
				exit(1);
			}
			ins >> k;
			while (k != F_END) {
				++agraph->num_edge;//�����ߣ���������
				p = (Arc *)malloc(sizeof(Arc));//�����ڴ棬����һ����
				p->adjvex = agraph->adjlist[k].ver_head;//��ͷ
				ins >> p->weight;						//����Ȩֵ
				p->next = agraph->adjlist[i].first;		//ͷ�巨
				agraph->adjlist[i].first = p;
				ins >> k;						//��ȡ��һ��������Ϣ
			}
		}
	}
	catch (...)
	{
		printErrorAndExit("Create_AGraph");
	}
}
void Print_AGraph_Matrix(AGraph *agraph) {//��AGraph���Ͳ�����ӡ�ڽӾ����ʾ��ͼ
	int i;
	Arc *p;
	cout << "ͼ�еĶ�����ϢΪ��" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		cout << agraph->adjlist[i].ver_head.info << " ���Ϊ��" << agraph->adjlist[i].ver_head.no << '\t';
	}
	cout << endl << "ͼ�еĻ����ߣ�����" << agraph->num_edge << "����������Ϣ���£�"<<endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			cout << "(" << i << "," << p->adjvex.no << ":" << p->weight << ")" << '\t';
			p = p->next;
		}
		cout << "����" << endl;
	}
}
void DFS(AGraph *agraph, int vertex, bool have_visited[]) {
	//�ݹ���ͼ��������ȱ���
	//vertex��ʾ���ĸ����㿪ʼ����
	//��������������֮ǰ����Ҫ��ʼ��have_visited[]ȫΪFALSE
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "�������Ϊ1��agraph->num_node֮�����" << endl;
		exit(1);
	}
	Arc *p;
	have_visited[vertex] = true;
	cout << agraph->adjlist[vertex].ver_head.no << '\t';//����
	p = agraph->adjlist[vertex].first;
	while (p)
	{
		if (have_visited[p->adjvex.no] == false) {//���û�з��ʣ��ͷ�����
			DFS(agraph, p->adjvex.no, have_visited);
		}
		p = p->next;
	}
}
void DFS2(AGraph *agraph, int vertex) {
	//�ǵݹ���ͼ��������ȱ���������ջ
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "�������Ϊ1��agraph->num_node֮�����" << endl;
		exit(1);
	}
	Arc *p;
	int i,k,top=-1;	//��ʼ��ջ
	int stack[N_list];
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		have_visited[i] = false;	//��ʼ�����ʱ������
	cout << vertex << '\t';		//����
	have_visited[vertex] = true;	//���Ϊ�ѷ���
	stack[++top] = vertex;	//��ջ
	while (top != -1) {
		k = stack[top];		//ȡջ��Ԫ��
		p = agraph->adjlist[k].first;		//ָ��ջ���ĵ�һ����
		while (p && have_visited[p->adjvex.no] == true)
			p = p->next;			//�ߵ���һ��û�з��ʹ����ڽӶ�������ߵ�����β
		if (p == NULL)				//��������β����˵����ǰ����������ڽӵ�������
			--top;					//��ջ
		else
		{
			cout << p->adjvex.no << '\t';	//����
			have_visited[p->adjvex.no] = true;	//���Ϊ�ѷ���
			stack[++top] = p->adjvex.no;	//��ջ
		}
	}
}
void BFS(AGraph *agraph, int vertex, bool have_visited[]) {
	//���ö�����ͼ�Ĺ�����ȱ���
	//��������������֮ǰ����Ҫ��ʼ��have_visited[]ȫΪFALSE
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "�������Ϊ1��agraph->num_node֮�����" << endl;
		exit(1);
	}
	int ver = vertex;
	Arc *p;
	int queue[N_queue];
	int rear = 0, front = 0;
	cout << agraph->adjlist[ver].ver_head.info << ":" << ver << endl;
	have_visited[ver] = true;	//�����������֮ǰ���
	queue[++rear] = ver;
	while (rear != front) {
		ver = queue[++front];			//������
		p = agraph->adjlist[ver].first;	//ָ���һ����
		while (p)
		{
			ver = p->adjvex.no;
			if (have_visited[ver] == false) {
				cout << agraph->adjlist[ver].ver_head.info << ":" << ver << endl;//����
				have_visited[ver] = true;			//�����������֮ǰ���
				queue[++rear] = ver;
			}
			p = p->next;				//ָ����һ����
		}
	}
}
int BFS_far(AGraph *agraph, int vertex) {
	//����Ȩ��������ͨͼ
	//���붥��v��Զ��һ������
	//��������������㷨���������һ������
	if (vertex<1 || vertex>agraph->num_node) {
		cout << "�������Ϊ1��agraph->num_node֮�����" << endl;
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
	have_visited[ver] = true;//�����������֮ǰ���
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
	return far;//�����Ӽ�Ϊ��vertex��Զ�Ķ���
}
void DFS_NC(AGraph *agraph) {
	//����ͨͼ��������ȱ���
	int i;
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i) {
		have_visited[i] = false;
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (have_visited[i] == false)
			DFS(agraph, i, have_visited);//��������ͼ������DFS()�Ĵ�����Ϊ��ͨ������
	}
}
void BFS_NC(AGraph *agraph) {
	//����ͨͼ�Ĺ�����ȱ���
	int i;
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i) {
		have_visited[i] = false;
	}
	for (i = 1; i <= agraph->num_node; ++i) {
		if (have_visited[i] == false)
			BFS(agraph, i, have_visited);//��������ͼ������BFS()�Ĵ�����Ϊ��ͨ������
	}
}
void DFS_istree(AGraph *agraph, int vertex, bool have_visited[], int &vn, int &en) {
	if (vertex<1 || vertex>agraph->num_node)
	{
		cout << "����DFS��������ver����Ϊ1~agra->num_node֮���������" << endl;
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
	//����ͼ���ж����Ƿ�Ϊһ����
	//������1���Ƿ���ͨ���ܱ��������еĵ���˵����ͨ����2������ȱ�����һ
	int i, vn = 0, en = 0;//vn�Ƕ����������en�Ǳߵ�����
	bool have_visited[N_list];
	for (i = 1; i <= agraph->num_node; ++i)
		have_visited[i] = false;
	DFS_istree(agraph, 1, have_visited, vn, en);
	if (vn == agraph->num_node && vn-1==en/2) {
		cout << "������ͼ��һ����" << endl;
		return;
	}
	else
	{
		cout << "������ͼ����һ����" << endl;
		return;
	}
}
void BFS_Min_Distance(AGraph *agraph, int vertex) {
	//����Ӷ���u��v�����·��distance[u,v]Ϊ��u��v������·�������ٵı���
	//BFS�㷨���Ǵ�Ȩͼ�ĵ�Դ���·�����⣬��ΪBFS���ǰ��վ����ɽ���Զ������ͼ��ÿ�������
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
	cout << "����"<<vertex<<"������������·��Ϊ" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		cout << distance[i] << '\t';
	}
}
Value_Type Prim(MGraph *mgraph, int v0) {
	//����ķ�㷨����������ͨͼ����С������
	//����v0���ӵ���СȨֵ��������v1����Ȼ������v0��v1���ӵ���СȨֵ���Դ�����
	int i,k,choose,pre[N_matrix];//pre[N_matrix]��ÿһ�������СȨֵ�Ļ�β��chooseΪÿһ��ѡ�е���pre���ӵ�����СȨֵ�Ļ�ͷ
	bool visited[N_matrix];//����Ѿ����ʹ��Ķ���
	Value_Type sum=0, min,lowcost[N_matrix];//lowcost���鱣��ÿһ�ֵ�Ȩֵ��ѡ��һ����С�ģ���һ�־͸���lowcost����
	for (i = 1; i <= mgraph->num_node; ++i) {//��ʼ��
		visited[i] = false;
		if (mgraph->edge[v0][i] > CON_SELF) {
			lowcost[i] = mgraph->edge[v0][i];
			pre[i] = v0;
		}
		else
		{
			lowcost[i] = Infinity_big;
			pre[i] = -1;
		}
	}
	visited[v0] = true;//���ʵ�һ������
	for (k = 1; k < mgraph->num_node; ++k) {
		min = Infinity_big;
		for (i = 1; i <= mgraph->num_node; ++i) {//�ҵ���һ�ֵ���СȨֵ�Ͷ���
			if (visited[i] == false && min > lowcost[i]) {
				min = lowcost[i];
				choose = i;
			}
		}
		cout << "(" << pre[choose] << "," << choose << ")" << '\t';
		sum += min;
		visited[choose] = true;//���뵽�ѷ��ʵĶ�����
		for (i = 1; i <= mgraph->num_node; ++i) {//����lowcost��pre
			if (visited[i] == false && mgraph->edge[choose][i] > CON_SELF && mgraph->edge[choose][i] < lowcost[i]) {
				lowcost[i] = mgraph->edge[choose][i];
				pre[i] = choose;
			}
		}
	}
	return sum;
}
int sort_edge(Road road[], MGraph *mgraph) {
	//�������Ȩֵ����С��������
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
	for (i = 0; i < k - 1; ++i) {//��k����Ȩֵ�ı�
		for (j = i + 1; j < k; ++j) {
			if (road[j].weight < road[i].weight)
				std::swap(road[i],road[j]);
		}
	}
	for (i = 0; i < k; ++i)
		cout << road[i].weight << '\t';
	return k;
}
int getRoot(int a, int root[]) {//���鼯������ĳ��Ԫ�صĸ�������
	while (root[a] != a)
		a = root[a];
	return a;
}
void Kruskal(MGraph *mgraph) {
	//��³˹�����㷨����������ͨͼ����С������
	//�Ƚ�Ȩֵ����С��������Ȼ��ÿ��ȡһ���ߣ��������ɻ�·�������
	int i,a,b;
	Value_Type sum = 0;
	Road road[N_matrix];
	int num_sorted = sort_edge(road, mgraph);//�����������Ȩֵ�ıߵ�����
	int root[N_road];
	for (i = 1; i <= mgraph->num_node; ++i) {
		root[i] = i;		//��ʼ��һ�����鼯��root����洢Ԫ�صĸ�����ʼ���������Լ�
	}
	cout << "�߷��ʵ�˳��Ϊ��" << endl;
	for (i = 0; i < num_sorted; ++i) {
		a = getRoot(road[i].begin, root);
		b = getRoot(road[i].end, root);
		if (a != b) {		//�ж�a,b����������ĸ��ǲ���һ������һ�����ٰ������߼���ͻᵼ���л�·
			root[b] = a;	//��a��ֵ��b�ĸ���ʹ��������������ͬ�ĸ�
			cout << "(" << road[i].begin << "," << road[i].end << ")" << '\t';//����
			sum += road[i].weight;
		}
	}
	cout << "��С��������Ȩֵ��Ϊ��" << sum << endl;
}


