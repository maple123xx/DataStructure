#include<iostream>
#include<stdlib.h>
using namespace std;

//������ʵ��˳��ջ
typedef struct stack {
	int data[100];	//����һ������Ϊ100��һά�����������������ó���
	int top;	//ջ��ָ��

}STACK, *Stack;

void InitStack(Stack s);//��ʼ��һ��˳��ջ
bool EmptyStack(Stack s);//�ж�ջ�Ƿ�Ϊ��
bool FullStack(Stack s);//�ж�ջ�Ƿ�Ϊ��
bool PushStack(Stack s, int x);//��ջ
bool PopStack(Stack s,int *a);//��ջ
int TopStack(Stack s);//ȡջ��Ԫ��
int LengthStack(Stack s);//����ջ�ĳ���
void TravelStack(Stack s);//����ջ

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
		s->data[++s->top] = x;//ָ����++���ٰ����ݴ��ջ��
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
	int i, length, ss;//ssΪջ��
	Stack s = (Stack)malloc(sizeof(STACK));
	InitStack(s);
	PushStack(s, 1);
	PushStack(s, 2);
	PushStack(s, 3);
	PushStack(s, 4);
	PushStack(s, 5);
	PushStack(s, 6);
	ss = TopStack(s);
	cout << "ջ��Ϊ" << ss << endl;
	PopStack(s,&i);
	cout << "��" << i <<"��ջ"<< endl;
	ss = TopStack(s);
	cout << "ջ��Ϊ" << ss << endl;
	length = LengthStack(s);
	cout << "����Ϊ" << length << endl;
	TravelStack(s);

	system("pause");
	return 0;
}
