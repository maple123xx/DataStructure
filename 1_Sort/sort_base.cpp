#include"sort_base.h"
#include<iostream>
#include<algorithm>
#define N_array 100
using namespace std;
//void swap(int &a, int &b) {	//不用自己写swap
//	int temp = a;
//	a = b;
//	b=temp;
//}

//直接插入排序
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
	/*for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[i])
				swap(A[j], A[i]);
		}
	}*/
}
//折半插入排序
void Bi_Insert_Sort(int A[], int n) {//先折半的找到要插入的位置，再插入
	for (int i = 1; i < n; ++i) {
		int temp = A[i];
		int low = 0, high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (A[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; --j) {
			A[j + 1] = A[j];
		}
		A[high + 1] = temp;
	}
}
//希尔排序
//希尔排序就是直接插入排序的高级版，将数组按增量分组，然后分别做直接插入排序，逐渐缩小增量
void Shell_sort(int A[], int n) {
	int i, j, increment = n;
	//int temp;
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
//改进的冒泡排序
void Bubble_sort2(int A[], int n) {
	for (int i = 0; i < n - 2; ++i) {
		bool flag = false;	//发生交换的标志，若一趟下来没有交换，说明已经排好了
		for (int j = n - 1; j > i; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = true;
			}
		}
		if (!flag)
			return;
	}
}
//双向冒泡
void Bubble_sort3(int A[], int n) {
	int i,j,low = 0, high = n - 1;
	bool flag = true;
	while (low < high&&flag) {
		flag = false;
		for (i = low; i < high; ++i) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				flag = true;	//还存在交换
			}
		}
		--high;
		for (j = high; j > low; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = true;
			}
		}
		++low;
	}
}
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
//堆排序（升序排序要建大顶堆）
//1. 从第最后一个非叶节点（A[n/2-1]）开始，逐渐往上到根建立大顶堆
//2. 交换堆顶元素和最末尾元素，调整堆
void Heap_sort(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {//从第最后一个非叶节点（A[n/2-1]）开始，逐渐往上到根，完成后这棵树就是一个大顶堆了
		AdjustHeap(A, i, n);
	}
	for (int j = n - 1; j > 0; --j) {
		swap(A[j], A[0]);//交换堆顶元素和最末尾元素
		AdjustHeap(A, 0, j);//这里A[0]为当前需要调整的节点,因为建好大顶堆后，交换堆顶元素和最末尾元素，只破坏0位置的堆性质，所以从这里开始调整
							//这里是j，不是j-1
	}

}
//调整堆
void AdjustHeap(int A[], int i, int n) {//
	int k=2*i+1;//i表示当前要调整的节点，k是当前节点的左孩子
	int temp = A[i];//先保存起当前的值
	while (k < n) {
		if (k + 1 < n && A[k] < A[k + 1]) {//左孩子<右孩子
			k = k + 1;
		}
		if (A[k] > temp) {
			A[i] = A[k];//不要怕覆盖A[i]，它的值已经保存在temp里了
			//swap(A[i], A[k]);//也可以立即交换A[i]和A[k]的值，最后就不需要A[i] = temp;这条语句了
			i = k;
			k = 2 * i + 1;
		}
		else
		{
			break;//当前节点比左右孩子都大，直接跳出
		}
	}
	A[i] = temp;
}

//二路归并排序
//利用递归，将原始序列不断两两分块，直到每块剩下一个元素，这个元素肯定是有序的。然后利用递归的原理合并即可
void Merge_sort(int A[], int low, int high) {
	if (low < high) {//重要，递归终止条件
		int mid = (low + high) / 2;
		Merge_sort(A, low, mid);
		Merge_sort(A, mid + 1, high);
		Merge(A,low, mid, high);
	}
}
//将前后相邻的两个有序表合并为一个有序表
void Merge(int A[],int low, int mid, int high) {
	int i, j, k;
	int B[N_array];	//辅助数组
	for (i = low; i <= high; ++i) {//这里是<=哦
		B[i] = A[i];//复制A给B
	}
	k = low;
	for (i = low, j = mid + 1; i <= mid&&j <= high;) {
		if (B[i] < B[j]) {
			A[k++] = B[i++];
		}
		else
		{
			A[k++] = B[j++];
		}
	}
	while (i<=mid)
	{
		A[k++] = B[i++];
	}
	while (j<=high)
	{
		A[k++] = B[j++];
	}
}