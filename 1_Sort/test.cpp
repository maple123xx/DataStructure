#include<iostream>
#include"time.h"
#include"sort_base.h"
#define N_array 100
using namespace std;

void MoveEven_Odd(int A[], int n) {//����������Ų��ż��ǰ��
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
//д�ɺ���ָ����ʽ�����ڴ�������
void Reorder(int A[], int n, bool (*func)(int)) {
	int low = 0, high = n - 1;
	while (low < high) {
		while (low < high&&!func(A[low]))	//!func(A[low])��ʾfunc(A[low])��0�Ļ����ͽ���
			++low;
		while (low < high&&func(A[high]))
			--high;
		if (low<high)
			swap(A[low], A[high]);
		++low;
		--high;
	}
}
bool isEven(int n) {	//��ż��������0��������������1
	return (n & 1)==0;
}
bool isMinus(int n) {	//�Ǹ���������0
	return (n>0);
}
void MoveEven_Odd2(int A[], int n) {
	Reorder(A, n, isMinus);
}
int K_Element(int A[], int low, int high, int k) {
	//�ҵ������ĵ�kС������������һ��O(nlogn)�������㷨����Ȼ��ֱ���ҵ���k��Ԫ��
	//�����ÿ�������ķ���
	int pivot = A[low];
	int i = low, j = high;	//��Ϊ��ı�low,high�������ȱ������������ڵݹ�
	while (low < high) {
		while (A[high] >= pivot&&low < high) --high;
		A[low] = A[high];		//���Ǹ�С��pivot��ֵ�ŵ������
		while (A[low] <= pivot&&low < high) ++low;
		A[high] = A[low];		//���Ǹ�����pivot��ֵ�ŵ��ұ�
	}
	A[low] = pivot;	//pivot���ڵ�����λ��
	if (low == k)
		return A[low];
	else if (low > k)
		return K_Element(A, i, low - 1, k);
	else
		return K_Element(A, low + 1, j, k);
}
int setPartition(int A[], int n) {
	//�����ܵĽ�����ֳ������֣������ֵ�Ԫ��ֵ�͵Ĳ���ܴ�
	//ʹ�ÿ��ŵķ����������Ϊ���룬��pivot�����м��λ�ã������
	//�����ȫ��Ԫ������ƽ��ʱ��ΪO(n)���ռ�ΪO(1)
	int i, k = n / 2, low = 0, high = n - 1;
	int low_temp = 0, high_temp = n - 1, flag = 1;//low_temp��high_temp���ݴ���һ�ֵ�low��high��
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
typedef enum{RED,WHITE,BLUE} color;//����ö������
void Flag_Arrange(color A[], int n) {
	//���������гɺ����
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
			swap(A[j], A[k]);//����û��j--���Է�������A[j]��Ϊ��ɫ
			k--;
		default:
			break;
		}
	}
}
void BarrelSort(int A[], int n) {
	//Ͱ����,���Ԫ��ֵ��Χ��������
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
	int A[] = { 72, 3, 542, 748, -6, 214, -5, 63, 1000 };
	//RadixSort(A, n);
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
		cout << "��С����" << endl;*/
	Heap_sort(A, 8);	//������ӵ�һ��Ԫ�ؿ�ʼ
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
	//Bubble_sort2(A, n);
	//Quick_sort2(A, 0, n - 1);
	//Merge_sort(A, 0, n - 1);
	//Bi_Insert_Sort(A, 12);
	//MoveEven_Odd2(A, n);
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
	printf("\n������ʱ��Ϊ��%f��\n", (float)(finish - start) / CLOCKS_PER_SEC);

	return 0;
}