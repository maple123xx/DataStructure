#include"Search.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
int Sequence_Search(ValueType A[], int n,ValueType key) {
	//顺序查找，数组A[]下标从1开始。对线性的链表只能顺序，查找
	//还有一种是有序表的顺序查找，当A[i]>key,A[i+1]<key时，就不用继续往后找了，有序表的顺序查找的思想和二分查找是不一样的
	int i;
	A[0] = key;//哨兵，防止越界
	for (i = n; A[i] != key; i--);
	return i;//查找成功则返回正确位置，失败则返回0
}
int Bin_Search1(ValueType A[], ValueType obj, int low, int high) {
	//二分查找,仅适用于有序表，递归版本,若找到，返回下标；否则，返回0
	//适合二分查找的存储结构必须具有随机存取的特性，所欲二分查找不适用于线性表的链式存储结构
	if (low > high) {
		return 0;
	}
	int mid = (low + high) / 2;
	if (A[mid] == obj) {
		return mid;
	}
	else if (A[mid] > obj) {
		return Bin_Search1(A, obj, low, mid-1);
	}
	else {
		return Bin_Search1(A, obj, mid+1, high);
	}
}
int Bin_Search2(ValueType A[], ValueType obj, int low, int high) {
	//二分查找，非递归版本,若找到，返回下标；否则，返回0
	if (low>high)
	{
		cout << "参数low不允许大于high" << endl;
		exit(1);
	}
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == obj) {
			return mid;
		}
		else if (A[mid] > obj) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return 0;	//没找到，返回0，这个很重要
}
void Init_Hash(HashTable *H, int size) {
	//初始化散列表
	H->size = size;
	H->data = (ValueType *)malloc(size*sizeof(ValueType));
	for (int i = 0; i < size; ++i) {
		H->data[i] = NULLKEY;
	}
}
int Hash(HashTable H, ValueType key) {
	//散列函数
	return key % 13;	//除留取余法
}
bool Insert_Hash(HashTable *H, const string &str) {
	//把关键字插入散列表中
	try
	{
		int i, addr, num_data;//num_data是关键值个数
		ValueType key;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		ins >> num_data;
		if (num_data < 1) { throw exception(); }
		for (i = 1; i <= num_data; ++i) {
			ins >> key;
			addr = Hash(*H, key);			//求散列地址
			while (H->data[addr] != NULLKEY) {	//不为空则冲突
				addr = (addr + 1) % H->size;//开放定址法的线性探测
				if (addr == Hash(*H, key)) {
					return false;	//寻找下一个空位置，一直找了一圈又找回来，都满了
				}
			}
			H->data[addr] = key;//直到有空位置了插入
		}
		
	}
	catch (...)
	{
		printErrorAndExit("Insert_Hash");
	}
	return true;
}
bool Search_Hash(HashTable H, ValueType key, int &addr) {
	//散列表查找关键字
	//查找成功返回TRUE，失败返回FALSE
	//若查找成功，addr存储其位置
	addr = Hash(H, key);
	if (H.data[addr] == NULLKEY)
		return false;		//散列地址为空
	while (H.data[addr] != key) {
		addr = (addr + 1) % H.size;
		if (H.data[addr] == NULLKEY || addr == Hash(H, key)) {
			return false;		//下一个散列地址为空说明肯定不存在这个地址了，或者循环回到原点也说明不存在
			//H.data[addr] = key;//或者当为没找到的时候，就把这个关键字插入
		}
	}
	return true;
}

//生成斐波那契数列，数列的最后一个元素大于或者等于n
int Fibonacci(int A[], int n)
{
	int k = 1;
	A[0] = 0;
	A[1] = 1;
	while (A[k]<n)
	{
		++k;
		A[k] = A[k - 1] + A[k - 2];
	}
	return k;
}

//数组A[]下标从1开始
//n为待查找数组含有元素的个数，key为需要查找的关键字
int Fibonacci_search(ValueType A[], int n, ValueType key)
{
	int i, k;
	int F[N_Node];
	k = Fibonacci(F, n + 1);		//斐波那契数列的最后一个元素大于或等于n+1
	int low = 1, high = F[k] - 1, mid;
	for (i = n + 1; i <= F[k] - 1; ++i)
	{
		A[i] = A[n];			//将不满的数值补全
	}
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;		//计算当前分隔下标
		if (key == A[mid])
		{
			if (mid <= n)
			{
				return mid;		//mid即为查找到的位置
			}
			else
			{
				return n;		//说明是补全数组
			}
		}
		else if (key<A[mid])
		{
			high = mid - 1;
			--k;			//斐波那契数列下标减1
		}
		else
		{
			low = mid + 1;
			k = k - 2;			//斐波那契数列下标减2
		}
	}
	return 0;
}