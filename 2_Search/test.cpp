#include"Search.h"

int main() {
	ValueType A[] = { 1,3,5,7,8,9 };
	int n = sizeof(A) / sizeof(A[0]);
	//int i = Sequence_Search(A, n, 10);
	//int i = Bin_Search2(A, 8, 0, n-1);//若A[0]不算元素的话，则low设为1，其他不变
	int i = Fibonacci_search(A, n, 5);
	cout << "查找到的序号为"<<i << endl;

	return 0;
}