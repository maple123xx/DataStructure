#ifndef Queue_
#define Queue_
#define MaxSize 100
typedef struct {		//用数组实现的循环队列
	int data[MaxSize];
	int front, rear;
}SqQueue;

typedef struct node {//链式队列
	int data;
	struct node *next;

}LinkNode;
typedef struct linknode {
	LinkNode *front, *rear;
}LinkQueue;

void InitQueue(SqQueue &q);//顺序队列的操作
bool isEmpty(SqQueue *q);
void EnQueue(SqQueue *q, int x);
void DeQueue(SqQueue *q, int *x);
void PrintQueue(SqQueue *q);
int LengthQueue(SqQueue *q);

void InitQueue2(LinkQueue &q);//链式队列的操作
bool IsEmpty2(LinkQueue &q);
void EnQueue2(LinkQueue &q, int x);
void DeQueue2(LinkQueue &q, int *x);
void PrintQueue2(LinkQueue &q);
int LengthQueue2(LinkQueue &q);
#endif // !Queue_
