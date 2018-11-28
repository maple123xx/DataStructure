#include"Graph.h"

int main() {
	const string str = "data\\MGraph_05_2.txt";
	MGraph *mgraph = (MGraph *)malloc(sizeof(MGraph));
	Create_MGraph(mgraph, str);
	Print_MGraph_Matrix(mgraph);
	cout << endl;
	const string str1 = "data\\AGraph_05.txt";
	AGraph *agraph = (AGraph *)malloc(sizeof(AGraph));
	Create_AGraph(agraph, str1);
	Print_AGraph_Matrix(agraph);
	return 0;
}