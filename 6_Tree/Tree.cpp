#include"Tree.h"

BTNode* CreateTree(const string &str) {
	BTNode *p;
	try
	{
		
		int i;
		int num_node;
		ElemType tree_data[N_Node];
		int tree_order[N_Node];
		p = (BTNode *)malloc(sizeof(BTNode));
		p->lchild = p->rchild = NULL;

		ifstream ins(str);
		if (!ins) { throw exception(); }
		ins >> num_node;//����һ�У�����ڵ����
		if (num_node < 1) { throw exception(); }

		for (i = 1; i <= num_node; ++i) {//����������ݶԣ�BT_type��int����ǰ�߱�ʾdata��
			ins >> tree_data[i];		 //���߱�ʾ��λ������ȫ������������Ӧ����ţ����������Ϊ1��
			ins >> tree_order[i];
		}
		for (i = 1; i <= num_node; ++i)//ͨ�������ҵ���һ������㣬��Ϊ�����ʱ����ܲ��ǰ�˳�����
		{
			if (tree_order[i] == 1)		//���������Ϊ1
			{
				CreateTree2(i, num_node, tree_data, tree_order, p);
			}
		}
		
	}
	catch (...)//...��ʾ�������д���
	{
		printErrorAndExit("CreateTree");
	}

	return p;

}
void CreateTree2(int root, int num_node, ElemType tree_data[N_Node], int tree_order[N_Node], BTNode *p) {
	int i;					//�ݹ鴴�����Ľڵ�
//	BTNode *lchild, *rchild;
	p->data = tree_data[root];
	for (i = 1; i <= num_node; ++i) {
		if (tree_order[i] == tree_order[root] * 2) {
			BTNode *lchild = (BTNode *)malloc(sizeof(BTNode));
			p->lchild = lchild;
			lchild->lchild = lchild->rchild = NULL;
			CreateTree2(i, num_node, tree_data, tree_order, lchild);
		}
		else if (tree_order[i] == tree_order[root] * 2 + 1) {
			BTNode *rchild = (BTNode *)malloc(sizeof(BTNode));
			p->rchild = rchild;
			rchild->lchild = rchild->rchild = NULL;
			CreateTree2(i, num_node, tree_data, tree_order, rchild);
		}
	}
}
void PreOrder(BTNode *root) {//��������ݹ��
	if (root) {
		cout <<root->data<< '\t';
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void InOrder(BTNode *root) {//��������ݹ��
	if (root) {
		InOrder(root->lchild);
		cout << root->data << '\t';
		InOrder(root->rchild);
		
	}
}
void PostOrder(BTNode *root) {//��������ݹ��
	if (root) {
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout << root->data << '\t';
	}
}
void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}