#include<iostream>
#include"Queue.h"
using namespace std;
int main() {
	/*SqQueue q;
	int i;
	InitQueue(q);
	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	EnQueue(&q, 4);
	EnQueue(&q, 5);
	EnQueue(&q, 6);
	EnQueue(&q, 7);
	EnQueue(&q, 8);
	DeQueue(&q, &i);
	cout << "��" << i << "����" << endl;
	DeQueue(&q, &i);
	cout << "��" << i << "����" << endl;
	cout << "���г���Ϊ" << LengthQueue(&q) << endl;
	PrintQueue(&q);*/

	LinkQueue q;
	int x;
	InitQueue2(q);
	for (int i = 0; i < 10; ++i) {
		EnQueue2(q, i);
	}
	DeQueue2(q, &x);
	cout << "��" << x << "����" << endl;
	DeQueue2(q, &x);
	cout << "��" << x << "����" << endl;
	DeQueue2(q, &x);
	cout << "��" << x << "����" << endl;
	cout << "���г���Ϊ" << LengthQueue2(q) << endl;
	PrintQueue2(q);
	system("pause");
	return 0;
}