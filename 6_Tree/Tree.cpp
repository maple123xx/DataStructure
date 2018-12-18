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
	p->ltag = p->rtag = 0;
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
int sum = 0;
int stack[N_Node];
int top = -1;
void Print_Road(BTNode *root, int x) {
	//�Ӹ���ʼ���·���һֱ��Ҷ�ڵ㣬�����������нڵ��γ�һ��·��
	//������к�x��ȵ�·��
	if (root) {				//�ݹ�ķ���
		sum += root->data;
		stack[++top] = root->data;
		if (!root->lchild && !root->rchild&&sum==x) {
			for (int i = 0; i <= top; ++i) {
				cout << stack[i] << '\t';
			}
			cout << endl;
		}
		Print_Road(root->lchild, x);
		Print_Road(root->rchild, x);
		sum -= stack[top--];
	}
	//bool flag = false;		//�ǵݹ�ķ���
	//BTNode *p = root;
	//BTNode *stack[N_Node];
	//int top = -1;
	//BTNode *SumStack[N_Node];//�������浱ǰ����ջ��Ԫ��ֵ��
	//int top1 = -1,i,sum=0;
	//while (top != -1 || p) {
	//	if (p) {
	//		stack[++top] = p;
	//		SumStack[++top1] = p;
	//		sum += SumStack[top1]->data;
	//		p = p->lchild;
	//	}
	//	else {
	//		p = stack[top--];
	//		flag = p->lchild == NULL ? true : false;
	//		p = p->rchild;			
	//		if (!p) {
	//			if (sum == x&&flag) {
	//				cout << "·��Ϊ��" << endl;
	//				for (i = 0; i <= top1; ++i) {
	//					cout << SumStack[i]->data << '\t';
	//				}
	//				cout << endl;
	//			}
	//			while (SumStack[top1]!=stack[top]) {	//����ջ��ָ��ָ���Ԫ����һ����
	//				sum -= SumStack[top1--]->data;
	//			}
	//		}
	//	}
	//}
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
int NoSonNodes(BTNode *root) {
	//ͳ��Ҷ�ڵ����
	//�ǵݹ�ķ�����DoubleSonNodes�ĸ�һ�¾Ϳ�����
	if (!root)
		return 0;
	else if (root->lchild == NULL&&root->rchild == NULL)
		return 1 + NoSonNodes(root->lchild) + NoSonNodes(root->rchild);
	else
		return NoSonNodes(root->lchild) + NoSonNodes(root->rchild);
}
int SingleSonNodes(BTNode *root) {
	//ͳ�ƶ�Ϊ1�Ľڵ����
	//�ǵݹ�ķ�����DoubleSonNodes�ĸ�һ�¾Ϳ�����
	if (!root)
		return 0;
	else if ((!root->lchild&&root->rchild) || (root->lchild && !root->rchild))
		return 1 + SingleSonNodes(root->lchild) + SingleSonNodes(root->rchild);
	else
		return SingleSonNodes(root->lchild) + SingleSonNodes(root->rchild);
}
void SwapTree(BTNode *root) {	//��������������������
	if (root) {
		if(root->lchild)
			SwapTree(root->lchild);
		if(root->rchild)
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
}
void DeleteLeaf(BTNode *&root) {
	//ɾ��������������Ҷ�ڵ�
	bool lflag = false, rflag = false;
	if (root) {
		if (!root->lchild && !root->rchild) {
			free(root);
			root = NULL;
			return;
		}
		if (root->lchild) {
			if (!root->lchild->lchild && !root->lchild->rchild) {
				lflag = true;
				free(root->lchild);
				root->lchild = NULL;
			}
		}
		if (root->rchild) {
			if (!root->rchild->lchild && !root->rchild->rchild) {
				rflag = true;
				free(root->rchild);
				root->rchild = NULL;
			}
		}
		if(!lflag)
			DeleteLeaf(root->lchild);
		if(!rflag)
			DeleteLeaf(root->rchild);
	}
	//BTNode *p;			//�ò�α���
	//BTNode *queue[N_Node];
	//int rear = 0, front = 0;
	//queue[++rear] = root;
	//while (rear != front) {
	//	p = queue[++front];
	//	if (p->lchild) {			
	//		if (p->lchild->lchild == NULL&&p->lchild->rchild == NULL) {//�ж������ǲ���Ҷ�ڵ�
	//			DeleteXTree(p->lchild);
	//			p->lchild = NULL;
	//		}
	//		else {
	//			queue[++rear] = p->lchild;
	//		}
	//	}
	//	if (p->rchild) {			
	//		if (p->rchild->lchild == NULL&&p->rchild->rchild == NULL) {//�ж��Һ����ǲ���Ҷ�ڵ�
	//			DeleteXTree(p->rchild);
	//			p->rchild = NULL;
	//		}
	//		else {
	//			queue[++rear] = p->rchild;
	//		}
	//	}
	//	
	//}
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
BTNode *PreInCreate(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2) {
	// ������������������������һ��������,�ٶ��������н�������ֵ������ͬ����Ҫ��
	BTNode *root = (BTNode *)malloc(sizeof(BTNode));
	root->data = A[l1];
	root->ltag = root->rtag = 0;
	int i;
	for (i = l2; B[i] != root->data; ++i);//�ҵ�λ���м�Ľڵ㣨���ڵ㣩
	int llen = i - l2;//����������
	int rlen = h2 - i;		//����������
	if (llen)
		root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if (rlen)
		root->rchild = PreInCreate(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;

}
void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2) {
	int half;//֪��һ�������������������������������
	if (h1>=l1) {
		post[h2] = pre[l1];
		half = (h1 - l1) / 2;
		PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}
void Level_X(BTNode *root, int x, int L, int *res) {
	//��Ԫ��ֵΪx��Ԫ�����ڵĲ��
	if (root) {
		if (root->data == x)
			*res = L;		//*res�Ƿ���ֵ������x�Ĳ��
		Level_X(root->lchild, x, L+1, res);
		Level_X(root->rchild, x, L+1, res);
	}
}
int Level_X2(BTNode *root, int x) {
	//��Ԫ��ֵΪx��Ԫ�����ڵĲ�εĵڶ��ַ���
	if(!root)
		return 0;
	if (root->data == x)
		return 1;
	int a = Level_X2(root->lchild, x);
	if (a)			//�����������ҵ��ˣ�����a+1
		return 1 + a;
	else {
		int b = Level_X2(root->rchild, x);
		if(b)		//ͬ�������������ҵ��ˣ�����b+1
			return 1 + b;
	}
}
void PreValue_Level(BTNode *root,int L) {
	//�������ÿ���ڵ��ֵ�����ڲ��
	if (root) {
		cout << root->data << '\t' << L << endl;
		PreValue_Level(root->lchild,L+1);//������������棬�ݹ�����ʱ��ÿ��L+1
		PreValue_Level(root->rchild,L+1);//�ݹ鵽���ˣ������൱������һ�ε��õ�L�ϼ�1
	}
}
LinkedList head, p = NULL;
LinkedList InOrderLeaf(BTNode *root) {//����������Ҷ������ָ�봮����
	if (root) {
		InOrderLeaf(root->lchild);
		if (root->lchild == NULL && root->rchild == NULL) {
			if (p == NULL) {
				head = root;
				p = root;
			}
			else {
				p->rchild = root;
				p = root;
			}
		}
		InOrderLeaf(root->rchild);
		p->rchild = NULL;
	}
	return head;

}
void PrintLeaf(BTNode *root) {//��Ҷ�ӽڵ����
	LinkedList pHead = InOrderLeaf(root);
	while (pHead) {
		cout << pHead->data << '\t';
		pHead = pHead->rchild;
	}
}
void All_leaf_Path_Core(BTNode *root,BTNode *path[],int &top) {
	if (root) {
		path[++top] = root;
		if (!root->lchild && !root->rchild) {
			for (int i = 0; i <= top; ++i) {
				cout << path[i]->data << '\t';
			}
			cout << endl;
		}
		All_leaf_Path_Core(root->lchild, path, top);
		All_leaf_Path_Core(root->rchild, path, top);
		--top;	//����һ�������븸�ڵ���Һ���
	}
}
void All_leaf_Path(BTNode *root) {
	//��ӡ�������и���ÿ��Ҷ�ӵ�·��
	BTNode *path[N_Node];
	int top = -1;
	All_leaf_Path_Core(root, path, top);
}

weightBTNode* CreateWeightTree(const string &str) {//��һ�Ŵ�Ȩ·�������൱�ڰ����Ľڵ���Ϣ��ΪȨֵ����������
	weightBTNode *p;
	try
	{
		int i;
		int num_node;
		int tree_weight[N_Node];
		int tree_order[N_Node];
		p = (weightBTNode *)malloc(sizeof(weightBTNode));
		p->lchild = p->rchild = NULL;

		ifstream ins(str);
		if (!ins) { throw exception(); }
		ins >> num_node;//����һ�У�����ڵ����
		if (num_node < 1) { throw exception(); }

		for (i = 1; i <= num_node; ++i) {//����������ݶԣ�int��int����ǰ�߱�ʾweight��
			ins >> tree_weight[i];		 //���߱�ʾ��λ������ȫ������������Ӧ����ţ����������Ϊ1��
			ins >> tree_order[i];
		}
		for (i = 1; i <= num_node; ++i)//ͨ�������ҵ���һ������㣬��Ϊ�����ʱ����ܲ��ǰ�˳�����
		{
			if (tree_order[i] == 1)		//���������Ϊ1
			{
				CreateWeightTree2(i, num_node, tree_weight, tree_order, p);
			}
		}
	}
	catch (...)//...��ʾ�������д���
	{
		printErrorAndExit("CreateTree");
	}
	return p;
}
void CreateWeightTree2(int root, int num_node, int tree_weight[N_Node], int tree_order[N_Node], weightBTNode *p) {
	int i;					//�ݹ鴴�����Ľڵ�
							//	BTNode *lchild, *rchild;
	p->weight = tree_weight[root];
	for (i = 1; i <= num_node; ++i) {
		if (tree_order[i] == tree_order[root] * 2) {
			weightBTNode *lchild = (weightBTNode *)malloc(sizeof(weightBTNode));
			p->lchild = lchild;
			lchild->lchild = lchild->rchild = NULL;
			CreateWeightTree2(i, num_node, tree_weight, tree_order, lchild);
		}
		else if (tree_order[i] == tree_order[root] * 2 + 1) {
			weightBTNode *rchild = (weightBTNode *)malloc(sizeof(weightBTNode));
			p->rchild = rchild;
			rchild->lchild = rchild->rchild = NULL;
			CreateWeightTree2(i, num_node, tree_weight, tree_order, rchild);
		}
	}
}
int WPL(weightBTNode *root) {//���Ȩ·����,��ʵ��ȫû�б�Ҫд����Ȩ���Ĵ��룬��ElemType��char��Ϊint�Ϳɵ�weight��
	return wpl_PreOrder(root, 0);//����ֻ��һ�����ڵ㣬��Ȩ·��Ϊ0����Ȼ��Ҷ�ڵ㣬����û�б�
}
int wpl_PreOrder(weightBTNode *root, int deep) {

	static int wpl = 0;	//��һ���ݹ�
	if (root->lchild == NULL && root->rchild == NULL)
		wpl += deep*root->weight;
	if (root->lchild)
		wpl_PreOrder(root->lchild, deep + 1);
	if (root->rchild)
		wpl_PreOrder(root->rchild, deep + 1);
	return wpl;
}
int wpl_LevelOrder(weightBTNode *root) {
	weightBTNode *p;	//���Ȩ��·���ĵڶ��ַ�������α���
	weightBTNode *queue[N_Node];
	int rear = 0, front = 0;
	int wpl = 0, deep = 0;//��ʼ��wpl�����
	weightBTNode *lastNode;//��¼��ǰ������һ���ڵ�
	weightBTNode *newLastNode;//��¼��һ������һ���ڵ�
	lastNode = root;//��ʼ��Ϊ���ڵ�
	newLastNode = NULL;//��ʼ��Ϊ��
	queue[++rear] = root;
	while (rear != front) {
		p = queue[++front];//����
		if (p->lchild == NULL && p->rchild == NULL)
			wpl += deep*p->weight;
		if (p->lchild) {
			queue[++rear] = p->lchild;
			newLastNode = p->lchild;//����һ������һ���ڵ�Ϊ�ýڵ����ڵ�
		}
		if (p->rchild) {
			queue[++rear] = p->rchild;
			newLastNode = p->rchild;//����һ������һ���ڵ�Ϊ�ýڵ����ڵ�
		}
		if (p == lastNode) {//���ýڵ�Ϊ��������һ���ڵ㣬�����lastNode
			lastNode = newLastNode;
			++deep;			//������1
		}
	}
	return wpl;
}
int Caculation_Core(int A, int B, char C) {
	switch (C)
	{
	case '+':return A + B;
	case '-':return A - B;
	case '*':return A * B;
	case '/':return A / B;
	case '%':return A % B;
	default:
		cout << "�ļ���ʽ���ԣ����������" << endl;
		exit(1);
	}
}
int Caculation(BTNode *root) {
	//����+��-��*��/��%
	//rootֻ���ж�Ϊ2��0�Ľ�㣬��Ϊ2�Ľ��������5����������ַ�����Ϊ0�Ľ������ֵ0~9���ַ�
	if (root) {
		int l_value, r_value;
		if (root->lchild&&root->rchild) {
			l_value = Caculation(root->lchild);
			r_value = Caculation(root->rchild);
			return Caculation_Core(l_value, r_value, root->data);
		}
		else {
			return root->data - '0';//�ַ�תint
		}
	}
	else {
		return 0;
	}
}

//������������һЩ����
void Create_BST(BTNode *&root, ElemType str[], int n) {
	root = NULL;
	for (int i = 0; i < n; ++i) {
		BST_Insert(root, str[i]);
	}
}
bool BST_Insert(BTNode *&root, ElemType key) {//��Ϊ��ı�root,����Ҫ��&root
	//������½ڵ�һ����ĳ��Ҷ�ڵ�
	if (!root) {
		root = (BTNode *)malloc(sizeof(BTNode));
		root->data = key;
		root->lchild = root->rchild = NULL;
		return true;
	}
	else if (root->data == key)
		return false;	//����������ͬ�ؼ��ֵĽڵ�
	else if (root->data > key)
		return BST_Insert(root->lchild, key);
	else
		return BST_Insert(root->rchild, key);
}
bool BST_Delete_Core(BTNode *&root) {
	//����������ɾ����㣬���ҵ��ؼ���key
	//ָ��rootָ��ؼ���key
	BTNode *s,*q;
	if (root->lchild == NULL&&root->rchild == NULL) {
		root = NULL;
	}
	else if (root->lchild == NULL) {	//�������գ�������������root
		q = root->rchild;
		*root = *q;	//�൱�ڿ�����һ��
		free(q);
	}
	else if (root->rchild == NULL) {
		q = root->lchild;
		*root = *q;
		free(q);
	}
	else {			//�������������գ���root��ֱ��ǰ��(�����������ҽڵ�)����
		q = root;
		s = root->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		root->data = s->data;
		if (q == root)
			q->lchild = s->lchild;
		else {
			q->rchild = s->lchild;
		}
		free(s);
	}
	return true;
}
bool BST_Delete(BTNode *&root, ElemType key) {
	//�������������ڹؼ���key��ɾ��֮����������������������true
	//���ؼ���key�����ڣ���ɾ��ʧ�ܷ���false
	if (root==NULL)
		return false;	//��Ϊ�գ�����false
	else if (root->data == key) {
		BST_Delete_Core(root);
		return true;
	}
	else if (root->data > key) {
		return BST_Delete(root->lchild,key);
	}
	else {
		return BST_Delete(root->rchild,key);
	}
}
BTNode *SearchBST(BTNode *root, ElemType key, BTNode *&p) {
	//���Һ�������ָ��ؼ���ΰkey�Ľڵ�ָ�룬�����ڷ���NULL
	p = NULL;
	while (root&&root->data != key) {
		p = root;	//pָ�򱻲��ҽڵ��˫�ף����ڲ����ɾ������
		if (root->data > key) {
			root = root->lchild;
		}
		else
			root = root->rchild;
	}
	return root;
}
bool SearchBST2(BTNode *root, ElemType key, BTNode *&parent, BTNode *&p) {
	//�ݹ�Ĳ���
	//���ҳɹ�����true��ͬʱָ��pָ���Ԫ�ؽ�㣻����ʧ�ܷ���FALSE��ָ��pָ�����·���ϵ����һ�����
	//ָ��parentָ��root��˫�ף���ʼ����ֵΪNULL
	if (!root) {
		p = parent;
		return false;
	}
	else if (root->data == key) {
		p = root;
		return true;
	}
	else if (root->data > key) {
		SearchBST2(root->lchild, key, root, p);
	}
	else
	{
		SearchBST2(root->rchild, key, root, p);
	}
}
ElemType pre = -9999;//ȫ�ֱ��������浱ǰ�ڵ�����ǰ����ֵ����ʼ��Ϊһ����С��ֵ
bool JudgeBST1(BTNode *root) {
	//�жϸ����������Ƿ�Ϊ����������
	//�ⷨһ���������������Ϊ�������У�ǰһ��ֵ�Ƿ�����С�ں�һ��ֵ
	int b1, b2;
	if (!root)
		return true;
	else {
		b1 = JudgeBST1(root->lchild);
		if (!b1 || pre >= root->data)
			return false;
		pre = root->data;	//����pre��ֵ
		b2 = JudgeBST1(root->rchild);
		return b2;
	}
}
bool JudgeBST2(BTNode *root) {
	//�ⷨ�����ж�ÿ������Ƿ����������С�����Һ��ӣ��ݹ�ķ���
	if (!root)
		return true;
	if (root->lchild == NULL&&root->rchild == NULL)
		return true;
	else if (root->lchild == NULL) {
		if (root->rchild->data < root->data)
			return false;
		else
			return JudgeBST2(root->rchild);
	}
	else if (root->rchild == NULL) {
		if (root->lchild->data > root->data)
			return false;
		else
			return JudgeBST2(root->lchild);
	}
	else {
		if ((root->data < root->lchild->data) || (root->data > root->rchild->data))
			return false;
		else
			return JudgeBST2(root->lchild) && JudgeBST2(root->rchild);
	}
}
int BST_Level(BTNode *root, ElemType key) {
	if (!root)
		return 0;
	int count = 1;
	while (root&&root->data != key) {
		++count;
		if (root->data > key)
			root = root->lchild;
		else
			root = root->rchild;
	}
	return count;
}
void MinKey(BTNode *root) {
	while (root->lchild) {
		root = root->lchild;
	}
	cout << "��������������СֵΪ" << root->data << endl;
}
void MaxKey(BTNode *root) {
	while (root->rchild) {
		root = root->rchild;
	}
	cout << "���������������ֵΪ" << root->data << endl;
}
void Output_Max_K(BTNode *root,ElemType k) {
	//�Ӵ�С������д��ڵ���k����
	//�Ӵ�С��������ȴ��������ݹ�
	if (root) {
		Output_Max_K(root->rchild,k);
		if (root->data >= k)
			cout << root->data << '\t';
		Output_Max_K(root->lchild, k);
	}
}
int Count_Node(BTNode *root) {
	//�洢�Ըýڵ�Ϊ���������Ľڵ����
	if (!root) {
		return 0;
	}
	else {
		root->count = 1 + Count_Node(root->lchild) + Count_Node(root->rchild);
	}
}
BTNode* Number_K(BTNode *root, int k) {
	//����rootΪ���Ķ�����������Ѱ�ҵ�kС��Ԫ�أ����������ڽڵ��ָ��
	if (k<1 || k>root->count)
		return NULL;
	if (!root->lchild) {
		if (k == 1)
			return root;
		else
			return Number_K(root->rchild, k - 1);
	}
	else {
		if (root->lchild->count == k - 1)
			return root;
		if (root->lchild->count > (k - 1))
			return Number_K(root->lchild, k);
		if (root->lchild->count < (k - 1))
			return Number_K(root->rchild, k - (root->lchild->count + 1));
	}
}

//�����������Ĳ������Ժ�����Ѷ������������ˣ��ж���û�����Ӿ�Ҫ��root->ltag==0,������root->lchild==NULL�ˣ�û���������Ļ����ճ�
//�Ժ����Ҫ�������������Ļ�����Ҫ�ڴ���һ���ڵ��ʱ��root->ltag=s->rtag=0;
void InThread_Core(BTNode *root, BTNode *&pre) {
	if (root) {
		InThread_Core(root->lchild, pre);//�ݹ飬������������
		if (!root->lchild) {			//������Ϊ�գ�����ǰ������
			root->lchild = pre;
			root->ltag = 1;
		}
		if (pre&&pre->rchild == NULL) {	//����ǰ���ڵ�ĺ������
			pre->rchild = root;	
			pre->rtag = 1;
		}
		pre = root;					//��ǵ�ǰ�ڵ�Ϊ�ոշ��ʹ��Ľڵ�
		InThread_Core(root->rchild, pre);	//�ݹ飬������������
	}
}
void InThread(BTNode *root) {
	//ͨ���������������������
	if (root) {
		BTNode *pre = NULL;		//ǰ���ڵ�
		InThread_Core(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
BTNode *FirstNode(BTNode *p) {
	//�������������������������µĵ�һ���ڵ�
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}
BTNode *NextNode(BTNode *p) {
	//��ڵ�p�������е���һ���ڵ�
	if (p->rtag == 0)
		return FirstNode(p->rchild);	//��������Ϊ�գ����������������½ڵ�
	else
		return p->rchild;	//rtag=1��ֱ�ӷ��غ��
}
void InOrder_Thread(BTNode *root) {
	//���������������Ķ�����
	BTNode *p = FirstNode(root);
	while (p) {
		cout << p->data << '\t';
		p=NextNode(p);
	}
	cout << endl;
}
void PreThread_Core(BTNode *root, BTNode *&pre) {
	if (root) {
		if (!root->lchild) {	//û������
			root->lchild = pre;
			root->ltag = 1;
		}
		if (pre && !pre->rchild) {
			pre->rchild = root;
			pre->rtag = 1;
		}
		pre = root;
		if(root->ltag==0)		//����һ��Ҫ���жϣ���Ȼ����ѭ���ˣ�
			PreThread_Core(root->lchild, pre);
		if(root->rtag==0)
			PreThread_Core(root->rchild, pre);
	}
}
void PreThread(BTNode *root) {
	//ͨ���������������������
	if (root) {
		BTNode *pre = NULL;
		PreThread_Core(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
void PreOrder_Thread(BTNode *root) {
	//���������������Ķ�����
	if (root) {
		BTNode *p = root;
		while (p) {
			while (p->ltag == 0) {
				cout << p->data << '\t';
				p = p->lchild;				//�߷��ʱ��ƶ�
			}
			cout << p->data << '\t';	//��p->ltag=1ʱ�Ѿ�����ѭ���ˣ����Ի�Ҫ������
			p = p->rchild;	//��p���Һ��ӣ���ָ���Һ��ӣ���pû���Һ��ӣ���ָ������
		}
		}
}