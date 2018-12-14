#include"Recursion.h"

void hanoi(int n, char x, char y, char z) {
	//汉诺塔问题，n块，将x移到z,用y做辅助
	if (n == 1)
		cout << x << "-----" << z << endl;
	else {
		hanoi(n - 1, x, z, y);	//将x上面的n-1块，x移动到y，用z做辅助
		cout << x << "-----" << z << endl;
		hanoi(n - 1, y, x, z);	//将y上面的n-1块移动到z，用x做辅助
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