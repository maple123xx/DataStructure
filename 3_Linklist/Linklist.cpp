#include"Linklist.h"
#include<iostream>
#include<algorithm>
using namespace std;

void InitList(PNODE pHead) {//带头节点的单链表初始化
	pHead->next = NULL;
	cout << "初始化成功" << endl;
}
void CreateList(PNODE pHead) {	//PNODE是指针类型,PNODE等价于NODE *
	PNODE s, r = pHead;
	int x;
	cout << "请输入链表的值（输入100表示结束）：" << endl;
	cin >> x;
	while (x != 100) {//输入100表示结束
		s = (PNODE)malloc(sizeof(NODE));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
}

void DestroyList(PNODE pHead) {
	if (pHead == NULL)
		return;
	//PNODE p = NULL;
	//printf("输出值后销毁链表\n");
	//while (pHead != NULL)
	//{	
	//	p = pHead->next;//先保存下一个节点
	//	if (p == NULL)//当pHead指向最后一个节点，p指向NULL的时候，要判断一下，不然出错
	//		break;
	//	printf("%d\t", p->data);
	//	free(pHead);//pHead是一个指针，free它指向的内存
	//	pHead = p;
	//}
	PNODE pre = pHead;
	pHead = pre->next;
	free(pre);
	while (pHead) {
		cout << pHead->data << '\t';
		pre = pHead;
		pHead = pHead->next;
		free(pre);
	}
}

PNODE ClearList(PNODE pHead) {
	if (pHead->next)
		return pHead;
	DestroyList(pHead->next);
	pHead->next = NULL;
	return pHead;
}

int FindList(PNODE pHead, int pos) {
	int i = 0;
	PNODE p = pHead;
	while (p != NULL && i<pos-1)//用&&,不是||
	{
		p = p->next;
		++i;
	}
	if (p->next == NULL || i > pos - 1) {
		printf("Error input pos");
		exit(-1);
	}
	return p->next->data;
		
}

bool InsertList(PNODE pHead, int pos, int value) {
	int i = 0;
	PNODE p = pHead;//p和pHead指向同一块内存，p为要插入的元素的前面的元素
	while ((p != NULL) && (i < pos - 1)) {//到pos-1位置停下
		p = p->next;
		++i;
	}
	if (p == NULL || i > pos - 1)//把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；
		return false;			//比如当链表有3个元素时，pos=4，将不会进行插入操作
	PNODE q = (PNODE)malloc(sizeof(NODE));//凭空创造的时候就要用malloc,q为要插入的元素
	q->data = value;
	q->next = p->next;
	p->next = q;
	return true;
}

int DeleteList(PNODE pHead, int pos) {
	int i = 0;
	PNODE p = pHead;//必须p和pHead指向同一块内存，不然不知道p指向哪，
	while(p != NULL && i <pos-1)
	{
		p = p->next;
		++i;
	}
	if (p == NULL || i > pos - 1)
		exit(-1);
	PNODE q = p->next;//要删除的节点,不需要用malloc
	int value = q->data;
	p->next = q->next;
	free(q);	//释放q所指向节点的内存
	q = NULL;	//千万不可以忘记，否则会出现野指针

	return value;//返回删除节点的值

}

int LengthList(PNODE pHead) {
	int length = 0;
	PNODE p = pHead->next;
	while (p != NULL)
	{
		p = p->next;
		++length;
	}
	return length;
}

void SortList(PNODE pHead) {
	int length = LengthList(pHead);
	int i, j;
	PNODE p, q;
	for (i = 0, p = pHead->next; i < length - 1; ++i, p = p->next) {
		for (j = i + 1, q = p->next; j < length; ++j, q = q->next) {
			if (q->data < p->data) {
				swap(q->data, p->data);
			}
		}
	}
}

void PrintList(PNODE pHead) {
	PNODE p = pHead->next;
	cout << "输出此链表："<< endl;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout<<endl;
}

void InsertFrontList(PNODE pos, int x) {
	PNODE temp = (PNODE)malloc(sizeof(NODE));
	temp->data = pos->data;
	temp->next = pos->next;
	pos->next = temp;
	pos->data = x;
}
