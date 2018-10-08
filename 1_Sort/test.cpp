#include<iostream>
#include"time.h"
#include"sort_base.h"
using namespace std;
int main() {
	int i, n = 8;
	int A[N_array] = { 1,4,2,5,6,3 ,100,20};
	Insert_direct_sort(A, n);
	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}