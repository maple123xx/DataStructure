#include<iostream>
#include"Queue.h"
using namespace std;


void InitQueue(SqQueue &q) {//��һ��д������&q�Ļ�������.�����
	q.front = q.rear = 0;
	cout << "��ʼ���ɹ�" << endl;
}
bool isEmpty(SqQueue *q) {
	if (q->front == q->rear) {
		return true;
	}
	else
		return false;
}
void EnQueue(SqQueue *q,int x) {
	if ((q->rear + 1) % MaxSize == q->front) {//����һ���洢��Ԫ���ж϶���
		cout << "����" << endl;
		return;
	}
	q->data[q->rear] = x;//q->rearָ�����һ��Ԫ�ص���һ���������ȸ�ֵ����++
	q->rear = (q->rear + 1) % MaxSize;
}
void DeQueue(SqQueue *q,int *x) {
	if (isEmpty(q)) {
		return;
	}
	*x = q->data[q->front];//q->frontָ���һ��Ԫ�أ�����Ҳ���ȸ�ֵ����++
	q->front = (q->front + 1) % MaxSize;
}
void PrintQueue(SqQueue *q) {
	int x;
	cout << "��ӡ����: " << endl;
	while (!isEmpty(q)) {
		DeQueue(q, &x);
		cout << x << '\t';
	}
	cout << endl;
}
int LengthQueue(SqQueue *q) {
	//cout << q->rear << '\t' << q->front << endl;
	return (q->rear-q->front+MaxSize)%MaxSize;
}