#include<iostream>
using namespace std;

//������ʵ��˳��ջ
typedef struct stack {
	int data[100];	//����һ������Ϊ100��һά�����������������ó���
	int top;	//ջ��ָ��

}STACK, *Stack;

void InitStack(Stack s) {//��ʼ��һ��˳��ջ
	s->top = -1;
}
bool EmptyStack(Stack s) {//�ж�ջ�Ƿ�Ϊ��
	if (s->top == -1)
		return true;
	else
		return false;
}
bool FullStack(Stack s) {//�ж�ջ�Ƿ�Ϊ��
	if (s->top == 99)
		return true;
	else
		return false;
}
bool PushStack(Stack s, int x) {//��ջ
	if (FullStack(s))
		return false;
	else {
		s->data[++s->top] = x;//ָ����++���ٰ����ݴ��ջ��
		return true;
	}
}
bool PopStack(Stack s, int *a) {//��ջ
	if (EmptyStack(s)) {
		return false;
	}
	else
	{
		*a = s->data[s->top--];
		return true;
	}
}
int TopStack(Stack s) {//ȡջ��Ԫ��
	int x;
	x = s->data[s->top];
	return x;
}
int LengthStack(Stack s) {//����ջ�ĳ���
	return s->top + 1;
}
void TravelStack(Stack s) {//����ջ
	int x;
	while (!EmptyStack(s))
	{
		PopStack(s,&x);
		cout << x << '\t';
	}
	cout << endl;
}
void JudgeStack(char a[]) {//�ж�һ��ջ�Ľ�ջ��ջ�����Ƿ�Ϸ�
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
				cout << "���зǷ�" << endl;
				return;
			}
		}
		++i;
	}
	if (j != k) {
		cout << "���зǷ�" << endl;
		return;
	}
	else {
		cout << "���кϷ�" << endl;
		return;
	}
}

int main() {
	int i, length, ss;//ssΪջ��
	STACK s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PushStack(&s, 6);
	PushStack(&s, 7);
	ss = TopStack(&s);
	cout << "ջ��Ϊ" << ss << endl;
	PopStack(&s,&i);
	cout << "��" << i <<"��ջ"<< endl;
	ss = TopStack(&s);
	cout << "ջ��Ϊ" << ss << endl;
	length = LengthStack(&s);
	cout << "����Ϊ" << length << endl;
	TravelStack(&s);
	//char a[100] = {'I','O','I','I','O' ,'I','O','O',};
	//JudgeStack(a);

	system("pause");
	return 0;
}

//#include<iostream>
//using namespace std;
//
////������ʵ�ֹ���˫��˳��ջ
//typedef struct stack {
//	int data[100];	//����һ������Ϊ100��һά�����������������ó���
//	int top1;	//ջ��ָ��1
//	int top2;	//ջ��ָ��1
//
//}STACK, *Stack;
//
//void InitStack(Stack s);//��ʼ��һ��˳��ջ
//bool PushDoubleStack(Stack s, int flag, int x);//��ջ
//bool PopDoubleStack(Stack s, int flag, int *e);//��ջ
//
//void InitStack(Stack s) {
//	s->top1 = -1;
//	s->top2 = 100;
//}
//bool PushDoubleStack(Stack s, int flag, int x) {//flagΪѡ��ջ1����ջ2
//	if (s->top1 + 1 == s->top2)//����ջ��
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
//	int e;                //��ջ���ջ��Ԫ��
//
//	while (true)
//	{
//		printf("��ѡ���˳��ջ�Ĳ�����\n");
//		printf("1.ջ1��ջ\n");
//		printf("2.ջ2��ջ\n");
//		printf("3.ջ1��ջ\n");
//		printf("4.ջ2��ջ\n");
//		printf("5.�˳�\n");
//		int a;
//		scanf_s("%d", &a);
//		switch (a)
//		{
//		case 1:
//			printf("��������ջ1��Ԫ�أ�");
//			scanf_s("%d", &e);
//			if (PushDoubleStack(s, 1, e))
//				printf("��ջ�ɹ�\n");
//			else
//				printf("��ջʧ��\n");
//			break;
//		case 2:
//			printf("��������ջ2��Ԫ�أ�");
//			scanf_s("%d", &e);
//			if (PushDoubleStack(s, 2, e))
//				printf("��ջ�ɹ�\n");
//			else
//				printf("��ջʧ��\n");
//			break;
//		case 3:
//			if (PopDoubleStack(s, 1, &e))
//				printf("��ջ��Ԫ��Ϊ��%d\n", e);
//			else
//				printf("ջ��\n");
//			break;
//		case 4:
//			if (PopDoubleStack(s, 2, &e))
//				printf("��ջ��Ԫ��Ϊ��%d\n", e);
//			else
//				printf("ջ��\n");
//			break;
//		case 5:
//			return 0;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}



