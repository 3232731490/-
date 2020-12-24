#include<iostream>
#include<queue>
using namespace std;
#define MAXSIZE 100
struct BTNode
{
	char data;
	BTNode* lchild, * rchild;

};

void Inner(BTNode*& B, char data)
{
	if (B == NULL)
	{
		B = new BTNode;
		B->data = data;
		B->lchild = NULL;
		B->rchild = NULL;
	}
	else
	{
		BTNode* p = B;
		queue<BTNode*> Q;
		Q.push(p);
		int flag = 0;
		BTNode *tmp=NULL;
		BTNode* P=NULL;
		while (!Q.empty())
		{
			tmp = Q.front();
			Q.pop();
			if (tmp->lchild != NULL)
			{
				Q.push(tmp->lchild);
			}
			else
			{
				flag = 1;
				P = tmp;
				tmp = tmp->lchild;
				break;
			}
			if (tmp->rchild != NULL)
			{
				Q.push(tmp->rchild);
			}
			else
			{
				flag = 2;
				P = tmp;
				tmp = tmp->rchild;
				break;
			}
		}
		tmp = new BTNode;
		tmp->data = data;
		tmp->lchild = NULL;
		tmp->rchild = NULL;
		if (flag == 1)
		{
			P->lchild = tmp;
		}
		else if (flag == 2)
		{
			P->rchild = tmp;
		}
	}
}
void Input(BTNode*& B)
{
	if (B != NULL)
	{
		cout << "��ǰ�������Ѵ�����Ҫ���������������ٶ�������" << endl;
		return;
	}
	char in;
	int count = 1;
	while (1)
	{
		cout << "������� " << count++ << " �����ݣ� (��#��������)" << endl;
		cin >> in;
		if (in == '#')
		{
			cout << "��������ұ��������Ѱ���ȫ������˳�����У�" << endl;
			return;
		}
		else
		{
			Inner(B, in);
		}
	}
}

void dis_BT(BTNode* B)
{
	if (B != NULL)
	{
		cout << B->data;
		if (B->lchild != NULL || B->rchild != NULL)
		{
			cout << "(";
			dis_BT(B->lchild);
			if (B->rchild != NULL)
			{
				cout << ",";
			}
			dis_BT(B->rchild);
			cout << ")";
		}
	}
}
void dis_BTree(BTNode* B)
{
	if (B == NULL)
	{
		cout << "��ǰ������Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "��ǰ������Ϊ�� ";
		dis_BT(B);
		cout << endl;
	}
}
bool dis_Node_child(BTNode* B, char c)
{
	if (B == NULL)
	{
		return false;
	}
	char temp = B->data;
	if (temp == c)
	{
		cout << c << " �ڵ�������ǣ� " << ((B->lchild == NULL) ? '#' : (B->lchild->data)) << " �Һ����ǣ� " << ((B->rchild == NULL) ? '#' : (B->rchild->data)) << endl;
		return true;
	}
	else
	{
		bool b1 = dis_Node_child(B->lchild, c);
		if (!b1)
		{
			return dis_Node_child(B->rchild, c);
		}
		else
		{
			return true;
		}
	}
}
void dis_NODE_child(BTNode* B)
{
	if (B == NULL)
	{
		cout << "��ǰ������Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "��������Ҫ�鿴�ĸ�Ԫ�صĺ��ӣ�" << endl;
		char c;
		cin >> c;
		if (!dis_Node_child(B, c))
		{
			cout << "δ�ڶ��������ҵ���Ԫ�أ�" << endl;
			return;
		}
	}
}
int get_BTdeep(BTNode* B)
{
	if (B == NULL)
	{
		return 0;
	}
	else if (B->lchild == NULL && B->rchild == NULL)
	{
		return 1;
	}
	else
	{
		int ldeep = get_BTdeep(B->lchild) + 1;
		int rdeep = get_BTdeep(B->rchild) + 1;
		return (ldeep > rdeep) ? ldeep : rdeep;
	}
}

void dis_leaf(BTNode* B, int& count)
{
	if (B->lchild == NULL && B->rchild == NULL)
	{
		count++;
		cout << "Ҷ�ӽڵ� " << count << " " << B->data << endl;
	}
	else
	{
		if (B->lchild != NULL)
			dis_leaf(B->lchild, count);
		if (B->rchild != NULL)
			dis_leaf(B->rchild, count);
	}
}
void dis_BTree_leaf(BTNode* B)
{
	if (B == NULL) {
		cout << "��ǰ������Ϊ�գ�" << endl;
		return;
	}
	int count = 0;
	dis_leaf(B, count);
	cout << "Ҷ�ӽڵ��ܼƣ� " << count << endl;
}
void pre_dis(BTNode* B)
{
	if (B == NULL)
	{
		return;
	}
	cout << B->data << " ";
	pre_dis(B->lchild);
	pre_dis(B->rchild);
}
void mid_dis(BTNode* B)
{
	if (B == NULL)
	{
		return;
	}
	mid_dis(B->lchild);
	cout << B->data << " ";
	mid_dis(B->rchild);
}
void rear_dis(BTNode* B)
{
	if (B == NULL)
	{
		return;
	}
	rear_dis(B->lchild);
	rear_dis(B->rchild);
	cout << B->data << " ";
}
void lay_dis(BTNode* B)
{
	if (B == NULL)
	{
		return;
	}
	queue<BTNode> Q;
	Q.push(*B);
	while (!Q.empty())
	{
		BTNode p = Q.front();
		Q.pop();
		cout << p.data << " ";
		if (p.lchild != NULL)
		{
			Q.push(*p.lchild);
		}
		if (p.rchild != NULL)
		{
			Q.push(*p.rchild);
		}
	}
}
void Visit_BTree(BTNode* B)
{
	if (B == NULL)
	{
		cout << "��ǰ������Ϊ�գ�" << endl;
		return;
	}
	cout << "����������鿴���ַ�ʽ���������������У�" << endl;
	cout << "1��ǰ�����" << endl;
	cout << "2���������" << endl;
	cout << "3���������" << endl;
	cout << "4���������" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "ǰ�����Ϊ�� ";
		pre_dis(B);
		cout << endl;
		break;
	case 2:
		cout << "�������Ϊ�� ";
		mid_dis(B);
		cout << endl;
		break;
	case 3:
		cout << "�������Ϊ�� ";
		rear_dis(B);
		cout << endl;
		break;
	case 4:
		cout << "�������Ϊ�� ";
		lay_dis(B);
		cout << endl;
		break;
	default:
		cout << "������������" << endl;

	}
}
void free_BTree(BTNode*& B)
{
	if (B != NULL)
	{
		free_BTree(B->lchild);
		free_BTree(B->rchild);
		delete B;
		B = NULL;
	}
}
void free_BTREE(BTNode*& B)
{
	if (B == NULL)
	{
		cout << "��ǰ���������ͷţ�" << endl;
		return;
	}
	else
	{
		free_BTree(B);
		cout << "��ǰ���������ͷţ�" << endl;
	}
}
void dis_menu()
{
	cout << "1������������" << endl;
	cout << "2�����ָ���ڵ�����Һ���" << endl;
	cout << "3������������߶�" << endl;
	cout << "4�����Ҷ�ӽڵ�������Ҷ�ӽڵ�ֵ" << endl;
	cout << "5������������" << endl;
	cout << "6���ͷŶ�����" << endl;
	cout << "0���˳�" << endl;
}
int main()
{
	BTNode* B = NULL;
	while (1)
	{
		dis_menu();
		cout << "��������ѡ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Input(B);
			system("pause");
			system("cls");
			break;
		case 2:
			dis_NODE_child(B);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "��ǰ�������߶ȣ� " << get_BTdeep(B) << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			dis_BTree_leaf(B);
			system("pause");
			system("cls");
			break;
		case 5:
			Visit_BTree(B);
			system("pause");
			system("cls");
			break;
		case 6:
			free_BTREE(B);
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			cout << "����ѡ����ȷ,���������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}