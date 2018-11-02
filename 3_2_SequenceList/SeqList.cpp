#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {//��̬�����˳���
	int data[100];//������洢���Ա��е�Ԫ��
	int length;		//˳���ĳ���
}SeqList,*PSeqList;

void InitList(PSeqList s);//˳���ĳ�ʼ������
int Length(PSeqList s);//��˳���ĳ���
int GetData(PSeqList s, int i);//�������ݱ��е�i��Ԫ�ص�ֵ
int InsertList(PSeqList s, int i, int e);   //��˳���ĵ�i��λ�ò���Ԫ��
int DeleteList(PSeqList s, int i, int* e); //ɾ��˳���L�ĵ�i������Ԫ��
int LocateList(PSeqList s, int e); //��������Ԫ��e�ڱ��е�λ��
void ClearList(PSeqList L);//���˳���
void PrintList(PSeqList s);	//��ӡ����Ԫ��

void InitList(PSeqList s) {//��PSeqList�����s��һ��ָ�룬������SeqList�����ʵ��s���봫�����ĵ�ַ&s
	if (s == NULL)
		return;
	s->length = 0;
}
int Length(PSeqList s) {
	if (s == NULL)
		return 0;
	return s->length;
}
int GetData(PSeqList s, int i) {
	if (s->length<1 || s->length>Length(s))
		return 0;
	return s->data[i-1];//����Ԫ�ص���Ŵ�1��ʼ�������±��0��ʼ����i��Ԫ�ض�Ӧ�������±�Ϊi-1
}
int InsertList(PSeqList s, int i, int e) {
	if (i<1 || i>s->length + 1) {
		cout << "����λ�ò��Ϸ�" << endl;
		return 0;
	}
	else if (s->length >= 100) {
		cout << "˳�����" << endl;
		return 0;
	}
	for (int j = s->length - 1; j >= i-1; --j) {
		s->data[j + 1] = s->data[j];
	}
	s->data[i - 1] = e;
	s->length++;
	return 0;
}
int DeleteList(PSeqList s, int i, int* e) {
	if (s->length == 0) {
		cout << "˳����" << endl;
		return 0;
	}
	*e = s->data[i - 1];
	for (int j = i; j < s->length; ++j) {
		s->data[j - 1] = s->data[j];
	}
	s->length--;
	return *e;
}
int LocateList(PSeqList s, int e) {
	for (int i = 0; i < s->length; ++i) {
		if (s->data[i] == e)
			return i + 1;
	}
	return 0;
}
void ClearList(PSeqList L)
{
	L->length = 0;
}
void PrintList(PSeqList s)
{
	if (s->length==0)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	for (int k = 0; k < s->length; k++)
	{
		printf("%d\t", s->data[k]);
	}
	printf("\n");
}

int DeleteMin(PSeqList s) {//ɾ������������Сֵ��Ԫ�أ�����Ψһ�����ճ���λ�������һ��Ԫ���
	int min = s->data[0];
	int k = 0;
	for (int i = 1; i < Length(s); ++i) {
		if (min > s->data[i]) {
			min = s->data[i];
			k = i;
		}
	}
	s->data[k] = s->data[s->length - 1];
	--s->length;
	return min;
}
void ReverseList(PSeqList s) {//��˳��������Ԫ�����ã�Ҫ��ռ临�Ӷ�ΪO(1)
	for (int i = 0, j = s->length-1; i < j; ++i, --j) {
		swap(s->data[i], s->data[j]);
	}
}
void DeleteX(PSeqList s,int x) {//ɾ��˳���������ֵΪx��Ԫ��
	//for (int i = 0; i < s->length; ) {//����һ����ĩβԪ�����x�����������ı�Ԫ�ص����λ��
	//	if (s->data[i] == x) {
	//		s->data[i] = s->data[s->length - 1];
	//		--s->length;
	//	}
	//	else
	//	{
	//		++i;
	//	}
	//}
	int k = 0;
	for (int i = 0; i < s->length; ++i) {//����������k��¼����ֵ������x��Ԫ�ظ���
		if (s->data[i] != x) {
			s->data[k] = s->data[i];
			++k;
		}
	}
	s->length = k;
}
void Delete_p_q(PSeqList s, int p, int q) {//ɾ���������ֵΪp,q(p<q)֮���Ԫ�أ���Ϊ����������p,q֮���Ԫ������
	int i, j;
	for (i = 0; i < s->length && s->data[i] < p; ++i);//�ҵ���һ�����ڵ���p����
	if (i >= s->length)
		return;//����Ԫ�ض�С��p
	for (j = i; j < s->length && s->data[j] <= q; ++j);//�ҵ���һ������q����
	for (;j<s->length;++i,++j) {
		s->data[i] = s->data[j];
	}
	s->length = i;
}
void Delete_p_q2(PSeqList s, int p, int q) {//ɾ��˳�����������ģ���ֵΪp,q(p<q)֮���Ԫ��
	int k = 0;//k��¼Ԫ��ֵ��p,q֮��Ԫ�صĸ���
	for (int i = 0; i < s->length; ++i) {
		if (s->data[i] >= p && s->data[i] <= q) 
			++k;
		else
			s->data[i-k] = s->data[i];//ǰ��k��λ��
	}
	s->length -= k;
}
void DeleteRepeat(PSeqList s) {//ɾ��������ȫ���ظ�Ԫ�أ�ʹ��������Ԫ�ز�ͬ
	int i, j;//iָ���һ�����ظ���Ԫ�أ�j����ָ��
	for (i = 0, j = 1; j < s->length;++j) {//ʹ��ֱ�Ӳ���ķ�������ʼʱ����һ��Ԫ�ؿ������ظ��������֮�������ж�
		if (s->data[i] != s->data[j])	   //�����Ԫ���Ƿ���ǰ����ظ����������ͬ�������ͬ��������жϣ���ͬ�Ͳ���
			s->data[++i] = s->data[j];	
	}
	s->length = i + 1;
}
void Merge(PSeqList a, PSeqList b, PSeqList c) {//�����������ϲ�Ϊһ��
	int i = 0, j = 0, k = 0;
	while (i < a->length && j < b->length)
		if (a->data[i] < b->data[j])
			c->data[k++] = a->data[i++];
		else
			c->data[k++] = b->data[j++];
	while(i<a->length)
		c->data[k++] = a->data[i++];
	while (j<b->length)
		c->data[k++] = b->data[j++];
	c->length = k;
}
void ReverseList2(PSeqList s, int low, int high) {
	for (int i = low, j = high - 1; i < j; ++i, --j)
		swap(s->data[i], s->data[j]);
}
void ExchangeList(PSeqList s, int m, int n) {//һά����A[m+n]�������˳���(a1...am),(b1...bm),����������Ϊ
	ReverseList2(s, 0, m);					 //(b1...bm)��(a1...am)
	ReverseList2(s, m, n);
	ReverseList2(s, 0, n);
}
void FindX(PSeqList s,int x) {//����������Ƿ���x,�еĻ������Ԫ�ؽ�����û�еĻ�����
	int low = 0, high = s->length - 1,mid;
	int i;
	while (low <= high) {
		mid = (low + high) / 2;
		if (s->data[mid] == x)
			break;
		else if (s->data[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (s->data[mid] == x && mid != s->length - 1)//�ҵ����Ҳ������һ��Ԫ��
		swap(s->data[mid], s->data[mid + 1]);
	if (low > high) {
		for (i = s->length - 1; i > high; --i)
			s->data[i + 1] = s->data[i];
		s->data[i + 1] = x;
		s->length++;
	}

}
int M_Search(int a[], int b[], int n) {//�����������飬�ϲ��󷵻�
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (a[m1] == b[m2])
			return a[m1];
		else if (a[m1] < b[m2]) {
			if ((s1+d1) % 2 == 0) {//Ԫ�ظ���Ϊ����
				s1 = m1;
				d2 = m2;
				
			}
			else
			{
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else
		{
			if ((s2+d2) % 2 == 0) {//Ԫ�ظ���Ϊ����
				d1 = m1;
				s2 = m2;
			}
			else
			{
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return a[s1] < b[s2] ? a[s1] : b[s2];
}
int Majority(int a[], int n) {//�ҵ���Ԫ�أ���������һ�룩���أ�û�ҵ�����-1
	int c = a[0], count = 1;
	int i;
	for (i = 1; i < n; ++i) {
		if (c == a[i])
			++count;
		else if (count > 0)
			--count;
		else {
			c = a[i];
			count = 1;
		}
	}
	if (count > 0)
		return c;
	else
		return -1;
}

int main() {
	//SeqList s;
	//int e;
	//InitList(&s);
	////�ڱ��в���Ԫ��
	//printf("�����ڱ��в���Ԫ�أ�\n");
	//InsertList(&s, 1, 1);
	//InsertList(&s, 2, 2);
	//InsertList(&s, 3, 2);
	//InsertList(&s, 4, 2);
	//InsertList(&s, 5, 3);
	//InsertList(&s, 6, 3);
	//InsertList(&s, 7, 7);
	////��ӡ����Ԫ��
	//printf("����Ԫ���У�\n");
	//PrintList(&s);
	//e = DeleteList(&s, 6, &e);
	//cout << "ɾ����Ԫ��Ϊ��" << e << endl;
	//PrintList(&s);
	////���˳���
	//ClearList(&s);
	/*e = DeleteMin(&s);
	cout << "ɾ������СԪ��Ϊ��"<<e << endl;*/
	//ReverseList(&s);
	//DeleteX(&s, 54);
	//Delete_p_q2(&s, 3,6);
	//DeleteRepeat(&s);
	//PrintList(&s);
	/*SeqList a, b,c;
	InitList(&a);
	InitList(&b);
	InitList(&c);
	InsertList(&a, 1, 1);
	InsertList(&a, 2, 2);
	InsertList(&a, 3, 5);
	InsertList(&a, 4, 7);
	InsertList(&a, 5, 10);
	InsertList(&a, 6, 11);

	InsertList(&b, 1, 1);
	InsertList(&b, 2, 4);
	InsertList(&b, 3, 6);
	InsertList(&b, 4, 10);
	InsertList(&b, 5, 10);
	InsertList(&b, 6, 12);
	Merge(&a, &b, &c);
	PrintList(&c);*/
	/*SeqList s;
	InitList(&s);
	InsertList(&s, 1, 1);
	InsertList(&s, 2, 3);
	InsertList(&s, 3, 5);
	InsertList(&s, 4, 7);
	InsertList(&s, 5, 9);
	InsertList(&s, 6, 2);
	InsertList(&s, 7, 4);
	InsertList(&s, 8, 6);
	InsertList(&s, 9, 8);
	InsertList(&s, 10, 10);
	InsertList(&s, 11, 11);
	PrintList(&s);
	ExchangeList(&s,5,11);
	PrintList(&s);*/

	/*SeqList s;
	InitList(&s);
	InsertList(&s, 1, 1);
	InsertList(&s, 2, 3);
	InsertList(&s, 3, 5);
	InsertList(&s, 4, 7);
	InsertList(&s, 5, 9);
	FindX(&s, 1);
	PrintList(&s);*/
	//int a[] = { 1,5,6,13,17 };
	//int b[] = { 2,9,10,13,22};
	//int m = M_Search(a, b, 5);
	//cout << "��λ���ǣ�" << m << endl;
	int a[] = { 1,1,1,2,2,1,1,2,2,2,1 };
	cout << "��Ԫ����" << Majority(a, sizeof(a) / sizeof(a[0])) << endl;

	system("pause");
	return 0;
}


//#include<iostream>
//using namespace std;
//#define LIST_INIT_SIZE 100     // ���Ա�洢�ռ�ĳ�ʼ��������
//
//typedef struct {//��̬����
//	int *data;//�洢�ռ��ַ
//	int length;//��ǰ����
//	int listSize; //��ǰ����Ĵ洢����(��sizeof(int)Ϊ��λ)
//}SeqList,*PSeqList;
//
////����һ���յ����Ա�L
//PSeqList InitList() {
//	PSeqList s = (PSeqList)malloc(sizeof(SeqList));
//	s->data = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
//	if (!s->data) {
//		cout << "�ڴ����ʧ��" << endl;
//		return NULL;
//	}
//	s->length = 0;//�ձ���Ϊ0
//	s->listSize = LIST_INIT_SIZE;//��ʼ���洢��
//	cout << "��ʼ���ɹ�" << endl;
//	return s;
//}
//void Destory(PSeqList s)//�ͷ��ڴ棬���ٱ����,ֱ�Ӱ��ڴ��ͷŵĲ���������free()��c++��delete������
//						//ע�⣺��malloc��������Ŀռ����ͷ�ʱ�������ͷŵģ����������ַ���ڵ����ɿռ�ȫ���ͷ�
//						//����˳������ٿ���ֻ�ͷŻ�ַ�����Զ��ͷ����пռ䣬������Ҫһ��һ���İѽڵ�ɾ��
//{
//  //   if (s->data)//�����ǰ������
//  //   {
//  //       free(s->data);//����֮,�ڴ涼û�ˣ�������Ҳ�Ͳ������ˣ���Ĳ��ùܡ�
//  //   }
//	 //free(s);
//	cout << "��ʼ�������ٲ���" << endl;
//	if (s == NULL)
//	{
//		return;
//	}
//	free(s->data);
//	printf("�����Ա������٣�\n");
//}
//int InsertList(PSeqList s, int i, int e) {
//	if (i<1 || i>s->length + 1) {
//		cout << "iֵ���Ϸ�" << endl;
//	}
//	if (s->length * sizeof(int) >= (unsigned)(s->listSize)) {
//		int *newBase = (int *)realloc(s->data, (s->length) + sizeof(int));
//		if (!newBase) {
//			cout << "�ڴ����ʧ��" << endl;
//			return 0;
//		}
//		s->data = newBase;
//		s->listSize += sizeof(int);
//	}
//	int *p, *q;
//	q = &(s->data[i - 1]);
//	for (p = &(s->data[s->length - 1]); p >= q; --p) {
//		*(p + 1) = *p;		// ����λ�ü�֮���Ԫ������
//	}
//	*q = e;	//����Ԫ��e
//	++s->length;	//������1
//	return 0;
//}
//void DeleteList(PSeqList s, int i) {
//	if (i<1 || i>s->length) {
//		cout << "iֵ���Ϸ�" << endl;
//	}
//	int *p, *q;
//	q = &(s->data[i - 1]);
//	cout << "ɾ����Ԫ��Ϊ��" << *q << endl;
//	for (p = q + 1; p < &(s->data[s->length]); ++p) {
//		*(p - 1) = *p;//�����*p����*(p-1)���൱�ڰ�*p����*q�ˣ�������󷵻ص���*(q+1)
//	}
//	--s->length;
//}
//void PrintList(PSeqList s) {
//	int *p;
//	if (s->length == 0) {
//		cout << "��Ϊ��" << endl;
//	}
//	for (p = &(s->data[0]); p < &(s->data[s->length]); ++p) {
//		cout << *p << '\t';
//	}
//	cout << endl;
//}
//int main() {
//	PSeqList s = InitList();
//	InsertList(s, 1, 1);
//	InsertList(s, 2, 2);
//	InsertList(s, 3, 3);
//	InsertList(s, 4, 4);
//	InsertList(s, 5, 5);
//	InsertList(s, 6, 6);
//	InsertList(s, 7, 7);
//	InsertList(s, 8, 8);
//	PrintList(s);
//	DeleteList(s, 4);
//	PrintList(s);
//	Destory(s);
//	system("pause");
//	return 0;
//}
