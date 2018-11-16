#ifndef Tree_
#define Tree_

#include"myNamespace.h"
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	//int ltag, rtag;		//Ϊ0����ָ���ӣ�Ϊ1����ָ������
	struct BTNode *lchild, *rchild;
}BTNode,*BTree;

#define N_Node 100 //��������������н���������޴�1
#define N_lev 10 //�����������
#define N_level 1024 //�����α�����ѭ�����д�С��Ҫ��
#define N_stack 100 //ջ��������

BTNode* CreateTree(const string &str);
void CreateTree2(int root, int num_node, ElemType tree_data[N_Node], int tree_order[N_Node], BTNode *p);
void printErrorAndExit(const string &str);
void PreOrder(BTNode *root);
void InOrder(BTNode *root);
void PostOrder(BTNode *root);
#endif // !Tree_
