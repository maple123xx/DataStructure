#include"Tree.h"

int main() {
	const string str = "data\\weight_7.txt";
	BTNode *p = CreateTree(str);
	const string str1 = "data\\tree_15.txt";
	BTNode *p1 = CreateTree(str1);
	All_leaf_Path(p1);
	//PreThread(p1);
	//PreOrder_Thread(p1);
	//InThread(p1);
	//BTNode *p2 = FirstNode(p1);
	/*BTNode *p3 = NextNode(p1);
	cout << "������һ���ڵ�Ϊ��"<<p3->data << endl;
	InOrder_Thread(p1);*/
	//BTNode *root;
	//BTNode *parent=NULL,*p;
	//ElemType A[] = { 40,72,38,35,67,51,90,8,55,21};
	//ElemType A[] = { 10,5,12,3,7,4 };
	//Create_BST(root, A, 10);
	/*if (SearchBST2(root, 4, parent, p)) {
		cout << p->data << endl;
	}
	else {
		cout << "�����ڴ˹ؼ���" << endl;
	}*/
	//BTNode *s=SearchBST(root, 72, parent);
	//cout << s->data << endl;
	//InOrder(root);
	//cout << endl;
	/*int res=0;
	int L = 1;
	Level_X(root, 55, L, &res);
	cout << res << endl;
	cout << Level_X2(root, 55);*/
	//int L = 1;
	//PreValue_Level(root, L);
	/*Count_Node(root);
	BTNode *s = Number_K(root, 9);
	cout << s->data << endl;
	cout << SingleSonNodes(root) << endl;*/
	/*if (JudgeBST2(p))
		cout << "�Ƕ���������" << endl;
	else
		cout << "���Ƕ���������" << endl;*/
	/*cout << "���Ϊ" << BST_Level(root, 51) << endl;
	MinKey(root);
	cout << "���ڵ���k����Ϊ��" << endl;
	Output_Max_K(root, 41);
	cout << endl;*/
	//BST_Insert(root, 39);
	//BST_Delete(root,72);
	//LevelOrder(root);
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
	//PrintLeaf(p1);
	//const string str2 = "data\\weight_7.txt";
	//weightBTNode *root = CreateWeightTree(str2);
	////cout << "��Ȩ·������Ϊ" <<WPL(root)<< endl;
	//cout << "��Ȩ·������Ϊ" << wpl_LevelOrder(root) << endl;
	return 0;
}