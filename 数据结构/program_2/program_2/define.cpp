#include"define.h"

Flight::Flight()
{
	f_no = "000000";
	f_price = 0;
	f_disc = 0;
	f_num = 0;
	loc_begin = loc_end = "NULL";
	f_maxsize = 0;
}
Flight::Flight(string no, FTime t_begin, FTime t_end, string l_begin, string l_end, float price, float disc, int num, int maxsize)
{
	f_no = no;
	time_begin = t_begin;
	time_end = t_end;
	f_price = price;
	f_disc = disc;
	loc_begin = l_begin;
	loc_end = l_end;
	f_num = num;
	f_maxsize = maxsize;
}

void Flight::set_flight(string no, FTime t_begin, FTime t_end, string l_begin, string l_end, float price, float disc, int num,int maxsize)
{
	f_no = no;
	time_begin = t_begin;
	time_end = t_end;
	f_price = price;
	f_disc = disc;
	loc_begin = l_begin;
	loc_end = l_end;
	f_num = num;
	f_maxsize = maxsize;
}
void Flight::dis_flight()
{
	cout << " ����ţ� " << f_no << " ���ʱ�䣺 ";
	time_begin.dis_time();
	cout << " ����ʱ�䣺 ";
	time_end.dis_time();
	cout << endl;
	cout << " ��ɳ��У� " << loc_begin << " �ִ���У� " << loc_end << endl;
	cout << " ����Ʊ�ۣ� " << f_price << "  �����ۿۣ� " << f_disc << endl;
	cout << " ��ǰ�Ѷ�Ʊ������ " << f_num << " �ú��������������� " <<f_maxsize<<"\n"<< ((f_num > f_maxsize) ? "����ǰ�������޿�����λ����" : "��ǰ���໹�п�����λ��") << endl;
}

void Flight::mod_flight()
{
	string f_no;
	FTime time_begin, time_end;
	float f_price;
	string loc_begin, loc_end;
	float f_disc;
	int f_num;
	int f_maxsize;

	cout << "��ѡ����Ҫ�޸ĺ����ʲô��Ϣ��" << endl;
	cout << "1������ţ� " << endl;
	cout << "2����ʱ�䣺" << endl;
	cout << "3���𽵳��У� " << endl;
	cout << "4������Ʊ�ۣ� " << endl;
	cout << "5�������ۿۣ� " << endl;
	cout << "6����ǰ�Ѷ�Ʊ������ " << endl;
	cout << "7���ú��������������� " << endl;
	cout << "0���˳�" << endl;
	int choice;
	cin >> choice;
	bool flag = true;
	while (flag)
	{
		bool flag1 = true;
		switch (choice)
		{
		case 1:
		{	
			cout << "�����뺽����: ���磺CZ3151��" << endl;
			cin >> f_no;
			regex pattern("\\w{2}\\d{4}");
			if (regex_match(f_no, pattern))
			{
				set_no(f_no);
				flag = false;
			}
			else
			{
				cout << "������ĺ���Ų��Ϸ�,���������룡" << endl;
			}
			break;
		}
		case 2:
			cout << "���������ʱ����Ϣ��" << endl;
			if (!time_begin.mod_Time())
			{
				flag1 = false;
			}
			cout << "�����뽵��ʱ����Ϣ��" << endl;
			if (time_end.mod_Time())
			{
				flag1 = false;
			}
			if (flag1)
			{
				set_time(time_begin, time_end);
				flag = false;
			}
			else
			{
				cout << "���������ʱ�䲻�Ϸ������������룡" << endl;
			}
			break;
		case 3:
			cout << "��������ɳ��У�" << endl;
			cin >> loc_begin;
			cout << "�����뽵����У�" << endl;
			cin >> loc_end;
			set_loc(loc_begin, loc_end);
			break;
		case 4:
			cout << "�����뺽��Ʊ�ۣ� " << endl;
			cin >> f_price;
			if (f_price < 0)
			{
				cout << "������ĺ���Ʊ�۲��Ϸ������������룡" << endl;
			}
			else
			{
				set_price(f_price);
				flag = false;
			}
			break;
		case 5:
			cout << "�����뺽���ۿۣ� " << endl;
			cin >> f_disc;
			if (f_disc < 0)
			{
				cout << "������ĺ����ۿ۲��Ϸ������������룡" << endl;
			}
			else
			{
				set_disc(f_disc);
				flag = false;
			}
			break;
		case 6:
			cout << "�����뵱ǰ�Ѷ�Ʊ������" << endl;
			cin >> f_num;
			if (f_num <= 0 || f_num > this->f_maxsize)
			{
				cout << "��������Ѷ�Ʊ�������Ϸ������������룡" << endl;
			}
			else
			{
				flag = false;
				set_num(f_num);
			}
			break;
		case 7:
			cout << "�����뵱ǰ���������������" << endl;
			cin >> f_maxsize;
			if (f_maxsize <= 0)
			{
				cout << "�������������������Ϸ������������룡" << endl;
			}
			else
			{
				flag = false;
				set_maxsize(f_maxsize);
			}
			break;
		case 0:
			return;
		default:
			cout << "����ѡ���������������룡" << endl;
			cin >> choice;
			break;
		}
	}
	cout << "��ǰ������Ϣ���޸���ϣ��޸ĺ�ĺ�����ϢΪ��" << endl;
	this->dis_flight();
}

void Flight::set_no(string no)
{
	f_no = no;
}
void Flight::set_time(FTime begin, FTime end)
{
	time_begin = begin;
	time_end = end;
}
void Flight::set_price(float price)
{
	f_price = price;
}
void Flight::set_loc(string begin, string end)
{
	loc_begin = begin;
	loc_end = end;
}
void Flight::set_disc(float disc)
{
	f_disc = disc;
}
void Flight::set_num(int num)
{
	f_num = num;
}
void Flight::set_maxsize(int maxsize)
{
	f_maxsize = maxsize;
}

string  Flight::get_no()
{
	return f_no;
}
FTime  Flight::get_begin_time()
{
	return time_begin;
}
FTime  Flight::get_end_time()
{
	return time_end;
}
float  Flight::get_price()
{
	return f_price;
}
string  Flight::get_begin_loc()
{
	return loc_begin;
}
string  Flight::get_end_loc()
{
	return loc_end;
}
float  Flight::get_disc()
{
	return f_disc;
}
int  Flight::get_num()
{
	return f_num;
}
int  Flight::get_maxsize()
{
	return f_maxsize;
}

FTime::FTime()
{
	m_year = 0;
	m_month = 0;
	m_day = 0;
	m_hours = 0;
	m_minite = 0;
}
FTime::FTime(int year, int month, int day, int hours, int minte)
{
	m_year = year;
	m_month = month;
	m_day = day;
	m_hours = hours;
	m_minite = minte;
}
void FTime::set_time(int year, int month, int day, int hours, int minte)
{
	m_year = year;
	m_month = month;
	m_day = day;
	m_hours = hours;
	m_minite = minte;
}
bool FTime::mod_Time()
{
	int m_year;
	int m_month;
	int m_day;
	int m_hours;
	int m_minite;
	cout << "��������Ҫ�޸ĵ��µĺ���ʱ�䣺" << endl;
	cout << "�����������ꡢ�¡��ա�Сʱ������" << endl;
	cin >> m_year >> m_month >> m_day >> m_hours >> m_minite;

	if (is_legal(m_year, m_month, m_day, m_hours, m_minite))
	{
		set_time(m_year, m_month, m_day, m_hours, m_minite);
		return true;
	}
	else
	{
		cout << "�������ʱ�䲻�Ϸ���" << endl;
		return false;
	}
}
void FTime::dis_time()
{
	cout << m_year << " �� " << m_month << " �� " << m_day << " �� " << m_hours << " ʱ " << m_minite << " �� ";
}
int FTime::get_year()
{
	return m_year;
}
int FTime::get_month()
{
	return m_month;
}
int FTime::get_day()
{
	return m_day;
}
int FTime::get_hour()
{
	return m_hours;
}
int FTime::get_minite()
{
	return m_minite;
}
bool FTime::is_legal(int year, int month, int day, int hours, int minite)
{

	//��ȡĿǰʱ��
	time_t nowtime;  //����һ��time_t����һ��64λʱ�������
	struct tm p; //ϵͳ�����һ��ʱ��ṹ�壬�������ꡢ�¡��յ�����
	time(&nowtime);  //��ȡĿǰʱ��
	localtime_s(&p,&nowtime);  //������ʱ��ת�ɱ���ʱ���ŵ�p��
#pragma warning(suppress : 4996)//�رվ���
	bool flag = true;
	if (year<(p.tm_year+1900) || year>(p.tm_year + 1901) || month<p.tm_mon || month>(p.tm_mon + 3)||month>12 || hours <= 0 || hours > 24 || minite <= 0 || minite > 60||day<0)
	{
		flag = false;
	}
	if (flag)
	{ 
		if (day < p.tm_mday||!is_day_legal(year, month, day))
			flag = false;
	}
	return flag;
}
bool FTime::is_day_legal(int year, int month,int day)
{
	if (is_leap(year))
	{
		if (month == 2)
		{
			if (day > 29)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (month == 2)
		{
			if (day > 28)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	switch (month)
	{
	case 1:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 3:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 4:
		if (day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 5:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 6:
		if (day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 7:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 8:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
	case 9:
		if (day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 10:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 11:
		if (day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	case 12:
		if (day > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	}
}
bool FTime::is_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Client::Client()
{
	c_name = "NULL";
	c_idcard = "NULL";
	c_no = "NULL";
	c_num = 0;
}
Client::Client(string name, string id, string no, int num, Flight flight)
{
	c_name = name;
	c_idcard = id;
	c_no = no;
	c_num = num;
	c_flight = flight;
}

void Client::dis_client()
{
	cout << "�ͻ������� " << c_name << "\n���֤�ţ� " << c_idcard << "\n������ţ� " << c_no << "\n������Ϣ�� ";
	c_flight.dis_flight();
}

void Client::mod_client()
{
	string c_name;  //�ͻ�����
	string c_idcard;  //���֤��
	string c_no;  //�������
	int c_num;  //��Ʊ����
	Flight c_flight;  //��������
	cout << "�������µĿͻ���Ϣ��" << endl;
	cout << "��ѡ����Ҫ�޸Ŀͻ���ʲô��Ϣ��" << endl;

	cout << "1��������" << endl;
	cout << "2�����֤�ţ� " << endl;
	cout << "3��������Ϣ�� " << endl;
	cout << "4������������" << endl;
	cout << "0���˳�" << endl;
	int choice;
	cin >> choice;
	bool flag = true;
	while (flag)
	{
		switch (choice)
		{
		case 1:
			cout << "������ͻ�������" << endl;
			cin >> c_name;
			set_name(c_name);
			flag = false;
			break;
		case 2:
		{
			cout << "������ͻ������֤�ţ�" << endl;
			cin >> c_no;
			regex pattern("\\d{17}(x|\\d)");
			if (regex_match(c_no, pattern))
			{
				set_no(c_no);
				flag = false;
			}
			else
			{
				cout << "�������֤�������������������룡" << endl;
			}
			break;
		}
		case 3:
			this->c_flight.mod_flight();
			flag = false;
			break;
		case 4:
			cout << "���������µĶ�Ʊ������" << endl;
			cin >> c_num;
			if (c_num < 0)
			{
				cout << "������Ķ�Ʊ�����������������룡" << endl;
			}
			else
			{
				set_num(c_num);
				flag = false;
			}
			break;
		case 0:
			return;
		default:
			cout << "���������������������룡" << endl;
			cin >> choice;
			break;
		}
	}
	
	cout << "��ǰ�ͻ���Ϣ���޸���ϣ�" << endl;
	cout << "�޸ĺ�Ŀͻ���ϢΪ��" << endl;
	dis_client();
}
void Client::set_name(string name)
{
	c_name = name;
}
void Client::set_idcard(string id)
{
	c_idcard = id;
}
void Client::set_no(string no)
{
	c_no = no;
}
void Client::set_num(int num)
{
	c_num = num;
}
void Client::set_flight(Flight flight)
{
	c_flight = flight;
}
void Client::set_client(string name, string id, string no, int num, Flight flight)
{
	c_flight = flight;
	c_name = name;
	c_no = no;
	c_idcard = id;
	c_num = num;
}

string Client::get_name()
{
	return c_name;
}
string Client::get_idcard()
{
	return c_idcard;
}
string Client::get_no()
{
	return c_no;
}
int Client::get_num()
{
	return c_num;
}
Flight Client::get_flight()
{
	return c_flight;
}