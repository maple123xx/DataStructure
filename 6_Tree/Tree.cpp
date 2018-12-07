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
	int last = 1, level = 1;	//last指向当前层最右节点
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
ElemType PreKNode(BTNode *root,int k) {//求先序遍历序列中第k个节点的值
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
BTNode *Search1(BTNode *root, ElemType x) {//查找值为x的结点，若存在则返回指向该结点的指针，否则返回NULL
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
	BTNode *p = root;			//寻找节点s和t的最近公共祖先节点，用后序遍历
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
int BTwidth(BTNode *root) {//求树的宽度
	BTNode *p;
	BT_Width queue[N_Node];
	int rear = 0, front = 0;
	int k,max=0;
	int depth = getDepth(root);	//求树的深度
	int num[N_lev];		//记录每一层节点数的数组，即每一层的宽度
	for (int i = 1; i <= depth; ++i)
		num[i] = 0;
	rear = (rear + 1) % N_Node;
	queue[rear].t_node = root;//根节点入队
	queue[rear].num_level = 1;//根节点的层次数为1

	while (rear != front) {
		front = (front + 1) % N_Node;
		k = queue[front].num_level;	//k记录出队节点所在层次
		++num[k];						//该层节点数+1
		p = queue[front].t_node;
		if (p->lchild) {
			rear = (rear + 1) % N_Node;
			queue[rear].t_node = p->lchild;
			queue[rear].num_level = k+1;	//层次数+1
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
int Similar(BTNode *root1, BTNode *root2) {//判断两棵二叉树是否相似
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
	// 根据先序遍历和中序遍历创建一个二叉树
	BTNode *root = (BTNode *)malloc(sizeof(BTNode));
	root->data = A[l1];
	int i;
	for (i = l2; B[i] != root->data; ++i);//找到位于中间的节点（根节点）
	int llen = i - l2;//左子树长度
	int rlen = h2 - i;		//右子树长度
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
	int half;//知道一颗满二叉树的先序遍历，求其后序遍历
	if (h1>=l1) {
		post[h2] = pre[l1];
		half = (h1 - l1) / 2;
		PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}
LinkedList head, p = NULL;
LinkedList InOrderLeaf(BTNode *root) {//将二叉树的叶子用右指针串起来
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
void PrintLeaf(BTNode *root) {
	LinkedList pHead = InOrderLeaf(root);
	while (pHead) {
		cout << pHead->data << '\t';
		pHead = pHead->rchild;
	}
}


weightBTNode* CreateWeightTree(const string &str) {//建一颗带权路径树，相当于把树的节点信息变为权值，其他不变
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
		ins >> num_node;//读第一行，代表节点个数
		if (num_node < 1) { throw exception(); }

		for (i = 1; i <= num_node; ++i) {//其余均是数据对（int，int），前者表示weight，
			ins >> tree_weight[i];		 //后者表示其位置在完全二叉树中所对应的序号（根结点的序号为1）
			ins >> tree_order[i];
		}
		for (i = 1; i <= num_node; ++i)//通过遍历找到第一个根结点，因为读入的时候可能不是按顺序读的
		{
			if (tree_order[i] == 1)		//根结点的序号为1
			{
				CreateWeightTree2(i, num_node, tree_weight, tree_order, p);
			}
		}
	}
	catch (...)//...表示捕获所有错误
	{
		printErrorAndExit("CreateTree");
	}
	return p;
}
void CreateWeightTree2(int root, int num_node, int tree_weight[N_Node], int tree_order[N_Node], weightBTNode *p) {
	int i;					//递归创建树的节点
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
int WPL(weightBTNode *root) {//求带权路径和,其实完全没有必要写建带权树的代码，把ElemType的char改为int就可当weight了
	return wpl_PreOrder(root, 0);//假设只有一个根节点，带权路径为0，虽然是叶节点，但是没有边
}
int wpl_PreOrder(weightBTNode *root, int deep) {

	static int wpl = 0;	//法一：递归
	if (root->lchild == NULL && root->rchild == NULL)
		wpl += deep*root->weight;
	if (root->lchild)
		wpl_PreOrder(root->lchild, deep + 1);
	if (root->rchild)
		wpl_PreOrder(root->rchild, deep + 1);
	return wpl;
}
int wpl_LevelOrder(weightBTNode *root) {
	weightBTNode *p;	//求带权的路径的第二种方法：层次遍历
	weightBTNode *queue[N_Node];
	int rear = 0, front = 0;
	int wpl = 0, deep = 0;//初始化wpl和深度
	weightBTNode *lastNode;//记录当前层的最后一个节点
	weightBTNode *newLastNode;//记录下一层的最后一个节点
	lastNode = root;//初始化为根节点
	newLastNode = NULL;//初始化为空
	queue[++rear] = root;
	while (rear != front) {
		p = queue[++front];//出队
		if (p->lchild == NULL && p->rchild == NULL)
			wpl += deep*p->weight;
		if (p->lchild) {
			queue[++rear] = p->lchild;
			newLastNode = p->lchild;//设下一层的最后一个节点为该节点的左节点
		}
		if (p->rchild) {
			queue[++rear] = p->rchild;
			newLastNode = p->rchild;//设下一层的最后一个节点为该节点的左节点
		}
		if (p == lastNode) {//若该节点为本层的最后一个节点，则更新lastNode
			lastNode = newLastNode;
			++deep;			//层数加1
		}
	}
	return wpl;
}