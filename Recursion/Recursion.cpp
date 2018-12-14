#include"Recursion.h"

void hanoi(int n, char x, char y, char z) {
	//��ŵ�����⣬n�飬��x�Ƶ�z,��y������
	if (n == 1)
		cout << x << "-----" << z << endl;
	else {
		hanoi(n - 1, x, z, y);	//��x�����n-1�飬x�ƶ���y����z������
		cout << x << "-----" << z << endl;
		hanoi(n - 1, y, x, z);	//��y�����n-1���ƶ���z����x������
	}
}
//char *digit = "1234567";
//void Print_Digit(int n, int m) {
//	if (n < m)
//		cout << n << '\t';
//	else {
//
//	}
//}
char DIGIT[17] = "0123456789abcdef";
void print_m(int n, int m)
{
	if (n<m)
	{
		cout << DIGIT[n];
	}
	else
	{
		print_m(n / m, m);
		cout << DIGIT[n%m];
	}
}