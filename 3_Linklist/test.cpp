#include<iostream>
#include"Linklist.h"
using namespace std;

void InitList2(PNODE &L) {//不带头节点的单链表初始化，用&L可以取到PNODE L定义的指针的地址，从而达到传地址而不是传值的目的
	L = NULL;
	cout << "初始化成功"<< endl;
}
void CreateList2_1(PNODE &L) {//头插创建不带头节点的单链表
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
void CreateList2_2(PNODE &L) {//尾插创建不带头的单链表
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
void Delete_Min2(PNODE pHead) {//依次删除最小值并输出
	PNODE pre, p, minp, minpre;
	cout << "输出此链表" << endl;
	while (pHead->next)
	{
		pre = pHead;
		p = pre->next;
		minpre = pHead;
		minp = minpre->next;
		while (p)
		{
			if (minp->data>p->data) {
				minpre = pre;
				minp = p;
			}
			pre = p;
			p = p->next;
		}
		cout << minp->data << '\t';
		minpre->next = minp->next;
		free(minp);
	}
	cout << endl;
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
void UnionList(PNODE A, PNODE B) {//求两个递增链表的交集
	PNODE r = A, pa = A->next, pb = B->next;//结果链表就保存在A中,r是尾指针
	while (pa && pb)
	{
		if (pa->data == pb->data) {
			r->next = pa;
			r = pa;
			pa = pa->next;
			PNODE u = pb;
			pb = pb->next;
			free(u);
		}
		else if (pa->data < pb->data) {
			PNODE u = pa;
			pa = pa->next;
			free(u);
		}
		else
		{
			PNODE u = pb;
			pb = pb->next;
			free(u);
		}
	}
	while (pa) {
		PNODE u = pa;
		pa = pa->next;
		free(u);
	}
	while (pb) {
		PNODE u = pb;
		pb = pb->next;
		free(u);
	}
	r->next = NULL;
}
void PatternList(PNODE A, PNODE B) {//判断整数序列B是否是整数序列A的连续子序列
	PNODE p = A->next,q=B->next;
	PNODE pre = p;
	while (p && q)
	{
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else
		{
			pre = pre->next;
			p = pre;
			q = B->next;
		}
	}
	if (q == NULL)
		cout << "B是A的连续子序列" << endl;
	else
	{
		cout << "B不是A的连续子序列" << endl;
	}
}
void Search_K(PNODE pHead, int k) {//寻找倒数第K个节点
	PNODE p = pHead->next, q = pHead->next;
	int count = 0;
	while (p)
	{
		if (count < k)
			++count;
		else
			q = q->next;
		p = p->next;
	}
	if (count < k)
		return;
	else
		cout << "倒数第" << k << "个值为" << q->data << endl;
}
void Find_Common(PNODE A, PNODE B) {//找寻两个链表的公共起点
	PNODE pa = A->next, pb = B->next;
	int m = LengthList(A), n = LengthList(B);
	cout << "共同的起点为" << endl;
	while (m>n)
	{
		pa = pa->next;
		--m;
	}
	while (n>m)
	{
		pb = pb->next;
		--n;
	}
	while (pa && pa->data != pb->data)
	{
		pa = pa->next;
		pb = pb->next;
	}
	cout << pa->data << endl;


}
void Delete_Absolute(PNODE pHead) {//单链表的所有数的绝对值都小于100，仅保留第一次出现的值，删除绝对值重复的值

	//PNODE p = pHead, r;
	//int a[100] = { 0 };//用一个数组保存已出现的值，用空间换时间
	//while (p->next)
	//{
	//	int m = (p->next->data > 0) ? p->next->data : -(p->next->data);//只能用p->next判断，走到p的时候，判断p->next是否重复，
	//	if (a[m] == 0) {											   //重复的话令r指向p->next，删除p->next
	//		a[m] = 1;
	//		p = p->next;
	//	}
	//	else
	//	{
	//		r = p->next;
	//		p->next = r->next;
	//		free(r);
	//	}
	//}
	PNODE p = pHead, r;
	int *q;
	q = (int *)malloc(sizeof(int) * 101);
	for (int i = 0; i < 101; ++i) {//动态分配内存给一个数组
		*(q + i) = 0;
	}
	while (p->next)
	{
		int m = (p->next->data > 0) ? p->next->data : -(p->next->data);
		if (*(q + m) == 0) {
			*(q + m) = 1;
			p = p->next;
		}
		else
		{
			r = p->next;
			p->next = r->next;
			free(r);
		}
	}
	free(q);
}
void Symmetry2(PNODE pHead) {//判断单链表是否是对称的
	int a[100] = {0};//使用栈的方法将前一半的链表入栈，然后每出栈一个就和链表的下一个值比较
	int i;
	int n = LengthList(pHead);
	PNODE p = pHead->next;
	for (i = 0; i < n / 2; ++i) {
		a[i] = p->data;
		p = p->next;
	}
	--i;//将i看成栈顶指针,回退一步
	if (n % 2 == 1)//个数为奇数时，中间的数不用判断
		p = p->next;
	while (i > -1) {
		if (a[i] == p->data) {
			--i;
			p = p->next;
		}
		else
		{
			cout << "不是对称的" << endl;
			return;
		}
	}
	cout << "是对称的" << endl;
}

void InitList3(PNODE pHead) {//带头节点循环单链表的初始化
	pHead->next = pHead;
	cout << "初始化成功" << endl;
}
void CreateList3_1(PNODE pHead) {//头插创建带头循环单链表
	PNODE p;
	int x;
	cout << "请输入链表的值（输入100表示结束）：" << endl;
	cin >> x;
	while (x != 100)
	{
		p = (PNODE)malloc(sizeof(NODE));
		p->data = x;
		p->next = pHead->next;
		pHead->next = p;
		cin >> x;
	}
}
void CreateList3_2(PNODE pHead) {//尾插创建带头循环单链表
	PNODE p, r = pHead;
	int x;
	cout << "请输入链表的值（输入100表示结束）：" << endl;
	cin >> x;
	while (x != 100)
	{
		p = (PNODE)malloc(sizeof(NODE));
		p->data = x;
		r->next = p;
		r = p;
		cin >> x;
	}
	r->next = pHead;
}
void PrintList3(PNODE pHead) {
	PNODE p = pHead->next;
	cout << "输出链表为：" << endl;
	while (p != pHead)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
void UnionList2(PNODE A, PNODE B) {//将一个循环单链表接到另一个循环单链表后面，使之仍保持循环
	PNODE pa = A->next, pb = B->next;
	while (pa->next != A)
		pa = pa->next;
	while (pb->next != B)
		pb = pb->next;
	pa->next = B;
	pb->next = A;
}
void Delete_Min3(PNODE pHead) {//依次删除循环单链表的最小节点并输出
	PNODE pre, p, minpre, minp;
	cout << "输出此链表：" << endl;
	while (pHead->next != pHead) {
		pre = pHead;
		p = pHead->next;
		minpre = pre;
		minp = p;
		while (p != pHead)
		{
			if (minp->data > p->data) {
				minpre = pre;
				minp = p;
			}
			pre = p;
			p = p->next;
		}
		cout << minp->data << '\t';
		minpre->next = minp->next;
		free(minp);
	}
	cout << endl;
}

void InitList4(DPNODE pHead) {//循环双链表的初始化
	pHead->next = pHead;
	pHead->prior = pHead;
	cout << "初始化成功" << endl;
}
void CreateList4_1(DPNODE pHead) {//头插创建带头循环双链表
	DPNODE p;
	int x;
	cout << "请输入链表的值（输入100表示结束）：" << endl;
	cin >> x;
	while (x != 100)
	{
		p = (DPNODE)malloc(sizeof(DNODE));
		p->data = x;
		p->next = pHead->next;
		pHead->next->prior = p;
		pHead->next = p;
		p->prior = pHead;
		cin >> x;
	}
	cout << "pHead->prior=" << pHead->prior << endl;
}
void CreateList4_2(DPNODE pHead) {//尾插创建带头循环双链表,有问题
	DPNODE p, r = pHead;
	int x;
	cout << "请输入链表的值（输入100表示结束）：" << endl;
	cin >> x;
	while (x != 100)
	{
		p = (DPNODE)malloc(sizeof(DNODE));
		p->data = x;
		r->next = p;
		p->prior = r;
		r = p;
		cin >> x;
	}
	r->next = pHead;
}
void PrintList4(DPNODE pHead) {
	DPNODE p = pHead->prior;
	cout << "输出链表为：" << endl;
	while (p != pHead)
	{
		cout << p->data << "\t";
		p = p->prior;
	}
	cout << endl;
}
void Symmetry(DPNODE pHead) {//判断循环双链表是否是对称的
	DPNODE p = pHead->next, q = pHead->prior;
	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
		{
			cout << "该循环双链表不是对称的" << endl;
			return;
		}
	}
	cout << "该循环双链是对称的" << endl;
	return;
}

int main() {
	//PNODE L;//定义一个指针，而不是一个节点，如果用NODE L;则至少会创造一个节点(因为只要头指针，不要头节点)
	//InitList2(L);
	//CreateList3(L);
	//PrintList2(L);
	//Delete_X_3(L, 1);
	//PrintList2(L);
	//NODE L;
	//InitList(&L);
	//CreateList(&L);
	//PrintList(&L);
	//Del_Same(&L);
	//PrintList(&L);
	//NODE A, B;
	//InitList(&A);
	//CreateList(&A);
	//PrintList(&A);
	//InitList(&B);
	//CreateList(&B);
	//PrintList(&B);
	//PatternList(&A, &B);
	//UnionList(&A, &B);
	//PrintList(&A);
	//PNODE C = Get_Common(&A, &B);
	//PrintList(C);
	//Delete_X_2(&L, 1);
	//ReversePrint(&L);
	//Delete_Min1(&L);
	//Reverse_1(&L);
	//SortList(&L);
	//Delete_Min2(&L);
	//PrintList(&L);
	//NODE A;
	//InitList(&A);
	//CreateList(&A);
	//PrintList(&A);
	//PNODE B = DecompositonList1(&A);
	//PrintList(&A);
	//PrintList(B);
	/*NODE A;
	InitList3(&A);
	CreateList3_2(&A);
	Delete_Min3(&A);
	PrintList3(&A);*/
	/*NODE pHead;
	InitList(&pHead);
	CreateList(&pHead);
	Search_K(&pHead,3);*/
	/*DNODE A;
	InitList4(&A);
	CreateList4_2(&A);
	PrintList4(&A);*/
	//Symmetry(&A);
	NODE pHead;
	InitList(&pHead);
	CreateList(&pHead);
	Symmetry2(&pHead);
	system("pause");
	return 0;
}