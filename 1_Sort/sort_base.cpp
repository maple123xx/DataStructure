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

//希尔排序
//希尔排序就是直接插入排序的高级版，将数组按增量分组，然后分别做直接插入排序，逐渐缩小增量
void Shell_sort(int A[], int n) {
	int i, j, temp,increment=n;
	/*do {
		increment = increment / 3 + 1;
		for (i = increment; i < n; ++i) {
			temp = A[i];
			for (j = i; j >= increment && A[j - increment]>temp; j -= increment) {	//这里的判断条件和直接插入排序有点区别，是>=,不然一次循环也进不去
				A[j] = A[j - increment];
			}
			A[j] = temp;
		}
	} while (increment > 1);*/
	do {	//与直接插入排序一样，希尔排序也有两种排序方法
		increment = increment / 3 + 1;
		for (i = increment; i < n; ++i) {
			for (j = i; j >= increment; j -= increment) {	
				if (A[j] < A[j - increment]) {
					swap(A[j], A[j - increment]);
				}
			}
		}
	} while (increment > 1);
}

//快速排序
//对冒泡排序的一种改进
void Quick_sort(int A[], int left,int right) {
	int i = left, j = right;
	if (left>=right)//！！！非常重要，递归的终止条件
		return;
	int temp = A[left];	//基准
	while (i != j) {
		while (temp <= A[j] && i < j)//从右往左，找到第一个小于基准的数的位置j（必须要先从右往左,因为基准设为最左边，如果i先往右走，可能会挡住j
									//（有i<j这个条件束缚着），使得j没有到达应该到的位置（第一个小于temp的位置）。
									//所以需要j先从右往左走，来控制i）
			--j;					
		while (temp >= A[i] && i < j)//从左往右，找到第一个大于基准的数的位置i
			++i;
		swap(A[i], A[j]);
	}
	A[left] = A[i];
	A[i] = temp;//现在i的位置就是基准应该在的位置，左边的都比基准小，右边的都比基准大
	Quick_sort(A, left, i - 1);
	Quick_sort(A, i + 1, right);

}
