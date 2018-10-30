#include<iostream>
#include<stdlib.h>
using namespace std;

//用数组实现顺序栈
typedef struct stack {
	int data[100];	//定义一个长度为100的一维数组这里可以随便设置长度
	int top;	//栈顶指针

}STACK, *Stack;

void InitStack(Stack s);//初始化一个顺序栈
bool EmptyStack(Stack s);//判断栈是否为空
bool FullStack(Stack s);//判断栈是否为满
bool PushStack(Stack s, int x);//入栈
bool PopStack(Stack s,int *a);//出栈
int TopStack(Stack s);//取栈顶元素
int LengthStack(Stack s);//返回栈的长度
void TravelStack(Stack s);//遍历栈

void InitStack(Stack s) {
	s->top = -1;
}
bool EmptyStack(Stack s) {
	if (s->top == -1)
		return true;
	else
		return false;
}
bool FullStack(Stack s) {
	if (s->top == 99)
		return true;
	else
		return false;
}
bool PushStack(Stack s, int x) {
	if (FullStack(s))
		return false;
	else {
		s->data[++s->top] = x;//指针先++，再把数据存进栈顶
		return true;
	}
}
bool PopStack(Stack s, int *a) {
	if (EmptyStack(s)) {
		return false;
	}
	else
	{
		*a = s->data[s->top--];
		return true;
	}
}
int TopStack(Stack s) {
	int x;
	x = s->data[s->top];
	return x;
}
int LengthStack(Stack s) {
	return s->top + 1;
}
void TravelStack(Stack s) {
	int x;
	while (!EmptyStack(s))
	{
		PopStack(s,&x);
		cout << x << '\t';
	}
	cout << endl;
}
int main() {
	int i, length, ss;//ss为栈顶
	Stack s = (Stack)malloc(sizeof(STACK));
	InitStack(s);
	PushStack(s, 1);
	PushStack(s, 2);
	PushStack(s, 3);
	PushStack(s, 4);
	PushStack(s, 5);
	PushStack(s, 6);
	PushStack(s, 7);
	ss = TopStack(s);
	cout << "栈顶为" << ss << endl;
	PopStack(s,&i);
	cout << "将" << i <<"出栈"<< endl;
	ss = TopStack(s);
	cout << "栈顶为" << ss << endl;
	length = LengthStack(s);
	cout << "长度为" << length << endl;
	TravelStack(s);

	system("pause");
	return 0;
}

//#include<iostream>
//#include<stdlib.h>
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



