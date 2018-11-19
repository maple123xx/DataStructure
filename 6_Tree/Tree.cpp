#include"Tree.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
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
int getDepth(BTNode *root) {//�����������
	if (root == NULL)
		return 0;
	else
	{
		int ldepth, rdepth;
		ldepth = getDepth(root->lchild);
		rdepth = getDepth(root->rchild);
		return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
	}
}
void LevelOrder(BTNode *root) {//�ǵݹ�Ĳ�α���
	BTNode *p;
	int rear = 0, front = 0;
	BTNode *queue[N_Node];
	rear = (rear + 1) % N_Node;
	queue[rear] = root;
	while (rear != front)//���в���ʱ,100���ڵ�϶��ﲻ�������Բ��ù�rear!=front�Ƕӿջ��Ƕ���
	{
		front = (front + 1) % N_Node;
		p = queue[front];
		cout << p->data << '\t';
		if (p->lchild) {
			rear = (rear + 1) % N_Node;
			queue[rear] = p->lchild;
		}
		if (p->rchild) {
			rear = (rear + 1) % N_Node;
			queue[rear] = p->rchild;
		}

	}
}
void PreOrder2(BTNode *root) {	//��������ķǵݹ�汾
	//BTNode *p;		//��һ��̫���ķ�����
	//BTNode *stack[N_Node];
	//int top = -1;
	//stack[++top] = root;
	//while (top != -1)//ջ����ʱ
	//{
	//	p = stack[top--];
	//	cout << p->data << "\t";
	//	if (p->rchild)		//�Һ����Ƚ�ջ
	//		stack[++top] = p->rchild;
	//	if (p->lchild)
	//		stack[++top] = p->lchild;
	//}

	BTNode *p = root;			//����������������ǵݹ������ֻ�����data�ĵط���һ��
	BTNode *stack[N_Node];
	int top = -1;
	while (top != -1 || p)
	{
		if (p) {
			stack[++top] = p;
			cout << p->data << '\t';
			p = p->lchild;
		}
		else
		{
			p = stack[top--];
			p = p->rchild;
		}
	}
}
void InOrder2(BTNode *root) {	//��������ķǵݹ�汾
	BTNode *p=root;
	BTNode *stack[N_Node];
	int top = -1;
	while (top != -1 || p)//p==NULL���жϲ��ܵ���ջ�յ�ʱ�������������û����
	{
		if (p)
		{
			stack[++top] = p;
			p = p->lchild;
		}
		else {
			p = stack[top--];
			cout << p->data << '\t';
			p = p->rchild;
		}
	}
}
void PostOrder2(BTNode *root) {//��������ķǵݹ�汾
	BTNode *p=root;	//̫���ķ�����������ջ���ڵ�����ջ��ջ1���ٳ�ջ��ջ2��������ջ2
	BTNode *stack1[N_Node],*stack2[N_Node];
	int top1 = -1, top2 = -1;
	stack1[++top1] = p;
	while (top1 != -1)
	{
		p = stack1[top1--];
		stack2[++top2] = p;
		if (p->lchild)
			stack1[++top1]=p->lchild;
		if(p->rchild)
			stack1[++top1] = p->rchild;
	}
	while (top2 != -1)
	{
		p = stack2[top2--];
		cout << p->data << '\t';
	}
}