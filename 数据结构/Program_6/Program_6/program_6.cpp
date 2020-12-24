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
		cout << "当前二叉树已创建，要输入数据请先销毁二叉树！" << endl;
		return;
	}
	char in;
	int count = 1;
	while (1)
	{
		cout << "请输入第 " << count++ << " 个数据： (以#结束输入)" << endl;
		cin >> in;
		if (in == '#')
		{
			cout << "插入完毕且本二叉树已按完全二叉树顺序排列！" << endl;
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
		cout << "当前二叉树为空！" << endl;
		return;
	}
	else
	{
		cout << "当前二叉树为： ";
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
		cout << c << " 节点的左孩子是： " << ((B->lchild == NULL) ? '#' : (B->lchild->data)) << " 右孩子是： " << ((B->rchild == NULL) ? '#' : (B->rchild->data)) << endl;
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
		cout << "当前二叉树为空！" << endl;
		return;
	}
	else
	{
		cout << "请输入您要查看哪个元素的孩子：" << endl;
		char c;
		cin >> c;
		if (!dis_Node_child(B, c))
		{
			cout << "未在二叉树中找到该元素！" << endl;
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
		cout << "叶子节点 " << count << " " << B->data << endl;
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
		cout << "当前二叉树为空！" << endl;
		return;
	}
	int count = 0;
	dis_leaf(B, count);
	cout << "叶子节点总计： " << count << endl;
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
		cout << "当前二叉树为空！" << endl;
		return;
	}
	cout << "请输入您想查看哪种方式遍历二叉树的序列：" << endl;
	cout << "1、前序遍历" << endl;
	cout << "2、中序遍历" << endl;
	cout << "3、后序遍历" << endl;
	cout << "4、层序遍历" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "前序遍历为： ";
		pre_dis(B);
		cout << endl;
		break;
	case 2:
		cout << "中序遍历为： ";
		mid_dis(B);
		cout << endl;
		break;
	case 3:
		cout << "后序遍历为： ";
		rear_dis(B);
		cout << endl;
		break;
	case 4:
		cout << "层序遍历为： ";
		lay_dis(B);
		cout << endl;
		break;
	default:
		cout << "您的输入有误！" << endl;

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
		cout << "当前二叉树已释放！" << endl;
		return;
	}
	else
	{
		free_BTree(B);
		cout << "当前二叉树已释放！" << endl;
	}
}
void dis_menu()
{
	cout << "1、创建二叉树" << endl;
	cout << "2、输出指定节点的左右孩子" << endl;
	cout << "3、输出二叉树高度" << endl;
	cout << "4、输出叶子节点总数及叶子节点值" << endl;
	cout << "5、遍历二叉树" << endl;
	cout << "6、释放二叉树" << endl;
	cout << "0、退出" << endl;
}
int main()
{
	BTNode* B = NULL;
	while (1)
	{
		dis_menu();
		cout << "请入您的选择：" << endl;
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
			cout << "当前二叉树高度： " << get_BTdeep(B) << endl;
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
			cout << "您的选择不正确,请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}