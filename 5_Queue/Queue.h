#ifndef Queue_
#define Queue_
#define MaxSize 100
typedef struct {		//������ʵ�ֵ�ѭ������
	int data[MaxSize];
	int front, rear;
}SqQueue;

typedef struct node {//��ʽ����
	int data;
	struct node *next;

}LinkNode;
typedef struct linknode {
	LinkNode *front, *rear;
}LinkQueue;

void InitQueue(SqQueue &q);//˳����еĲ���
bool isEmpty(SqQueue *q);
void EnQueue(SqQueue *q, int x);
void DeQueue(SqQueue *q, int *x);
void PrintQueue(SqQueue *q);
int LengthQueue(SqQueue *q);

void InitQueue2(LinkQueue &q);//��ʽ���еĲ���
bool IsEmpty2(LinkQueue &q);
void EnQueue2(LinkQueue &q, int x);
void DeQueue2(LinkQueue &q, int *x);
void PrintQueue2(LinkQueue &q);
int LengthQueue2(LinkQueue &q);
#endif // !Queue_
