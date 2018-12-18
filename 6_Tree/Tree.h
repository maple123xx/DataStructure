#ifndef Tree_
#define Tree_

#include"myNamespace.h"
typedef int ElemType;
typedef struct BTNode {
	ElemType data;
	int ltag, rtag;		//ltag为0指向左孩子，为1指向前驱；rtag为0指向右孩子，为1代表指向后继
	struct BTNode *lchild, *rchild;
	int count;		//给二叉树增设一个count成员，存储以该节点为根的子树的节点个数，二叉排序树的时候用到了
}BTNode,*BTree,*LinkedList;

typedef struct BT_Width {//求数的宽度时定义的一个结构体，用来定义队列
	BTNode *t_node;
	int num_level;	//节点所在的层次
}BT_Width;



#define N_Node 100 //结点数量，比树中结点数量上限大1
#define N_lev 10 //树的深度上限
#define N_level 1024 //满足层次遍历对循环队列大小的要求
#define N_stack 100 //栈容量上限

void printErrorAndExit(const string &str);
BTNode* CreateTree(const string &str);
void CreateTree2(int root, int num_node, ElemType tree_data[N_Node], int tree_order[N_Node], BTNode *p);
void PreOrder(BTNode *root);
void InOrder(BTNode *root);
void PostOrder(BTNode *root);
int getDepth(BTNode *root);
int getDepth2(BTNode *root);
void LevelOrder(BTNode *root);
void PreOrder2(BTNode *root);
void Print_Road(BTNode *root, int x);
void InOrder2(BTNode *root);
void PostOrder2(BTNode *root);
void InverseLevel(BTNode *root);
void IsComplete(BTNode *root);
int DoubleSonNodes(BTNode *root);
int NoSonNodes(BTNode *root);
int SingleSonNodes(BTNode *root);;
void SwapTree(BTNode *root);
ElemType PreKNode(BTNode *root,int k);
void DeleteXTree(BTNode *root);
void DeleteX(BTNode *root, ElemType x);
void DeleteLeaf(BTNode *&root);
void SearchX(BTNode *root, ElemType x);
BTNode *Search1(BTNode *root, ElemType x);
BTNode *CommonAncestor(BTNode *root, BTNode *p, BTNode *q);
int BTwidth(BTNode *root);
int Similar(BTNode *root1, BTNode *root2);
BTNode *PreInCreate(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2);
void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2);
void Level_X(BTNode *root, int x,int L,int *res);
int Level_X2(BTNode *root, int x);
void PreValue_Level(BTNode *root, int L);
LinkedList InOrderLeaf(BTNode *root);
void PrintLeaf(BTNode *root);
void All_leaf_Path_Core(BTNode *root, BTNode *path[], int &top);
void All_leaf_Path(BTNode *root);

typedef struct weightBTNode {
	int weight;
	struct weightBTNode *lchild, *rchild;
}weightBTNode;
weightBTNode* CreateWeightTree(const string &str);
void CreateWeightTree2(int root, int num_node, int weight[N_Node], int tree_order[N_Node], weightBTNode *p);
int WPL(weightBTNode *root);
int wpl_PreOrder(weightBTNode *root, int deep);
int wpl_LevelOrder(weightBTNode *root);
int Caculation_Core(int A, int B, char C);
int Caculation(BTNode *root);

//二叉排序树的操作
void Create_BST(BTNode *&root, ElemType str[], int n);
bool BST_Insert(BTNode *&root, ElemType key);
bool BST_Delete_Core(BTNode *&root);
bool BST_Delete(BTNode *&root, ElemType key);
BTNode *SearchBST(BTNode *root, ElemType key, BTNode *&p);
bool SearchBST2(BTNode *root, ElemType key, BTNode *&parent, BTNode *&p);
bool JudgeBST1(BTNode *root);
bool JudgeBST2(BTNode *root);
int BST_Level(BTNode *root, ElemType key);
void MinKey(BTNode *root);
void MaxKey(BTNode *root);
void Output_Max_K(BTNode *root, ElemType k);
int Count_Node(BTNode *root);
BTNode* Number_K(BTNode *root, int k);

//线索二叉树的操作
void InThread_Core(BTNode *root, BTNode *&pre);
void InThread(BTNode *root);
BTNode *FirstNode(BTNode *p);
BTNode *NextNode(BTNode *p);
void InOrder_Thread(BTNode *root);
void PreThread_Core(BTNode *root, BTNode *&pre);
void PreThread(BTNode *root);
void PreOrder_Thread(BTNode *root);
#endif // !Tree_
