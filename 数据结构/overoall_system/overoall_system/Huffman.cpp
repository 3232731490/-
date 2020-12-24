#include"Huffman.h"
int* A = new int[MAXSIZE];
bool* flag = new bool[MAXSIZE];
void sort(int* a, int n)
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
void Init(int* a, BTNode** B, int& n)
{
	cout << "请输入您要构建一个多少数据的哈夫曼树" << endl;
	cin >> n;
	if (n <= 0 || n > MAXSIZE)
	{
		cout << "您输入的长度有误！" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第 " << (i + 1) << " 个数据：" << endl;
		cin >> a[i];
		flag[i] = false;
	}
	sort(a, n);
	for (int i = 0; i < n; i++)
	{
		B[i] = new BTNode;
		B[i]->data = a[i];
		B[i]->Lchild = B[i]->Rchild = NULL;
	}
}
void merge(BTNode** B, BTNode& min1, BTNode& min2, int n)
{
	BTNode* temp = new BTNode;
	temp->data = min1.data + min2.data;
	temp->Lchild = &min1;
	temp->Rchild = &min2;
	B[n] = temp;
}
void creat_HTree(BTNode** B, int a[], int n)
{
	int min1, min2;
	for (int i = 0; i < n - 1; i++)
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
			if ((j + 1) < n && min2 > B[(j + 1)]->data)
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
		cout << "当前哈夫曼树未初始化，请先执行1、2操作！" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "哈夫曼树未创建，请先创建哈夫曼树(操作2)！" << endl;
		return;
	}
	cout << "哈夫曼树的各个叶子节点为： ";
	dis_Tree(B);
	cout << endl;

}
int get_weight(BTNode* B, int layer)
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
		return get_weight(B->Lchild, layer + 1) + get_weight(B->Rchild, layer + 1);
	}
	else if (B->Lchild != NULL)
	{
		return  get_weight(B->Lchild, layer + 1);
	}
	else if (B->Rchild != NULL)
	{
		return layer * get_weight(B->Rchild, layer + 1);
	}
}
void Get_weight(BTNode* B)
{
	if (B == NULL)
	{
		cout << "当前哈夫曼树未初始化，请先执行1、2操作！" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "哈夫曼树未创建，请先创建哈夫曼树(操作2)！" << endl;
		return;
	}
	int layer = 0;
	int weight = get_weight(B, layer);
	cout << "当前哈夫曼树的总权值为： " << weight << endl;
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
		cout << "当前哈夫曼树未初始化，无需销毁！" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "哈夫曼树未创建，无需销毁！" << endl;
		return;
	}
	free_BTree(B);
	cout << "当前二叉树已释放！" << endl;

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
		cout << "当前哈夫曼树未初始化，请先执行1、2操作！" << endl;
		return;
	}
	if (B->Lchild == NULL && B->Rchild == NULL)
	{
		cout << "哈夫曼树未创建，请先创建哈夫曼树(操作2)！" << endl;
		return;
	}
	dis_BT(B);
	cout << endl;
}
void dis_Huff_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************哈夫曼********************************" << endl;
	cout << "\t\t\t***\t1、初始化数据\t\t\t       2、创建哈夫曼树\t  ***" << endl;
	cout << "\t\t\t***\t3、输出哈夫曼树叶子\t\t       4、输出总权值\t  ***" << endl;
	cout << "\t\t\t***\t5、括号法输出哈夫曼树\t\t       6、销毁哈夫曼树\t  ***" << endl;
	cout << "\t\t\t***\t0、退出\t\t\t      \t\t\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}

void Huff_main_func()
{
	BTNode* B[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		B[i] = NULL;
	}
	int n = MAXSIZE;
	int choice;
	bool flag = false;
	while (1)
	{
		dis_Huff_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init(A, B, n);
			flag = true;
			system("pause");
			system("cls");
			break;
		case 2:
			if (flag)
			{
				creat_HTree(B, A, n);
				cout << "哈夫曼树已创建！" << endl;
			}
			else
			{
				cout << "请先初始化数据后在执行此操作！" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			Dis_Tree(B[n - 1]);
			system("pause");
			system("cls");
			break;
		case 4:
			Get_weight(B[n - 1]);
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
			flag = false;
			system("pause");
			system("cls");
			break;
		case 0:
			return;
		default:
			cout << "您的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return ;
}