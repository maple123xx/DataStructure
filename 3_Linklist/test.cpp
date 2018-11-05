#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"Linklist.h"
using namespace std;

void InitList2(PNODE &L) {//不带头节点的单链表初始化，用&L可以取到PNODE L定义的指针的地址，从而达到传地址而不是传值的目的
	L = NULL;
	cout << "初始化成功"<< endl;
}
void CreateList2(PNODE &L) {//头插创建单链表
	PNODE p;
	int x;
	cout << "请输入链表的值（输入100表示结束）："<< endl;
	cin >> x;
	while (x != 100) {
		p = (PNODE)malloc(sizeof(NODE));
		p->data = x;
		p->next = L;
		L = p;
		cin >> x;
	}
}
void CreateList3(PNODE &L) {//尾插创建不带头的单链表
	PNODE r = L;//r是尾指针
	if (r)			//若r不为空指针，则变成尾指针
		while (r->next)
			r = r->next;
	int x;
	cout<< "请输入链表的值（输入100表示结束）：" << endl;
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
void PrintList2(PNODE L) {//不带头节点的输出
	PNODE p = L;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}
void Delete_X_3(PNODE &L, int x) {//递归删除一个不带头节点的链表中所有值为x的元素
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
void Delete_X_2(PNODE pHead,int x) {//删除带头节点的链表中所有值为x的元素
	/*PNODE pre = pHead;//方法一，用前后两个指针
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
	PNODE p = pHead->next, r = pHead, q;//方法二，用尾指针
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
void ReversePrint(PNODE pHead) {//用递归的方法逆序输出链表的值，也可以用栈实现
	PNODE p = pHead->next;
	if (p->next) {
		ReversePrint(p);
	}
	cout << p->data << "\t";
}
void Delete_Min1(PNODE pHead) {//删除带头节点链表的最小值（假设唯一）
	PNODE p = pHead->next;//工作指针
	PNODE q = p;//q指向具有最小值的节点
	int min = p->data;
	while (p)
	{
		if (p->data < min) {
			min = p->data;
			q = p;
		}
		p = p->next;
	}
	PNODE pre = pHead;//用一个pre指向q的前驱，否则直接删除q会断链
	while (pre->next != q) {
		pre = pre->next;
	}
	pre->next = q->next;
	free(q);
	q = NULL;
}
void Reverse_1(PNODE pHead) {//逆置链表
	
	//PNODE p = pHead->next;//方法一：头插法p为工作指针，r为其后继，以防断链，将头节点摘下，然后从第一个节点开始，依次插入到头节点后面
	//PNODE r;
	//pHead->next = NULL;//将pHead的next域赋为空，因为链表逆置后它为最后一个节点
	//while (p)
	//{
	//	r = p->next;
	//	p->next=pHead->next;
	//	pHead->next = p;
	//	p = r;
	//}
	PNODE pre, p = pHead->next;//方法二：将每个节点的next域赋为上一个节点
	PNODE r = p->next;
	p->next = NULL;//将第一个有值的节点的next域赋为空，因为链表逆置后它为最后一个节点
	while (r) {//r为空，说明p为最后一个节点
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	pHead->next = p;

}
void SortList2(PNODE pHead) {//带头节点的排序,不同于第一个排序方法，这个是直接操作链表
	PNODE p = pHead->next,pre;//采用直接插入的方法，先构成只含一个数据节点的有序单链表，然后依次扫描单链表中剩下的节点插入进来
	PNODE r = p->next;//r防止断链
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
//有问题
void Delete_Min2(PNODE pHead) {//依次删除最小值并输出
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
PNODE DecompositonList1(PNODE A) {//将链表A分解为A和B,A中包含所有奇数元素，B中包含所有偶数元素
	PNODE B = (PNODE)malloc(sizeof(NODE));
	B->next = NULL;//B的初始化
	int i = 0;
	PNODE ra = A, rb = B;
	PNODE p = A->next;//工作指针
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
	ra->next = NULL;//尾插法一定要将尾指针置为空
	rb->next = NULL;//尾插法一定要将尾指针置为空
	return B;
}
PNODE DecompositonList2(PNODE A) {//将A={a1,b1,a2,b2,...,an,bn}变为A={a1,a2,...,an},B={bn,bn-1,...,b1}
	PNODE B = (PNODE)malloc(sizeof(NODE));//则先尾插，再头插即可
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
void Del_Same(PNODE pHead) {//删除递增有序表的重复元素，即（7，10，10，21，21，42）-》（7，10，21，42）
	/*PNODE p = pHead->next;//方法一
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
	PNODE r=pHead->next;//方法二，采用尾插法
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
void MergeList(PNODE A, PNODE B) {//合并两个有序递增链表，使其结果链表按元素值递减次序排列
	PNODE r, pa = A->next, pb = B->next;//要递减输出，就要用头插法
	A->next = NULL;//A作为结果链表，初始化为空
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
PNODE Get_Common(PNODE A, PNODE B) {//求两个递增有序的链表的公共节点
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
	//PNODE L;//定义一个指针，而不是一个节点，如果用NODE L;则至少会创造一个节点(因为只要头指针，不要头节点)
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