#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"Linklist.h"

int main() {
	int pos, value;
	PNODE p = CreateList();
	print(p);
	DestroyList(p);
	ClearList(p);
	/*printf("The length of the list is: %d\n", LengthList(p));
	printf("Please input pos that you want to find:");
	scanf_s("%d", &pos);
	printf("The value in pos is %d\n", FindList(p, pos));
	printf("Please input pos and value what you want to insert:");
	scanf_s("%d %d", &pos, &value);
	InsertList(p, pos, value);
	print(p);
	printf("Please input pos what you want delete:");
	scanf_s("%d", &pos);
	DeleteList(p, pos);
	print(p);
	SortList(p);
	printf("The sorted list is: \n");*/
	//print(p);


	system("pause");
	return 0;
}