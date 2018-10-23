#ifndef Linklist_
#define Linklist_

typedef struct Node {
	int data;
	struct Node* next;
}NODE,*PNODE;	//NODE�ȼ���struct Node,*PNODE �ȼ���struct Node *

PNODE CreateList();//β�崴������
void DestroyList(PNODE pHead);//��������
PNODE ClearList(PNODE pHead);//�������
int FindList(PNODE pHead, int pos);//���ص�posλ�õĽڵ�
bool InsertList(PNODE pHead, int pos, int value);//�ڵ�posλ��ǰ�������Ԫ��
int DeleteList(PNODE pHead, int pos);//ɾ��posλ�õ�Ԫ��
int LengthList(PNODE pHead);//��������
void SortList(PNODE pHead);//�������еĽڵ㰴ֵ���������ü򵥵�ѡ������
void print(PNODE pHead);//˳���ӡ����

#endif // !Linklist
