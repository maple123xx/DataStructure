#include<iostream>
#include"time.h"
#include"sort_base.h"
#define N_array 100
using namespace std;
int main() {

	clock_t start;
	clock_t finish;
	start = clock();

	int i, n = 11;
	int A[N_array] = { 45,21,35,23,4,56,15,32,11,-1,100};
	//Select_sort(A, n);
	//Insert_direct_sort(A, n);
	//Shell_sort(A, n);
	//Bubble_sort(A, n);
	//Quick_sort(A, 0, n - 1);
	Heap_sort(A, n);
	//Merge_sort(A, 0, n - 1);
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	finish = clock();
	printf("\n程序共用时间为：%f秒\n", (float)(finish - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}