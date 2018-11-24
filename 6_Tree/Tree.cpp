#include"Tree.h"
using namespace std;

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
int getDepth2(BTNode *root) {	//�ǵݹ���������ȣ��ò�α���
	if (!root)
		return 0;
	BTNode *p;
	BTNode *queue[N_Node];
	int front = 0, rear = 0;
	int last = 1, level = 1;	//lastָ��ǰ�����ҽڵ�
	queue[++rear] = root;	//û��ʹ��ѭ�����У�������һ��
	while (rear != front) {
		p = queue[++front];
		if(p->lchild)
			queue[++rear] = p->lchild;
		if (p->rchild)
			queue[++rear] = p->rchild;
		if (last == front) {	//����ò����ҽڵ�
			++level;
			last = rear;
		}
	}
	return level - 1;
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

	//BTNode *p;		//��һ��̫���ķ���
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

	//BTNode *p=root;	//��һ��̫���ķ�����������ջ���ڵ�����ջ��ջ1���ٳ�ջ��ջ2��������ջ2
	//BTNode *stack1[N_Node],*stack2[N_Node];
	//int top1 = -1, top2 = -1;
	//stack1[++top1] = p;
	//while (top1 != -1)
	//{
	//	p = stack1[top1--];
	//	stack2[++top2] = p;
	//	if (p->lchild)
	//		stack1[++top1]=p->lchild;
	//	if(p->rchild)
	//		stack1[++top1] = p->rchild;
	//}
	//while (top2 != -1)
	//{
	//	p = stack2[top2--];
	//	cout << p->data << '\t';
	//}

	BTNode *p = root;		//���������ñ��
	BTNode *stack[N_Node];
	int top = -1;
	BTNode *r = NULL;	//���ָ��
	while (p || top != -1)
	{
		if (p) {			//�ߵ������
			stack[++top] = p;
			p = p->lchild;
		}
		else           //����
		{
			p = stack[top];	//���ǳ�ջ������ȡջ���ڵ㸳��p
			if (p->rchild && p->rchild != r) {//���p���Һ��ӣ����Һ���δ�����ʹ�
				p = p->rchild;		//ת����
				stack[++top] = p;	//��ջ
				p = p->lchild;		//����������
			}
			else             //���򵯳���㲢����
			{
				p = stack[top--];
				cout << p->data << '\t';
				r = p;				//���pΪ���ʹ�
				p = NULL;			//��p�ÿպ���Ҫ����Ȼû��û�˵�һֱѭ��
			}
		}
	}
}
void InverseLevel(BTNode *root) {	//���¶��ϣ���������Ĳ�α���
	BTNode *p;
	BTNode *queue[N_Node], *stack[N_Node];
	int top = -1;
	int rear = 0, front = 0;
	rear = (rear + 1) % N_Node;
	queue[rear] = root;
	while (rear != front)
	{
		front = (front + 1) % N_Node;
		p = queue[front];	//����
		stack[++top] = p;	//�����ʣ�������ջ
		if (p->lchild) {
			rear = (rear + 1) % N_Node;
			queue[rear] = p->lchild;
		}
		if (p->rchild) {
			rear = (rear + 1) % N_Node;
			queue[rear] = p->rchild;
		}
	}
	while (top != -1)
	{
		p = stack[top--];
		cout << p->data << '\t';
	}
}
void IsComplete(BTNode *root) {	//�ж϶������ǲ�����ȫ���������ò�α�������һ���սڵ���нڵ㣬������ȫ������
	if (!root) {
		cout << "������ȫ������" << endl;
		return;
	}
	BTNode *p;
	BTNode *queue[N_Node];
	int rear = 0, front = 0;
	queue[++rear] = root;
	while (rear != front) {
		p = queue[++front];
		if (p) {
			queue[++rear] = p->lchild;
			queue[++rear] = p->rchild;
		}
		else {
			p = queue[++front];
			if (p) {
				cout << "������ȫ������" << endl;
				return;
			}
		}
	}
	cout<< "����ȫ������" << endl;
	return;
}
int DoubleSonNodes(BTNode *root) {
	//if (!root)			//��һ���ݹ�
	//	return 0;
	//else if (root->lchild && root->rchild)
	//	return DoubleSonNodes(root->lchild) + DoubleSonNodes(root->rchild) + 1;
	//else
	//{
	//	return DoubleSonNodes(root->lchild) + DoubleSonNodes(root->rchild);
	//}

	BTNode *p=root;			//�������ǵݹ飬���ñ���num,ÿ����һ���ڵ���ж�һ��
	BTNode *stack[N_Node];
	int top = -1;
	int num = 0;
	while (p || top != -1)
	{
		if (p) {
			stack[++top] = p;
			if (p->lchild && p->rchild)
				++num;
			p = p->lchild;
		}
		else
		{
			p = stack[top--];
			p = p->rchild;
		}
	}
	return num;
}
void SwapTree(BTNode *root) {	//��������������������
	if (root) {
		SwapTree(root->lchild);
		SwapTree(root->rchild);
		swap(root->lchild, root->rchild);
	}
}
ElemType PreKNode(BTNode *root,int k) {//��������������е�k���ڵ��ֵ
	BTNode *p = root;
	BTNode *stack[N_Node];
	int top = -1;
	int i = 1;
	while (p || top != -1)
	{
		if (p) {
			stack[++top] = p;
			if (i == k)
				return p->data;
			++i;
			p = p->lchild;
		}
		else
		{
			p = stack[top--];
			p = p->rchild;
		}
	}
	return '*';
}
void DeleteXTree(BTNode *root) {//ɾ����rootΪ��������
	if (root) {
		DeleteXTree(root->lchild);
		DeleteXTree(root->rchild);
		free(root);
	}
}
void DeleteX(BTNode *root, ElemType x) {//ɾ����xΪ�������������ͷſռ�
	if (root) {
		if (root->data == x) {
			DeleteXTree(root);
			exit(0);
		}
	}
	BTNode *p;			//�ò�α���
	BTNode *queue[N_Node];
	int rear = 0, front = 0;
	queue[++rear] = root;
	while (rear != front) {
		p = queue[++front];
		if (p->lchild) {
			if (p->lchild->data == x) {
				DeleteXTree(p->lchild);
				p->lchild = NULL;
			}
			else
				queue[++rear] = p->lchild;
		}
		if (p->rchild) {
			if (p->rchild->data == x) {
				DeleteXTree(p->rchild);
				p->rchild = NULL;
			}
			else
				queue[++rear] = p->rchild;
		}
	}
}
void SearchX(BTNode *root,ElemType x) {	//����ֵΪx�Ľڵ㣬����ӡ�ýڵ���������ȣ�����ֵΪx�Ľڵ�Ψһ
	BTNode *p = root;			//�ú���������������ĳ���ڵ�ʱ��ջ��Ԫ�ض�����������
	BTNode *stack[N_Node];
	BTNode *r = NULL;
	int top = -1;
	while (p || top != -1) {
		if (p) {
			stack[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = stack[top];
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
				stack[++top] = p;
				p = p->lchild;
			}
			else
			{
				p = stack[top--];
				if (p->data == x) {
					while (top != -1)
					{
						p = stack[top--];
						cout << p->data << '\t';
					}
				}
				r = p;
				p = NULL;
			}
		}
	}
}
BTNode *Search1(BTNode *root, ElemType x) {//����ֵΪx�Ľ�㣬�������򷵻�ָ��ý���ָ�룬���򷵻�NULL
	BTNode *p = NULL;
	if (root) {
		if (root->data == x)
			p = root;
		else
		{
			p = Search1(root->lchild, x);
			if (p == NULL)
				p = Search1(root->rchild,x);
		}
	}
	return p;
}
BTNode *CommonAncestor(BTNode *root, BTNode *s, BTNode *t) {
	BTNode *p = root;			//Ѱ�ҽڵ�s��t������������Ƚڵ㣬�ú������
	BTNode *stack[N_Node], *stack1[N_Node];
	int top = -1, top1 = -1;
	BTNode *r = NULL;
	while (p || top != -1) {
		if (p) {
			stack[++top] = p;
			p = p->lchild;
		}
		else {
			p = stack[top];
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
				stack[++top] = p;
				p = p->lchild;
			}
			else
			{
				p = stack[top--];
				if (p == s) {
					for (int i = 0; i <= top; ++i)
						stack1[++top1] = stack[i];
				}
				if (p == t) {
					for (int i = top; i >= 0; --i) {
						for (int j = top1; j >= 0; --j) {
							if (stack[i] == stack1[j])
								return stack[i];
						}
					}
				}
				r = p;
				p = NULL;
			}
		}
	}
	return NULL;
}
int BTwidth(BTNode *root) {//�����Ŀ��
	BTNode *p;
	BT_Width queue[N_Node];
	int rear = 0, front = 0;
	int k,max=0;
	int depth = getDepth(root);	//���������
	int num[N_lev];		//��¼ÿһ��ڵ��������飬��ÿһ��Ŀ��
	for (int i = 1; i <= depth; ++i)
		num[i] = 0;
	rear = (rear + 1) % N_Node;
	queue[rear].t_node = root;//���ڵ����
	queue[rear].num_level = 1;//���ڵ�Ĳ����Ϊ1

	while (rear != front) {
		front = (front + 1) % N_Node;
		k = queue[front].num_level;	//k��¼���ӽڵ����ڲ��
		++num[k];						//�ò�ڵ���+1
		p = queue[front].t_node;
		if (p->lchild) {
			rear = (rear + 1) % N_Node;
			queue[rear].t_node = p->lchild;
			queue[rear].num_level = k+1;	//�����+1
		}
		if (p->rchild) {
			rear = (rear + 1) % N_Node;
			queue[rear].t_node = p->rchild;
			queue[rear].num_level = k + 1;
		}
	}
	for (int i = 1; i < N_lev; ++i) {
		if (num[i] > max)
			max = num[i];
	}
	return max;
}
int Similar(BTNode *root1, BTNode *root2) {//�ж����ö������Ƿ�����
	int left, right;
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}
	else if (root1 == NULL || root2 == NULL) {
		return 0;
	}
	else
	{
		left = Similar(root1->lchild, root2->lchild);
		right = Similar(root1->rchild, root2->rchild);
		return left&&right;
	}
}