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
	cout << "��������Ҫ�򿪵�ͨѶ¼���ƣ�" << endl;
	cin >> File_name;
	ifstream ifs;
	User user;
	ifs.open(File_name, ios::in);
	if (!ifs)
	{
		cout << "�������ͨѶ¼�����ڣ�" << endl;
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
			cout << "��ǰͨѶ¼�û���Ϣ���£�" << endl;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				cout << "\t��ţ� " << it->get_No() << " ������ " << it->get_name() << " �绰�� " << it->get_num() << " ���䣺 " << it->get_age() << " סַ�� " << it->get_addr() << endl;
			}
			User_List.clear();
		}
		else
		{
			cout << "��ǰͨѶ¼���û���ϢΪ�գ�" << endl;
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
	cout << "��������Ҫ��Ӽ����û���Ϣ��" << endl;
	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << "��������û���������" << endl;
		return;
	}
	cout << "��������Ҫ�������ݵ�ʲô�ļ���" << endl;
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
		cout << "�������"<<(i+1)<<"���û��ĺ��룺" << endl;
		cout << "(ʾ����13822222222/021-1234567)" << endl;
B:		cin >> phone_num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (regex_match(phone_num, pattern))
		{
			user.set_num(phone_num);
		}
		else
		{
			cout << "������ĵ绰���벻���ϸ�ʽҪ�����������룡" << endl;
			goto B;
		}
		cout << "�������" << (i + 1) << "���û���������" << endl;
		cin >> user_name;
		user.set_name(user_name);
		cout << "�������" << (i + 1) << "���û������䣺" << endl;
	A:	cin >> user_age;
		if (user_age <= 0 || user_age >= 100)
		{
			cout << "���������䲻�Ϸ������������룡" << endl;
			goto A;
		}
		user.set_age(user_age);
		cout << "�������" << (i + 1) << "���û���סַ��" << endl;
		cin >> user_addr;
		user.set_addr(user_addr);

		user.set_No(User::get_sum());

		outfile << user.get_num() << " " << user.get_addr() << " " << user.get_name() << " " << user.get_age() <<" "<<user.get_No()<< endl;
	}
	User::set_sum_0();
	outfile.close();

	cout << "����ɹ���" << endl;

}
bool read_File(list<User>& User_List,string &File_name,int& begin)
{
	string temp="";
	string user_addr;
	string phone_num;
	string user_name;
	int user_No;
	int user_age;
	cout << "��������Ҫ�򿪵�ͨѶ¼���ƣ�" << endl;
	cin >> File_name;
	ifstream ifs;
	User user;
	ifs.open(File_name, ios::in);
	if (!ifs)
	{
		remove(File_name.c_str());
		cout << "�������ͨѶ¼�����ڣ�" << endl;
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
		cout << "��ǰͨѶ¼����Ϊ�գ�" << endl;
		return;
	}
	cout << "����������ͨ��ʲô��ʽ�����û���Ϣ��" << endl;
	cout << "1���û�����" << endl;
	cout << "2���û����" << endl;
	cout << "3���û�����" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		{	string name;
			cout << "��������Ҫ��ѯ���û������� " << endl;
			cin >> name;
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_name() == name)
				{
					cout << "��ѯ�����û���Ϣ��" << endl;
					cout << "\t��ţ� " << it->get_No() << " ������ " << it->get_name() << " �绰�� " << it->get_num() << " ���䣺 " << it->get_age() << " סַ�� " << it->get_addr() << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
			}
			system("pause");
			system("cls");
			break; 
		}
	case 2:
		{
			int no;
			cout << "��������Ҫ��ѯ���û���ţ� " << endl;
			cin >> no;
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_No() == no)
				{
					cout << "��ѯ�����û���Ϣ��" << endl;
					cout << "\t��ţ� " << it->get_No() << " ������ " << it->get_name() << " �绰�� " << it->get_num() << " ���䣺 " << it->get_age() << " סַ�� " << it->get_addr() << endl;
					break;
				}
			}
			if (!flag)
			{
				cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
	case 3:
		{
			string num;
			cout << "��������Ҫ��ѯ���û����룺 " << endl;
		B:	cin >> num;
			regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
			if (!regex_match(num, pattern))
			{
				cout << "������ĵ绰���벻���ϸ�ʽҪ�����������룡" << endl;
				goto B;
			}
			bool flag = false;
			for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
			{
				if (it->get_num() == num)
				{
					cout << "��ѯ�����û���Ϣ��" << endl;
					cout << "\t��ţ� " << it->get_No() << " ������ " << it->get_name() << " �绰�� " << it->get_num() << " ���䣺 " << it->get_age() << " סַ�� " << it->get_addr() << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
	case 0:
		return;
	default:
		cout << "���������������������룡" << endl;
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
		cout << "��ǰͨѶ¼����Ϊ�գ�" << endl;
		return;
	}
	cout << "����������ͨ��ʲô��ʽɾ���û���Ϣ��" << endl;
	cout << "1���û�����" << endl;
	cout << "2���û����" << endl;
	cout << "3���û�����" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	string name;
	cout << "��������Ҫɾ�����û������� " << endl;
	cin >> name;
	bool flag = false;
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		if (it->get_name() == name)
		{
			User_List.erase(it);
			cout << "��ɾ�����û�" << endl;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
	}
	system("pause");
	system("cls");
	break;
	}
	case 2:
	{
		int no;
		cout << "��������Ҫɾ�����û���ţ� " << endl;
		cin >> no;
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_No() == no)
			{
				User_List.erase(it);
				cout << "��ɾ�����û�" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		string num;
		cout << "��������Ҫɾ�����û����룺 " << endl;
	B:	cin >> num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (!regex_match(num, pattern))
		{
			cout << "������ĵ绰���벻���ϸ�ʽҪ�����������룡" << endl;
			goto B;
		}
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_num() == num)
			{
				User_List.erase(it);
				cout << "��ɾ�����û�" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 0:
		return;
	default:
		cout << "���������������������룡" << endl;
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
		cout << "��ǰͨѶ¼����Ϊ�գ�" << endl;
		return;
	}
	cout << "����������ͨ��ʲô��ʽ�޸��û���Ϣ��" << endl;
	cout << "1���û�����" << endl;
	cout << "2���û����" << endl;
	cout << "3���û�����" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	string name;
	cout << "��������Ҫ�޸ĵ��û������� " << endl;
	cin >> name;
	bool flag = false;
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		if (it->get_name() == name)
		{
			cout << "���ҵ����û���Ϣ��" << endl;
			cout << "��������û����º��룺" << endl;
			cin >> phone_num;
			it->set_num(phone_num);
			cout << "��������û�����������" << endl;
			cin >> user_name;
			it->set_name(user_name);
			cout << "��������û��������䣺" << endl;
			cin >> user_age;
			it->set_age(user_age);
			cout << "��������û�����סַ��" << endl;
			cin >> user_addr;
			it->set_addr(user_addr);

			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
	}
	system("pause");
	system("cls");
	break;
	}
	case 2:
	{
		int no;
		cout << "��������Ҫ�޸ĵ��û���ţ� " << endl;
		cin >> no;
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_No() == no)
			{
				cout << "���ҵ����û���Ϣ��" << endl;
				cout << "��������û����º��룺" << endl;
				cin >> phone_num;
				it->set_num(phone_num);
				cout << "��������û�����������" << endl;
				cin >> user_name;
				it->set_name(user_name);
				cout << "��������û��������䣺" << endl;
				cin >> user_age;
				it->set_age(user_age);
				cout << "��������û�����סַ��" << endl;
				cin >> user_addr;
				it->set_addr(user_addr);

				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		string num;
		cout << "��������Ҫ�޸ĵ��û����룺 " << endl;
	B:	cin >> num;
		regex pattern("(\\d{11})|(\\d{3}-\\d{7,8})");
		if (!regex_match(num, pattern))
		{
			cout << "������ĵ绰���벻���ϸ�ʽҪ�����������룡" << endl;
			goto B;
		}
		bool flag = false;
		for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
		{
			if (it->get_num() == num)
			{
				cout << "���ҵ����û���Ϣ��" << endl;
				cout << "��������û����º��룺" << endl;
				cin >> phone_num;
				it->set_num(phone_num);
				cout << "��������û�����������" << endl;
				cin >> user_name;
				it->set_name(user_name);
				cout << "��������û��������䣺" << endl;
				cin >> user_age;
				it->set_age(user_age);
				cout << "��������û�����סַ��" << endl;
				cin >> user_addr;
				it->set_addr(user_addr);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "��ǰ�ļ���δ��ѯ������û���Ϣ!" << endl;
		}
		system("pause");
		system("cls");
		break;
	}
	case 0:
		return;
	default:
		cout << "���������������������룡" << endl;
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
		cout << "��ǰͨѶ¼����Ϊ��,����ִ�д˲�����" << endl;
		return;
	}
	cout << "��ȷ����Ҫ��ո�ͨѶ¼��(Y/N)" << endl;
	char choice;
A:	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		User_List.clear();
		save_File(User_List, File_name);
		cout << "��ǰͨѶ¼����գ�" << endl;
	}
	else if (choice == 'N' || choice == 'n')
	{
		User_List.clear();
		cout << "�ѳ�����ղ�����" << endl;
		return;
	}
	else
	{
		cout << "������������,���������룡" << endl;
		goto A;
	}
}

void merge_File(list<User>& User_List)
{
	cout << "��������Ҫ�ϲ�����ͨѶ¼�ļ���" << endl;
	int n;
	int count = 1;
	int begin = 0;
	cin >> n;
	if (n <= 0)
	{
		cout << "�������ͨѶ¼��������" << endl;
		return;
	}
	string Filename;
	for (int i = 0; i < n; i++)
	{
		cout << "������� " << (i + 1) << " ���ļ�����" << endl;
		bool p=read_File(User_List, Filename, begin);
		if (!p&&count<=3)
		{
			i--;
			count++;
			cout << "����������ͨѶ¼���ƣ�" << endl;
		}
		else
		{
			if (count <= 3)
				remove(Filename.c_str());
			else
			{
				cout << "������ͨѶ¼���ƴ������࣬Ĭ������������ϣ�" << endl;
				break;
			}
		}
	}
	if (User_List.empty())
	{
		cout << "�������ͨѶ¼�ļ����û���Ϣ��Ϊ�գ��޷��ϲ���" << endl;
		return;
	}
	cout << "��������Ҫ������ͨѶ¼�ļ�����Ϣ�ϲ����ĸ�ͨѶ¼�ļ��У�" << endl;
	cin >> Filename;
	ofstream ofs;
	ofs.open(Filename, ios::out);
	for (list<User>::iterator it = User_List.begin(); it != User_List.end(); it++)
	{
		ofs << it->get_num() << " " << it->get_addr() << " " << it->get_name() << " " << it->get_age() << " " << it->get_No() << endl;
	}
	User_List.clear();
	cout << "�ϲ���ϣ�" << endl;
	ofs.close();
}
void dis_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t**************************ͨѶ¼����ϵͳ*****************************" << endl;
	cout << "\t\t\t***\t1����ͨѶ¼\t\t\t      2������û���Ϣ\t  ***" << endl;
	cout << "\t\t\t***\t3����ѯ�û���Ϣ\t\t\t      4��ɾ���û���Ϣ  \t  ***" << endl;
	cout << "\t\t\t***\t5���޸��û���Ϣ\t\t\t      6������û���Ϣ     ***" << endl;
	cout << "\t\t\t***\t7���ϲ��û���Ϣ\t\t\t      0���˳�ϵͳ\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;

}