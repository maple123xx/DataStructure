#include"sort_base.h"
#include<iostream>
#include<algorithm>
using namespace std;
//void swap(int &a, int &b) {	//�����Լ�дswap
//	int temp = a;
//	a = b;
//	b=temp;
//}

//ֱ�Ӳ������򣬻��߽н�������
void Insert_direct_sort(int A[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; ++i) {//��A[1]��ΪҪ����ĵ�һ��Ԫ�ؿ�ʼ
		temp = A[i];//����Ҫ�����Ԫ�أ�ÿ�ζ������ȣ�����������С��Ԫ�أ�һ��Ҫ�Ƚϵ����嵽A[0]λ��
		for (j = i; j > 0 && A[j - 1] > temp; --j) {	//��ѭ��������������A[j - 1] > temp������ʱ
			A[j] = A[j - 1];//��Ҫ�¸���A[i],�Ѿ���temp����A[i]��ֵ��
			
		}
		//for (j = i; j > 0; --j) {	
		//	if (A[j - 1] > temp) {	//��ѭ��������������A[j - 1] > temp������ʱ,����������жϵĻ���ÿ��temp����嵽A[0]λ�ã��������
		//		A[j] = A[j - 1];
		//	}
		//}
		A[j] = temp;
	}
	/*for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j>0; --j) {//�ӵ�һ��Ԫ�ؿ�ʼ��ÿ�δӺ�����һ���������ź������������
			if (A[j] < A[j - 1]) {
				swap(A[j - 1], A[j]);
			}
		}
	}*/
}

//��ѡ������
void Select_sort(int A[], int n) {
	int i, j, k;
	for (i = 0; i < n - 1; ++i) {
		k = i;//k������¼��Сֵ��λ��
		for (j = i + 1; j < n; ++j) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		swap(A[k], A[i]);//����Сֵ����i��λ��
	}
}

//ð������
void Bubble_sort(int A[], int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i) {//һ����һ����С��Ԫ��ð��������
		for (j = n - 1; j > i; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
			}
		}
	}
}
