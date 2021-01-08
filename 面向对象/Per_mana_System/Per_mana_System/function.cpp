#include"function.h"

void read_info(list<Person>& mylist,PortList*& Port ,string& Filename)
{
	mylist.clear();
	string name;
	int age;
	string port;
	float wages;
	string addr;
	string phone_num;
	int file_error_count = 0;
	int sex;
	Person person;
	cout << "��������Ҫ�򿪵�������Ϣ�ļ���" << endl;
	cin >> Filename;
	Filename = Filename + ".txt";
	ifstream ifs(Filename, ios::in);
	while (file_error_count < 3)
	{
		if (!ifs)
		{
			cout << "����������¹�����Ϣ�ļ������ڣ��������������..." << endl;
			file_error_count++;
			cout << "�����ڻ��� " << (3 - file_error_count) << "���������" << endl;
			if (file_error_count < 3)
			{
				cout << "��������Ҫ�򿪵�������Ϣ�ļ���" << endl;
				cin >> Filename;
				Filename = Filename + ".txt";
				ifstream ifs(Filename, ios::in);
			}
		}
		else
		{
			break;
		}
	}
	if (file_error_count == 3)
	{
		cout << "�������������࣬���Զ��˳���" << endl;
		return;
	}
	int count = 0;
	while (!ifs.eof())
	{
		ifs >> name >> age >>sex>> addr >> port >> wages >> phone_num;
		if (age < 0)
		{
			continue;
		}
		person.set_name(name);
		person.set_age(age);
		person.set_sex(sex);
		person.set_phone(phone_num);
		person.set_port(port);
		person.set_wages(wages);
		person.set_addr(addr);
		mylist.push_front(person);
		count++;
	}
	ifs.close();
	read_count_info(mylist, Port);
}
void read_info_temp(list<Person>& mylist,string& Filename)
{
	string name;
	int age;
	string port;
	float wages;
	string addr;
	string phone_num;
	int file_error_count = 0;
	int sex;
	Person person;
	ifstream ifs(Filename, ios::in);
	while (!ifs.eof())
	{
		ifs >> name >> age >> sex >> addr >> port >> wages >> phone_num;
		if (age < 0)
		{
			continue;
		}
		person.set_name(name);
		person.set_age(age);
		person.set_sex(sex);
		person.set_phone(phone_num);
		person.set_port(port);
		person.set_wages(wages);
		person.set_addr(addr);
		mylist.push_front(person);
	}
	ifs.close();
}
void del_info(list<Person>& mylist, string &Filename)
{
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	cout << "��������Ҫͨ��ʲô��ʽɾ��������Ϣ" << endl;
	cout << "1������" << endl;
	cout << "2���绰" << endl;
	string name, phone;
	int choice;
	bool flag = false;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫɾ������Ա������ " << endl;
		cin >> name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == name)
			{
				cout << "���ҵ����û����������Ƿ�ȷ�Ͻ���ɾ����(Y/N)" << endl;
				char a;
			A:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					mylist.erase(it);
					cout << "��ǰ��Ա��ɾ����" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "�ѳ���ɾ��������" << endl;
				}
				else
				{
					cout << "���������������������룺" << endl;
					goto A;
				}
				break;
			}
		}
		break;
	}
	case 2:
	{
		cout << "��������Ҫɾ������Ա�绰�� (8-11λ����)" << endl;
		cin >> phone;
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone;
		if (!regex_match(phone, pattern))
		{
			cout << "�������벻�Ϸ������������룡" << endl;
			count++;
			if (count < 3)
				goto Z;
			else
			{
				cout << "���Ѷ�δ������룬���˳���" << endl;
				return;
			}
		}
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "���ҵ����û����������Ƿ�ȷ�Ͻ���ɾ����(Y/N)" << endl;
				char a;
			B:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					mylist.erase(it);
					cout << "��ǰ��Ա��ɾ����" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "�ѳ���ɾ��������" << endl;
				}
				else
				{
					cout << "���������������������룺" << endl;
					goto B;
				}
				break;
			}
		}
		break;
	}
	default:
		cout << "���������������������룡" << endl;
		goto C;
	}
	if (flag)
	{
		save_info(mylist,Filename);
	}
	else
	{
		cout << "δ�ڵ�ǰ������Ϣ�²��ҵ�����Ա��" << endl;
	}
}
void save_info(list<Person>& mylist,string &Filename)  //����ļ���ʽ������Ϣ
{
	ofstream ofs(Filename, ios::trunc);
	for (list<Person>::iterator it = mylist.begin(); it != mylist.end();)
	{
		ofs << it->get_name() << " " << it->get_age() <<" "<<it->get_sex()<< " " << it->get_addr() << " " << it->get_port() << " " << it->get_wages() << " " << it->get_phone();
		if (++it != mylist.end())
		{
			ofs << endl;
		}
	}
	ofs.close();
}
void search_info(list<Person>& mylist)
{
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	cout << "��������Ҫͨ��ʲô��ʽ����������Ϣ" << endl;
	cout << "1������" << endl;
	cout << "2���绰" << endl;
	string name, phone;
	int choice;
	bool flag = false;
A:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫ���ҵ���Ա������ " << endl;
		cin >> name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == name)
			{
				cout << "���ҵ����û������û���ϸ��Ϣ���£�" << endl;
				it->dis_info();
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ������Ϣ�ļ���δ���ҵ�����Ϊ�� "<<name<<"���û���" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "��������Ҫ���ҵ���Ա�绰��(8-11λ����) " << endl;
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone;
		if (!regex_match(phone, pattern))
		{
			cout << "�������벻�Ϸ������������룡" << endl;
			count++;
			if(count<3)
			goto Z;
			else
			{
				cout << "���Ѷ�δ������룬���˳���" << endl;
				return;
			}
		}
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "���ҵ����û������û���ϸ��Ϣ���£�" << endl;
				it->dis_info();
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ������Ϣ�ļ���δ���ҵ��ֻ���Ϊ�� " << phone << "���û���" << endl;
		}
		break;
	}
	default:
		cout << "���������������������룡" << endl;
		goto A;
	}
}
void mod_info(list<Person>& mylist,string &Filename)  //�޸�������Ϣ
{
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	string name;
	int age;
	string port;
	float wages;
	string addr;
	string phone_num;
	int sex;
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	cout << "��������Ҫͨ��ʲô��ʽ�޸�������Ϣ" << endl;
	cout << "1������" << endl;
	cout << "2���绰" << endl;
	string n_name, phone;
	int choice;
	bool flag = false;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫ�޸ĵ���Ա������ " << endl;
		cin >> n_name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == n_name)
			{
				cout << "���ҵ����û����������Ƿ�ȷ�Ͻ����޸ģ�(Y/N)" << endl;
				char a;
			A:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					cout << "���������Ա��������Ϣ��" << endl;
					cout << "������ ";
					cin >> name;
					cout << "���䣺" ;
				H:	cin >> age;
					if (age <= 0 || age > 150)
					{
						cout << "�������벻�Ϸ�������������" << endl;
						goto H;
					}
					cout << "�Ա� (1-��|0-Ů)" ;
					cin >> sex;
					cout << "סַ��";
					cin >> addr;
					cout << "ְ��";
					cin >> port;
					cout << "���ʣ�";
					cin >> wages;
					cout << "�ֻ��ţ�(8-11λ����)";
					regex pattern("\\d{8,11}");
					int count = 0;
				Z:	cin >> phone_num;
					if (!regex_match(phone_num, pattern))
					{
						cout << "�������벻�Ϸ������������룡" << endl;
						count++;
						if (count < 3)
							goto Z;
						else
						{
							cout << "���Ѷ�δ������룬���˳���" << endl;
							return;
						}
					}
					it->set_name(name);
					it->set_addr(addr);
					it->set_age(age);
					it->set_phone(phone_num);
					it->set_port(port);
					it->set_sex(sex);
					it->set_wages(wages);
					cout << "��ǰ�û���Ϣ���޸���ϣ�" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "�ѳ����޸Ĳ�����" << endl;
				}
				else
				{
					cout << "���������������������룺" << endl;
					goto A;
				}
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ������Ϣ��δ�ҵ�����Ա��" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "��������Ҫ�޸ĵ���Ա�绰�� " << endl;
		cin >>phone;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "���ҵ����û����������Ƿ�ȷ�Ͻ����޸ģ�(Y/N)" << endl;
				char a;
			B:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					cout << "���������Ա��������Ϣ��" << endl;
					cout << "������ ";
					cin >> name;
					cout << "���䣺";
				R:	cin >> age;
					if (age <= 0 || age > 150)
					{
						cout << "�������벻�Ϸ�������������" << endl;
						goto R;
					}
					cout << "�Ա� (1-��|0-Ů)";
					cin >> sex;
					cout << "סַ��";
					cin >> addr;
					cout << "ְ��";
					cin >> port;
					cout << "���ʣ�";
					cin >> wages;
					cout << "�ֻ��ţ�(8-11λ����)";
					regex pattern("\\d{8,11}");
					int count = 0;
				Y:	cin >> phone_num;
					if (!regex_match(phone_num, pattern))
					{
						cout << "�������벻�Ϸ������������룡" << endl;
						count++;
						if (count < 3)
							goto Y;
						else
						{
							cout << "���Ѷ�δ������룬���˳���" << endl;
							return;
						}
					}
					it->set_name(name);
					it->set_addr(addr);
					it->set_age(age);
					it->set_phone(phone);
					it->set_port(port);
					it->set_sex(sex);
					it->set_wages(wages);
					cout << "��ǰ�û���Ϣ���޸���ϣ�" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "�ѳ����޸Ĳ�����" << endl;
				}
				else
				{
					cout << "���������������������룺" << endl;
					goto B;
				}
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ������Ϣ��δ�ҵ�����Ա��" << endl;
		}
		break;
	}
	default:
		cout << "���������������������룡" << endl;
		goto C;
	}
	if (flag)
	{
		save_info(mylist, Filename);
	}
}
bool cmp_age_de(Person &p1,Person &p2)
{
	if (p1.get_age() == p2.get_age())
	{
		return p1.get_wages ()> p1.get_wages();  //���չ��ʽ���
	}
	else
	{
		return p1.get_age() > p2.get_age();    //�������併��
	}
}
bool cmp_age_ri(Person& p1, Person& p2)
{
	if (p1.get_age() == p2.get_age())
	{
		return p1.get_wages() > p1.get_wages();  //���չ��ʽ���
	}
	else
	{
		return p1.get_age() < p2.get_age();    //������������
	}
}
bool cmp_wage_de(Person& p1, Person& p2)
{
	if (p1.get_wages() == p2.get_wages())
	{
		return p1.get_age() > p1.get_age();  //�������併��
	}
	else
	{
		return p1.get_wages() < p2.get_wages();    //���չ��ʽ���
	}
}
bool cmp_wage_ri(Person& p1, Person& p2)
{
	if (p1.get_wages() == p2.get_wages())
	{
		return p1.get_age() > p1.get_age();  //�������併��
	}
	else
	{
		return p1.get_wages() > p2.get_wages();    //���չ�������
	}
}
void all_sort(list<Person>& mylist, PortList*& Port)   //���������������в��ŵ�������
{
	read_count_info(mylist, Port);
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	cout << "��������Ҫ��������Ϣ�ļ������������1�������Ƕ�ĳһ�����Ž�������2����" << endl;
	int count = 0;
	bool flag = true;
	int choice;
	while (count < 3&&flag)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			sort_info(mylist);
			cout << "��ǰ������Ϣ�������������£� " << endl;
			dis_info(mylist);
			flag = false;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			PortList* p, * pre;
			p = Port->next;
			int sum = 1;
			cout << "��ǰ���в������£�������Ҫ���ĸ����Ž������򣺣����벿��ǰ��ţ� " << endl;
			while (p != NULL)
			{
				cout << sum++ <<"\t"<< p->port << endl;
				p = p->next;
			}
			p = Port->next;
			int a;
			cin >> a;
			if (a<1 || a>=sum)
			{
				cout << "������Ĳ��Ų�����,�����²�����" << endl;
				count++;
				break;
			}
			for (int i = 0; i < a-1; i++)
			{
				p = p->next;
			}
			if (p->list.empty())
			{
				cout << "��ǰ������ϢΪ�գ����˳���" << endl;
				return;
			}
			sort_info(p->list);
			cout << "���ţ� " << p->port << " ���������£� " << endl;
			dis_info(p->list);
			flag = false;
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "����������������������" << endl;
			count++;
			system("pause");
			system("cls");
		}
		}
	}
	if (count >= 3)
	{
		cout << "���Ĳ�������������࣬���˳���" << endl;
		return;
	}
}
void sort_info(list<Person>& mylist)  //����
{
	cout << "��������Ҫͨ��ʲô��ʽ��������Ϣ��������" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	int choice;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "��������Ҫ�������併��(1)��������(2)���У�" << endl;
		int b;
	D:	cin >> b;
		if (b == 1)
		{
			mylist.sort(cmp_age_de);
			cout << "��Ϊ���������併������" << endl;
		}
		else if (b == 2)
		{
			mylist.sort(cmp_age_ri);
			cout << "��Ϊ������������������" << endl;
		}
		else
		{
			cout << "���������������������룺" << endl;
			goto D;
		}
		break;
	}
	case 2:
	{
		cout << "��������Ҫ���չ��ʽ���(1)��������(2)���У�" << endl;
		int b;
	E:	cin >> b;
		if (b == 1)
		{
			mylist.sort(cmp_wage_de);
			cout << "��Ϊ�����չ��ʽ�������" << endl;
		}
		else if (b == 2)
		{
			mylist.sort(cmp_wage_ri);
			cout << "��Ϊ�����չ�����������" << endl;
		}
		else
		{
			cout << "���������������������룺" << endl;
			goto E;
		}
		break;
	}
	default:
		cout << "���������������������룡" << endl;
		goto C;
	}
}
void dis_info(list<Person>& mylist)   //չʾδ�����������Ϣ
{
	for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
	{
		it->dis_info();
		cout << endl;
	}
}
void read_count_info(list<Person>& mylist, PortList*&Port) 
{
	PortList *p,*p1,*pre;
	Port = new PortList;
	Port->port = "";
	Port->next = NULL;
	Port->count = 0;
	p = Port->next;
	p1 =pre= p;
	bool flag = false;
	for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
	{
		flag = false;
		if (p == NULL)
		{
			p = new PortList;
			p->port = it->get_port();
			p->count=1;
			p->list.push_back(*it);
			p->next = NULL;
			Port->next = p;
			continue;
		}
		p1 = p;
		while (p1!= NULL)
		{
			if (p1->port == it->get_port())
			{
				p1->count++;
				flag = true;
				p1->list.push_back(*it);
			}
			pre = p1;
			p1 = p1->next;
		}
		if (!flag)
		{
			p1 = new PortList;
			p1->port = it->get_port();
			p1->count = 1;
			p1->next = NULL;
			p1->list.push_back(*it);
			pre->next = p1;
		}
	}
}
void dis_count_info(list<Person>& mylist,PortList*& Port)  //չʾ���в��ŷ�����Ϣ
{
	if (mylist.empty())
	{
		cout << "��ǰ������Ϣ�ļ�Ϊ�ջ�δ���ļ������˳���" << endl;
		return;
	}
	read_count_info(mylist, Port);
	PortList* p, *pre;
	p = Port->next;
	pre = Port;
	cout << "��ǰ������Ϣ����ְλ��������: " << endl;
	while (p != NULL)
	{
		cout << "ְλ�� " << p->port << "ְԱ������ " << p->count << endl;
		for (list<Person>::iterator it = p->list.begin(); it != p->list.end(); it++)
		{
			it->dis_info();
			cout << endl;
		}
		p = p->next;
	} 
}

void input_info()
{
	string Filenamne;
	list<Person> mylist;
	PortList *Port;
	cout << "��������Ҫ���������Ϣ���ĸ��ļ����У� " << endl;
	cin >> Filenamne;
	Filenamne = Filenamne + ".txt";
	ifstream ifs(Filenamne);
	if (!ifs)
	{
		cout << "��ǰ�ļ������ڣ��������Ƿ�Ҫ�������ļ���(Y/N)" << endl;
		char c;
	K:	cin >> c;
		if(c == 'N' || c == 'n')
		{
			cout << "���������Ϣʧ�ܣ�" << endl;
			return;
		}
		else  if (c == 'Y' || c == 'y')
		{}
		else
		{
			cout << "���������������������룺" << endl;
			goto K;
		}
	}
	else
	{
		read_info_temp(mylist, Filenamne);
	}
	string name;
	int age;
	string port;
	float wages;
	string addr;
	string phone_num;
	Person person;
	int sex;
	while (1)
	{
		cout << "���������Ա��������Ϣ��" << endl;
		cout << "������ ";
		cin >> name;
		cout << "���䣺";
	H:	cin >> age;
		if (age <= 0 || age > 150)
		{
			cout << "�������벻�Ϸ�������������" << endl;
			goto H;
		}
		cout << "�Ա� (1-��|0-Ů)";
		cin >> sex;
		cout << "סַ��";
		cin >> addr;
		cout << "ְ��";
		cin >> port;
		cout << "���ʣ�";
		cin >> wages;
		cout << "�ֻ��ţ�(8-11λ����)";
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone_num;
		if (!regex_match(phone_num, pattern))
		{
			cout << "�������벻�Ϸ������������룡" << endl;
			count++;
			if (count < 3)
				goto Z;
			else
			{
				cout << "���Ѷ�δ������룬���˳���" << endl;
				return;
			}
		}
		person.set_name(name);
		person.set_addr(addr);
		person.set_age(age);
		person.set_phone(phone_num);
		person.set_port(port);
		person.set_sex(sex);
		person.set_wages(wages);
		mylist.push_back(person);
		cout << "�������Ƿ�Ҫ��������������Ϣ��(Y/N)" << endl;
		char choice;
	A:	cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			continue;
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "��ǰ������Ϣ���������" << endl;
			break;
		}
		else
		{
			cout << "����������������������" << endl;
			goto A;
		}
	}
	save_info(mylist, Filenamne);
}

void dis_main_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t**************************������Ϣ����ϵͳ***************************" << endl;
	cout << "\t\t\t***\t1����������Ϣ�ļ�\t\t      2�����������Ϣ\t  ***" << endl;
	cout << "\t\t\t***\t3����ѯ������Ϣ\t\t\t      4��ɾ��������Ϣ  \t  ***" << endl;
	cout << "\t\t\t***\t5���޸�������Ϣ\t\t\t      6�����������Ϣ     ***" << endl;
	cout << "\t\t\t***\t7��չʾ������Ϣ\t\t\t      8������������Ϣ     ***" << endl;
	cout << "\t\t\t***\t0���˳�ϵͳ\t\t\t      \t\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}

void func_main(list<Person>& mylist, PortList*& Port)
{
	string Filename;
	while (1)
	{
		dis_main_menu();
		cout << "����������ѡ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			read_info(mylist,Port, Filename);
			cout << "��ǰ������Ϣ�ļ��Ѵ򿪣������������" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			input_info();
			system("pause");
			system("cls");
			break;
		case 3:
			search_info(mylist);
			system("pause");
			system("cls");
			break;
		case 4:
			del_info(mylist, Filename);
			system("pause");
			system("cls");
			break;
		case 5:
			mod_info(mylist, Filename);
			system("pause");
			system("cls");
			break;
		case 6:
			clear_info();
			system("pause");
			system("cls");
			break;
		case 7:
			dis_count_info(mylist,Port);
			system("pause");
			system("cls");
			break;
		case 8:
		{
			all_sort(mylist, Port);
			system("pause");
			system("cls");
			break;
		}
		case 0:
			system("cls");
			cout << "��ӭ�´�ʹ�ñ�ϵͳ��" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "���������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void clear_info()
{
	string filename;
	cout << "��������Ҫ��յ������ļ�����" << endl;
	cin >> filename;
	filename = filename + ".txt";
	ifstream ifs(filename, ios::in);
	if (!ifs)
	{
		cout << "��ǰ������Ϣ�ļ������ڣ��������ִ�б�������" << endl;
		ifs.close();
		return;
	}
	cout << "���ٴ�ȷ�����Ƿ�Ҫ��ո�������Ϣ�ļ���(Y/N)" << endl;
	char choice;
A:	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		ofstream ofs(filename, ios::trunc);
		ofs.close();
		cout << "��ǰ������Ϣ�ļ�����գ�" << endl;
	}
	else if(choice=='n'||choice=='N')
	{
		cout << "����ļ������ѳ�����" << endl;
		return;
	}
	else
	{
		cout << "����������������������" << endl;
		goto A;
	}
}