#ifndef sort_base_H
#define sort_base_H

//void swap(int &a, int &b);
//≤Â»Î≈≈–Ú
void Insert_direct_sort(int A[], int n);
void Bi_Insert_Sort(int A[], int n);
void Shell_sort(int A[], int n);
//Ωªªª≈≈–Ú
void Bubble_sort(int A[], int n);
void Quick_sort(int A[], int low,int high);
//—°‘Ò≈≈–Ú
void Select_sort(int A[], int n);
void AdjustHeap(int A[], int i, int length);
void Heap_sort(int A[], int n);
//πÈ≤¢≈≈–Ú
void Merge_sort(int A[], int low, int high);
void Merge(int A[], int low, int mid, int high);

#endif // !sort_base

