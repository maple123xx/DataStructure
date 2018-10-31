#include<iostream>
#include"Queue.h"
using namespace std;

void InitQueue2(LinkQueue &q) {
	q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));//把q.front和q.rear当成节点，它也有data和next成员
	q.front->next = NULL;//将q.front设为头节点，头节点不含信息
	cout << "初始化成功" << endl;
}
bool IsEmpty2(LinkQueue &q) {
	if (q.front == q.rear)
		return true;
	else
		return false;
}
void EnQueue2(LinkQueue &q,int x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}
void DeQueue2(LinkQueue &q, int *x) {
	if (q.rear == q.front)//队空
		return;
	LinkNode *s = q.front->next;
	*x = s->data;
	q.front->next = s->next;
	if (q.rear == s)
		q.rear = q.front;//若原队列中只有一个节点，删除后变空
	free(s);
}
void PrintQueue2(LinkQueue &q) {
	int x;
	cout << "打印队列" << endl;
	while (!IsEmpty2(q))
	{
		DeQueue2(q, &x);
		cout << x << '\t';

	}
	cout << endl;
}
int LengthQueue2(LinkQueue &q) {
	int length = 0;
	LinkNode* p = q.front->next;
	while (p)
	{
		++length;
		p = p->next;
	}
	return length;
}