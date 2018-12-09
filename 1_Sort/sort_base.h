#ifndef sort_base_H
#define sort_base_H
#include<iostream>
#include<algorithm>
#define N_array 100
using namespace std;
//void swap(int &a, int &b);
//≤Â»Î≈≈–Ú

typedef struct List {
	int data;
	int count;
}List;

void Insert_direct_sort(int A[], int n);
void Bi_Insert_Sort(int A[], int n);
void Shell_sort(int A[], int n);
//Ωªªª≈≈–Ú
void Bubble_sort(int A[], int n);
void Bubble_sort2(int A[], int n);
void Bubble_sort3(int A[], int n);
void Quick_sort(int A[], int low,int high);
int Partition(int A[], int low, int high);
void Quick_sort2(int A[], int low, int high);
//—°‘Ò≈≈–Ú
void Select_sort(int A[], int n);
void AdjustHeap(int A[], int i, int length);
void Insert_Heap(int A[], int key, int n);
void Heap_sort(int A[], int n);
bool Judge_Heap(int A[], int n);
//πÈ≤¢≈≈–Ú
void Merge_sort(int A[], int low, int high);
void Merge(int A[], int low, int mid, int high);
//º∆ ˝≈≈–Ú
void CountSort(int A[], int B[], int n);
void CountSort2(List A[], int B[], int n);
//ª˘ ˝≈≈–Ú
void RadixSort(int A[], int n);
void RadixSortCore(int A[], int n, int bit);
int getMax(int A[], int n);

#endif // !sort_base

