#include<iostream>
using namespace std;

//用数组实现顺序栈
typedef struct stack {
	int data[100];	//定义一个长度为100的一维数组这里可以随便设置长度
	int top;	//栈顶指针

}STACK, *Stack;

void InitStack(Stack s) {//初始化一个顺序栈
	s->top = -1;
	cout << "栈初始化成功" << endl;
}
bool EmptyStack(Stack s) {//判断栈是否为空
	if (s->top == -1)
		return true;
	else
		return false;
}
bool FullStack(Stack s) {//判断栈是否为满
	if (s->top == 99)
		return true;
	else
		return false;
}
bool PushStack(Stack s, int x) {//入栈
	if (FullStack(s))
		return false;
	else {
		s->data[++s->top] = x;//指针先++，再把数据存进栈顶
		return true;
	}
}
bool PopStack(Stack s, int *a) {//出栈
	if (EmptyStack(s)) {
		return false;
	}
	else
	{
		*a = s->data[s->top--];
		return true;
	}
}
int TopStack(Stack s) {//取栈顶元素
	int x;
	x = s->data[s->top];
	return x;
}
int LengthStack(Stack s) {//返回栈的长度
	return s->top + 1;
}
void TravelStack(Stack s) {//遍历栈
	int x;
	while (!EmptyStack(s))
	{
		PopStack(s,&x);
		cout << x << '\t';
	}
	cout << endl;
}
void JudgeStack(char a[]) {//判断一个栈的进栈出栈操作是否合法
	int i = 0, j = 0, k = 0;
	while (a[i] != '\0')
	{
		switch (a[i])
		{
		case 'I':
			++j;
			break;
		case 'O':
			++k;
			if (k > j) {
				cout << "序列非法" << endl;
				return;
			}
		}
		++i;
	}
	if (j != k) {
		cout << "序列非法" << endl;
		return;
	}
	else {
		cout << "序列合法" << endl;
		return;
	}
}
void BracketsCheck(int *a) {//一个括号表达式由‘(’、‘)’、‘[’、‘]’、‘{’、‘}’组成，判断括号表达式是否
	STACK s;				//合法，用1、4、2、5、3、6分别表示‘(’、‘)’、‘[’、‘]’、‘{’、‘}’，用0表示输入结束。
	InitStack(&s);
	int i = 0;
	int x;
	while (a[i] != 0) {
		switch (a[i])
		{
		case 1:
			PushStack(&s, 1);break;
		case 2:
			PushStack(&s, 2);break;
		case 3:
			PushStack(&s, 3);break;
		case 4:
			PopStack(&s, &x);
			if (x != 1) {
				cout << "表达式不合法" << endl;
				return;
			}
			break;
		case 5:
			PopStack(&s, &x);
			if (x != 2) {
				cout << "表达式不合法" << endl;
				return;
			}
			break;
		case 6:
			PopStack(&s, &x);
			if (x != 3) {
				cout << "表达式不合法" << endl;
				return;
			}
			break;
		default:
			break;
		}
		++i;
	}
	if (!EmptyStack(&s)) {
		cout << "表达式不合法" << endl;
		return;
	}
	else
	{
		cout << "表达式合法" << endl;
		return;
	}

}
void Train_Arrange(int *train) {//火车硬座、软座车厢调度，遇到硬座就入栈，遇到软座就进行下一个，最后完了再出栈，就
	STACK s;					//能实现所有软座车厢在所有硬座车厢之前了，用1代表硬座车厢，2代表软座车厢
	InitStack(&s);
	int x;
	int *p = train, *q = train;
	while (*p)
	{
		if (*p == 1)
			PushStack(&s, 1);
		else
			*(q++) = *p;
		p++;
	}
	while (!EmptyStack(&s)) {
		PopStack(&s, &x);
		*(q++) = x;
	}
}

#define MaxSize 100
typedef struct {		//用数组实现的循环队列
	int data[MaxSize];
	int front, rear;
}SQQUEUE,*SqQueue;
void InitQueue(SqQueue q) {//另一种写法，用&q的话，就用.运算符
	q->front = q->rear = 0;
	cout << "队列初始化成功" << endl;
}
bool QueueEmpty(SqQueue q) {
	if (q->front == q->rear) {
		return true;
	}
	else
		return false;
}
void EnQueue(SqQueue q, int x) {
	if ((q->rear + 1) % MaxSize == q->front) {//牺牲一个存储单元来判断队满
		cout << "队满" << endl;
		return;
	}
	q->data[q->rear] = x;//q->rear指向最后一个元素的下一个，所以先赋值，再++
	q->rear = (q->rear + 1) % MaxSize;
}
void DeQueue(SqQueue q, int *x) {
	if (QueueEmpty(q)) {
		return;
	}
	*x = q->data[q->front];//q->front指向第一个元素，所以也是先赋值，再++
	q->front = (q->front + 1) % MaxSize;
}
void PrintQueue(SqQueue q) {
	int x;
	cout << "打印队列: " << endl;
	while (!QueueEmpty(q)) {
		DeQueue(q, &x);
		cout << x << '\t';
	}
	cout << endl;
}
void InverseQueue(Stack s, SqQueue q) {//用栈和队列将队列的元素逆置，先将队列元素全部入栈，然后全部出栈入队列
	int x;
	while(!QueueEmpty(q)){
		DeQueue(q, &x);
		PushStack(s, x);
	}
	while (!EmptyStack(s))
	{
		PopStack(s, &x);
		EnQueue(q, x);
	}
	PrintQueue(q);
}
double func(int n, int x) {//利用栈实现递归函数的非递归版本
	struct stack
	{
		int no;
		double value;
	}Stack[100];
	int top = -1, i;
	double fv1 = 1, fv2 = 2 * x;
	for (i = n; i >= 2; --i) {
		++top;
		Stack[top].no = i;

	}
	while (top>=0)
	{
		Stack[top].value = 2 * x*fv2 - 2 * (Stack[top].no - 1)*fv1;
		fv1 = fv2;
		fv2 = Stack[top].value;
		--top;
	}
	if (n == 0)
		return fv1;
	return fv2;
}

int main() {
	//int i, length, ss;//ss为栈顶
	//STACK s;
	//InitStack(&s);
	//PushStack(&s, 1);
	//PushStack(&s, 2);
	//PushStack(&s, 3);
	//PushStack(&s, 4);
	//PushStack(&s, 5);
	//PushStack(&s, 6);
	//PushStack(&s, 7);
	//ss = TopStack(&s);
	//cout << "栈顶为" << ss << endl;
	//PopStack(&s,&i);
	//cout << "将" << i <<"出栈"<< endl;
	//ss = TopStack(&s);
	//cout << "栈顶为" << ss << endl;
	//length = LengthStack(&s);
	//cout << "长度为" << length << endl;
	//TravelStack(&s);
	////char a[100] = {'I','O','I','I','O' ,'I','O','O',};
	////JudgeStack(a);

	/*STACK s;
	SQQUEUE q;
	InitStack(&s);
	InitQueue(&q);
	for (int i = 0; i < 20; ++i) {
		EnQueue(&q, i);
	}
	InverseQueue(&s, &q);*/

	//int a[100] = { 3,2,1,4,5,6,1,0 };
	//BracketsCheck(a);

	/*int train[30] = { 1,2,1,2,1,2,2,2,2,1,1,1,1,2,2,1};
	int n = sizeof(train) / sizeof(train[0]);
	Train_Arrange(train);
	cout << "经过调度后为：" << endl;
	for (int i = 0; i < n; ++i) {
		cout << train[i] << '\t';
	}
	cout << endl;*/

	//double x = func(6, 1);
	//cout << "结果为：" << x << endl;


	system("pause");
	return 0;
}

//#include<iostream>
//using namespace std;
//
////用数组实现共享双向顺序栈
//typedef struct stack {
//	int data[100];	//定义一个长度为100的一维数组这里可以随便设置长度
//	int top1;	//栈顶指针1
//	int top2;	//栈顶指针1
//
//}STACK, *Stack;
//
//void InitStack(Stack s);//初始化一个顺序栈
//bool PushDoubleStack(Stack s, int flag, int x);//入栈
//bool PopDoubleStack(Stack s, int flag, int *e);//出栈
//
//void InitStack(Stack s) {
//	s->top1 = -1;
//	s->top2 = 100;
//}
//bool PushDoubleStack(Stack s, int flag, int x) {//flag为选择栈1还是栈2
//	if (s->top1 + 1 == s->top2)//共享栈满
//		return false;
//	if (flag == 1)
//		s->data[++s->top1] = x;
//	if (flag == 2)
//		s->data[--s->top2] = x;
//	return true;
//}
//bool PopDoubleStack(Stack s, int flag, int *e) {
//	if (flag == 1 && s->top1 != -1) {
//		*e = s->data[s->top1--];
//		return true;
//	}
//	if (flag == 2 && s->top2 != 100) {
//		*e = s->data[s->top1++];
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	Stack s = (Stack)malloc(sizeof(STACK));
//	InitStack(s);
//	int e;                //入栈与出栈的元素
//
//	while (true)
//	{
//		printf("请选择对顺序栈的操作：\n");
//		printf("1.栈1入栈\n");
//		printf("2.栈2入栈\n");
//		printf("3.栈1出栈\n");
//		printf("4.栈2出栈\n");
//		printf("5.退出\n");
//		int a;
//		scanf_s("%d", &a);
//		switch (a)
//		{
//		case 1:
//			printf("请输入入栈1的元素：");
//			scanf_s("%d", &e);
//			if (PushDoubleStack(s, 1, e))
//				printf("入栈成功\n");
//			else
//				printf("入栈失败\n");
//			break;
//		case 2:
//			printf("请输入入栈2的元素：");
//			scanf_s("%d", &e);
//			if (PushDoubleStack(s, 2, e))
//				printf("入栈成功\n");
//			else
//				printf("入栈失败\n");
//			break;
//		case 3:
//			if (PopDoubleStack(s, 1, &e))
//				printf("出栈的元素为：%d\n", e);
//			else
//				printf("栈空\n");
//			break;
//		case 4:
//			if (PopDoubleStack(s, 2, &e))
//				printf("出栈的元素为：%d\n", e);
//			else
//				printf("栈空\n");
//			break;
//		case 5:
//			return 0;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}



