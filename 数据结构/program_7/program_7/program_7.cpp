#include<iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 100
struct BTNode {
	int data;
	BTNode* Lchild, * Rchild;
};
int *a = new int[MAXSIZE];
bool* flag = new bool[MAXSIZE];
void sort(int* a ,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
void Init(int* a ,BTNode **B,int &n)
{
	cout << "��������Ҫ����һ���������ݵĹ�������" << endl;
	cin >> n;
	if (n <= 0 || n > MAXSIZE)
	{
		cout << "������ĳ�������" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "������� " << (i + 1) << " �����ݣ�" << endl;
		cin >> a[i];
		flag[i] = false;
	}
	sort(a,n);
	for (int i = 0; i < n; i++)
	{
		B[i] = new BTNode;
		B[i]->data = a[i];
		B[i]->Lchild = B[i]->Rchild = NULL;
	}
}
void merge(BTNode** B, BTNode & min1,BTNode &min2, int n)
{
	BTNode *temp = new BTNode;
	temp->data = min1.data + min2.data;
	temp->Lchild = &min1;
	temp->Rchild = &min2;
	B[n] = temp;
}
void creat_HTree(BTNode** B, int a[] ,int n)
{
	int min1, min2;
	for (int i = 0; i < n-1; i++)
	{
		int k = i;
		while (flag[k] != false)
		{
			k++;
		}
		int j = i + 1;
		while (flag[j] != false)
		{
			j++;
		}
		min1 = B[k]->data;
		min2 = B[j]->data;
		while (min1 > min2)
		{
			min1 = min2;
			if ((j+1)<n&&min2 > B[(j+1)]->data)
			{
				min2 = B[++j]->data;
			}
			else
			{
				min2 = B[k]->data;
			}
		}
		flag[k] = true;

		merge(B, *B[k], *B[j], j);
	}
}

void dis_Tree(BTNode* B)
{
	if (B == NULL)
	{
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << B->data << " ";
	}
	if (B->Lchild != NULL)
	{
		dis_Tree(B->Lchild);
	}
	if (B->Rchild != NULL)
	{
		dis_Tree(B->Rchild);
	}
}
void Dis_Tree(BTNode*& B)
{
	if (B == NULL)
	{
		cout << "��ǰ��������δ��ʼ��������ִ��1��2������" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "��������δ���������ȴ�����������(����2)��" << endl;
		return;
	}
	cout << "���������ĸ���Ҷ�ӽڵ�Ϊ�� ";
	dis_Tree(B);
	cout << endl;

}
int get_weight(BTNode* B ,int layer)
{
	if (B == NULL)
	{
		return 1;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		return B->data * layer;
	}
	if (B->Lchild != NULL && B->Rchild != NULL)
	{
		return get_weight(B->Lchild, layer+1) + get_weight(B->Rchild, layer+1);
	}
	else if (B->Lchild != NULL)
	{
		return  get_weight(B->Lchild, layer+1);
	}
	else if (B->Rchild != NULL)
	{
		return layer * get_weight(B->Rchild, layer+1);
	}
}
void Get_weight(BTNode* B)
{
	if (B == NULL)
	{
		cout << "��ǰ��������δ��ʼ��������ִ��1��2������" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "��������δ���������ȴ�����������(����2)��" << endl;
		return;
	}
	int layer = 0;
	int weight = get_weight(B, layer);
	cout << "��ǰ������������ȨֵΪ�� " << weight << endl;
}

void free_BTree(BTNode*& B)
{
	if (B != NULL)
	{
		free_BTree(B->Lchild);
		free_BTree(B->Rchild);
		delete B;
		B = NULL;
	}
}
void free_BTREE(BTNode*& B)
{
	if (B == NULL)
	{
		cout << "��ǰ��������δ��ʼ�����������٣�" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "��������δ�������������٣�" << endl;
		return;
	}
	free_BTree(B);
	cout << "��ǰ���������ͷţ�" << endl;

}
void dis_BT(BTNode* B)
{

	if (B != NULL)
	{
		cout << B->data;
		if (B->Lchild != NULL || B->Rchild != NULL)
		{
			cout << "(";
			dis_BT(B->Lchild);
			if (B->Rchild != NULL)
			{
				cout << ",";
			}
			dis_BT(B->Rchild);
			cout << ")";
		}
	}
}
void Dis_HTree(BTNode* B)
{
	if (B == NULL)
	{
		cout << "��ǰ��������δ��ʼ��������ִ��1��2������" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "��������δ���������ȴ�����������(����2)��" << endl;
		return;
	}
	dis_BT(B);
	cout << endl;
}
void dis_menu()
{
	cout << "1����ʼ������" << endl;
	cout << "2��������������" << endl;
	cout << "3�������������Ҷ��" << endl;
	cout << "4�����������������Ȩֵ" << endl;
	cout << "5�����ŷ������������" << endl;
	cout << "6�����ٹ�������" << endl;
	cout << "0���˳�" << endl;
}

int main()
{
	BTNode* B[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		B[i] = NULL;
	}
	int n = MAXSIZE;
	int choice;
	while (1)
	{
		dis_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init(a, B, n);
			system("pause");
			system("cls");
			break;
		case 2:
			creat_HTree(B, a, n);
			system("pause");
			system("cls");
			break;
		case 3:
			Dis_Tree(B[n - 1]);
			system("pause");
			system("cls");
			break;
		case 4:
			Get_weight(B[n-1]);
			system("pause");
			system("cls");
			break;
		case 5:
			Dis_HTree(B[n - 1]);
			system("pause");
			system("cls");
			break;
		case 6:
			free_BTREE(B[n - 1]);
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			cout << "����������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}