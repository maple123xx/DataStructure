#include"Graph.h"

int main() {
	/*const string str = "data\\MGraph_05_2.txt";
	MGraph *mgraph = (MGraph *)malloc(sizeof(MGraph));
	Create_MGraph(mgraph, str);
	Print_MGraph_Matrix(mgraph);
	cout << endl;*/
	const string str1 = "data\\AGraph_05.txt";
	AGraph *agraph = (AGraph *)malloc(sizeof(AGraph));
	Create_AGraph(agraph, str1);
	Print_AGraph_Matrix(agraph);
	//bool have_visited[N_list] = { false };
	//cout << "������ȱ���Ϊ��" << endl;
	//DFS2(agraph, 1);
	//cout << "������ȱ���Ϊ��" << endl;
	//BFS(agraph,1,have_visited);
	//int far = BFS_far(agraph, 1);
	//cout << "��Զ�Ķ���Ϊ��"<<far << endl;
	//Graph_istree(agraph);
	BFS_Min_Distance(agraph, 3);
	return 0;
}