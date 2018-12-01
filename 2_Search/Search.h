#ifndef Search_
#define Search_

#include"myNamespace.h"
typedef int ValueType;
#define N_Node 100	//顺序表的最大元素个数

int Sequence_Search(ValueType A[], int n,ValueType key);
int Bin_Search1(ValueType A[], ValueType obj, int low, int high);
int Bin_Search2(ValueType A[], ValueType obj, int low, int high);

int Fibonacci(int A[], int n);
int Fibonacci_search(ValueType A[], int n, ValueType key);

#endif // !Search_

