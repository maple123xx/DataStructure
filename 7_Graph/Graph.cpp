#include"Graph.h"

void printErrorAndExit(const string &str)
{
	cout << "There is an error in " + str + " ! " << endl;
	exit(1);
}
void Create_MGraph(MGraph *&mgraph, const string &str) {
	//�ɾ���������ڽӾ����ʾ��ͼ
	//�ļ��ĵ�һ��������ͼ�ж�������
	//�������Ƕ���ı����������Ϣ����1��ʼ��ţ�
	//�������Ǿ��������������Ϊ��ֵ���Լ����Լ��ľ���Ϊ0����������Ϊ-1
	//ע�⣺��������ͼ�������˺�������󣬱ߵ�����Ϊʵ��������2��
	try
	{
		int i, j;
		Value_Type k;	//��Ȩֵ
		ifstream ins(str);
		if (!ins) { throw exception(); }
		mgraph->num_edge = 0;//��ʼ�������ߣ�������Ϊ0
		ins >> mgraph->num_node;//����һ�У�����ڵ����
		if (mgraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= mgraph->num_node; ++i) {
			ins >> mgraph->vertex[i].info;
			ins >> mgraph->vertex[i].no;
		}
		for (i = 1; i <= mgraph->num_node; ++i) {
			for (j = 1; j <= mgraph->num_node; ++j) {
				ins >> k;
				if (k > CON_SELF && i != j) {//������ʱ
					mgraph->edge[i][j]=k;
					++mgraph->num_edge;//������1
				}
				else if(i==j)			//���Լ��ľ���Ϊ0
				{
					mgraph->edge[i][j] = CON_SELF;
				}
				else                  //������
				{
					mgraph->edge[i][j] = CON_N;
				}
			}
		}
	}
	catch (...)
	{
		printErrorAndExit("Create_MGraph");
	}
}
void Print_MGraph_Matrix(MGraph *mgraph) {//��MGraph���Ͳ�����ӡ�ڽӾ����ʾ��ͼ
	int i, j;
	cout << "ͼ�еĶ��㼰����Ϊ��" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		cout << mgraph->vertex[i].info << ":" << mgraph->vertex[i].no << '\t';
	}
	cout << endl << "ͼ�еĻ����ߣ�����" << mgraph->num_edge << "��������������£�" << endl;
	for (i = 1; i <= mgraph->num_node; ++i) {
		for (j = 1; j <= mgraph->num_node; ++j) {
			cout.width(6);
			cout << mgraph->edge[i][j];
		}
		cout << endl;
	}
}
void Create_AGraph(AGraph *&agraph, const string &str) {
	//���ڽӱ����͵��ļ�����ͼ���ڽӱ�
	//�ļ��ĵ�һ������Ϊ�������num_node
	//�ļ��ĵ�2���Ƕ�����Ϣ��������'A'����Ĭ�ϱ�Ŵ�1��ʼ������
	//�ļ��ĵ�3�е���num_node+2�о�Ϊ����ÿ������ĵ�һ�������ǻ�β�������ţ����������ǻ�ͷ���������Լ�����Ȩ�أ����һ������Ϊ-1����ʾ�������
	//���磺6,5,7.2,8,3.6,3,10.8,-1������ʾ������(6,5,7.2),(6,8,3.6),(6,3,10.8)
	//��1��ʼ���
	//��Ϊ����ͼ����num_edgeΪʵ��ֵ������
	try
	{
		int i, k;
		Arc *p;
		ifstream ins(str);
		if (!ins) { throw exception(); }
		agraph->num_edge = 0;//��ʼ�������ߣ�����Ϊ0
		ins >> agraph->num_node;
		if (agraph->num_node < 1) { throw exception(); }
		for (i = 1; i <= agraph->num_node; ++i) {
			agraph->adjlist[i].ver_head.no = i;//���i�������ͷ��������Ϊi
			ins >> agraph->adjlist[i].ver_head.info;//��1��agraph->num_node���ζ�ȡ������Ϣ�������ơ�A��
			agraph->adjlist[i].first = NULL;//��Ҫ
		}
		for (i = 1; i <= agraph->num_node; ++i) {
			ins >> k;
			if (i != k) {
				cout << "�ļ���ʽ���������ͷ����Ӧ�ô�1��ʼ��������" << endl;
				exit(1);
			}
			ins >> k;
			while (k != F_END) {
				++agraph->num_edge;//�����ߣ���������
				p = (Arc *)malloc(sizeof(Arc));//�����ڴ棬����һ����
				p->adjvex = agraph->adjlist[k].ver_head;//��ͷ
				ins >> p->weight;						//����Ȩֵ
				p->next = agraph->adjlist[i].first;		//ͷ�巨
				agraph->adjlist[i].first = p;
				ins >> k;						//��ȡ��һ��������Ϣ
			}
		}
	}
	catch (...)
	{
		printErrorAndExit("Create_AGraph");
	}
}
void Print_AGraph_Matrix(AGraph *agraph) {//��AGraph���Ͳ�����ӡ�ڽӾ����ʾ��ͼ
	int i;
	Arc *p;
	cout << "ͼ�еĶ�����ϢΪ��" << endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		cout << agraph->adjlist[i].ver_head.info << " ���Ϊ��" << agraph->adjlist[i].ver_head.no << '\t';
	}
	cout << endl << "ͼ�еĻ����ߣ�����" << agraph->num_edge << "����������Ϣ���£�"<<endl;
	for (i = 1; i <= agraph->num_node; ++i) {
		p = agraph->adjlist[i].first;
		while (p) {
			cout << "(" << i << "," << p->adjvex.no << ":" << p->weight << ")" << '\t';
			p = p->next;
		}
		cout << "����" << endl;
	}
}
