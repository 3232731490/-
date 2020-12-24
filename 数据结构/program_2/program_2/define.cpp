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
	cout << " 航班号： " << f_no << " 起飞时间： ";
	time_begin.dis_time();
	cout << " 降落时间： ";
	time_end.dis_time();
	cout << endl;
	cout << " 起飞城市： " << loc_begin << " 抵达城市： " << loc_end << endl;
	cout << " 航班票价： " << f_price << "  航班折扣： " << f_disc << endl;
	cout << " 当前已定票人数： " << f_num << " 该航班最大乘坐人数： " <<f_maxsize<<"\n"<< ((f_num > f_maxsize) ? "（当前航班已无空余座位！）" : "当前航班还有空余座位！") << endl;
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

	cout << "请选择您要修改航班的什么信息：" << endl;
	cout << "1、航班号： " << endl;
	cout << "2、起降时间：" << endl;
	cout << "3、起降城市： " << endl;
	cout << "4、航班票价： " << endl;
	cout << "5、航班折扣： " << endl;
	cout << "6、当前已定票人数： " << endl;
	cout << "7、该航班最大乘坐人数： " << endl;
	cout << "0、退出" << endl;
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
			cout << "请输入航班编号: （如：CZ3151）" << endl;
			cin >> f_no;
			regex pattern("\\w{2}\\d{4}");
			if (regex_match(f_no, pattern))
			{
				set_no(f_no);
				flag = false;
			}
			else
			{
				cout << "您输入的航班号不合法,请重新输入！" << endl;
			}
			break;
		}
		case 2:
			cout << "请输入起飞时间信息：" << endl;
			if (!time_begin.mod_Time())
			{
				flag1 = false;
			}
			cout << "请输入降落时间信息：" << endl;
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
				cout << "您输入的起降时间不合法，请重新输入！" << endl;
			}
			break;
		case 3:
			cout << "请输入起飞城市：" << endl;
			cin >> loc_begin;
			cout << "请输入降落城市：" << endl;
			cin >> loc_end;
			set_loc(loc_begin, loc_end);
			break;
		case 4:
			cout << "请输入航班票价： " << endl;
			cin >> f_price;
			if (f_price < 0)
			{
				cout << "您输入的航班票价不合法，请重新输入！" << endl;
			}
			else
			{
				set_price(f_price);
				flag = false;
			}
			break;
		case 5:
			cout << "请输入航班折扣： " << endl;
			cin >> f_disc;
			if (f_disc < 0)
			{
				cout << "您输入的航班折扣不合法，请重新输入！" << endl;
			}
			else
			{
				set_disc(f_disc);
				flag = false;
			}
			break;
		case 6:
			cout << "请输入当前已订票人数：" << endl;
			cin >> f_num;
			if (f_num <= 0 || f_num > this->f_maxsize)
			{
				cout << "您输入的已定票人数不合法，请重新输入！" << endl;
			}
			else
			{
				flag = false;
				set_num(f_num);
			}
			break;
		case 7:
			cout << "请输入当前航班最大载人数：" << endl;
			cin >> f_maxsize;
			if (f_maxsize <= 0)
			{
				cout << "您输入的最大载人数不合法，请重新输入！" << endl;
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
			cout << "您的选择有误，请重新输入！" << endl;
			cin >> choice;
			break;
		}
	}
	cout << "当前航班信息已修改完毕，修改后的航班信息为：" << endl;
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
	cout << "请输入您要修改的新的航班时间：" << endl;
	cout << "请依次输入年、月、日、小时、分钟" << endl;
	cin >> m_year >> m_month >> m_day >> m_hours >> m_minite;

	if (is_legal(m_year, m_month, m_day, m_hours, m_minite))
	{
		set_time(m_year, m_month, m_day, m_hours, m_minite);
		return true;
	}
	else
	{
		cout << "您输入的时间不合法！" << endl;
		return false;
	}
}
void FTime::dis_time()
{
	cout << m_year << " 年 " << m_month << " 月 " << m_day << " 日 " << m_hours << " 时 " << m_minite << " 分 ";
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

	//获取目前时间
	time_t nowtime;  //创建一个time_t对象（一个64位时间变量）
	struct tm p; //系统定义的一个时间结构体，里面有年、月、日等属性
	time(&nowtime);  //获取目前时间
	localtime_s(&p,&nowtime);  //将日历时间转成本地时间存放到p中
#pragma warning(suppress : 4996)//关闭警告
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
	cout << "客户姓名： " << c_name << "\n身份证号： " << c_idcard << "\n订单编号： " << c_no << "\n航班信息： ";
	c_flight.dis_flight();
}

void Client::mod_client()
{
	string c_name;  //客户姓名
	string c_idcard;  //身份证号
	string c_no;  //订单编号
	int c_num;  //订票数量
	Flight c_flight;  //所定航班
	cout << "请输入新的客户信息：" << endl;
	cout << "请选择您要修改客户的什么信息：" << endl;

	cout << "1、姓名：" << endl;
	cout << "2、身份证号： " << endl;
	cout << "3、航班信息： " << endl;
	cout << "4、订单数量：" << endl;
	cout << "0、退出" << endl;
	int choice;
	cin >> choice;
	bool flag = true;
	while (flag)
	{
		switch (choice)
		{
		case 1:
			cout << "请输入客户姓名：" << endl;
			cin >> c_name;
			set_name(c_name);
			flag = false;
			break;
		case 2:
		{
			cout << "请输入客户的身份证号：" << endl;
			cin >> c_no;
			regex pattern("\\d{17}(x|\\d)");
			if (regex_match(c_no, pattern))
			{
				set_no(c_no);
				flag = false;
			}
			else
			{
				cout << "您的身份证号输入有误，请重新输入！" << endl;
			}
			break;
		}
		case 3:
			this->c_flight.mod_flight();
			flag = false;
			break;
		case 4:
			cout << "请输入您新的订票数量：" << endl;
			cin >> c_num;
			if (c_num < 0)
			{
				cout << "您输入的订票数量有误，请重新输入！" << endl;
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
			cout << "您的输入有误，请重新输入！" << endl;
			cin >> choice;
			break;
		}
	}
	
	cout << "当前客户信息已修改完毕！" << endl;
	cout << "修改后的客户信息为：" << endl;
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