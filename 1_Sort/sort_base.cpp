#include"sort_base.h"
#include<iostream>
#include<algorithm>
using namespace std;
//void swap(int &a, int &b) {	//不用自己写swap
//	int temp = a;
//	a = b;
//	b=temp;
//}

//直接插入排序，或者叫交换排序
void Insert_direct_sort(int A[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; ++i) {//从A[1]作为要插入的第一个元素开始
		temp = A[i];//保存要插入的元素，每次都和它比，比如它是最小的元素，一定要比较到它插到A[0]位置
		for (j = i; j > 0 && A[j - 1] > temp; --j) {	//内循环跳出的条件是A[j - 1] > temp不满足时
			A[j] = A[j - 1];//不要怕覆盖A[i],已经用temp保存A[i]的值了
			
		}
		//for (j = i; j > 0; --j) {	
		//	if (A[j - 1] > temp) {	//内循环跳出的条件是A[j - 1] > temp不满足时,如果在这里判断的话，每次temp都会插到A[0]位置，程序错误
		//		A[j] = A[j - 1];
		//	}
		//}
		A[j] = temp;
	}
	/*for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j>0; --j) {//从第一个元素开始，每次从后面找一个插入已排好序的子数组中
			if (A[j] < A[j - 1]) {
				swap(A[j - 1], A[j]);
			}
		}
	}*/
}

//简单选择排序
void Select_sort(int A[], int n) {
	int i, j, k;
	for (i = 0; i < n - 1; ++i) {
		k = i;//k用来记录最小值的位置
		for (j = i + 1; j < n; ++j) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		swap(A[k], A[i]);//把最小值放在i的位置
	}
}

//冒泡排序
void Bubble_sort(int A[], int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i) {//一轮有一个最小的元素冒到最上面
		for (j = n - 1; j > i; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
			}
		}
	}
}
