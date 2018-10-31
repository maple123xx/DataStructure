#include<iostream>
#include"Queue.h"
using namespace std;


void InitQueue(SqQueue &q) {//另一种写法，用&q的话，就用.运算符
	q.front = q.rear = 0;
	cout << "初始化成功" << endl;
}
bool isEmpty(SqQueue *q) {
	if (q->front == q->rear) {
		return true;
	}
	else
		return false;
}
void EnQueue(SqQueue *q,int x) {
	if ((q->rear + 1) % MaxSize == q->front) {//牺牲一个存储单元来判断队满
		cout << "队满" << endl;
		return;
	}
	q->data[q->rear] = x;//q->rear指向最后一个元素的下一个，所以先赋值，再++
	q->rear = (q->rear + 1) % MaxSize;
}
void DeQueue(SqQueue *q,int *x) {
	if (isEmpty(q)) {
		return;
	}
	*x = q->data[q->front];//q->front指向第一个元素，所以也是先赋值，再++
	q->front = (q->front + 1) % MaxSize;
}
void PrintQueue(SqQueue *q) {
	int x;
	cout << "打印队列: " << endl;
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