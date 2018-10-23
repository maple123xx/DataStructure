#include"Linklist.h"
#include<iostream>
#include<algorithm>
using namespace std;

PNODE CreateList() {	//PNODE是指针类型,PNODE等价于NODE *
	int length;//链表长度
	int value;//用于临时存放用户输入的节点的值
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//pHead是一个指针,可用来指向一个NODE型对象
	if (pHead == NULL) {
		printf("Memory allocation failure");
		exit(-1);
	}
	else
	{
		PNODE pTail = pHead;
		pHead->next = NULL;
		printf("Please input the length of the list: ");
		scanf_s("%d", &length);
		for (int i = 0; i < length; ++i) {
			PNODE p = (PNODE)malloc(sizeof(NODE));
			if (p == NULL) {
				printf("Memory allocation failure");
				exit(-1);
			}
			else
			{	
				printf("Please input the value of the node: ");
				scanf_s("%d", &value);
				p->data = value;
				pTail->next = p;
				p->next = NULL;
				pTail = p;
			}
		}
	}
	return pHead;//返回头节点
}

void DestroyList(PNODE pHead) {
	if (pHead == NULL)
		return;
	PNODE p = NULL;
	printf("\n输出值后销毁链表\n");
	while (pHead != NULL)
	{	
		printf("%d\t", pHead->data);
		p = pHead->next;//先保存下一个节点
		free(pHead);
		pHead = p;
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

void print(PNODE pHead) {
	PNODE p = pHead->next;
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
