#include"sort_base.h"
#include<iostream>
#include<algorithm>
#define N_array 100
using namespace std;
//void swap(int &a, int &b) {	//�����Լ�дswap
//	int temp = a;
//	a = b;
//	b=temp;
//}

//ֱ�Ӳ�������
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
	/*for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[i])
				swap(A[j], A[i]);
		}
	}*/
}
//�۰��������
void Bi_Insert_Sort(int A[], int n) {//���۰���ҵ�Ҫ�����λ�ã��ٲ���
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
//ϣ������
//ϣ���������ֱ�Ӳ�������ĸ߼��棬�����鰴�������飬Ȼ��ֱ���ֱ�Ӳ�����������С����
void Shell_sort(int A[], int n) {
	int i, j, increment = n;
	//int temp;
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
//�Ľ���ð������
void Bubble_sort2(int A[], int n) {
	for (int i = 0; i < n - 2; ++i) {
		bool flag = false;	//���������ı�־����һ������û�н�����˵���Ѿ��ź���
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
//˫��ð��
void Bubble_sort3(int A[], int n) {
	int i,j,low = 0, high = n - 1;
	bool flag = true;
	while (low < high&&flag) {
		flag = false;
		for (i = low; i < high; ++i) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				flag = true;	//�����ڽ���
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
//��������������Ҫ���󶥶ѣ�
//1. �ӵ����һ����Ҷ�ڵ㣨A[n/2-1]����ʼ�������ϵ��������󶥶�
//2. �����Ѷ�Ԫ�غ���ĩβԪ�أ�������
void Heap_sort(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {//�ӵ����һ����Ҷ�ڵ㣨A[n/2-1]����ʼ�������ϵ�������ɺ����������һ���󶥶���
		AdjustHeap(A, i, n);
	}
	for (int j = n - 1; j > 0; --j) {
		swap(A[j], A[0]);//�����Ѷ�Ԫ�غ���ĩβԪ��
		AdjustHeap(A, 0, j);//����A[0]Ϊ��ǰ��Ҫ�����Ľڵ�,��Ϊ���ô󶥶Ѻ󣬽����Ѷ�Ԫ�غ���ĩβԪ�أ�ֻ�ƻ�0λ�õĶ����ʣ����Դ����￪ʼ����
							//������j������j-1
	}

}
//������
void AdjustHeap(int A[], int i, int n) {//
	int k=2*i+1;//i��ʾ��ǰҪ�����Ľڵ㣬k�ǵ�ǰ�ڵ������
	int temp = A[i];//�ȱ�����ǰ��ֵ
	while (k < n) {
		if (k + 1 < n && A[k] < A[k + 1]) {//����<�Һ���
			k = k + 1;
		}
		if (A[k] > temp) {
			A[i] = A[k];//��Ҫ�¸���A[i]������ֵ�Ѿ�������temp����
			//swap(A[i], A[k]);//Ҳ������������A[i]��A[k]��ֵ�����Ͳ���ҪA[i] = temp;���������
			i = k;
			k = 2 * i + 1;
		}
		else
		{
			break;//��ǰ�ڵ�����Һ��Ӷ���ֱ������
		}
	}
	A[i] = temp;
}

//��·�鲢����
//���õݹ飬��ԭʼ���в��������ֿ飬ֱ��ÿ��ʣ��һ��Ԫ�أ����Ԫ�ؿ϶�������ġ�Ȼ�����õݹ��ԭ��ϲ�����
void Merge_sort(int A[], int low, int high) {
	if (low < high) {//��Ҫ���ݹ���ֹ����
		int mid = (low + high) / 2;
		Merge_sort(A, low, mid);
		Merge_sort(A, mid + 1, high);
		Merge(A,low, mid, high);
	}
}
//��ǰ�����ڵ����������ϲ�Ϊһ�������
void Merge(int A[],int low, int mid, int high) {
	int i, j, k;
	int B[N_array];	//��������
	for (i = low; i <= high; ++i) {//������<=Ŷ
		B[i] = A[i];//����A��B
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