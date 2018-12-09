#include<iostream>
#include"time.h"
#include"sort_base.h"
#define N_array 100
using namespace std;

void MoveEven_Odd(int A[], int n) {//把所有奇数挪到偶数前面
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
int K_Element(int A[], int low, int high, int k) {
	//找到排序后的第k小的数，可以用一个O(nlogn)的排序算法排序，然后直接找到第k个元素
	//本题用快速排序的方法
	int pivot = A[low];
	int i = low, j = high;	//因为会改变low,high，所以先保存起来，便于递归
	while (low < high) {
		while (A[high] >= pivot&&low < high) --high;
		A[low] = A[high];		//把那个小于pivot的值放到左边来
		while (A[low] <= pivot&&low < high) ++low;
		A[high] = A[low];		//把那个大于pivot的值放到右边
	}
	A[low] = pivot;	//pivot所在的最终位置
	if (low == k)
		return A[low];
	else if (low > k)
		return K_Element(A, i, low - 1, k);
	else
		return K_Element(A, low + 1, j, k);//右半部分，是k-low,相对位置
}
int setPartition(int A[], int n) {
	//尽可能的将数组分成两部分，两部分的元素值和的差尽可能大
	//使用快排的方法将数组分为两半，若pivot不是中间的位置，则继续
	//无需对全部元素排序，平均时间为O(n)，空间为O(1)
	int i, k = n / 2, low = 0, high = n - 1;
	int low_temp = 0, high_temp = n - 1, flag = 1;//low_temp和high_temp是暂存上一轮的low和high的
	int s1 = 0, s2 = 0;
	while (flag) {
		int pivot = A[low];
		while (low < high) {
			while (A[high] >= pivot&&low < high) --high;
			A[low] = A[high];
			while (A[low] <= pivot&&low < high) ++low;
			A[high] = A[low];
		}
		A[low] = pivot;
		if (low == k - 1)
			flag = 0;
		else if (low < k - 1) {
			low_temp = ++low;
			high = high_temp;
		}
		else {
			high_temp = --high;
			low = low_temp;
		}
	}
	for (i = 0; i < k; ++i) {
		s1 += A[i];
	}
	for (i = k; i < n; ++i) {
		s2 += A[i];
	}
	return s2 - s1;
}
typedef enum{RED,WHITE,BLUE} color;//设置枚举数组
void Flag_Arrange(color A[], int n) {
	//将数组排列成红白蓝
	int i = 0, j = 0, k = n - 1;
	while (j <= k) {
		switch (A[j])
		{
		case RED:
			swap(A[i], A[j]);
			i++;
			j++;
			break;
		case WHITE:
			j++;
			break;
		case BLUE:
			swap(A[j], A[k]);//这里没有j--，以防交换后A[j]仍为蓝色
			k--;
		default:
			break;
		}
	}
}
void BarrelSort(int A[], int n) {
	//桶排序,针对元素值范围不大的情况
	int count[101] = { 0 };
	for (int i = 0; i < n; ++i) {
		++count[A[i]];
	}
	for (int i = 0; i < 101; ++i) {
		while (count[i]) {
			cout << i << '\t';
			--count[i];
		}
	}
}
int main() {
	clock_t start;
	clock_t finish;
	start = clock();
	int i, n = 9;
	int A[] = { 53, 3, 542, 748, 14, 214, 154, 63, 616 };
	RadixSort(A, n);
	/*int A[N_array] = { 45,21,35,23,4,56,15,32,11,6,100,79,1};
	int B[N_array];
	List C[N_array];
	for (i = 0; i < n; ++i) {
		C[i].data = A[i];
	}
	CountSort2(C, B, n);*/
	//CountSort(A, B, n);
	/*int A[N_array] = { 1,2,3,4,5,6,7};
	if (Judge_Heap(A, 6))
		cout << "是小根堆" << endl;*/
	//Heap_sort(A, 11);	//堆排序从第一个元素开始
	/*Insert_Heap(A, 70, n);
	for (int j = n+1; j > 1; --j) {
		swap(A[j], A[1]);
		AdjustHeap(A, 1, j - 1);
	}
	for (i = 1; i <= n + 1; i++) {
		cout << A[i] << "\t";
	}*/
	//Select_sort(A, n);
	//Insert_direct_sort(A, n);
	//Shell_sort(A, n);
	//Bubble_sort3(A, n);
	//Quick_sort2(A, 0, n - 1);
	//Merge_sort(A, 0, n - 1);
	//Bi_Insert_Sort(A, 12);
	//MoveEven_Odd(A, n);
	//cout << setPartition(A, 12) << endl;
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	/*color B[10] = { RED,WHITE,BLUE,RED,WHITE,RED,BLUE };
	Flag_Arrange(B, 7);
	for (int i = 0; i < 7; ++i) {
		cout << B[i] << '\t';
	}*/
	//cout << endl << K_Element(A, 0, 11, 5) << endl;
	finish = clock();
	printf("\n程序共用时间为：%f秒\n", (float)(finish - start) / CLOCKS_PER_SEC);

	return 0;
}