#include"Tree.h"

int main() {
	const string str = "data\\tree_15.txt";
	BTNode *p = CreateTree(str);
	//PostOrder(p);
	//cout << endl;
	//LevelOrder(p);
	//InverseLevel(p);
	//cout << endl;
	//int depth=getDepth2(p);
	//cout << "树的深度为" << depth << endl;
	//IsComplete(p);
	//cout << "双分支节点个数为" << DoubleSonNodes(p) << endl;
	//SwapTree(p);
	//PreOrder(p);
	//cout << PreKNode(p, 5) << endl;
	//DeleteX(p, 'B');
	//PreOrder(p);
	BTNode *s=Search1(p, 'L');
	BTNode *t = Search1(p, 'O');
	BTNode *common = CommonAncestor(p, s, t);
	cout << "公共祖先为"<<common->data << endl;
	return 0;
}