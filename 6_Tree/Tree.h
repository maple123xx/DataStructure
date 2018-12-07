#ifndef Tree_
#define Tree_

#include"myNamespace.h"
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	//int ltag, rtag;		//Ϊ0����ָ���ӣ�Ϊ1����ָ������
	struct BTNode *lchild, *rchild;
}BTNode,*BTree,*LinkedList;

typedef struct BT_Width {//�����Ŀ��ʱ�����һ���ṹ�壬�����������
	BTNode *t_node;
	int num_level;	//�ڵ����ڵĲ��
}BT_Width;



#define N_Node 100 //��������������н���������޴�1
#define N_lev 10 //�����������
#define N_level 1024 //�����α�����ѭ�����д�С��Ҫ��
#define N_stack 100 //ջ��������

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
void InOrder2(BTNode *root);
void PostOrder2(BTNode *root);
void InverseLevel(BTNode *root);
void IsComplete(BTNode *root);
int DoubleSonNodes(BTNode *root);
void SwapTree(BTNode *root);
ElemType PreKNode(BTNode *root,int k);
void DeleteXTree(BTNode *root);
void DeleteX(BTNode *root, ElemType x);
void SearchX(BTNode *root, ElemType x);
BTNode *Search1(BTNode *root, ElemType x);
BTNode *CommonAncestor(BTNode *root, BTNode *p, BTNode *q);
int BTwidth(BTNode *root);
int Similar(BTNode *root1, BTNode *root2);
BTNode *PreInCreate(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2);
void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2);

//typedef struct LinkList {
//	ElemType data;
//	struct LinkList *rchild;
//} *LinkList;
//LinkList head, pre = NULL;
//LinkList InOrderLeaf(BTNode *root);

LinkedList InOrderLeaf(BTNode *root);
void PrintLeaf(BTNode *root);

typedef struct weightBTNode {
	int weight;
	struct weightBTNode *lchild, *rchild;
}weightBTNode;
weightBTNode* CreateWeightTree(const string &str);
void CreateWeightTree2(int root, int num_node, int weight[N_Node], int tree_order[N_Node], weightBTNode *p);
int WPL(weightBTNode *root);
int wpl_PreOrder(weightBTNode *root, int deep);
int wpl_LevelOrder(weightBTNode *root);
#endif // !Tree_
