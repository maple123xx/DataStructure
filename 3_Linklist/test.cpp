#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"Linklist.h"
using namespace std;

void InitList2(PNODE &L) {//����ͷ�ڵ�ĵ������ʼ������&L����ȡ��PNODE L�����ָ��ĵ�ַ���Ӷ��ﵽ����ַ�����Ǵ�ֵ��Ŀ��
	L = NULL;
	cout << "��ʼ���ɹ�"<< endl;
}
void CreateList2(PNODE &L) {//ͷ�崴��������
	PNODE p;
	int x;
	cout << "�����������ֵ������100��ʾ��������"<< endl;
	cin >> x;
	while (x != 100) {
		p = (PNODE)malloc(sizeof(NODE));
		p->data = x;
		p->next = L;
		L = p;
		cin >> x;
	}
}
void CreateList3(PNODE &L) {//β�崴������ͷ�ĵ�����
	PNODE r = L;//r��βָ��
	if (r)			//��r��Ϊ��ָ�룬����βָ��
		while (r->next)
			r = r->next;
	int x;
	cout<< "�����������ֵ������100��ʾ��������" << endl;
	cin >> x;
	while (x != 100) {
		PNODE p = (PNODE)malloc(sizeof(NODE));
		p->data = x;
		p->next = NULL;
		if (r == NULL) {
			L = p;
			r = p;
		}
		r->next = p;
		r = p;
		cin >> x;
	}
}
void PrintList2(PNODE L) {//����ͷ�ڵ�����
	PNODE p = L;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}
void Delete_X_3(PNODE &L, int x) {//�ݹ�ɾ��һ������ͷ�ڵ������������ֵΪx��Ԫ��
	PNODE p;
	if (L == NULL)
		return;
	else if (L->data == x) {
		p = L;
		L = L->next;
		free(p);
		Delete_X_3(L, x);
	}
	else
		Delete_X_3(L->next, x);
}
void Delete_X_2(PNODE pHead,int x) {//ɾ����ͷ�ڵ������������ֵΪx��Ԫ��
	/*PNODE pre = pHead;//����һ����ǰ������ָ��
	PNODE p = pre->next;
	while (p)
	{
		if (p->data == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = pre->next;
			p = p->next;
		}
	}*/
	PNODE p = pHead->next, r = pHead, q;//����������βָ��
	while (p)
	{
		if (p->data != x) {
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			q = p;
			p = p->next;
			free(q);
		}
	}
	r->next = NULL;
}
void ReversePrint(PNODE pHead) {//�õݹ�ķ���������������ֵ��Ҳ������ջʵ��
	PNODE p = pHead->next;
	if (p->next) {
		ReversePrint(p);
	}
	cout << p->data << "\t";
}
void Delete_Min1(PNODE pHead) {//ɾ����ͷ�ڵ��������Сֵ������Ψһ��
	PNODE p = pHead->next;//����ָ��
	PNODE q = p;//qָ�������Сֵ�Ľڵ�
	int min = p->data;
	while (p)
	{
		if (p->data < min) {
			min = p->data;
			q = p;
		}
		p = p->next;
	}
	PNODE pre = pHead;//��һ��preָ��q��ǰ��������ֱ��ɾ��q�����
	while (pre->next != q) {
		pre = pre->next;
	}
	pre->next = q->next;
	free(q);
	q = NULL;
}
void Reverse_1(PNODE pHead) {//��������
	
	//PNODE p = pHead->next;//����һ��ͷ�巨pΪ����ָ�룬rΪ���̣��Է���������ͷ�ڵ�ժ�£�Ȼ��ӵ�һ���ڵ㿪ʼ�����β��뵽ͷ�ڵ����
	//PNODE r;
	//pHead->next = NULL;//��pHead��next��Ϊ�գ���Ϊ�������ú���Ϊ���һ���ڵ�
	//while (p)
	//{
	//	r = p->next;
	//	p->next=pHead->next;
	//	pHead->next = p;
	//	p = r;
	//}
	PNODE pre, p = pHead->next;//����������ÿ���ڵ��next��Ϊ��һ���ڵ�
	PNODE r = p->next;
	p->next = NULL;//����һ����ֵ�Ľڵ��next��Ϊ�գ���Ϊ�������ú���Ϊ���һ���ڵ�
	while (r) {//rΪ�գ�˵��pΪ���һ���ڵ�
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	pHead->next = p;

}
void SortList2(PNODE pHead) {//��ͷ�ڵ������,��ͬ�ڵ�һ�����򷽷��������ֱ�Ӳ�������
	PNODE p = pHead->next,pre;//����ֱ�Ӳ���ķ������ȹ���ֻ��һ�����ݽڵ����������Ȼ������ɨ�赥������ʣ�µĽڵ�������
	PNODE r = p->next;//r��ֹ����
	p->next = NULL;
	p = r;
	while (p) {
		r = p->next;
		pre = pHead;
		while (pre->next && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//������
void Delete_Min2(PNODE pHead) {//����ɾ����Сֵ�����
	while (pHead->next) {
		PNODE pre = pHead;
		PNODE p = pHead->next;
		while (p->next)
		{
			if (pre->next->data > p->next->data)
				pre = p;
			p = p->next;
		}
		cout << pre->next->data << "\t";
		PNODE q = pre->next;
		pre->next = q->next;
		free(q);
	}
	free(pHead);
	pHead = NULL;
}
PNODE DecompositonList1(PNODE A) {//������A�ֽ�ΪA��B,A�а�����������Ԫ�أ�B�а�������ż��Ԫ��
	PNODE B = (PNODE)malloc(sizeof(NODE));
	B->next = NULL;//B�ĳ�ʼ��
	int i = 0;
	PNODE ra = A, rb = B;
	PNODE p = A->next;//����ָ��
	while (p)
	{
		++i;
		if (i % 2 == 0) {
			rb->next = p;
			rb = p;
		}
		else
		{
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;//β�巨һ��Ҫ��βָ����Ϊ��
	rb->next = NULL;//β�巨һ��Ҫ��βָ����Ϊ��
	return B;
}
PNODE DecompositonList2(PNODE A) {//��A={a1,b1,a2,b2,...,an,bn}��ΪA={a1,a2,...,an},B={bn,bn-1,...,b1}
	PNODE B = (PNODE)malloc(sizeof(NODE));//����β�壬��ͷ�弴��
	B->next = NULL;
	PNODE p = A->next;
	PNODE ra = A,q;
	while (p) {
		ra->next = p;
		ra = p;
		p = p->next;
		if (p == NULL)
			break;
		q = p->next;
		p->next = B->next;
		B->next = p;
		p = q;
	}
	ra->next = NULL;
	return B;
}
void Del_Same(PNODE pHead) {//ɾ�������������ظ�Ԫ�أ�����7��10��10��21��21��42��-����7��10��21��42��
	/*PNODE p = pHead->next;//����һ
	PNODE q;
	while (p->next) {
		q = p->next;
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}*/
	PNODE r=pHead->next;//������������β�巨
	PNODE p = r->next,q;
	r->next = NULL;
	while (p->next) {
		q = p->next;
		if (r->data != p->data) {
			r->next = p;
			r = p;
		}
		else
		{
			free(p);
		}
		p = q;
	}
	if (r->data == p->data)
		r->next = NULL;
	else
	{
		r->next = p;
		r->next = NULL;
	}
	
}
void MergeList(PNODE A, PNODE B) {//�ϲ����������������ʹ��������Ԫ��ֵ�ݼ���������
	PNODE r, pa = A->next, pb = B->next;//Ҫ�ݼ��������Ҫ��ͷ�巨
	A->next = NULL;//A��Ϊ���������ʼ��Ϊ��
	while (pa && pb)
	{
		if (pa->data <= pb->data) {
			r = pa->next;
			pa->next = A->next;
			A->next = pa;
			pa = r;
		}
		else
		{
			r = pb->next;
			pb->next = A->next;
			A->next = pb;
			pb = r;
		}
	}
	if (pb)
		pa = pb;
	while (pa)
	{
		r = pa->next;
		pa->next = A->next;
		A->next = pa;
		pa = r;
	}
}
PNODE Get_Common(PNODE A, PNODE B) {//�������������������Ĺ����ڵ�
	PNODE r,s, pa = A->next, pb = B->next;
	PNODE C = (PNODE)malloc(sizeof(NODE));
	r = C;
	C->next = NULL;
	while (pa && pb) {
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else
		{
			s = (PNODE)malloc(sizeof(NODE));
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
	return C;
}
int main() {
	//PNODE L;//����һ��ָ�룬������һ���ڵ㣬�����NODE L;�����ٻᴴ��һ���ڵ�(��ΪֻҪͷָ�룬��Ҫͷ�ڵ�)
	//InitList2(L);
	//CreateList3(L);
	//PrintList2(L);
	//Delete_X_3(L, 1);
	//PrintList2(L);
	/*NODE L;
	InitList(&L);
	CreateList(&L);
	PrintList(&L);
	Del_Same(&L);
	PrintList(&L);*/
	NODE A, B;
	InitList(&A);
	CreateList(&A);
	PrintList(&A);
	InitList(&B);
	CreateList(&B);
	PrintList(&B);
	PNODE C = Get_Common(&A, &B);
	PrintList(C);
	//Delete_X_2(&L, 1);
	//ReversePrint(&L);
	//Delete_Min1(&L);
	//Reverse_1(&L);
	//SortList(&L);
	//Delete_Min2(&L);
	//PrintList(&L);
	/*NODE A;
	InitList(&A);
	CreateList(&A);
	PrintList(&A);
	PNODE B = DecompositonList1(&A);
	PrintList(&A);
	PrintList(B);*/
	system("pause");
	return 0;
}