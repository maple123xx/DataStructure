#include"Tree.h"

int main() {
	const string str = "data\\tree_6.txt";
	BTNode *p = CreateTree(str);
	//PostOrder(p);
	//cout << endl;
	//LevelOrder(p);
	//InverseLevel(p);
	//cout << endl;
	//int depth=getDepth2(p);
	//cout << "�������Ϊ" << depth << endl;
	//IsComplete(p);
	//cout << "˫��֧�ڵ����Ϊ" << DoubleSonNodes(p) << endl;
	//SwapTree(p);
	//PreOrder(p);
	//cout << PreKNode(p, 5) << endl;
	//DeleteX(p, 'B');
	//PreOrder(p);
	SearchX(p, 'F');
	cout << endl;
	return 0;
}