#include"Linklist.h"
#include<iostream>
#include<algorithm>
using namespace std;

void InitList(PNODE pHead) {//��ͷ�ڵ�ĵ������ʼ��
	pHead->next = NULL;
	cout << "��ʼ���ɹ�" << endl;
}
void CreateList(PNODE pHead) {	//PNODE��ָ������,PNODE�ȼ���NODE *
	PNODE s, r = pHead;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
	cin >> x;
	while (x != 100) {//����100��ʾ����
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
	//printf("���ֵ����������\n");
	//while (pHead != NULL)
	//{	
	//	p = pHead->next;//�ȱ�����һ���ڵ�
	//	if (p == NULL)//��pHeadָ�����һ���ڵ㣬pָ��NULL��ʱ��Ҫ�ж�һ�£���Ȼ����
	//		break;
	//	printf("%d\t", p->data);
	//	free(pHead);//pHead��һ��ָ�룬free��ָ����ڴ�
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
	while (p != NULL && i<pos-1)//��&&,����||
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
	PNODE p = pHead;//p��pHeadָ��ͬһ���ڴ棬pΪҪ�����Ԫ�ص�ǰ���Ԫ��
	while ((p != NULL) && (i < pos - 1)) {//��pos-1λ��ͣ��
		p = p->next;
		++i;
	}
	if (p == NULL || i > pos - 1)//������Ϊ�յ�������ǽ�ȥ�ˣ�i>pos-1 ���Է�ֹ�û��������
		return false;			//���統������3��Ԫ��ʱ��pos=4����������в������
	PNODE q = (PNODE)malloc(sizeof(NODE));//ƾ�մ����ʱ���Ҫ��malloc,qΪҪ�����Ԫ��
	q->data = value;
	q->next = p->next;
	p->next = q;
	return true;
}

int DeleteList(PNODE pHead, int pos) {
	int i = 0;
	PNODE p = pHead;//����p��pHeadָ��ͬһ���ڴ棬��Ȼ��֪��pָ���ģ�
	while(p != NULL && i <pos-1)
	{
		p = p->next;
		++i;
	}
	if (p == NULL || i > pos - 1)
		exit(-1);
	PNODE q = p->next;//Ҫɾ���Ľڵ�,����Ҫ��malloc
	int value = q->data;
	p->next = q->next;
	free(q);	//�ͷ�q��ָ��ڵ���ڴ�
	q = NULL;	//ǧ�򲻿������ǣ���������Ұָ��

	return value;//����ɾ���ڵ��ֵ

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
	cout << "���������"<< endl;
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
