#include<iostream>
using namespace std;

typedef struct NODE {
	int data;
	struct NODE *next;
}Node;
typedef struct stack {
	Node *top;	//ջ��ָ�룬ֻ��һ��ָ��
}LinkStack;

LinkStack* CreateStack() {
	LinkStack* s = (LinkStack *)malloc(sizeof(LinkStack));
	if (s == NULL) {
		cout << "�ڵ����ʧ��" << endl;
		return NULL;
	}
	s->top = NULL;//��s->top����һ���ڵ㣬��Ҳ��data��next��Ա
	return s;
}
bool EmptyStack(LinkStack *s) {
	return (s->top == NULL);
}
void PushStack(LinkStack *s,int x) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		cout << "�ڵ����ʧ��" << endl;
	}
	p->data = x;
	p->next = s->top;	//�������һ�����ָ��֮ǰ��top ��һ��ΪNULL
	s->top = p;			//��topָ��ָ���µĽ��p
}
void PopStack(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "ջ��" << endl;
	}
	Node* p = s->top;
	cout << "��ջ��Ԫ��Ϊ��"<<p->data << endl;
	s->top = p->next;
	free(p);
	p = NULL;
}
void PrintStack(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "ջ��" << endl;
		return;
	}
	Node* p = s->top;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;

}
int GetTop(LinkStack* s) {
	if (EmptyStack(s)) {
		cout << "ջ��" << endl;
		return 0;
	}
	return s->top->data;
}
void SetEmpty(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "ջ��" << endl;
		return;
	}
	Node* p = s->top;
	Node* temp = NULL;
	while (p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
	s->top = NULL;
}
void Destroy(LinkStack* s) {
	SetEmpty(s);
	free(s);
	s = NULL;
}
int main() {
	LinkStack *s = CreateStack();
	PushStack(s, 1);
	PushStack(s, 2);
	PushStack(s, 3);
	PushStack(s, 4);
	PushStack(s, 5);
	PrintStack(s);
	PopStack(s);
	PrintStack(s);
	cout << "ջ��Ԫ���ǣ�" << GetTop(s) << endl;
	SetEmpty(s);
	PrintStack(s);
	Destroy(s);

	system("pause");
	return 0;
}
