#include<iostream>
#include"time.h"
#include"sort_base.h"
#include"time.h"
using namespace std;
int main() {

	clock_t start;
	clock_t finish;
	start = clock();

	int i, n = 6;
	int A[N_array] = { 2,4,1,3,6,5};
	Select_sort(A, n);
	//Insert_direct_sort(A, n);
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	finish = clock();
	printf("\n程序共用时间为：%f秒\n", (float)(finish - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}