#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct link *AppendNode(struct link *head);
struct link *DeleteNode(struct link *head);
void DisplyNode(struct link*head);
struct link
{
	int data;
	struct link *next;
};

int main()
{
	char c, a;
	int i = 0;
	struct link *head = NULL;
	printf("Do you want to append a new node(Y/N)?\n");
	scanf_s(" %c", &c);
	while (c == 'Y' || c == 'y')
	{
		head = AppendNode(head);
		printf("Do you want to append a new node(Y/N)?\n");
		scanf_s(" %c", &c);
		i++;
	}
	DisplyNode(head);
	printf("%d new nodes have been apended!\n", i);
	printf("Do you want to delete a node(Y/N)?\n");
	scanf_s(" %c", &a);
	while (a == 'Y' || a == 'y')
	{
		i--;
		head = DeleteNode(head);
		if (head == NULL) {
			printf("Linked Table is empty,there is no node to delete!\n");
			break;
		}
		printf("Do you want to delete a node(Y/N)?\n");
		scanf_s(" %c", &a);
	}
	printf("we have %d nodes.\n", i);

	system("pause");
	return 0;
}
struct link *AppendNode(struct link *head)
{
	struct link *p = NULL, *pr = head;
	int data;
	p = (struct link*)malloc(sizeof(struct link));
	if (p == NULL)
	{
		printf("No enough memory to allocate!\n");
		exit(0);
	}
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	printf("Please node data:");
	scanf_s("%d", &data);
	p->data = data;
	p->next = NULL;
	return head;

}
struct link *DeleteNode(struct link *head)
{
	struct link *p = head, *pr=head;
	if (head->next == NULL)//head指向第一个节点，head->next == NULL就只有一个节点了
	{
		printf("the data which was deleted is %d\n", head->data);
		head = NULL;
		return(head);
	}
	while (p->next != NULL)
	{
		pr = p;
		p = p->next;
	}
	pr->next = p->next;
	printf("the data which was deleted is %d\n", p->data);
	free(p);
	return head;
}
void DisplyNode(struct link *head)
{
	struct link *p = head;
	int j = 1;
	while (p != NULL)
	{
		printf("%5d%10d\n", j, p->data);
		p = p->next;
		j++;
	}
}