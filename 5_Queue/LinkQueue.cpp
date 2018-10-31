#include<iostream>
#include"Queue.h"
using namespace std;

void InitQueue2(LinkQueue &q) {
	q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));//��q.front��q.rear���ɽڵ㣬��Ҳ��data��next��Ա
	q.front->next = NULL;//��q.front��Ϊͷ�ڵ㣬ͷ�ڵ㲻����Ϣ
	cout << "��ʼ���ɹ�" << endl;
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
	if (q.rear == q.front)//�ӿ�
		return;
	LinkNode *s = q.front->next;
	*x = s->data;
	q.front->next = s->next;
	if (q.rear == s)
		q.rear = q.front;//��ԭ������ֻ��һ���ڵ㣬ɾ������
	free(s);
}
void PrintQueue2(LinkQueue &q) {
	int x;
	cout << "��ӡ����" << endl;
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