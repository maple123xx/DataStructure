#include"Tree.h"

int main() {
	const string str = "data\\tree_6.txt";
	BTNode *p = CreateTree(str);
	const string str1 = "data\\tree_15.txt";
	BTNode *p1 = CreateTree(str1);
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
	/*BTNode *s=Search1(p, 'L');
	BTNode *t = Search1(p, 'O');
	BTNode *common = CommonAncestor(p, s, t);
	cout << "��������Ϊ"<<common->data << endl;*/
	//cout << "�ö������Ŀ��Ϊ" << BTwidth(p) << endl;
	int x=Similar(p, p1);
	if (x == 1)
		cout << "����" << endl;
	else
		cout << "������" << endl;
	return 0;
}