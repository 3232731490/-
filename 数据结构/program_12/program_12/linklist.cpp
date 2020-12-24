#include"linklist.h"

void init_Link(LinkList** L)
{
	if (*L == NULL)
	{
		*L = new LinkList;
		(*L)->next = NULL;  //ͷ�ڵ�
		cout << "��ʼ���ɹ���" << endl;
	}
	else
	{
		cout << "��ǰ�����ѳ�ʼ������" << endl;
	}
}
void push_link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		LinkList* p = L;
		while (p->next)
		{
			p = p->next;
		}


		cout << "������Ҫ��ʼ�����뼸��Ԫ��(β�巨)��" << endl;
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
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		LinkList* p = L->next;
		if (p == NULL)
		{
			cout << "��ǰ����Ϊ�գ�" << endl;
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
		cout << "���ȳ�ʼ������" << endl;
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
		cout << "���ȳ�ʼ������" << endl;
		return false;
	}
	else
	{
		if (L->next == NULL)
		{
			cout << "������Ϊ�գ�" << endl;
			return L->next == NULL;
		}
		else
		{
			cout << "������Ϊ�գ�" << endl;
			return L->next == NULL;
		}

	}
}


void in_link(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		cout << "��������Ҫ��ʲôλ�ò���Ԫ�أ�" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "�������λ������" << endl;
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
			cout << "��������Ҫ�����Ԫ�أ�" << endl;
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
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		cout << "����������ɾ��ʲôλ�õ�Ԫ�أ�" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "�������λ������" << endl;
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
		cout << "���ȳ�ʼ������" << endl;
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
		cout << "�������ͷţ�" << endl;
	}
}
void find_ele(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		cout << "��������Ҫ���ҵڼ���Ԫ��:" << endl;
		int i;
		cin >> i;
		if (i > get_len(L) || i < 1)
		{
			cout << "�������λ������" << endl;
			return;
		}
		else
		{
			LinkList* p = L;
			for (int j = 0; j < i; j++)
			{
				p = p->next;
			}
			cout << "��ѯ�ɹ��� " << p->data << endl;
		}
	}
}
void get_pos(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
	}
	else {
		cout << "��������Ҫ��ѯ�ĸ�Ԫ�ص�λ�ã�" << endl;
		char data;
		cin >> data;
		int pos = 1;
		LinkList* p = L->next;
		while (p)
		{
			if (p->data == data)
			{
				cout << data << "Ԫ�ص�λ��Ϊ�� " << pos << endl;
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
			cout << "δ��ѯ����Ԫ�أ�" << endl;
		}
	}
}

void head_push(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
		return;
	}
	cout << "��������Ҫͷ��ʲôԪ�أ�" << endl;
	char data;
	cin >> data;
	LinkList* p = L;
	LinkList* temp = new LinkList;
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	cout << "����ɹ���" << endl;
}
void rear_push(LinkList* L)
{
	if (L == NULL)
	{
		cout << "���ȳ�ʼ������" << endl;
		return;
	}
	cout << "��������Ҫβ��ʲôԪ�أ�" << endl;
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
	cout << "����ɹ���" << endl;
}
void del_link_ele(LinkList* L)
{
	cout << "��������Ҫɾ���ĸ�Ԫ�أ�" << endl;
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
		cout << "δ�������в�ѯ����Ԫ�أ�" << endl;
		return;
	}
	else
	{
		pre->next = p->next;
		delete p;
		cout << data << " Ԫ����ɾ����" << endl;
	}

}

void del(LinkList* L)
{
	system("cls");
	cout << "��������Ҫ�����ַ�ʽɾ��Ԫ��" << endl;
	cout << "1��ɾ��ָ��λ��Ԫ��" << endl;
	cout << "2��ɾ��ָ��Ԫ��" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cout << endl << "ɾ��Ԫ��֮ǰ����Ϊ�� ";
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
		cout << "������������,���������룡" << endl;
		goto A;
	}
	cout << endl << "ɾ��Ԫ��֮������Ϊ�� ";
	dis_Link(L);
}

void push(LinkList* L)
{
	system("cls");
	cout << "��������Ҫ�����ַ�ʽ����Ԫ��" << endl;
	cout << "1��ָ��λ�ò���Ԫ��" << endl;
	cout << "2��ͷ�巨����Ԫ��" << endl;
	cout << "3��β�巨����Ԫ��" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cout << endl << "����Ԫ��֮ǰ����Ϊ�� ";
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
		cout << "������������,���������룡" << endl;
		goto B;
	}
	cout << endl << "����Ԫ��֮������Ϊ�� ";
	dis_Link(L);
}

void search(LinkList* L)
{
	system("cls");
	cout << "��������Ҫ�����ַ�ʽ����Ԫ��" << endl;
	cout << "1������ָ��Ԫ��λ��" << endl;
	cout << "2����������Ԫ��" << endl;
	cout << "0���˳�" << endl;
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
		cout << "������������,���������룡" << endl;
		goto B;
	}
}
void dis_menu()
{
	cout << "����������ѡ��" << endl;
	cout << "1����ʼ������" << endl;
	cout << "2����ʼ����������" << endl;
	cout << "3��չʾ����" << endl;
	cout << "4����ȡ������" << endl;
	cout << "5������Ԫ��" << endl;
	cout << "6������Ԫ��" << endl;
	cout << "7����ѯ�����Ƿ�Ϊ��" << endl;
	cout << "8��ɾ��Ԫ��" << endl;
	cout << "9���ͷ�����" << endl;
	cout << "0���˳�" << endl;
}