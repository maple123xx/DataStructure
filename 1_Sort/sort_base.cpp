#include"sort_base.h"
#include<iostream>
#include<algorithm>
using namespace std;

//直接插入排序，或者叫交换排序
void Insert_direct_sort(int A[], int n) {
	int i, j;
	int temp;
	for (i = 0; i < n-1; ++i) {
		for(j=i+1;j>0;--j){	
			temp = A[i];
			if (A[j] < A[j - 1]) {
				A[j - 1] = A[j];
				A[j] = temp;
			}
		}
	}
	/*for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j>0; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j - 1], A[j]);
			}
		}
	}*/
}
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b=temp;
//}