#include"Graph.h"

int main() {
	const string str = "data\\MGraph_05_3.txt";
	MGraph *mgraph = (MGraph *)malloc(sizeof(MGraph));
	Create_MGraph(mgraph, str);
	Print_MGraph_Matrix(mgraph);
	cout << endl;
	const string str1 = "data\\AGraph_05_4.txt";
	AGraph *agraph = (AGraph *)malloc(sizeof(AGraph));
	Create_AGraph(agraph, str1);
	Print_AGraph_Matrix(agraph);
	Top_Sort_DFS(agraph);
	//int path[N_list] = { 0 };
	//int paths[N_list][N_list] = { 0 };
	//int pathnum = 0;
	//int d = -1;
	//bool visited[N_list] = { false };
	//Path_U_V(agraph, 1, 5, path, paths, pathnum, d, visited);
	//for (int i = 0; i < pathnum; ++i) {
	//	cout << "·��Ϊ��" << endl;
	//	for (int j = 0; j < N_list; ++j) {
	//		if (paths[i][j] != 0)
	//			cout << paths[i][j] << '\t';
	//	}
	//	cout << endl;
	//}
	/*MGraph mgraph;
	ConvertA_M(agraph, &mgraph);*/
	//Print_MGraph_Matrix(&mgraph);
	/*bool have_visited[N_list] = { false };
	cout << "������ȱ���Ϊ��" << endl;
	DFS(agraph, 1,have_visited);*/
	/*if (Exist_Path_DFS2(agraph, 5, 1))
		cout << "i��j������" << endl;
	else
		cout << "i��j������" << endl;*/
	//cout << "������ȱ���Ϊ��" << endl;
	//BFS(agraph,1,have_visited);
	//int far = BFS_far(agraph, 1);
	//cout << "��Զ�Ķ���Ϊ��"<<far << endl;
	//Graph_istree(agraph);
	//BFS_Min_Distance(agraph, 3);
	//Kruskal(mgraph);
	//Dijstra_call(mgraph, 2, 4);
	//Floyd_call(mgraph, 2, 4);
	/*int i;
	int sorted[N_list] = {0};
	bool a = Top_Sort(agraph, sorted);
	if (a == true) {
		cout << "����ɹ����޻�·" << endl;
		for (i = 0; i < agraph->num_node; ++i) {
			cout << sorted[i] << '\t';
		}
	}
	else{
		cout << "����ʧ�ܣ��л�·" << endl;
	}*/
	//Critical_Path(agraph);
	return 0;
}