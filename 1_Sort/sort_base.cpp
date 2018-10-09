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

//ϣ������
//ϣ���������ֱ�Ӳ�������ĸ߼��棬�����鰴�������飬Ȼ��ֱ���ֱ�Ӳ�����������С����
void Shell_sort(int A[], int n) {
	int i, j, temp,increment=n;
	/*do {
		increment = increment / 3 + 1;
		for (i = increment; i < n; ++i) {
			temp = A[i];
			for (j = i; j >= increment && A[j - increment]>temp; j -= increment) {	//������ж�������ֱ�Ӳ��������е�������>=,��Ȼһ��ѭ��Ҳ����ȥ
				A[j] = A[j - increment];
			}
			A[j] = temp;
		}
	} while (increment > 1);*/
	do {	//��ֱ�Ӳ�������һ����ϣ������Ҳ���������򷽷�
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

//��������
//��ð�������һ�ָĽ�
void Quick_sort(int A[], int left,int right) {
	int i = left, j = right;
	if (left>=right)//�������ǳ���Ҫ���ݹ����ֹ����
		return;
	int temp = A[left];	//��׼
	while (i != j) {
		while (temp <= A[j] && i < j)//���������ҵ���һ��С�ڻ�׼������λ��j������Ҫ�ȴ�������,��Ϊ��׼��Ϊ����ߣ����i�������ߣ����ܻᵲסj
									//����i<j������������ţ���ʹ��jû�е���Ӧ�õ���λ�ã���һ��С��temp��λ�ã���
									//������Ҫj�ȴ��������ߣ�������i��
			--j;					
		while (temp >= A[i] && i < j)//�������ң��ҵ���һ�����ڻ�׼������λ��i
			++i;
		swap(A[i], A[j]);
	}
	A[left] = A[i];
	A[i] = temp;//����i��λ�þ��ǻ�׼Ӧ���ڵ�λ�ã���ߵĶ��Ȼ�׼С���ұߵĶ��Ȼ�׼��
	Quick_sort(A, left, i - 1);
	Quick_sort(A, i + 1, right);

}
