#include"Tree.h"

int main() {
	const string str = "data\\tree_15.txt";
	BTNode *p = CreateTree(str);
	//PostOrder(p);
	//cout << endl;
	//LevelOrder(p);
	PostOrder2(p);
	cout << endl;
	//int depth=getDepth(p);
	//cout << "�������Ϊ" << depth << endl;

	return 0;
}