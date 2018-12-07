#include"Search.h"

int main() {
	ValueType A[] = { 1,3,5,7,8,9,13,14 };
	int n = sizeof(A) / sizeof(A[0]);
	//int i = Sequence_Search(A, n, 10);
	//int i = Bin_Search2(A, 8, 0, n-1);//若A[0]不算元素的话，则low设为1，其他不变
	/*int i = Fibonacci_search(A, n, 5);
	cout << "查找到的序号为"<<i << endl;*/
	/*HashTable H;
	const string str = "data\\search_12.txt";
	Init_Hash(&H, 16);
	Insert_Hash(&H, str);
	int addr;
	bool result=Search_Hash(H, 38, addr);
	if (result)
		cout << "散列地址为：" << addr << endl;
	else
		cout << "不存在此关键字" << endl;*/
	//int result=Bin_Search3(A, 5, 0, n - 1);
	//cout << result << endl;
	cout << Fibonacci_search(A, n, 13) << endl;
	return 0;
}