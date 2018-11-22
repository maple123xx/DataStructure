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
		ins >> num_node;//读第一行，代表节点个数
		if (num_node < 1) { throw exception(); }

		for (i = 1; i <= num_node; ++i) {//其余均是数据对（BT_type，int），前者表示data，
			ins >> tree_data[i];		 //后者表示其位置在完全二叉树中所对应的序号（根结点的序号为1）
			ins >> tree_order[i];
		}
		for (i = 1; i <= num_node; ++i)//通过遍历找到第一个根结点，因为读入的时候可能不是按顺序读的
		{
			if (tree_order[i] == 1)		//根结点的序号为1
			{
				CreateTree2(i, num_node, tree_data, tree_order, p);
			}
		}
		
	}
	catch (...)//...表示捕获所有错误
	{
		printErrorAndExit("CreateTree");
	}

	return p;

}
void CreateTree2(int root, int num_node, ElemType tree_data[N_Node], int tree_order[N_Node], BTNode *p) {
	int i;					//递归创建树的节点
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
void PreOrder(BTNode *root) {//先序遍历递归版
	if (root) {
		cout <<root->data<< '\t';
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void InOrder(BTNode *root) {//中序遍历递归版
	if (root) {
		InOrder(root->lchild);
		cout << root->data << '\t';
		InOrder(root->rchild);
		
	}
}
void PostOrder(BTNode *root) {//后序遍历递归版
	if (root) {
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout << root->data << '\t';
	}
}
int getDepth(BTNode *root) {//返回树的深度
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
int getDepth2(BTNode *root) {	//非递归求树的深度，用层次遍历
	if (!root)
		return 0;
	BTNode *p;
	BTNode *queue[N_Node];
	int front = 0, rear = 0;
	int last = 1, level = 1;	//last指向下一层第一个节点
	queue[++rear] = root;	//没有使用循环队列，尽量简单一点
	while (rear != front) {
		p = queue[++front];
		if(p->lchild)
			queue[++rear] = p->lchild;
		if (p->rchild)
			queue[++rear] = p->rchild;
		if (last == front) {	//处理该层最右节点
			++level;
			last = rear;
		}
	}
	return level - 1;
}
void LevelOrder(BTNode *root) {//非递归的层次遍历
	BTNode *p;
	int rear = 0, front = 0;
	BTNode *queue[N_Node];
	rear = (rear + 1) % N_Node;
	queue[rear] = root;
	while (rear != front)//队列不空时,100个节点肯定达不到，所以不用管rear!=front是队空还是队满
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
void PreOrder2(BTNode *root) {	//先序遍历的非递归版本

	//BTNode *p;		//法一：太君的方法
	//BTNode *stack[N_Node];
	//int top = -1;
	//stack[++top] = root;
	//while (top != -1)//栈不空时
	//{
	//	p = stack[top--];
	//	cout << p->data << "\t";
	//	if (p->rchild)		//右孩子先进栈
	//		stack[++top] = p->rchild;
	//	if (p->lchild)
	//		stack[++top] = p->lchild;
	//}

	BTNode *p = root;			//法二：类似于中序非递归遍历，只是输出data的地方不一样
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
void InOrder2(BTNode *root) {	//中序遍历的非递归版本
	BTNode *p=root;
	BTNode *stack[N_Node];
	int top = -1;
	while (top != -1 || p)//p==NULL的判断不能掉，栈空的时候可能右子树还没遍历
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
void PostOrder2(BTNode *root) {//后序遍历的非递归版本

	//BTNode *p=root;	//法一：太君的方法，用两个栈，节点先入栈到栈1，再出栈到栈2，最后遍历栈2
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

	BTNode *p = root;		//法二：设置标记
	BTNode *stack[N_Node];
	int top = -1;
	BTNode *r = NULL;	//标记指针
	while (p || top != -1)
	{
		if (p) {			//走到最左边
			stack[++top] = p;
			p = p->lchild;
		}
		else           //向右
		{
			p = stack[top];	//不是出栈，而是取栈顶节点赋给p
			if (p->rchild && p->rchild != r) {//如果p有右孩子，且右孩子未被访问过
				p = p->rchild;		//转入右
				stack[++top] = p;	//入栈
				p = p->lchild;		//再走向最左
			}
			else             //否则弹出结点并访问
			{
				p = stack[top--];
				cout << p->data << '\t';
				r = p;				//标记p为访问过
				p = NULL;			//将p置空很重要，不然没完没了的一直循环
			}
		}
	}
}
void InverseLevel(BTNode *root) {	//自下而上，自右向左的层次遍历
	BTNode *p;
	BTNode *queue[N_Node], *stack[N_Node];
	int top = -1;
	int rear = 0, front = 0;
	rear = (rear + 1) % N_Node;
	queue[rear] = root;
	while (rear != front)
	{
		front = (front + 1) % N_Node;
		p = queue[front];	//出队
		stack[++top] = p;	//不访问，而是入栈
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
void IsComplete(BTNode *root) {	//判断二叉树是不是完全二叉树，用层次遍历，若一个空节点后还有节点，则不是完全二叉树
	if (!root) {
		cout << "不是完全二叉树" << endl;
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
				cout << "不是完全二叉树" << endl;
				return;
			}
		}
	}
	cout<< "是完全二叉树" << endl;
	return;
}
int DoubleSonNodes(BTNode *root) {
	//if (!root)			//法一：递归
	//	return 0;
	//else if (root->lchild && root->rchild)
	//	return DoubleSonNodes(root->lchild) + DoubleSonNodes(root->rchild) + 1;
	//else
	//{
	//	return DoubleSonNodes(root->lchild) + DoubleSonNodes(root->rchild);
	//}

	BTNode *p=root;			//法二：非递归，设置变量num,每遍历一个节点就判断一下
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
void SwapTree(BTNode *root) {	//交换二叉树的左右子树
	if (root) {
		SwapTree(root->lchild);
		SwapTree(root->rchild);
		swap(root->lchild, root->rchild);
	}
}
ElemType PreKNode(BTNode *root,int k) {
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
}
void DeleteXTree(BTNode *root) {//删除以root为根的子树
	if (root) {
		DeleteXTree(root->lchild);
		DeleteXTree(root->rchild);
		free(root);
	}
}
void DeleteX(BTNode *root, ElemType x) {//删除以x为根的子树，并释放空间
	if (root) {
		if (root->data == x) {
			DeleteXTree(root);
			exit(0);
		}
	}
	BTNode *p;			//用层次遍历
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
void SearchX(BTNode *root,ElemType x) {	//查找值为x的节点，并打印该节点的所有祖先，假设值为x的节点唯一
	BTNode *p = root;			//用后续遍历，当访问某个节点时，栈中元素都是它的祖先
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