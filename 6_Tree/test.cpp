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
	/*int x=Similar(p, p1);
	if (x == 1)
		cout << "����" << endl;
	else
		cout << "������" << endl;*/
	//ElemType *A = "ABDEFCGH";
	//ElemType *B = "BEDFAGCH";
	//BTNode *root = PreInCreate(A, B, 0, 7, 0, 7);
	//PostOrder(root);
	//cout << endl;
	/*ElemType *pre = "ABCDEFG";
	ElemType post[100];
	PreToPost(pre, 0, 6, post, 0, 6);
	for (int i = 0; i <= 6; ++i) {
		cout << post[i] << '\t';
	}
	cout << endl;*/
	PrintLeaf(p1);
	//const string str2 = "data\\weight_7.txt";
	//weightBTNode *root = CreateWeightTree(str2);
	////cout << "��Ȩ·������Ϊ" <<WPL(root)<< endl;
	//cout << "��Ȩ·������Ϊ" << wpl_LevelOrder(root) << endl;
	return 0;
}