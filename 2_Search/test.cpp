#include"Search.h"

int main() {
	//ValueType A[] = { 1,3,5,7,8,9,13,14 };
	//int n = sizeof(A) / sizeof(A[0]);
	//int i = Sequence_Search(A, n, 10);
	//int i = Bin_Search2(A, 8, 0, n-1);//��A[0]����Ԫ�صĻ�����low��Ϊ1����������
	/*int i = Fibonacci_search(A, n, 5);
	cout << "���ҵ������Ϊ"<<i << endl;*/
	/*HashTable H;
	const string str = "data\\search_12.txt";
	Init_Hash(&H, 16);
	Insert_Hash(&H, str);
	int addr;
	bool result=Search_Hash(H, 38, addr);
	if (result)
		cout << "ɢ�е�ַΪ��" << addr << endl;
	else
		cout << "�����ڴ˹ؼ���" << endl;*/
	//int result=Bin_Search3(A, 5, 0, n - 1);
	//cout << result << endl;
	//cout << Fibonacci_search(A, n, 13) << endl;
	const string str1 = "data\\search_12_2.txt";
	HashTableLinked *H=(HashTableLinked *)malloc(sizeof(HashTableLinked));
	Init_HashLinked(H, 13);
	Insert_HashLinked(H, str1);
	Print_HashLinked(H);
	int addr;
	if (Search_HashLinked(H, 7, addr))
		cout << "�ҵ��ˣ�����ɢ�е�ַΪ��" << addr << endl;
	else
		cout << "������" << endl;
	return 0;
}