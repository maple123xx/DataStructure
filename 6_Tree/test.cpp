#include"Tree.h"

int main() {
	const string str = "data\\weight_7.txt";
	BTNode *p = CreateTree(str);
	const string str1 = "data\\tree_15.txt";
	BTNode *p1 = CreateTree(str1);
	BTNode *root;
	//BTNode *parent=NULL,*p;
	ElemType A[] = { 40,72,38,35,67,51,90,8,55,21};
	//ElemType A[] = { 10,5,12,3,7,4 };
	Create_BST(root, A, 10);
	/*if (SearchBST2(root, 4, parent, p)) {
		cout << p->data << endl;
	}
	else {
		cout << "不存在此关键字" << endl;
	}*/
	//BTNode *s=SearchBST(root, 72, parent);
	//cout << s->data << endl;
	InOrder(root);
	cout << endl;
	/*int res=0;
	int L = 1;
	Level_X(root, 55, L, &res);
	cout << res << endl;
	cout << Level_X2(root, 55);*/
	int L = 1;
	PreValue_Level(root, L);
	/*Count_Node(root);
	BTNode *s = Number_K(root, 9);
	cout << s->data << endl;
	cout << SingleSonNodes(root) << endl;*/
	/*if (JudgeBST2(p))
		cout << "是二叉排序树" << endl;
	else
		cout << "不是二叉排序树" << endl;*/
	/*cout << "层次为" << BST_Level(root, 51) << endl;
	MinKey(root);
	cout << "大于等于k的数为：" << endl;
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
	//cout << "树的深度为" << depth << endl;
	//IsComplete(p);
	//cout << "双分支节点个数为" << DoubleSonNodes(p) << endl;
	//SwapTree(p);
	//PreOrder(p);
	//cout << PreKNode(p, 5) << endl;
	//DeleteX(p, 'B');
	//PreOrder(p);
	/*BTNode *s=Search1(p, 'L');
	BTNode *t = Search1(p, 'O');
	BTNode *common = CommonAncestor(p, s, t);
	cout << "公共祖先为"<<common->data << endl;*/
	//cout << "该二叉树的宽度为" << BTwidth(p) << endl;
	/*int x=Similar(p, p1);
	if (x == 1)
		cout << "相似" << endl;
	else
		cout << "不相似" << endl;*/
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
	////cout << "带权路径长度为" <<WPL(root)<< endl;
	//cout << "带权路径长度为" << wpl_LevelOrder(root) << endl;
	return 0;
}