#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {//静态分配的顺序表
	int data[100];//用数组存储线性表中的元素
	int length;		//顺序表的长度
}SeqList,*PSeqList;

void InitList(PSeqList s);//顺序表的初始化操作
int Length(PSeqList s);//求顺序表的长度
int GetData(PSeqList s, int i);//返回数据表中第i个元素的值
int InsertList(PSeqList s, int i, int e);   //在顺序表的第i个位置插入元素
int DeleteList(PSeqList s, int i, int* e); //删除顺序表L的第i个数据元素
int LocateList(PSeqList s, int e); //查找数据元素e在表中的位置
void ClearList(PSeqList L);//清空顺序表
void PrintList(PSeqList s);	//打印表中元素

void InitList(PSeqList s) {//用PSeqList定义的s是一个指针，所以用SeqList定义的实参s必须传入它的地址&s
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
	return s->data[i-1];//数据元素的序号从1开始，数组下表从0开始，第i个元素对应的数组下标为i-1
}
int InsertList(PSeqList s, int i, int e) {
	if (i<1 || i>s->length + 1) {
		cout << "插入位置不合法" << endl;
		return 0;
	}
	else if (s->length >= 100) {
		cout << "顺序表满" << endl;
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
		cout << "顺序表空" << endl;
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
		printf("表为空！\n");
		return;
	}
	for (int k = 0; k < s->length; k++)
	{
		printf("%d\t", s->data[k]);
	}
	printf("\n");
}
int DeleteMin(PSeqList s) {//删除表中最有最小值的元素（假设唯一），空出的位置由最后一个元素填补
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
void ReverseList(PSeqList s) {//将顺序表的所有元素逆置，要求空间复杂度为O(1)
	for (int i = 0, j = s->length-1; i < j; ++i, --j) {
		swap(s->data[i], s->data[j]);
	}
}
void DeleteX(PSeqList s,int x) {//删除顺序表中所有值为x的元素
	//for (int i = 0; i < s->length; ) {//方法一：用末尾元素替代x，这个方法会改变元素的相对位置
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
	for (int i = 0; i < s->length; ++i) {//方法二：用k记录表中值不等于x的元素个数
		if (s->data[i] != x) {
			s->data[k] = s->data[i];
			++k;
		}
	}
	s->length = k;
}
void Delete_p_q(PSeqList s, int p, int q) {//删除有序表中值为p,q(p<q)之间的元素，因为是有序，所以p,q之间的元素连续
	int i, j;
	for (i = 0; i < s->length && s->data[i] < p; ++i);//找到第一个大于等于p的数
	if (i >= s->length)
		return;//所有元素都小于p
	for (j = i; j < s->length && s->data[j] <= q; ++j);//找到第一个大于q的数
	for (;j<s->length;++i,++j) {
		s->data[i] = s->data[j];
	}
	s->length = i;
}
void Delete_p_q2(PSeqList s, int p, int q) {//删除顺序表（不是有序的）中值为p,q(p<q)之间的元素
	int k = 0;//k记录元素值在p,q之间元素的个数
	for (int i = 0; i < s->length; ++i) {
		if (s->data[i] >= p && s->data[i] <= q) 
			++k;
		else
			s->data[i-k] = s->data[i];//前移k个位置
	}
	s->length -= k;
}

int main() {
	SeqList s;
	int e;
	InitList(&s);
	//在表中插入元素
	printf("依次在表中插入元素：\n");
	InsertList(&s, 1, 3);
	InsertList(&s, 2, 2);
	InsertList(&s, 3, 3);
	InsertList(&s, 4, 4);
	InsertList(&s, 5, 11);
	InsertList(&s, 6, 4);
	InsertList(&s, 7, 7);
	//打印表中元素
	printf("表中元素有：\n");
	PrintList(&s);
	//e = DeleteList(&s, 6, &e);
	//cout << "删除的元素为：" << e << endl;
	//PrintList(&s);
	////清空顺序表
	//ClearList(&s);
	/*e = DeleteMin(&s);
	cout << "删除的最小元素为："<<e << endl;*/
	//ReverseList(&s);
	//DeleteX(&s, 54);
	Delete_p_q2(&s, 3,6);
	PrintList(&s);
	system("pause");
	return 0;
}


//#include<iostream>
//using namespace std;
//#define LIST_INIT_SIZE 100     // 线性表存储空间的初始化分配量
//
//typedef struct {//动态分配
//	int *data;//存储空间基址
//	int length;//当前长度
//	int listSize; //当前分配的存储容量(以sizeof(int)为单位)
//}SeqList,*PSeqList;
//
////构造一个空的线性表L
//PSeqList InitList() {
//	PSeqList s = (PSeqList)malloc(sizeof(SeqList));
//	s->data = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
//	if (!s->data) {
//		cout << "内存分配失败" << endl;
//		return NULL;
//	}
//	s->length = 0;//空表长度为0
//	s->listSize = LIST_INIT_SIZE;//初始化存储量
//	cout << "初始化成功" << endl;
//	return s;
//}
//void Destory(PSeqList s)//释放内存，销毁表操作,直接把内存释放的操作！类似free()和c++的delete操作符
//						//注意：用malloc函数分配的空间在释放时是连续释放的，即将物理地址相邻的若干空间全部释放
//						//所以顺序表销毁可以只释放基址，就自动释放所有空间，而链表要一个一个的把节点删除
//{
//  //   if (s->data)//如果当前表还存在
//  //   {
//  //       free(s->data);//销毁之,内存都没了，整个表也就不存在了，别的不用管。
//  //   }
//	 //free(s);
//	cout << "开始进行销毁操作" << endl;
//	if (s == NULL)
//	{
//		return;
//	}
//	free(s->data);
//	printf("本线性表已销毁！\n");
//}
//int InsertList(PSeqList s, int i, int e) {
//	if (i<1 || i>s->length + 1) {
//		cout << "i值不合法" << endl;
//	}
//	if (s->length * sizeof(int) >= (unsigned)(s->listSize)) {
//		int *newBase = (int *)realloc(s->data, (s->length) + sizeof(int));
//		if (!newBase) {
//			cout << "内存分配失败" << endl;
//			return 0;
//		}
//		s->data = newBase;
//		s->listSize += sizeof(int);
//	}
//	int *p, *q;
//	q = &(s->data[i - 1]);
//	for (p = &(s->data[s->length - 1]); p >= q; --p) {
//		*(p + 1) = *p;		// 插入位置及之后的元素右移
//	}
//	*q = e;	//插入元素e
//	++s->length;	//表增长1
//	return 0;
//}
//void DeleteList(PSeqList s, int i) {
//	if (i<1 || i>s->length) {
//		cout << "i值不合法" << endl;
//	}
//	int *p, *q;
//	q = &(s->data[i - 1]);
//	cout << "删除的元素为：" << *q << endl;
//	for (p = q + 1; p < &(s->data[s->length]); ++p) {
//		*(p - 1) = *p;//这里把*p赋给*(p-1)，相当于把*p赋给*q了，所以最后返回的是*(q+1)
//	}
//	--s->length;
//}
//void PrintList(PSeqList s) {
//	int *p;
//	if (s->length == 0) {
//		cout << "表为空" << endl;
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
