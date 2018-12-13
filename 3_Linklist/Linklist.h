#ifndef Linklist_
#define Linklist_

#include"myNamespace.h"


typedef struct Node {
	int data;
	struct Node* next;
}NODE,*PNODE;	//NODE等价于struct Node,*PNODE 等价于struct Node *

typedef struct DNode {//双链表的定义
	int data;
	struct DNode *prior, *next;
}DNODE,*DPNODE;

void InitList(PNODE pHead);//带头节点单链表的初始化
void CreateList(PNODE pHead);//尾插创建链表
void DestroyList(PNODE pHead);//销毁链表
PNODE ClearList(PNODE pHead);//清空链表
int FindList(PNODE pHead, int pos);//返回第pos位置的节点
bool InsertList(PNODE pHead, int pos, int value);//在第pos位置前插入给定元素
int DeleteList(PNODE pHead, int pos);//删除pos位置的元素
int LengthList(PNODE pHead);//求链表长度
void SortList(PNODE pHead);//对链表中的节点按值升序排序，用简单的选择排序
void PrintList(PNODE pHead);//顺序打印链表
void InsertFrontList(PNODE pos, int x);// 在无头单链表的一个非头节点前插入一个节点

void printErrorAndExit(const string &str);

#endif // !Linklist
