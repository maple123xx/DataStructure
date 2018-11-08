#ifndef Linklist_
#define Linklist_

typedef struct Node {
	int data;
	struct Node* next;
}NODE,*PNODE;	//NODE�ȼ���struct Node,*PNODE �ȼ���struct Node *

typedef struct DNode {//˫����Ķ���
	int data;
	struct DNode *prior, *next;
}DNODE,*DPNODE;

void InitList(PNODE pHead);//��ͷ�ڵ㵥����ĳ�ʼ��
PNODE CreateList(PNODE pHead);//β�崴������
void DestroyList(PNODE pHead);//��������
PNODE ClearList(PNODE pHead);//�������
int FindList(PNODE pHead, int pos);//���ص�posλ�õĽڵ�
bool InsertList(PNODE pHead, int pos, int value);//�ڵ�posλ��ǰ�������Ԫ��
int DeleteList(PNODE pHead, int pos);//ɾ��posλ�õ�Ԫ��
int LengthList(PNODE pHead);//��������
void SortList(PNODE pHead);//�������еĽڵ㰴ֵ���������ü򵥵�ѡ������
void PrintList(PNODE pHead);//˳���ӡ����
void InsertFrontList(PNODE pos, int x);// ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�

#endif // !Linklist
