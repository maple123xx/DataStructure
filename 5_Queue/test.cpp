#include<iostream>
#include"Queue.h"
using namespace std;
//int main() {
//	/*SqQueue q;
//	int i;
//	InitQueue(q);
//	EnQueue(&q, 1);
//	EnQueue(&q, 2);
//	EnQueue(&q, 3);
//	EnQueue(&q, 4);
//	EnQueue(&q, 5);
//	EnQueue(&q, 6);
//	EnQueue(&q, 7);
//	EnQueue(&q, 8);
//	DeQueue(&q, &i);
//	cout << "��" << i << "����" << endl;
//	DeQueue(&q, &i);
//	cout << "��" << i << "����" << endl;
//	cout << "���г���Ϊ" << LengthQueue(&q) << endl;
//	PrintQueue(&q);*/
//
//	LinkQueue q;
//	int x;
//	InitQueue2(q);
//	for (int i = 0; i < 10; ++i) {
//		EnQueue2(q, i);
//	}
//	DeQueue2(q, &x);
//	cout << "��" << x << "����" << endl;
//	DeQueue2(q, &x);
//	cout << "��" << x << "����" << endl;
//	DeQueue2(q, &x);
//	cout << "��" << x << "����" << endl;
//	cout << "���г���Ϊ" << LengthQueue2(q) << endl;
//	PrintQueue2(q);
//	system("pause");
//	return 0;
//}

typedef struct {		//������ʵ�ֵ�ѭ������,����һ��tag���ж�q.front==q.rear��ʱ���Ƕ������Ƕӿ�,�Ͳ�������һ����Ԫ
	int data[MaxSize];
	int front, rear;
	int tag;
}SqQueue2;
void InitQueue3(SqQueue2 &q) {//��һ��д������&q�Ļ�������.�����
	q.front = q.rear = 0;
	q.tag = 0;
	cout << "��ʼ���ɹ�" << endl;
}
void EnQueue3(SqQueue2 &q, int x) {
	if (q.front==q.rear&&q.tag==1) {//����һ��tag���ж�q.front==q.rear��ʱ���Ƕ������Ƕӿ�
		cout << "����" << endl;
		return;
	}
	q.data[q.rear] = x;//q->rearָ�����һ��Ԫ�ص���һ���������ȸ�ֵ����++
	q.rear = (q.rear + 1) % MaxSize;
	q.tag = 1;			//���ܶ���
}
void DeQueue3(SqQueue2 &q, int &x) {
	if (q.front == q.rear&&q.tag == 0) {//����һ��tag���ж�q.front==q.rear��ʱ���Ƕ������Ƕӿ�
		cout << "�ӿ�" << endl;
		return;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.tag = 1;
}
void PrintQueue3(SqQueue2 &q) {
	int x;
	cout << "��ӡ����: " << endl;
	while (q.front != q.rear) {
		DeQueue3(q, x);
		cout << x << '\t';
	}
	cout << endl;
}
int main() {
	SqQueue2 q;
	int x;
	InitQueue3(q);
	for (int i = 0; i < 15; ++i) {
		EnQueue3(q, i);
	}
	/*DeQueue3(q, x);
	cout << "��" << x << "����" << endl;
	DeQueue3(q, x);
	cout << "��" << x << "����" << endl;*/
	DeQueue3(q, x);
	cout << "��" << x << "����" << endl;
	PrintQueue3(q);
	system("pause");
	return 0;
}