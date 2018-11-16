#include"Tree.h"

int main() {
	const string str = "data\\tree_15.txt";
	BTNode *p = CreateTree(str);
	PostOrder(p);
	/*int num_node;
	char str1[100];
	int a[100];
	ifstream ins(str);
	ins >> num_node;
	for (int i = 1; i <= num_node; ++i) {
		ins >> str1[i];
		ins >> a[i];
	}
	for (int i = 1; i <= num_node; ++i) {
		cout << str[i]<<"   " << a[i] << endl;
	}
	cout << endl;*/
	return 0;
}