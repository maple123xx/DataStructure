#include"Search.h"

int main() {
	ValueType A[] = { 1,3,5,7,8,9 };
	int n = sizeof(A) / sizeof(A[0]);
	//int i = Sequence_Search(A, n, 10);
	//int i = Bin_Search2(A, 8, 0, n-1);//��A[0]����Ԫ�صĻ�����low��Ϊ1����������
	/*int i = Fibonacci_search(A, n, 5);
	cout << "���ҵ������Ϊ"<<i << endl;*/
	HashTable H;
	const string str = "data\\search_12.txt";
	Init_Hash(&H, 16);
	Insert_Hash(&H, str);
	int addr;
	bool result=Search_Hash(H, 38, addr);
	if (result)
		cout << "ɢ�е�ַΪ��" << addr << endl;
	else
		cout << "�����ڴ˹ؼ���" << endl;
	return 0;
}