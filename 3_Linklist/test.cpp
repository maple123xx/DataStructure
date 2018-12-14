#include"Linklist.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
void InitList2(PNODE &L) {//����ͷ�ڵ�ĵ������ʼ������&L����ȡ��PNODE L�����ָ��ĵ�ַ���Ӷ��ﵽ����ַ�����Ǵ�ֵ��Ŀ��
	L = NULL;
	cout << "��ʼ���ɹ�"<< endl;
}
void CreateList2_1(PNODE &L) {//ͷ�崴������ͷ�ڵ�ĵ�����
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
void CreateList2_2(PNODE &L) {//β�崴������ͷ�ĵ�����
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
//������25���ϲ��������������,ʹ������
PNODE MergeList2(PNODE A, PNODE B) {
	//���ǲ���ͷ�ڵ�ģ�ʹ�õݹ�ķ�����Ҳ�зǵݹ�ķ���
	if (!A)
		return B;
	else if (!B)
		return A;
	PNODE C = nullptr;
	if (A->data < B->data) {
		C= A;
		C->next = MergeList2(A->next, B);
	}
	else {
		C = B;
		C->next = MergeList2(A, B->next);
	}
	return C;
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
	PNODE p = pHead->next, r = pHead, q;//����������β�巨��������x�Ľڵ�ӵ�����
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
	
	//PNODE p = pHead->next;//����һ��ͷ�巨��pΪ����ָ�룬rΪ���̣��Է���������ͷ�ڵ�ժ�£�Ȼ��ӵ�һ���ڵ㿪ʼ�����β��뵽ͷ�ڵ����
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
void Reverse_2(PNODE pHead) {
	//���޸�����������������ֵ
	/*PNODE stack[100];	//����ջ
	int top = -1;
	PNODE p = pHead->next;
	while (p) {
		stack[++top] = p;
		p = p->next;
	}
	while (top != -1) {
		cout << stack[top--]->data << '\t';
	}*/
	PNODE p = pHead->next;//�ݹ�����
	if (p->next) {
		Reverse_2(p);
	}
	cout << p->data << "\t";
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
void Delete_Min2(PNODE pHead) {//����ɾ����Сֵ�����
	PNODE pre, p, minp, minpre;
	cout << "���������" << endl;
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
void UnionList(PNODE A, PNODE B) {//��������������Ľ���
	PNODE r = A, pa = A->next, pb = B->next;//�������ͱ�����A��,r��βָ��
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
void PatternList(PNODE A, PNODE B) {//�ж���������B�Ƿ�����������A������������
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
		cout << "B��A������������" << endl;
	else
	{
		cout << "B����A������������" << endl;
	}
}
void Search_K(PNODE pHead, int k) {//Ѱ�ҵ�����K���ڵ�
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
		cout << "������" << k << "��ֵΪ" << q->data << endl;
}
//�������ʮ���������е�����k���ڵ�
PNODE Search_K2(PNODE pHead, int k) {
	//������������p��k-1������һ���ߣ�ֱ��p�����һ���ڵ�
	if (!pHead || k == 0)	//����³����
		return NULL;
	PNODE p = pHead->next, q = pHead->next;
	for (int i = 0; i < k - 1; ++i) {	//����p��k-1��
		if (!p->next)		//����³����
			return NULL;
		p = p->next;
	}
	while (p->next) {
		p = p->next;
		q = q->next;
	}
	return q;
}
//�������ʮ�������Ŀ����������м�ڵ�
PNODE Middle_Node(PNODE pHead) {
	//p��������q��һ����p��ͷ�ˣ�q�͵��м���
	PNODE p = pHead->next, q = pHead->next;
	while (p) {
		p = p->next;
		if (p) {
			p = p->next;
			q = q->next;
		}
	}
	return q;
}

void Find_Common(PNODE A, PNODE B) {//��Ѱ��������Ĺ������
	PNODE pa = A->next, pb = B->next;
	int m = LengthList(A), n = LengthList(B);
	cout << "��ͬ�����Ϊ" << endl;
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
void Delete_Absolute(PNODE pHead) {//��������������ľ���ֵ��С��100����������һ�γ��ֵ�ֵ��ɾ������ֵ�ظ���ֵ

	//PNODE p = pHead, r;
	//int a[100] = { 0 };//��һ�����鱣���ѳ��ֵ�ֵ���ÿռ任ʱ��
	//while (p->next)
	//{
	//	int m = (p->next->data > 0) ? p->next->data : -(p->next->data);//ֻ����p->next�жϣ��ߵ�p��ʱ���ж�p->next�Ƿ��ظ���
	//	if (a[m] == 0) {											   //�ظ��Ļ���rָ��p->next��ɾ��p->next
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
	for (int i = 0; i < 101; ++i) {//��̬�����ڴ��һ������
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
void Symmetry2(PNODE pHead) {//�жϵ������Ƿ��ǶԳƵ�
	int a[100] = {0};//ʹ��ջ�ķ�����ǰһ���������ջ��Ȼ��ÿ��ջһ���ͺ��������һ��ֵ�Ƚ�
	int i;
	int n = LengthList(pHead);
	PNODE p = pHead->next;
	for (i = 0; i < n / 2; ++i) {
		a[i] = p->data;
		p = p->next;
	}
	--i;//��i����ջ��ָ��,����һ��
	if (n % 2 == 1)//����Ϊ����ʱ���м���������ж�
		p = p->next;
	while (i > -1) {
		if (a[i] == p->data) {
			--i;
			p = p->next;
		}
		else
		{
			cout << "���ǶԳƵ�" << endl;
			return;
		}
	}
	cout << "�ǶԳƵ�" << endl;
}

void InitList3(PNODE pHead) {//��ͷ�ڵ�ѭ��������ĳ�ʼ��
	pHead->next = pHead;
	cout << "��ʼ���ɹ�" << endl;
}
void CreateList3_1(PNODE pHead) {//ͷ�崴����ͷѭ��������
	PNODE p;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
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
void CreateList3_2(PNODE pHead) {//β�崴����ͷѭ��������
	PNODE p, r = pHead;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
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
	cout << "�������Ϊ��" << endl;
	while (p != pHead)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
void UnionList2(PNODE A, PNODE B) {//��һ��ѭ��������ӵ���һ��ѭ����������棬ʹ֮�Ա���ѭ��
	PNODE pa = A->next, pb = B->next;
	while (pa->next != A)
		pa = pa->next;
	while (pb->next != B)
		pb = pb->next;
	pa->next = B;
	pb->next = A;
}
void Delete_Min3(PNODE pHead) {//����ɾ��ѭ�����������С�ڵ㲢���
	PNODE pre, p, minpre, minp;
	cout << "���������" << endl;
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

void InitList4(DPNODE pHead) {//ѭ��˫����ĳ�ʼ��
	pHead->next = pHead;
	pHead->prior = pHead;
	cout << "��ʼ���ɹ�" << endl;
}
void CreateList4_1(DPNODE pHead) {//ͷ�崴����ͷѭ��˫����
	DPNODE p;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
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
}
void CreateList4_2(const string &str,DPNODE pHead)
{	//β�崴����ͷѭ��˫����
	try
	{
		DPNODE p;
		DPNODE r = pHead->prior;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		int numRow;
		ins >> numRow;
		if (numRow < 1) { throw exception(); }
		int x;
		for (int i = 0; i < numRow; ++i){
			p = (DPNODE)malloc(sizeof(DNODE));
			ins >> x;
			p->data = x;

			r->next = p;
			p->prior = r;
			p->next = pHead;
			pHead->prior = p;

			r = p;
		}
	}
	catch (...)
	{
		printErrorAndExit("CreateList4_2");
	}
}
void PrintList4(DPNODE pHead) {
	DPNODE p = pHead->next;
	cout << "�������Ϊ��" << endl;
	while (p != pHead)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
void Symmetry(DPNODE pHead) {//�ж�ѭ��˫�����Ƿ��ǶԳƵ�
	DPNODE p = pHead->next, q = pHead->prior;
	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
		{
			cout << "��ѭ��˫�����ǶԳƵ�" << endl;
			return;
		}
	}
	cout << "��ѭ��˫���ǶԳƵ�" << endl;
	return;
}

void InitList5(DPNODE pHead) {
	pHead->next = NULL;
	pHead->prior = NULL;
	cout << "˫�����ʼ���ɹ�" << endl;
}
void CreateList5_1(DPNODE pHead) {
	//ͷ�巨������ͷ�ڵ�˫����
	DPNODE p;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
	cin >> x;
	while (x != 100) {
		p = (DPNODE)malloc(sizeof(DNODE));
		p->data = x;
		if (!pHead->next) {		//����û�нڵ�ʱ
			p->next = NULL;
			pHead->next = p;
			p->prior = pHead;
		}
		else {
			p->next = pHead->next;
			pHead->next->prior = p;
			pHead->next = p;
			p->prior = pHead;
		}
		cin >> x;
	}
}
void CreateList5_2(DPNODE pHead) {
	//β�巨������ͷ�ڵ�˫����
	DPNODE p, r = pHead;
	int x;
	cout << "�����������ֵ������100��ʾ��������" << endl;
	cin >> x;
	while (x != 100) {
		p = (DPNODE)malloc(sizeof(DNODE));
		p->data = x;
		p->next = NULL;
		r->next = p;
		p->prior = r;
		r = p;
		cin >> x;
	}
}
void PrintList5(DPNODE pHead) {
	DPNODE p = pHead->next;
	cout << "�������Ϊ��" << endl;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

void SelectSort(PNODE pHead) {
	//ѡ������ÿ��ѡһ������ͷ�嵽ͷ�ڵ��
	PNODE p, pre, maxp, maxpre;
	PNODE  q = pHead->next;
	pHead->next = NULL;	//��ͷ�ڵ�ͺ���Ͽ�
	while (q) {
		maxpre = NULL, pre = NULL;
		maxp = q, p = q;
		while (p) {
			if (p->data > maxp->data) {
				maxpre = pre;
				maxp = p;
			}
			pre = p;
			p = p->next;
		}
		if (maxp == q)	//���ֵ�ڵ��ڵ�һ��λ��
			q = q->next;
		else
			maxpre->next = maxp->next;	//��������ֵ�ڵ�ժ����
		maxp->next = pHead->next;	//ͷ�嵽������
		pHead->next = maxp;
	}
	p = pHead->next;
	while (p) {
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}
//������ʮ�ߣ�ɾ�������ظ�Ԫ��
void DeleteRepeat(PNODE pHead) {
	//ɾ������ֵ�ظ���Ԫ�أ�����1��2��3��3��4��4��5��Ϊ1��2��5
	PNODE pre = pHead, p = pHead->next;
	while (p) {
		PNODE post = p->next;
		bool isRepeat = false;
		if (post&&post->data == p->data) {
			isRepeat = true;
		}
		if (!isRepeat) {
			pre = p;
			p = p->next;
		}
		else {
			int value = p->data;
			while (p&&p->data == value) {
				post = p->next;
				free(p);
				p = post;
			}
			pre->next = post;
		}
	}
}


int main() {
	PNODE L;
	InitList2(L);
	CreateList2_2(L);
	PrintList2(L);
	PNODE A, B;
	InitList2(A);
	CreateList2_2(A);
	InitList2(B);
	CreateList2_2(B);
	PNODE C = MergeList2(A, B);
	PrintList2(C);
	//PNODE L;//����һ��ָ�룬������һ���ڵ㣬�����NODE L;�����ٻᴴ��һ���ڵ�(��ΪֻҪͷָ�룬��Ҫͷ�ڵ�)
	//InitList2(L);
	//CreateList3(L);
	//PrintList2(L);
	//Delete_X_3(L, 1);
	//PrintList2(L);
	/*DNODE L;
	InitList5(&L);
	CreateList5_2(&L);
	PrintList5(&L);*/
	//DeleteRepeat(&L);
	//PrintList(&L);
	/*PNODE p = Middle_Node(&L);
	cout << "ֵΪ��" << p->data << endl;*/
	//Reverse_2(&L);
	//SelectSort(&L);
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

	/*const string str = "data\\test_5.txt";
	DNODE A;
	InitList4(&A);
	CreateList4_2(str, &A);
	PrintList4(&A);*/
	//Symmetry(&A);

	/*NODE pHead;
	InitList(&pHead);
	CreateList(&pHead);
	Symmetry2(&pHead);*/
	return 0;
}