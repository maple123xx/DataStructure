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
	cout << "将" << i << "出队" << endl;
	DeQueue(&q, &i);
	cout << "将" << i << "出队" << endl;
	cout << "队列长队为" << LengthQueue(&q) << endl;
	PrintQueue(&q);*/

	LinkQueue q;
	int x;
	InitQueue2(q);
	for (int i = 0; i < 10; ++i) {
		EnQueue2(q, i);
	}
	DeQueue2(q, &x);
	cout << "将" << x << "出队" << endl;
	DeQueue2(q, &x);
	cout << "将" << x << "出队" << endl;
	DeQueue2(q, &x);
	cout << "将" << x << "出队" << endl;
	cout << "队列长队为" << LengthQueue2(q) << endl;
	PrintQueue2(q);
	system("pause");
	return 0;
}