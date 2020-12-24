#include"linklist.h"

void init_Link(LinkList** L)
{
	if (*L == NULL)
	{
		*L = new LinkList;
		(*L)->next = NULL;  //头节点
		cout << "初始化成功！" << endl;
	}
	else
	{
		cout << "当前链表已初始化过！" << endl;
	}
}
void push_link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		LinkList* p = L;
		while (p->next)
		{
			p = p->next;
		}


		cout << "输入您要初始化插入几个元素(尾插法)：" << endl;
		int i;
		cin >> i;
		for (int j = 0; j < i; j++)
		{
			rear_push(L);
		}
	}
}

void dis_Link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		LinkList* p = L->next;
		if (p == NULL)
		{
			cout << "当前链表为空！" << endl;
			return;
		}
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
int get_len(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
		return -1;
	}
	else {
		LinkList* p = L->next;
		int len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		return len;
	}
}

bool isEmpty(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
		return false;
	}
	else
	{
		if (L->next == NULL)
		{
			cout << "此链表为空！" << endl;
			return L->next == NULL;
		}
		else
		{
			cout << "此链表不为空！" << endl;
			return L->next == NULL;
		}

	}
}


void in_link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		cout << "请输入您要在什么位置插入元素：" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "您输入的位置有误！" << endl;
			return;
		}
		else
		{
			LinkList* p = L;
			LinkList* pre = NULL;
			for (int j = 0; j < i; j++)
			{
				pre = p;
				p = p->next;
			}
			char data;
			cout << "请输入您要插入的元素：" << endl;
			cin >> data;
			LinkList* temp = new LinkList;
			temp->data = data;
			temp->next = p;
			pre->next = temp;
		}
	}
}

void del_link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		cout << "请输入您想删除什么位置的元素：" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "你输入的位置有误！" << endl;
			return;
		}
		else
		{
			LinkList* p = L;
			LinkList* pre = NULL;
			for (int j = 0; j < i; j++)
			{
				pre = p;
				p = p->next;
			}
			pre->next = p->next;
			delete p;
		}
	}
}
void free_link(LinkList** L)
{
	if (*L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		LinkList* pre = *L;
		LinkList* p = (*L)->next;
		while (p)
		{
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
		(*L) = NULL;
		cout << "链表已释放！" << endl;
	}
}
void find_ele(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		cout << "请输入您要查找第几个元素:" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "您输入的位置有误！" << endl;
			return;
		}
		else
		{
			LinkList* p = L;
			for (int j = 0; j < i; j++)
			{
				p = p->next;
			}
			cout << "查询成功： " << p->data << endl;
		}
	}
}
void get_pos(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
	}
	else {
		cout << "请输入您要查询哪个元素的位置：" << endl;
		char data;
		cin >> data;
		int pos = 1;
		LinkList* p = L->next;
		while (p)
		{
			if (p->data == data)
			{
				cout << data << "元素的位置为： " << pos << endl;
				return;
			}
			else
			{
				p = p->next;
				pos++;
			}
		}
		if (pos > get_len(L))
		{
			cout << "未查询到该元素！" << endl;
		}
	}
}

void head_push(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
		return;
	}
	cout << "请输入您要头插什么元素：" << endl;
	char data;
	cin >> data;
	LinkList* p = L;
	LinkList* temp = new LinkList;
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	cout << "插入成功！" << endl;
}
void rear_push(LinkList* L)
{
	if (L == NULL)
	{
		cout << "请先初始化链表！" << endl;
		return;
	}
	cout << "请输入您要尾插什么元素：" << endl;
	char data;
	cin >> data;
	LinkList* temp = new LinkList;
	temp->data = data;
	LinkList* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
	cout << "插入成功！" << endl;
}
void del_link_ele(LinkList* L)
{
	cout << "请输入您要删除哪个元素：" << endl;
	char data;
	cin >> data;
	LinkList* p = L->next;
	LinkList* pre = L;
	while (p != NULL&& p->data != data)
	{
		pre = p;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未在链表中查询到该元素！" << endl;
		return;
	}
	else
	{
		pre->next = p->next;
		delete p;
		cout << data << " 元素已删除！" << endl;
	}

}

void del(LinkList* L)
{
	system("cls");
	cout << "请输入您要以哪种方式删除元素" << endl;
	cout << "1、删除指定位置元素" << endl;
	cout << "2、删除指定元素" << endl;
	cout << "0、退出" << endl;
	int choice;
	cout << endl << "删除元素之前链表为： ";
	dis_Link(L);
	A:cin >> choice;
	switch (choice)
	{
	case 1:
		del_link(L);
		system("pause");
		break;
	case 2:
		del_link_ele(L);
		system("pause");
		break;
	case 0:
		return;
	default:
		cout << "您的输入有误,请重新输入！" << endl;
		goto A;
	}
	cout << endl << "删除元素之后链表为： ";
	dis_Link(L);
}

void push(LinkList* L)
{
	system("cls");
	cout << "请输入您要以哪种方式插入元素" << endl;
	cout << "1、指定位置插入元素" << endl;
	cout << "2、头插法插入元素" << endl;
	cout << "3、尾插法插入元素" << endl;
	cout << "0、退出" << endl;
	int choice;
	cout << endl << "插入元素之前链表为： ";
	dis_Link(L);
B:cin >> choice;
	switch (choice)
	{
	case 1:
		in_link(L);
		system("pause");
		break;
	case 2:
		rear_push(L);
		system("pause");
		break;
	case 3:
		rear_push(L);
		system("pause");
		break;
	case 0:
		return;
	default:
		cout << "您的输入有误,请重新输入！" << endl;
		goto B;
	}
	cout << endl << "插入元素之后链表为： ";
	dis_Link(L);
}

void search(LinkList* L)
{
	system("cls");
	cout << "请输入您要以哪种方式查找元素" << endl;
	cout << "1、查找指定元素位置" << endl;
	cout << "2、查找链表元素" << endl;
	cout << "0、退出" << endl;
	int choice;
B:cin >> choice;
	switch (choice)
	{
	case 1:
		get_pos(L);
		system("pause");
		break;
	case 2:
		find_ele(L);
		system("pause");
		break;
	case 0:
		return;
	default:
		cout << "您的输入有误,请重新输入！" << endl;
		goto B;
	}
}
void dis_menu()
{
	cout << "请输入您的选择：" << endl;
	cout << "1、初始化链表" << endl;
	cout << "2、初始化链表数据" << endl;
	cout << "3、展示链表" << endl;
	cout << "4、获取链表长度" << endl;
	cout << "5、查找元素" << endl;
	cout << "6、插入元素" << endl;
	cout << "7、查询链表是否为空" << endl;
	cout << "8、删除元素" << endl;
	cout << "9、释放链表" << endl;
	cout << "0、退出" << endl;
}