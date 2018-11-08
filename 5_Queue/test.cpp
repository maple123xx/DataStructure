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
//	cout << "将" << i << "出队" << endl;
//	DeQueue(&q, &i);
//	cout << "将" << i << "出队" << endl;
//	cout << "队列长队为" << LengthQueue(&q) << endl;
//	PrintQueue(&q);*/
//
//	LinkQueue q;
//	int x;
//	InitQueue2(q);
//	for (int i = 0; i < 10; ++i) {
//		EnQueue2(q, i);
//	}
//	DeQueue2(q, &x);
//	cout << "将" << x << "出队" << endl;
//	DeQueue2(q, &x);
//	cout << "将" << x << "出队" << endl;
//	DeQueue2(q, &x);
//	cout << "将" << x << "出队" << endl;
//	cout << "队列长队为" << LengthQueue2(q) << endl;
//	PrintQueue2(q);
//	system("pause");
//	return 0;
//}

typedef struct {		//用数组实现的循环队列,设置一个tag来判断q.front==q.rear的时候是队满还是队空,就不用牺牲一个单元
	int data[MaxSize];
	int front, rear;
	int tag;
}SqQueue2;
void InitQueue3(SqQueue2 &q) {//另一种写法，用&q的话，就用.运算符
	q.front = q.rear = 0;
	q.tag = 0;
	cout << "初始化成功" << endl;
}
void EnQueue3(SqQueue2 &q, int x) {
	if (q.front==q.rear&&q.tag==1) {//设置一个tag来判断q.front==q.rear的时候是队满还是队空
		cout << "队满" << endl;
		return;
	}
	q.data[q.rear] = x;//q->rear指向最后一个元素的下一个，所以先赋值，再++
	q.rear = (q.rear + 1) % MaxSize;
	q.tag = 1;			//可能队满
}
void DeQueue3(SqQueue2 &q, int &x) {
	if (q.front == q.rear&&q.tag == 0) {//设置一个tag来判断q.front==q.rear的时候是队满还是队空
		cout << "队空" << endl;
		return;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.tag = 1;
}
void PrintQueue3(SqQueue2 &q) {
	int x;
	cout << "打印队列: " << endl;
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
	cout << "将" << x << "出队" << endl;
	DeQueue3(q, x);
	cout << "将" << x << "出队" << endl;*/
	DeQueue3(q, x);
	cout << "将" << x << "出队" << endl;
	PrintQueue3(q);
	system("pause");
	return 0;
}