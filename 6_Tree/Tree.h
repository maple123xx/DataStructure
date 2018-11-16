#ifndef Tree_
#define Tree_

#include"myNamespace.h"
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	//int ltag, rtag;		//为0代表指向孩子，为1代表指向线索
	struct BTNode *lchild, *rchild;
}BTNode,*BTree;

#define N_Node 100 //结点数量，比树中结点数量上限大1
#define N_lev 10 //树的深度上限
#define N_level 1024 //满足层次遍历对循环队列大小的要求
#define N_stack 100 //栈容量上限

BTNode* CreateTree(const string &str);
void CreateTree2(int root, int num_node, ElemType tree_data[N_Node], int tree_order[N_Node], BTNode *p);
void printErrorAndExit(const string &str);
void PreOrder(BTNode *root);
void InOrder(BTNode *root);
void PostOrder(BTNode *root);
#endif // !Tree_
