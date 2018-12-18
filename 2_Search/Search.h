#ifndef Search_
#define Search_

#include"myNamespace.h"
typedef int ValueType;
#define N_Node 100	//顺序表的最大元素个数
#define NULLKEY -9999

typedef struct HashTable {
	ValueType *data;
	int size;
}HashTable;

struct Node {
	ValueType data;
	Node *next;
};
struct HashTableLinked {
	Node *key;
	int size;
};

void printErrorAndExit(const string &str);
int Sequence_Search(ValueType A[], int n,ValueType key);
int Bin_Search1(ValueType A[], ValueType obj, int low, int high);
int Bin_Search2(ValueType A[], ValueType obj, int low, int high);
int Bin_Search3(ValueType A[], ValueType obj, int low, int high);

void Init_Hash(HashTable *H, int size);
int Hash(HashTable H, ValueType key);
bool Insert_Hash(HashTable *H, const string &str);
bool Search_Hash(HashTable H, ValueType key, int &addr);

void Init_HashLinked(HashTableLinked *&H, int size);
int HashLinked(HashTableLinked *H, ValueType key);
void Insert_HashLinked(HashTableLinked *&H, const string &str);
void Print_HashLinked(HashTableLinked *H);
bool Search_HashLinked(HashTableLinked *H, ValueType value, int &addr);

int Fibonacci(int A[], int n);
int Fibonacci_search(ValueType A[], int n, ValueType key);

#endif // !Search_

