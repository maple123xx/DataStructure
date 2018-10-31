#include<iostream>
using namespace std;

typedef struct NODE {
	int data;
	struct NODE *next;
}Node;
typedef struct stack {
	Node *top;	//栈顶指针
}LinkStack;

LinkStack* CreateStack() {
	LinkStack* s = (Node *)malloc(sizeof(Node));
	if (s == NULL) {
		cout << "节点分配失败" << endl;
		return NULL;
	}
	s->top = NULL;//把s->top看成一个节点，它也有data和next成员
	return s;
}
bool EmptyStack(LinkStack *s) {
	return (s->top == NULL);
}
void PushStack(LinkStack *s,int x) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		cout << "节点分配失败" << endl;
	}
	p->data = x;
	p->next = s->top;	//链表的下一个结点指向之前的top 第一次为NULL
	s->top = p;			//把top指针指向新的结点p
}
void PopStack(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "栈空" << endl;
	}
	Node* p = s->top;
	cout << "出栈的元素为："<<p->data << endl;
	s->top = p->next;
	free(p);
	p = NULL;
}
void PrintStack(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "栈空" << endl;
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
		cout << "栈空" << endl;
		return 0;
	}
	return s->top->data;
}
void SetEmpty(LinkStack *s) {
	if (EmptyStack(s)) {
		cout << "栈空" << endl;
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
	cout << "栈顶元素是：" << GetTop(s) << endl;
	SetEmpty(s);
	PrintStack(s);
	Destroy(s);

	system("pause");
	return 0;
}
