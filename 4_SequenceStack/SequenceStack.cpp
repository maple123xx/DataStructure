#include<iostream>
using namespace std;

//������ʵ��˳��ջ
typedef struct stack {
	int data[100];	//����һ������Ϊ100��һά�����������������ó���
	int top;	//ջ��ָ��

}STACK, *Stack;

void InitStack(Stack s) {//��ʼ��һ��˳��ջ
	s->top = -1;
	cout << "ջ��ʼ���ɹ�" << endl;
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
void BracketsCheck(int *a) {//һ�����ű��ʽ�ɡ�(������)������[������]������{������}����ɣ��ж����ű��ʽ�Ƿ�
	STACK s;				//�Ϸ�����1��4��2��5��3��6�ֱ��ʾ��(������)������[������]������{������}������0��ʾ���������
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
				cout << "���ʽ���Ϸ�" << endl;
				return;
			}
			break;
		case 5:
			PopStack(&s, &x);
			if (x != 2) {
				cout << "���ʽ���Ϸ�" << endl;
				return;
			}
			break;
		case 6:
			PopStack(&s, &x);
			if (x != 3) {
				cout << "���ʽ���Ϸ�" << endl;
				return;
			}
			break;
		default:
			break;
		}
		++i;
	}
	if (!EmptyStack(&s)) {
		cout << "���ʽ���Ϸ�" << endl;
		return;
	}
	else
	{
		cout << "���ʽ�Ϸ�" << endl;
		return;
	}

}
void Train_Arrange(int *train) {//��Ӳ��������������ȣ�����Ӳ������ջ�����������ͽ�����һ������������ٳ�ջ����
	STACK s;					//��ʵ��������������������Ӳ������֮ǰ�ˣ���1����Ӳ�����ᣬ2������������
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
typedef struct {		//������ʵ�ֵ�ѭ������
	int data[MaxSize];
	int front, rear;
}SQQUEUE,*SqQueue;
void InitQueue(SqQueue q) {//��һ��д������&q�Ļ�������.�����
	q->front = q->rear = 0;
	cout << "���г�ʼ���ɹ�" << endl;
}
bool QueueEmpty(SqQueue q) {
	if (q->front == q->rear) {
		return true;
	}
	else
		return false;
}
void EnQueue(SqQueue q, int x) {
	if ((q->rear + 1) % MaxSize == q->front) {//����һ���洢��Ԫ���ж϶���
		cout << "����" << endl;
		return;
	}
	q->data[q->rear] = x;//q->rearָ�����һ��Ԫ�ص���һ���������ȸ�ֵ����++
	q->rear = (q->rear + 1) % MaxSize;
}
void DeQueue(SqQueue q, int *x) {
	if (QueueEmpty(q)) {
		return;
	}
	*x = q->data[q->front];//q->frontָ���һ��Ԫ�أ�����Ҳ���ȸ�ֵ����++
	q->front = (q->front + 1) % MaxSize;
}
void PrintQueue(SqQueue q) {
	int x;
	cout << "��ӡ����: " << endl;
	while (!QueueEmpty(q)) {
		DeQueue(q, &x);
		cout << x << '\t';
	}
	cout << endl;
}
void InverseQueue(Stack s, SqQueue q) {//��ջ�Ͷ��н����е�Ԫ�����ã��Ƚ�����Ԫ��ȫ����ջ��Ȼ��ȫ����ջ�����
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
double func(int n, int x) {//����ջʵ�ֵݹ麯���ķǵݹ�汾
	struct stack
	{
		int no;
		double value;
	}Stack[100];
	int top = -1, i;
	double fv1 = 1, fv2 = 2 * x;
	for (i = n; i >= 2; --i){
		++top;
		Stack[top].no = i;
	}
	while (top>=0){
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
	//int i, length, ss;//ssΪջ��
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
	//cout << "ջ��Ϊ" << ss << endl;
	//PopStack(&s,&i);
	//cout << "��" << i <<"��ջ"<< endl;
	//ss = TopStack(&s);
	//cout << "ջ��Ϊ" << ss << endl;
	//length = LengthStack(&s);
	//cout << "����Ϊ" << length << endl;
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
	cout << "�������Ⱥ�Ϊ��" << endl;
	for (int i = 0; i < n; ++i) {
		cout << train[i] << '\t';
	}
	cout << endl;*/

	//double x = func(6, 1);
	//cout << "���Ϊ��" << x << endl;


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



