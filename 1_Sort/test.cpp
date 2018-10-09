#include<iostream>
#include"time.h"
#include"sort_base.h"
#include"time.h"
#define N_array 100
using namespace std;
int main() {

	clock_t start;
	clock_t finish;
	start = clock();

	int i, n = 5;
	int A[N_array] = { 5,4,3,2,1};
	//Select_sort(A, n);
	//Insert_direct_sort(A, n);
	//Shell_sort(A, n);
	//Bubble_sort(A, n);
	Quick_sort(A, 0, n - 1);
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	finish = clock();
	printf("\n程序共用时间为：%f秒\n", (float)(finish - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}