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
	cout << "请输入您要打开的人事信息文件：" << endl;
	cin >> Filename;
	Filename = Filename + ".txt";
	ifstream ifs(Filename, ios::in);
	while (file_error_count < 3)
	{
		if (!ifs)
		{
			cout << "您输入的人事管理信息文件不存在，请检查后重新输入..." << endl;
			file_error_count++;
			cout << "您现在还有 " << (3 - file_error_count) << "次输入机会" << endl;
			if (file_error_count < 3)
			{
				cout << "请输入您要打开的人事信息文件：" << endl;
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
		cout << "输入错误次数过多，已自动退出！" << endl;
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
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
		return;
	}
	cout << "请输入您要通过什么方式删除人事信息" << endl;
	cout << "1、姓名" << endl;
	cout << "2、电话" << endl;
	string name, phone;
	int choice;
	bool flag = false;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入您要删除的人员姓名： " << endl;
		cin >> name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == name)
			{
				cout << "已找到该用户，请问您是否确认将其删除：(Y/N)" << endl;
				char a;
			A:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					mylist.erase(it);
					cout << "当前人员已删除！" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "已撤销删除操作！" << endl;
				}
				else
				{
					cout << "您的输入有误，请重新输入：" << endl;
					goto A;
				}
				break;
			}
		}
		break;
	}
	case 2:
	{
		cout << "请输入您要删除的人员电话： (8-11位数字)" << endl;
		cin >> phone;
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone;
		if (!regex_match(phone, pattern))
		{
			cout << "您的输入不合法，请重新输入！" << endl;
			count++;
			if (count < 3)
				goto Z;
			else
			{
				cout << "您已多次错误输入，已退出！" << endl;
				return;
			}
		}
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "已找到该用户，请问您是否确认将其删除：(Y/N)" << endl;
				char a;
			B:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					mylist.erase(it);
					cout << "当前人员已删除！" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "已撤销删除操作！" << endl;
				}
				else
				{
					cout << "您的输入有误，请重新输入：" << endl;
					goto B;
				}
				break;
			}
		}
		break;
	}
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		goto C;
	}
	if (flag)
	{
		save_info(mylist,Filename);
	}
	else
	{
		cout << "未在当前人事信息下查找到该人员！" << endl;
	}
}
void save_info(list<Person>& mylist,string &Filename)  //清空文件方式保存信息
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
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
		return;
	}
	cout << "请输入您要通过什么方式查找人事信息" << endl;
	cout << "1、姓名" << endl;
	cout << "2、电话" << endl;
	string name, phone;
	int choice;
	bool flag = false;
A:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入您要查找的人员姓名： " << endl;
		cin >> name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == name)
			{
				cout << "已找到该用户，该用户详细信息如下：" << endl;
				it->dis_info();
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前人事信息文件中未查找到姓名为： "<<name<<"的用户！" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "请输入您要查找的人员电话：(8-11位数字) " << endl;
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone;
		if (!regex_match(phone, pattern))
		{
			cout << "您的输入不合法，请重新输入！" << endl;
			count++;
			if(count<3)
			goto Z;
			else
			{
				cout << "您已多次错误输入，已退出！" << endl;
				return;
			}
		}
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "已找到该用户，该用户详细信息如下：" << endl;
				it->dis_info();
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前人事信息文件中未查找到手机号为： " << phone << "的用户！" << endl;
		}
		break;
	}
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		goto A;
	}
}
void mod_info(list<Person>& mylist,string &Filename)  //修改人事信息
{
	if (mylist.empty())
	{
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
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
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
		return;
	}
	cout << "请输入您要通过什么方式修改人事信息" << endl;
	cout << "1、姓名" << endl;
	cout << "2、电话" << endl;
	string n_name, phone;
	int choice;
	bool flag = false;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入您要修改的人员姓名： " << endl;
		cin >> n_name;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_name() == n_name)
			{
				cout << "已找到该用户，请问您是否确认将其修改：(Y/N)" << endl;
				char a;
			A:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					cout << "请输入该人员的以下信息：" << endl;
					cout << "姓名： ";
					cin >> name;
					cout << "年龄：" ;
				H:	cin >> age;
					if (age <= 0 || age > 150)
					{
						cout << "您的输入不合法，请重新输入" << endl;
						goto H;
					}
					cout << "性别： (1-男|0-女)" ;
					cin >> sex;
					cout << "住址：";
					cin >> addr;
					cout << "职务：";
					cin >> port;
					cout << "工资：";
					cin >> wages;
					cout << "手机号：(8-11位数字)";
					regex pattern("\\d{8,11}");
					int count = 0;
				Z:	cin >> phone_num;
					if (!regex_match(phone_num, pattern))
					{
						cout << "您的输入不合法，请重新输入！" << endl;
						count++;
						if (count < 3)
							goto Z;
						else
						{
							cout << "您已多次错误输入，已退出！" << endl;
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
					cout << "当前用户信息已修改完毕！" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "已撤销修改操作！" << endl;
				}
				else
				{
					cout << "您的输入有误，请重新输入：" << endl;
					goto A;
				}
				break;
			}
		}
		if (!flag)
		{
			cout << "当前人事信息下未找到该人员！" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "请输入您要修改的人员电话： " << endl;
		cin >>phone;
		for (list<Person>::iterator it = mylist.begin(); it != mylist.end(); it++)
		{
			if (it->get_phone() == phone)
			{
				cout << "已找到该用户，请问您是否确认将其修改：(Y/N)" << endl;
				char a;
			B:	cin >> a;
				if (a == 'Y' || a == 'y')
				{
					flag = true;
					cout << "请输入该人员的以下信息：" << endl;
					cout << "姓名： ";
					cin >> name;
					cout << "年龄：";
				R:	cin >> age;
					if (age <= 0 || age > 150)
					{
						cout << "您的输入不合法，请重新输入" << endl;
						goto R;
					}
					cout << "性别： (1-男|0-女)";
					cin >> sex;
					cout << "住址：";
					cin >> addr;
					cout << "职务：";
					cin >> port;
					cout << "工资：";
					cin >> wages;
					cout << "手机号：(8-11位数字)";
					regex pattern("\\d{8,11}");
					int count = 0;
				Y:	cin >> phone_num;
					if (!regex_match(phone_num, pattern))
					{
						cout << "您的输入不合法，请重新输入！" << endl;
						count++;
						if (count < 3)
							goto Y;
						else
						{
							cout << "您已多次错误输入，已退出！" << endl;
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
					cout << "当前用户信息已修改完毕！" << endl;
				}
				else if (a == 'N' || a == 'n')
				{
					cout << "已撤销修改操作！" << endl;
				}
				else
				{
					cout << "您的输入有误，请重新输入：" << endl;
					goto B;
				}
				break;
			}
		}
		if (!flag)
		{
			cout << "当前人事信息下未找到该人员！" << endl;
		}
		break;
	}
	default:
		cout << "您的输入有误，请重新输入！" << endl;
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
		return p1.get_wages ()> p1.get_wages();  //按照工资降序
	}
	else
	{
		return p1.get_age() > p2.get_age();    //按照年龄降序
	}
}
bool cmp_age_ri(Person& p1, Person& p2)
{
	if (p1.get_age() == p2.get_age())
	{
		return p1.get_wages() > p1.get_wages();  //按照工资降序
	}
	else
	{
		return p1.get_age() < p2.get_age();    //按照年龄升序
	}
}
bool cmp_wage_de(Person& p1, Person& p2)
{
	if (p1.get_wages() == p2.get_wages())
	{
		return p1.get_age() > p1.get_age();  //按照年龄降序
	}
	else
	{
		return p1.get_wages() < p2.get_wages();    //按照工资降序
	}
}
bool cmp_wage_ri(Person& p1, Person& p2)
{
	if (p1.get_wages() == p2.get_wages())
	{
		return p1.get_age() > p1.get_age();  //按照年龄降序
	}
	else
	{
		return p1.get_wages() > p2.get_wages();    //按照工资升序
	}
}
void all_sort(list<Person>& mylist, PortList*& Port)   //包括对整体排序还有部门单独排序
{
	read_count_info(mylist, Port);
	if (mylist.empty())
	{
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
		return;
	}
	cout << "请输入您要对人事信息文件整体进行排序（1），还是对某一个部门进行排序（2）？" << endl;
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
			cout << "当前人事信息整体排序结果如下： " << endl;
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
			cout << "当前所有部门如下，请问您要对哪个部门进行排序：（输入部门前序号） " << endl;
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
				cout << "您输入的部门不存在,请重新操作！" << endl;
				count++;
				break;
			}
			for (int i = 0; i < a-1; i++)
			{
				p = p->next;
			}
			if (p->list.empty())
			{
				cout << "当前人事信息为空，已退出！" << endl;
				return;
			}
			sort_info(p->list);
			cout << "部门： " << p->port << " 排序结果如下： " << endl;
			dis_info(p->list);
			flag = false;
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "您的输入有误，请重新输入" << endl;
			count++;
			system("pause");
			system("cls");
		}
		}
	}
	if (count >= 3)
	{
		cout << "您的操作错误次数过多，已退出！" << endl;
		return;
	}
}
void sort_info(list<Person>& mylist)  //排序
{
	cout << "请输入您要通过什么方式对人事信息进行排序" << endl;
	cout << "1、年龄" << endl;
	cout << "2、工资" << endl;
	int choice;
C:	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入您要按照年龄降序(1)还是升序(2)排列：" << endl;
		int b;
	D:	cin >> b;
		if (b == 1)
		{
			mylist.sort(cmp_age_de);
			cout << "已为您按照年龄降序排列" << endl;
		}
		else if (b == 2)
		{
			mylist.sort(cmp_age_ri);
			cout << "已为您按照年龄升序排列" << endl;
		}
		else
		{
			cout << "您的输入有误，请重新输入：" << endl;
			goto D;
		}
		break;
	}
	case 2:
	{
		cout << "请输入您要按照工资降序(1)还是升序(2)排列：" << endl;
		int b;
	E:	cin >> b;
		if (b == 1)
		{
			mylist.sort(cmp_wage_de);
			cout << "已为您按照工资降序排列" << endl;
		}
		else if (b == 2)
		{
			mylist.sort(cmp_wage_ri);
			cout << "已为您按照工资升序排列" << endl;
		}
		else
		{
			cout << "您的输入有误，请重新输入：" << endl;
			goto E;
		}
		break;
	}
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		goto C;
	}
}
void dis_info(list<Person>& mylist)   //展示未分类的人事信息
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
void dis_count_info(list<Person>& mylist,PortList*& Port)  //展示所有部门分类信息
{
	if (mylist.empty())
	{
		cout << "当前人事信息文件为空或未打开文件，已退出！" << endl;
		return;
	}
	read_count_info(mylist, Port);
	PortList* p, *pre;
	p = Port->next;
	pre = Port;
	cout << "当前人事信息按照职位分类如下: " << endl;
	while (p != NULL)
	{
		cout << "职位： " << p->port << "职员总数： " << p->count << endl;
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
	cout << "请输入您要添加人事信息到哪个文件名中： " << endl;
	cin >> Filenamne;
	Filenamne = Filenamne + ".txt";
	ifstream ifs(Filenamne);
	if (!ifs)
	{
		cout << "当前文件不存在，请问您是否要创建新文件？(Y/N)" << endl;
		char c;
	K:	cin >> c;
		if(c == 'N' || c == 'n')
		{
			cout << "添加人事信息失败！" << endl;
			return;
		}
		else  if (c == 'Y' || c == 'y')
		{}
		else
		{
			cout << "您的输入有误，请重新输入：" << endl;
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
		cout << "请输入该人员的以下信息：" << endl;
		cout << "姓名： ";
		cin >> name;
		cout << "年龄：";
	H:	cin >> age;
		if (age <= 0 || age > 150)
		{
			cout << "您的输入不合法，请重新输入" << endl;
			goto H;
		}
		cout << "性别： (1-男|0-女)";
		cin >> sex;
		cout << "住址：";
		cin >> addr;
		cout << "职务：";
		cin >> port;
		cout << "工资：";
		cin >> wages;
		cout << "手机号：(8-11位数字)";
		regex pattern("\\d{8,11}");
		int count = 0;
	Z:	cin >> phone_num;
		if (!regex_match(phone_num, pattern))
		{
			cout << "您的输入不合法，请重新输入！" << endl;
			count++;
			if (count < 3)
				goto Z;
			else
			{
				cout << "您已多次错误输入，已退出！" << endl;
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
		cout << "请问您是否还要继续输入人事信息？(Y/N)" << endl;
		char choice;
	A:	cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			continue;
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "当前人事信息已输入完毕" << endl;
			break;
		}
		else
		{
			cout << "您的输入有误，请重新输入" << endl;
			goto A;
		}
	}
	save_info(mylist, Filenamne);
}

void dis_main_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t**************************人事信息管理系统***************************" << endl;
	cout << "\t\t\t***\t1、打开人事信息文件\t\t      2、添加人事信息\t  ***" << endl;
	cout << "\t\t\t***\t3、查询人事信息\t\t\t      4、删除人事信息  \t  ***" << endl;
	cout << "\t\t\t***\t5、修改人事信息\t\t\t      6、清空人事信息     ***" << endl;
	cout << "\t\t\t***\t7、展示人事信息\t\t\t      8、排序人事信息     ***" << endl;
	cout << "\t\t\t***\t0、退出系统\t\t\t      \t\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}

void func_main(list<Person>& mylist, PortList*& Port)
{
	string Filename;
	while (1)
	{
		dis_main_menu();
		cout << "请输入您的选择" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			read_info(mylist,Port, Filename);
			cout << "当前人事信息文件已打开，请继续操作！" << endl;
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
			cout << "欢迎下次使用本系统！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void clear_info()
{
	string filename;
	cout << "请输入您要清空的人事文件名：" << endl;
	cin >> filename;
	filename = filename + ".txt";
	ifstream ifs(filename, ios::in);
	if (!ifs)
	{
		cout << "当前人事信息文件不存在，请检查后再执行本操作！" << endl;
		ifs.close();
		return;
	}
	cout << "请再次确认您是否要清空该人事信息文件？(Y/N)" << endl;
	char choice;
A:	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		ofstream ofs(filename, ios::trunc);
		ofs.close();
		cout << "当前人事信息文件已清空！" << endl;
	}
	else if(choice=='n'||choice=='N')
	{
		cout << "清空文件操作已撤销！" << endl;
		return;
	}
	else
	{
		cout << "您的输入有误，请重新输入" << endl;
		goto A;
	}
}