#include<iostream>
#include"time.h"
#include"sort_base.h"
#define N_array 100
using namespace std;

void fun(int A[], int n) {//把所有奇数挪到偶数前面
	int low = 0, high = n - 1;
	while (low < high) {
		while (low < high&&A[low] % 2 == 1)
			++low;
		while (low < high&&A[high] % 2 == 0)
			--high;
		if(low<high)
			swap(A[low], A[high]);
		++low;
		--high;
	}
}
int main() {

	clock_t start;
	clock_t finish;
	start = clock();

	int i, n = 12;
	int A[N_array] = { 45,21,35,23,4,56,15,32,11,6,100,1};
	//Select_sort(A, n);
	//Insert_direct_sort(A, n);
	//Shell_sort(A, n);
	//Bubble_sort3(A, n);
	//Quick_sort(A, 0, n - 1);
	//Merge_sort(A, 0, n - 1);
	//Bi_Insert_Sort(A, 12);
	fun(A, n);
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	finish = clock();
	printf("\n程序共用时间为：%f秒\n", (float)(finish - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}