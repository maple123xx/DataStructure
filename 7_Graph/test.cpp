#include"Graph.h"

int main() {
	/*const string str = "data\\MGraph_05_3.txt";
	MGraph *mgraph = (MGraph *)malloc(sizeof(MGraph));
	Create_MGraph(mgraph, str);
	Print_MGraph_Matrix(mgraph);
	cout << endl;*/
	const string str1 = "data\\AGraph_05_6.txt";
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
	Critical_Path(agraph);
	return 0;
}