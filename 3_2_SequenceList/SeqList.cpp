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

int main() {
	SeqList s;
	int e;
	InitList(&s);
	//�ڱ��в���Ԫ��
	printf("�����ڱ��в���Ԫ�أ�\n");
	InsertList(&s, 1, 3);
	InsertList(&s, 2, 2);
	InsertList(&s, 3, 3);
	InsertList(&s, 4, 4);
	InsertList(&s, 5, 11);
	InsertList(&s, 6, 4);
	InsertList(&s, 7, 7);
	//��ӡ����Ԫ��
	printf("����Ԫ���У�\n");
	PrintList(&s);
	//e = DeleteList(&s, 6, &e);
	//cout << "ɾ����Ԫ��Ϊ��" << e << endl;
	//PrintList(&s);
	////���˳���
	//ClearList(&s);
	/*e = DeleteMin(&s);
	cout << "ɾ������СԪ��Ϊ��"<<e << endl;*/
	//ReverseList(&s);
	//DeleteX(&s, 54);
	Delete_p_q2(&s, 3,6);
	PrintList(&s);
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
