#include"function.h"

void open_File(list<User> &User_List)
{
	string File_name;
	string user_addr;
	string phone_num;
	string temp="";
	string user_name;
	int user_No;
	int user_age;
	cout << "请输入您要打开的通讯录名称：" << endl;
	cin >> File_name;
	ifstream ifs;
	User user;
	ifs.open(File_name, ios::in);
	if (!ifs)
	{
		cout << "你输入的通讯录不存在！" << endl;
		return;
	}
	else
	{
		
		while (!ifs.eof())
		{
			ifs >> phone_num >> user_addr >> user_name >> user_age >> user_No;
			user.set_addr(user_addr);
			user.set_num(phone_num);
			user.set_name(user_name);
			user.set_age(user_age);
			user.set_No(user_No);
			if (temp != phone_num)
				User_List.push_back(user);
			temp = phone_num;
		}
		ifs.close();
		if (!User_List.empty())
		{
			cout << "当前通讯录用户信息如下：" << endl;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				cout << "\t编号： " << it->get_No() << " 姓名： " << it->get_name() << " 电话： " << it->get_num() << " 年龄： " << it->get_age() << " 住址： " << it->get_addr() << endl;
			}
			User_List.clear();
		}
		else
		{
			cout << "当前通讯录下用户信息为空！" << endl;
			return;
		}
	}
}
void save_File(list<User>& User_List ,string Filename)
{
	ofstream ofs;
	ofs.open(Filename, ios::trunc);
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		ofs<< it->get_num() << " " << it->get_addr() << " " << it->get_name() << " " << it->get_age() << " " << it->get_No() << endl;
	}
	ofs.close();
}
void add_File()
{
	int user_No;
	string temp = "";
	string File_name;
	string phone_num;
	string user_name;
	int user_age;
	string user_addr;
	User user;
	cout << "请输入您要添加几个用户信息：" << endl;
	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << "您输入的用户个数有误！" << endl;
		return;
	}
	cout << "请输入您要保存数据到什么文件名" << endl;
	cin >> File_name;
	ofstream outfile;
	ifstream ifs;
	ifs.open(File_name, ios::in);
	if(ifs){
		while (!ifs.eof())
		{
			ifs >> phone_num >> user_addr >> user_name >> user_age >> user_No;
			if (temp != phone_num)
				User::add_User();
			temp = phone_num;
		}
	}
	ifs.close();
	outfile.open(File_name, ios::out | ios::app);
	for (int i = 0; i < n; i++)
	{
		User::add_User();
		cout << "请输入第"<<(i+1)<<"个用户的号码：" << endl;
		cout << "(示例：13822222222/021-1234567)" << endl;
B:		cin >> phone_num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (regex_match(phone_num, pattern))
		{
			user.set_num(phone_num);
		}
		else
		{
			cout << "您输入的电话号码不符合格式要求，请重新输入！" << endl;
			goto B;
		}
		cout << "请输入第" << (i + 1) << "个用户的姓名：" << endl;
		cin >> user_name;
		user.set_name(user_name);
		cout << "请输入第" << (i + 1) << "个用户的年龄：" << endl;
	A:	cin >> user_age;
		if (user_age <= 0 || user_age >= 100)
		{
			cout << "您输入年龄不合法，请重新输入！" << endl;
			goto A;
		}
		user.set_age(user_age);
		cout << "请输入第" << (i + 1) << "个用户的住址：" << endl;
		cin >> user_addr;
		user.set_addr(user_addr);

		user.set_No(User::get_sum());

		outfile << user.get_num() << " " << user.get_addr() << " " << user.get_name() << " " << user.get_age() <<" "<<user.get_No()<< endl;
	}
	User::set_sum_0();
	outfile.close();

	cout << "保存成功！" << endl;

}
bool read_File(list<User>& User_List,string &File_name,int& begin)
{
	string temp="";
	string user_addr;
	string phone_num;
	string user_name;
	int user_No;
	int user_age;
	cout << "请输入您要打开的通讯录名称：" << endl;
	cin >> File_name;
	ifstream ifs;
	User user;
	ifs.open(File_name, ios::in);
	if (!ifs)
	{
		remove(File_name.c_str());
		cout << "你输入的通讯录不存在！" << endl;
		return false;
	}
	while (!ifs.eof())
	{
		ifs >> phone_num >> user_addr >> user_name >> user_age >> user_No;
		user.set_addr(user_addr);
		user.set_num(phone_num);
		user.set_name(user_name);
		user.set_age(user_age);
		user.set_No(user_No+begin);
		if(temp!=phone_num)
			User_List.push_back(user);
		temp = phone_num;
	}
	begin = User_List.size();
	ifs.close();
	return true;
}
void search_info(list<User> &User_List)
{
	int begin = 0;
	string File_name;
	if (!read_File(User_List, File_name, begin))
	{
		return;
	}
	if (User_List.empty())
	{
		cout << "当前通讯录内容为空！" << endl;
		return;
	}
	cout << "请输入您想通过什么方式查找用户信息：" << endl;
	cout << "1、用户姓名" << endl;
	cout << "2、用户编号" << endl;
	cout << "3、用户号码" << endl;
	cout << "0、退出" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		{	string name;
			cout << "请输入您要查询的用户姓名： " << endl;
			cin >> name;
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_name() == name)
				{
					cout << "查询到该用户信息：" << endl;
					cout << "\t编号： " << it->get_No() << " 姓名： " << it->get_name() << " 电话： " << it->get_num() << " 年龄： " << it->get_age() << " 住址： " << it->get_addr() << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "当前文件中未查询到相关用户信息!" << endl;
			}
			system("pause");
			system("cls");
			break; 
		}
	case 2:
		{
			int no;
			cout << "请输入您要查询的用户编号： " << endl;
			cin >> no;
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_No() == no)
				{
					cout << "查询到该用户信息：" << endl;
					cout << "\t编号： " << it->get_No() << " 姓名： " << it->get_name() << " 电话： " << it->get_num() << " 年龄： " << it->get_age() << " 住址： " << it->get_addr() << endl;
					break;
				}
			}
			if (!flag)
			{
				cout << "当前文件中未查询到相关用户信息!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
	case 3:
		{
			string num;
			cout << "请输入您要查询的用户号码： " << endl;
		B:	cin >> num;
			regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
			if (!regex_match(num, pattern))
			{
				cout << "您输入的电话号码不符合格式要求，请重新输入！" << endl;
				goto B;
			}
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_num() == num)
				{
					cout << "查询到该用户信息：" << endl;
					cout << "\t编号： " << it->get_No() << " 姓名： " << it->get_name() << " 电话： " << it->get_num() << " 年龄： " << it->get_age() << " 住址： " << it->get_addr() << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "当前文件中未查询到相关用户信息!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
	case 0:
		return;
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		system("pause");
		system("cls");
		break;
	}
}

void del_User(list<User>& User_List)
{
	int begin = 0;
	string File_name;
	if (!read_File(User_List, File_name, begin))
	{
		return;
	}
	if (User_List.empty())
	{
		cout << "当前通讯录内容为空！" << endl;
		return;
	}
	cout << "请输入您想通过什么方式删除用户信息：" << endl;
	cout << "1、用户姓名" << endl;
	cout << "2、用户编号" << endl;
	cout << "3、用户号码" << endl;
	cout << "0、退出" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	string name;
	cout << "请输入您要删除的用户姓名： " << endl;
	cin >> name;
	bool flag = false;
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		if (it->get_name() == name)
		{
			User_List.erase(it);
			cout << "已删除该用户" << endl;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "当前文件中未查询到相关用户信息!" << endl;
	}
	system("pause");
	system("cls");
	break;
	}
	case 2:
	{
		int no;
		cout << "请输入您要删除的用户编号： " << endl;
		cin >> no;
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_No() == no)
			{
				User_List.erase(it);
				cout << "已删除该用户" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前文件中未查询到相关用户信息!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		string num;
		cout << "请输入您要删除的用户号码： " << endl;
	B:	cin >> num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (!regex_match(num, pattern))
		{
			cout << "您输入的电话号码不符合格式要求，请重新输入！" << endl;
			goto B;
		}
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_num() == num)
			{
				User_List.erase(it);
				cout << "已删除该用户" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前文件中未查询到相关用户信息!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 0:
		return;
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		system("pause");
		system("cls");
		break;
	}
	save_File(User_List,File_name);
	User_List.clear();
}

void mod_User(list<User>& User_List)
{
	string phone_num;
	string user_name;
	int user_age;
	string user_addr;
	int begin = 0;
	string File_name;
	if (!read_File(User_List, File_name, begin))
	{
		return;
	}
	if (User_List.empty())
	{
		cout << "当前通讯录内容为空！" << endl;
		return;
	}
	cout << "请输入您想通过什么方式修改用户信息：" << endl;
	cout << "1、用户姓名" << endl;
	cout << "2、用户编号" << endl;
	cout << "3、用户号码" << endl;
	cout << "0、退出" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	string name;
	cout << "请输入您要修改的用户姓名： " << endl;
	cin >> name;
	bool flag = false;
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		if (it->get_name() == name)
		{
			cout << "已找到该用户信息：" << endl;
			cout << "请输入该用户的新号码：" << endl;
			cin >> phone_num;
			it->set_num(phone_num);
			cout << "请输入该用户的新姓名：" << endl;
			cin >> user_name;
			it->set_name(user_name);
			cout << "请输入该用户的新年龄：" << endl;
			cin >> user_age;
			it->set_age(user_age);
			cout << "请输入该用户的新住址：" << endl;
			cin >> user_addr;
			it->set_addr(user_addr);

			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "当前文件中未查询到相关用户信息!" << endl;
	}
	system("pause");
	system("cls");
	break;
	}
	case 2:
	{
		int no;
		cout << "请输入您要修改的用户编号： " << endl;
		cin >> no;
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_No() == no)
			{
				cout << "已找到该用户信息：" << endl;
				cout << "请输入该用户的新号码：" << endl;
				cin >> phone_num;
				it->set_num(phone_num);
				cout << "请输入该用户的新姓名：" << endl;
				cin >> user_name;
				it->set_name(user_name);
				cout << "请输入该用户的新年龄：" << endl;
				cin >> user_age;
				it->set_age(user_age);
				cout << "请输入该用户的新住址：" << endl;
				cin >> user_addr;
				it->set_addr(user_addr);

				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前文件中未查询到相关用户信息!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		string num;
		cout << "请输入您要修改的用户号码： " << endl;
	B:	cin >> num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (!regex_match(num, pattern))
		{
			cout << "您输入的电话号码不符合格式要求，请重新输入！" << endl;
			goto B;
		}
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_num() == num)
			{
				cout << "已找到该用户信息：" << endl;
				cout << "请输入该用户的新号码：" << endl;
				cin >> phone_num;
				it->set_num(phone_num);
				cout << "请输入该用户的新姓名：" << endl;
				cin >> user_name;
				it->set_name(user_name);
				cout << "请输入该用户的新年龄：" << endl;
				cin >> user_age;
				it->set_age(user_age);
				cout << "请输入该用户的新住址：" << endl;
				cin >> user_addr;
				it->set_addr(user_addr);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "当前文件中未查询到相关用户信息!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 0:
		return;
	default:
		cout << "您的输入有误，请重新输入！" << endl;
		system("pause");
		system("cls");
		break;
	}
	save_File(User_List, File_name);
	User_List.clear();
}
void clear_User(list<User>& User_List)
{
	int begin = 0;
	string File_name;
	if (!read_File(User_List, File_name, begin))
	{
		return;
	}
	if (User_List.empty())
	{
		cout << "当前通讯录内容为空,无需执行此操作！" << endl;
		return;
	}
	cout << "您确定您要清空该通讯录吗？(Y/N)" << endl;
	char choice;
A:	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		User_List.clear();
		save_File(User_List, File_name);
		cout << "当前通讯录已清空！" << endl;
	}
	else if (choice == 'N' || choice == 'n')
	{
		User_List.clear();
		cout << "已撤销清空操作！" << endl;
		return;
	}
	else
	{
		cout << "您的输入有误,请重新输入！" << endl;
		goto A;
	}
}

void merge_File(list<User>& User_List)
{
	cout << "请输入您要合并几个通讯录文件：" << endl;
	int n;
	int count = 1;
	int begin = 0;
	cin >> n;
	if (n <= 0)
	{
		cout << "您输入的通讯录个数有误！" << endl;
		return;
	}
	string Filename;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第 " << (i + 1) << " 个文件名：" << endl;
		bool p=read_File(User_List, Filename, begin);
		if (!p&&count<=3)
		{
			i--;
			count++;
			cout << "请重新输入通讯录名称：" << endl;
		}
		else
		{
			if (count <= 3)
				remove(Filename.c_str());
			else
			{
				cout << "您输入通讯录名称次数过多，默认您已输入完毕！" << endl;
				break;
			}
		}
	}
	if (User_List.empty())
	{
		cout << "您输入的通讯录文件内用户信息均为空，无法合并！" << endl;
		return;
	}
	cout << "请输入您要将以上通讯录文件内信息合并到哪个通讯录文件中：" << endl;
	cin >> Filename;
	ofstream ofs;
	ofs.open(Filename, ios::out);
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		ofs << it->get_num() << " " << it->get_addr() << " " << it->get_name() << " " << it->get_age() << " " << it->get_No() << endl;
	}
	User_List.clear();
	cout << "合并完毕！" << endl;
	ofs.close();
}
void dis_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t**************************通讯录管理系统*****************************" << endl;
	cout << "\t\t\t***\t1、打开通讯录\t\t\t      2、添加用户信息\t  ***" << endl;
	cout << "\t\t\t***\t3、查询用户信息\t\t\t      4、删除用户信息  \t  ***" << endl;
	cout << "\t\t\t***\t5、修改用户信息\t\t\t      6、清空用户信息     ***" << endl;
	cout << "\t\t\t***\t7、合并用户信息\t\t\t      0、退出系统\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;

}