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
