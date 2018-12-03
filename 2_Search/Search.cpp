#include"Search.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
int Sequence_Search(ValueType A[], int n,ValueType key) {
	//˳����ң�����A[]�±��1��ʼ�������Ե�����ֻ��˳�򣬲���
	//����һ�����������˳����ң���A[i]>key,A[i+1]<keyʱ���Ͳ��ü����������ˣ��������˳����ҵ�˼��Ͷ��ֲ����ǲ�һ����
	int i;
	A[0] = key;//�ڱ�����ֹԽ��
	for (i = n; A[i] != key; i--);
	return i;//���ҳɹ��򷵻���ȷλ�ã�ʧ���򷵻�0
}
int Bin_Search1(ValueType A[], ValueType obj, int low, int high) {
	//���ֲ���,����������������ݹ�汾,���ҵ��������±ꣻ���򣬷���0
	//�ʺ϶��ֲ��ҵĴ洢�ṹ������������ȡ�����ԣ��������ֲ��Ҳ����������Ա�����ʽ�洢�ṹ
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
	//���ֲ��ң��ǵݹ�汾,���ҵ��������±ꣻ���򣬷���0
	if (low>high)
	{
		cout << "����low����������high" << endl;
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
	return 0;	//û�ҵ�������0���������Ҫ
}
void Init_Hash(HashTable *H, int size) {
	//��ʼ��ɢ�б�
	H->size = size;
	H->data = (ValueType *)malloc(size*sizeof(ValueType));
	for (int i = 0; i < size; ++i) {
		H->data[i] = NULLKEY;
	}
}
int Hash(HashTable H, ValueType key) {
	//ɢ�к���
	return key % 13;	//����ȡ�෨
}
bool Insert_Hash(HashTable *H, const string &str) {
	//�ѹؼ��ֲ���ɢ�б���
	try
	{
		int i, addr, num_data;//num_data�ǹؼ�ֵ����
		ValueType key;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		ins >> num_data;
		if (num_data < 1) { throw exception(); }
		for (i = 1; i <= num_data; ++i) {
			ins >> key;
			addr = Hash(*H, key);			//��ɢ�е�ַ
			while (H->data[addr] != NULLKEY) {	//��Ϊ�����ͻ
				addr = (addr + 1) % H->size;//���Ŷ�ַ��������̽��
				if (addr == Hash(*H, key)) {
					return false;	//Ѱ����һ����λ�ã�һֱ����һȦ���һ�����������
				}
			}
			H->data[addr] = key;//ֱ���п�λ���˲���
		}
		
	}
	catch (...)
	{
		printErrorAndExit("Insert_Hash");
	}
	return true;
}
bool Search_Hash(HashTable H, ValueType key, int &addr) {
	//ɢ�б����ҹؼ���
	//���ҳɹ�����TRUE��ʧ�ܷ���FALSE
	//�����ҳɹ���addr�洢��λ��
	addr = Hash(H, key);
	if (H.data[addr] == NULLKEY)
		return false;		//ɢ�е�ַΪ��
	while (H.data[addr] != key) {
		addr = (addr + 1) % H.size;
		if (H.data[addr] == NULLKEY || addr == Hash(H, key)) {
			return false;		//��һ��ɢ�е�ַΪ��˵���϶������������ַ�ˣ�����ѭ���ص�ԭ��Ҳ˵��������
			//H.data[addr] = key;//���ߵ�Ϊû�ҵ���ʱ�򣬾Ͱ�����ؼ��ֲ���
		}
	}
	return true;
}

//����쳲��������У����е����һ��Ԫ�ش��ڻ��ߵ���n
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

//����A[]�±��1��ʼ
//nΪ���������麬��Ԫ�صĸ�����keyΪ��Ҫ���ҵĹؼ���
int Fibonacci_search(ValueType A[], int n, ValueType key)
{
	int i, k;
	int F[N_Node];
	k = Fibonacci(F, n + 1);		//쳲��������е����һ��Ԫ�ش��ڻ����n+1
	int low = 1, high = F[k] - 1, mid;
	for (i = n + 1; i <= F[k] - 1; ++i)
	{
		A[i] = A[n];			//����������ֵ��ȫ
	}
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;		//���㵱ǰ�ָ��±�
		if (key == A[mid])
		{
			if (mid <= n)
			{
				return mid;		//mid��Ϊ���ҵ���λ��
			}
			else
			{
				return n;		//˵���ǲ�ȫ����
			}
		}
		else if (key<A[mid])
		{
			high = mid - 1;
			--k;			//쳲����������±��1
		}
		else
		{
			low = mid + 1;
			k = k - 2;			//쳲����������±��2
		}
	}
	return 0;
}