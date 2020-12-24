#pragma once
#include"File_operation.h"

void input_flight(Flight& F)
{
	string f_no;  //航班编号
	FTime time_begin, time_end;  //起降时间
	float f_price;  //票价
	string loc_begin, loc_end;  //起降地点
	float f_disc;  //折扣
	int f_num;  //当前已定人数
	int f_maxsize;  //最大乘坐人数
	int m_year;
	int m_month;
	int m_day;
	int m_hours;
	int m_minite;

A:	cout << "请输入航班编号: （如：CZ3151）" << endl;
	cin >> f_no;
	regex pattern("\\w{2}\\d{4}");
	if (regex_match(f_no, pattern))
	{
		F.set_no(f_no);
	}
	else
	{
		cout << "您输入的航班号不合法,请重新输入！" << endl;
		goto A;
	}
	cout << "请输入起飞时间信息：" << endl;
B:	cout << "请依次输入起飞时间的年、月、日、时、分信息：" << endl;
	cin >> m_year >> m_month >> m_day >> m_hours >> m_minite;
	if (time_begin.is_legal(m_year, m_month, m_day, m_hours, m_minite))
		time_begin.set_time(m_year, m_month, m_day, m_hours, m_minite);
	else
	{
		cout << "您输入的起飞时间信息有误，请重新输入！" << endl;
		goto B;
	}
	cout << "请输入降落时间信息：" << endl;
C:	cout << "请依次输入降落时间的年、月、日、时、分信息：" << endl;
	cin >> m_year >> m_month >> m_day >> m_hours >> m_minite;
	if (time_end.is_legal(m_year, m_month, m_day, m_hours, m_minite))
		time_end.set_time(m_year, m_month, m_day, m_hours, m_minite);
	else
	{
		cout << "您输入的降落时间信息有误，请重新输入！" << endl;
		goto C;
	}
	F.set_time(time_begin, time_end);
	cout << "请输入起飞城市：" << endl;
	cin >> loc_begin;
	cout << "请输入降落城市：" << endl;
	cin >> loc_end;
	F.set_loc(loc_begin, loc_end);
D:		cout << "请输入航班票价： " << endl;
	cin >> f_price;
	if (f_price < 0)
	{
		cout << "您输入的航班票价不合法，请重新输入！" << endl;
		goto D;
	}
	else
	{
		F.set_price(f_price);
	}
E:		cout << "请输入航班折扣： " << endl;
	cin >> f_disc;
	if (f_disc < 0)
	{
		cout << "您输入的航班折扣不合法，请重新输入！" << endl;
		goto E;
	}
	else
	{
		F.set_disc(f_disc);
	}
F:		cout << "请输入当前航班最大载人数：" << endl;
	cin >> f_maxsize;
	if (f_maxsize <= 0)
	{
		cout << "您输入的最大载人数不合法，请重新输入！" << endl;
		goto F;
	}
	else
	{
		F.set_maxsize(f_maxsize);
	}
G:		cout << "请输入当前已订票人数：" << endl;
	cin >> f_num;
	if (f_num <= 0 || f_num > f_maxsize)
	{
		cout << "您输入的已定票人数不合法，请重新输入！" << endl;
		goto G;
	}
	else
	{
		F.set_num(f_num);
	}
}
void buy_ticket_no(Flight_list_head* f_head, Flight& F, string no ,int c_num)
{
	Flight_list_node* p = f_head->head;
	while (p != NULL && p->flight.get_no() != no)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未查询到航班号为 " << no << " 的航班信息" << endl;
	}
	else
	{
		if (p->flight.get_num() < p->flight.get_maxsize()&&c_num<(p->flight.get_maxsize()-p->flight.get_num()))
		{
			cout << "已为您购买到航班号为： " << no << " 的航班" << endl;
			F = p->flight;
			p->flight.set_num(p->flight.get_num()+c_num);
			cout << "航班信息为：" << endl;
			p->flight.dis_flight();
			savefile_flight(f_head);
			init_flight(f_head);
		}
		else
			cout << "当前航班已无满足您需求的座位" << endl;
	}
}
void search_path(Flight_list_head* f_head, string loc_begin, string loc_end,queue<queue<Flight>>&Path)
{
	bool flag = true;
	Flight_list_node* p = f_head->head;
	queue<Flight> path;
	queue<Flight_list_node*> start;
	while (p != NULL)
	{
		if (p->flight.get_begin_loc() == loc_begin)
		{
			start.push(p);
		}
		p = p->next;
	}
	while (!start.empty())
	{
		flag = true;
		p = f_head->head;
		Flight_list_node* temp = start.front();
		start.pop();
		loc_begin = temp->flight.get_end_loc();
		path.push(temp->flight);
		while (flag)
		{
			while (p != NULL && p->flight.get_begin_loc() != loc_begin)
			{
				p = p->next;
			}
			if (p == NULL)
			{
				while (!path.empty())
				{
					path.pop();
				}
				break;
				flag = false;
			}
			else
			{
				path.push(p->flight);
				loc_begin = p->flight.get_end_loc();
				p = f_head->head;
			}
			if (loc_begin == loc_end)
			{
				queue<Flight> p;
				while (!path.empty())
				{
					p.push(path.front());
					path.pop();
				}
				Path.push(p);
				flag = false;
				break;
			}
		}
	}
}

void buy_ticket_loc(Flight_list_head* f_head, Flight& F, string loc_begin, string loc_end,int c_num)
{
	bool flag = false;
	Flight_list_node* p = f_head->head;
	while (p != NULL && !(p->flight.get_begin_loc() == loc_begin && p->flight.get_end_loc() == loc_end))
	{
		p = p->next;
	}
	if (p == NULL)
	{

	}
	else
	{
		if (p->flight.get_num() < p->flight.get_maxsize()&&c_num<=(p->flight.get_maxsize()-p->flight.get_num()))
		{
			cout << "已为您购买到该航班" << endl;
			cout << "航班信息为： " << endl;
			F = p->flight;
			p->flight.set_num(p->flight.get_num() + c_num);
			p->flight.dis_flight();
			savefile_flight(f_head);
			init_flight(f_head);
			flag = true;
		}
		else
			cout << "当前航班已无满足您需求的座位" << endl;
	}
	if (!flag)
	{
		queue<queue<Flight>> Path;
		search_path(f_head, loc_begin, loc_end,Path);
		if (!Path.empty())
		{
			cout << "已为您推荐以下航班：" << endl;
			while (!Path.empty())
			{
				queue<Flight> path = Path.front();
				Path.pop();
				while (!path.empty())
				{
					Flight f = path.front();
					path.pop();
					if (path.empty())
						cout << "航班编号 " << f.get_no() << endl;
					else
						cout << "航班编号 " << f.get_no() << " ->";
				}
			}
		}
		else
		{
			cout << "目前暂无合适航班可以满足您的路线" << endl;
		}
	}
}
bool input_client(Client& C, Flight_list_head* f_head)
{
	string c_name;  //客户姓名
	string c_idcard;  //身份证号
	int c_num;  //订票数量
	Flight c_flight;  //所定航班
	string c_no;  //订单编号
	
	cout << "请输入客户姓名：" << endl;
	cin >> c_name;
	C.set_name(c_name);
A:	cout << "请输入客户的身份证号：" << endl;
	cin >> c_idcard;
	regex pattern("\\d{17}(x|\\d)");
	if (regex_match(c_idcard, pattern))
	{
		C.set_idcard(c_idcard);
	}
	else
	{
		cout << "您的身份证号输入有误，请重新输入！" << endl;
		goto A;
	}

D:	cout << "请输入您要订几张机票：" << endl;
	cin >> c_num;
	if (c_num <= 0 )
	{
		cout << "您输入的票的数量不合法！" << endl;
		goto D;
	}
	else
	{
		C.set_num(c_num);
	}

	cout << "请输入您要通过什么方式购买机票：" << endl;
	cout << "1、航班号" << endl;
	cout << "2、起降地点" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入航班号： " << endl;
		string c_no;
	B:		cin >> c_no;
		regex pattern("\\w{2}\\d{4}");
		if (regex_match(c_no, pattern))
			buy_ticket_no(f_head, c_flight, c_no,c_num);
		else
		{
			cout << "您输入的航班号不合法,请重新输入！" << endl;
			goto B;
		}
		break;
	}
	case 2:
		cout << "请输入起飞地点：" << endl;
		string loc_begin, loc_end;
		cin >> loc_begin;
		cout << "请输入降落地点：" << endl;
		cin >> loc_end;
		buy_ticket_loc(f_head, c_flight, loc_begin, loc_end,c_num);
		break;
	}
	if (c_flight.get_maxsize() == 0)
	{
		cout << "未购买到机票！" << endl;
		system("pause");
		system("cls");
		return false;
	}
	C.set_flight(c_flight);

	//获取目前时间
	time_t nowtime;  //创建一个time_t对象（一个64位时间变量）
	struct tm p; //系统定义的一个时间结构体，里面有年、月、日等属性
	time(&nowtime);  //获取目前时间
	localtime_s(&p, &nowtime);  //将日历时间转成本地时间存放到p中
#pragma warning(suppress : 4996)//关闭警告
	
	srand((int)time(0));
	int time = (p.tm_year - 100) * 1000000 + (p.tm_mon + 1) * 10000 + (p.tm_mday) * 100 + (random(99) + 10);
	c_no = to_string(time);
	C.set_no(c_no);

	return true;
}

void pushback_client(Client_list_head* c_head, Flight_list_head* f_head) //添加乘客信息
{
	init_client(c_head);
	init_flight(f_head);
	readfile_flight(f_head);
	readfile_client(c_head);
	system("cls");
	Client_list_Node* head = c_head->head;
	Client_list_Node* pre = head;
	while (head != NULL)
	{
		pre = head;
		head = head->next;
	}
	bool flag = true;
	bool flag2,flag1=false;
	while (1)
	{
		if (flag)
		{
			if (pre == head)
			{
				head = new Client_list_Node;
				cout << "请输入乘客信息：" << endl;
				c_head->num++;
				flag2=input_client(head->client, f_head);
				if (flag2)
				{
					head->next = NULL;
					c_head->head = head;
					pre = head;
					head = pre->next;
					flag1 = true;
				}
			}
			else
			{
				head = new Client_list_Node;
				cout << "请输入乘客信息：" << endl;
				c_head->num++;
				flag2 = input_client(head->client, f_head);
				if (flag2)
				{
					head->next = NULL;
					pre->next = head;
					pre = head;
					head = pre->next;
					flag1 = true;
				}
			}
		}
		cout << "请问您还要继续添加乘客信息么？(Y/N)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'Y':
		case 'y':
			flag = true;
			break;
		case 'N':
		case 'n':
			if (flag1)
			{
				savefile_client(c_head);
				cout << "乘客信息已添加完毕！" << endl;
			}
			else
			{
				cout << "当前未添加任何乘客信息！" << endl;
			}
			init_client(c_head);
			init_flight(f_head);
			return;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			flag = false;
		}
	}
}
void pushback_flight(Flight_list_head* f_head)  //添加航班信息
{
	init_flight(f_head);
	readfile_flight(f_head);
	system("cls");
	Flight_list_node* head = f_head->head;
	Flight_list_node* pre = head;
	while (head != NULL)
	{
		pre = head;
		head = head->next;
	}
	bool flag = true;
	while (1)
	{
		if (flag)
		{
			if (pre == head)
			{
				head = new Flight_list_node;
				cout << "请输入航班信息：" << endl;
				f_head->num++;
				input_flight(head->flight);
				head->next = NULL;
				f_head->head = head;
				pre = head;
				head = pre->next;
			}
			else
			{
				head = new Flight_list_node;
				cout << "请输入航班信息：" << endl;
				f_head->num++;
				input_flight(head->flight);
				head->next = NULL;
				pre->next = head;
				pre = head;
				head = pre->next;
			}
		}
		cout << "请问您还要继续添加航班信息么？(Y/N)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'Y':
		case 'y':
			flag = true;
			break;
		case 'N':
		case 'n':
			savefile_flight(f_head);
			init_flight(f_head);
			cout << "航班信息已添加完毕！" << endl;
			return;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			flag = false;
		}
	}
}
void savefile_flight(Flight_list_head* f_head)
{
	if (f_head->head == NULL)
	{
		return;
	}
	ofstream ofs("flight_info.txt", ios::out | ios::trunc);
	Flight_list_node* p = f_head->head;
	while (p != NULL)
	{
		Flight f = p->flight;
		FTime begin = p->flight.get_begin_time();
		FTime end = p->flight.get_end_time();
		ofs << f.get_no() << " " << f.get_begin_loc() << " " << f.get_end_loc() << " " << f.get_price() << " " << f.get_disc() << " " << f.get_num() << " " << f.get_maxsize() << endl;
		ofs << begin.get_year() << " " << begin.get_month() << " " << begin.get_day() << " " << begin.get_hour() << " " << begin.get_minite() << endl;
		ofs << end.get_year() << " " << end.get_month() << " " << end.get_day() << " " << end.get_hour() << " " << end.get_minite() << endl;
		p = p->next;
	}
	ofs.close();
}
bool readfile_flight(Flight_list_head* f_head)
{
	init_flight(f_head);
	ifstream ifs("flight_info.txt", ios::in);
	if (!ifs)
	{
		cout << "当前航班信息文件不存在！" << endl;
		return false;
	}
	string f_no;  //航班编号
	FTime time_begin, time_end;  //起降时间
	float f_price;  //票价
	string loc_begin, loc_end;  //起降地点
	float f_disc;  //折扣
	int f_num;  //当前已定人数
	int f_maxsize;  //最大乘坐人数
	int m_year_b, m_year_e;
	int m_month_b, m_month_e;
	int m_day_b, m_day_e;
	int m_hours_b, m_hours_e;
	int m_minite_b, m_minite_e;
	string no_temp = "NULL";
	Flight_list_node* head = f_head->head;
	Flight_list_node* pre = head;
	while (!ifs.eof())
	{
		ifs >> f_no >> loc_begin >> loc_end >> f_price >> f_disc >> f_num >> f_maxsize >> m_year_b >> m_month_b >> m_day_b >> m_hours_b >> m_minite_b >> m_year_e >> m_month_e >> m_day_e >> m_hours_e >> m_minite_e;
		if (f_no == "")
		{
			f_head->head = NULL;
			return true;
		}
		if (f_no != no_temp)
		{
			time_begin.set_time(m_year_b, m_month_b, m_day_b, m_hours_b, m_minite_b);
			time_end.set_time(m_year_e, m_month_e, m_day_e, m_hours_e, m_minite_e);
			head = new Flight_list_node;
			Flight temp = head->flight;
			temp.set_flight(f_no, time_begin, time_end, loc_begin, loc_end, f_price, f_disc, f_num, f_maxsize);
			head->next = NULL;
			head->flight = temp;
			if (pre == NULL)
				f_head->head = head;
			else
				pre->next = head;
			pre = head;
			head = head->next;
			f_head->num++;
			no_temp = f_no;
		}
		else
		{
			break;
		}
	}
	ifs.close();
	return true;
}
void savefile_client(Client_list_head* c_head)
{
	if (c_head->head == NULL)
	{
		return;
	}
	Flight c_flight;  //所定航班
	Client_list_Node* head = c_head->head;
	Client p;
	ofstream ofs("client_info.txt", ios::out | ios::trunc);
	while (head != NULL)
	{
		p = head->client;
		ofs << p.get_name() << " " << p.get_idcard() << " " << p.get_no() << " " << p.get_num() << endl;
		Flight f = p.get_flight();
		FTime begin, end;
		begin = f.get_begin_time();
		end = f.get_end_time();
		ofs << "\t" << f.get_no() << " " << f.get_begin_loc() << " " << f.get_end_loc() << " " << f.get_price() << " " << f.get_disc() << " " << f.get_num() << " " << f.get_maxsize() << endl;
		ofs << "\t" << begin.get_year() << " " << begin.get_month() << " " << begin.get_day() << " " << begin.get_hour() << " " << begin.get_minite() << endl;
		ofs << "\t" << end.get_year() << " " << end.get_month() << " " << end.get_day() << " " << end.get_hour() << " " << end.get_minite() << endl;
		head = head->next;
	}
	ofs.close();
}

bool readfile_client(Client_list_head* c_head)
{
	init_client(c_head);
	ifstream ifs("client_info.txt", ios::in);
	if (!ifs)
	{
		cout << "当前客户文件为不存在！" << endl;
		return false;
	}
	string f_no;  //航班编号
	FTime time_begin, time_end;  //起降时间
	float f_price;  //票价
	string loc_begin, loc_end;  //起降地点
	float f_disc;  //折扣
	int f_num;  //当前已定人数
	int f_maxsize;  //最大乘坐人数
	string c_name;  //客户姓名
	string c_idcard;  //身份证号
	string c_no;  //订单编号
	int c_num;  //订票数量
	int m_year_b, m_year_e;
	int m_month_b, m_month_e;
	int m_day_b, m_day_e;
	int m_hours_b, m_hours_e;
	int m_minite_b, m_minite_e;
	string no_temp = "NULL";
	Client_list_Node* head = c_head->head;
	Client_list_Node* pre = c_head->head;
	while (!ifs.eof())
	{
		ifs >> c_name >> c_idcard >> c_no >> c_num;
		ifs >> f_no >> loc_begin >> loc_end >> f_price >> f_disc >> f_num >> f_maxsize >> m_year_b >> m_month_b >> m_day_b >> m_hours_b >> m_minite_b >> m_year_e >> m_month_e >> m_day_e >> m_hours_e >> m_minite_e;
		if (c_name == "")
		{
			c_head->head = NULL;
			return true;
		}
		if (no_temp != c_no)
		{
			time_begin.set_time(m_year_b, m_month_b, m_day_b, m_hours_b, m_minite_b);
			time_end.set_time(m_year_e, m_month_e, m_day_e, m_hours_e, m_minite_e);
			head = new Client_list_Node;
			Flight temp;
			temp.set_flight(f_no, time_begin, time_end, loc_begin, loc_end, f_price, f_disc, f_num, f_maxsize);
			head->client.set_client(c_name, c_idcard, c_no, c_num, temp);
			if (pre == NULL)
			{
				c_head->head = head;
			}
			else
			{
				pre->next = head;
			}
			head->next = NULL;
			pre = head;
			head = head->next;
			c_head->num++;
			no_temp = c_no;
		}
		else
		{
			break;
		}
	}
	ifs.close();
	return true;
}
void search_flight_loc(Flight_list_node* p, string loc_begin, string loc_end)
{
	queue<Flight> flight_list;
	while (p != NULL &&!( p->flight.get_begin_loc() == loc_begin && p->flight.get_end_loc() == loc_end))
	{
		flight_list.push(p->flight);
		p = p->next;
	}
	if (flight_list.empty())
	{
		cout << "未查询到航班信息！" << endl;
	}
	else
	{
		cout << "查询到以下航班信息" << endl;
		while (!flight_list.empty())
		{
			Flight flight = flight_list.front();
			flight_list.pop();
			flight.dis_flight();
			cout << endl << endl;
		}

	}
}
void search_flight_no(Flight_list_node* p, string no)
{
	queue<Flight> flight_list;
	while (p != NULL && !(p->flight.get_no()==no))
	{
		flight_list.push(p->flight);
		p = p->next;
	}
	if (flight_list.empty())
	{
		cout << "未查询到航班信息！" << endl;
	}
	else
	{
		cout << "查询到以下航班信息" << endl;
		while (!flight_list.empty())
		{
			Flight flight = flight_list.front();
			flight_list.pop();
			flight.dis_flight();
			cout << endl << endl;
		}

	}
}

void search_flight(Flight_list_head* f_head)
{
	Flight_list_node* head = f_head->head;
A:	cout << "请输入您要通过什么方式来查询航班：" << endl;
	cout << "1、航班号" << endl;
	cout << "2、起降地点" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	cout << "请输入您要查询的航班号：" << endl;
	string no;
	cin >> no;
	search_flight_no(head, no);
	system("pause");
	system("cls");
	break;
	}
	case 2:
	{
		string loc_begin, loc_end;
		cout << "请输入起飞地点" << endl;
		cin >> loc_begin;
		cout << "请输入降落地点" << endl;
		cin >> loc_end;
		search_flight_loc(head, loc_begin, loc_end);
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
		goto A;
	}
}

void delete_flight(Flight_list_head* f_head, Flight flight)
{
	Flight_list_node* p = f_head->head;
	while (p->flight.get_no()!=flight.get_no())
	{
		p = p->next;
	}
	p->flight.set_num(p->flight.get_num() - 1);
	savefile_flight(f_head);
}
void refund_ticket(Client_list_head*& c_head, Flight_list_head* f_head)  //退票
{
	init_client(c_head);
	init_flight(f_head);
	bool flag1 = readfile_client(c_head);
	if (!flag1)
	{
		return;
	}
	Client_list_Node* p1 = c_head->head;
	if (p1 == NULL)
	{
		cout << "当前并没有客户购买机票！" << endl;
		system("pause");
		system("cls");
		return;
	}
	readfile_flight(f_head);
	cout << "请输入您的身份证号以验证您的身份：" << endl;
	string idcard;
	cin >> idcard;
	regex pattern("\\d{17}(x|\\d)");
	queue<Client_list_Node*> c;
	Client_list_Node* p = c_head->head;
	Flight flight;
	if (regex_match(idcard, pattern))
	{
		while (p != NULL)
		{
			if (p->client.get_idcard() == idcard)
			{
				c.push(p);
			}
			p = p->next;
		}
		if (c.empty())
		{
			cout << "未查询到该客户信息！" << endl;
			cout << "请检查信息是否正确后再次执行本操作" << endl;
			return;
		}
		else
		{
			cout << "已查询到该客户信息，请继续执行以下操作" << endl;
		}
	}
	cout << "请输入您要通过什么方式退票：" << endl;
	cout << "1、订单编号" << endl;
	cout << "2、航班号" << endl;
	int choice;
	cin >> choice;
	bool flag = true;
	while (flag)
	{
		switch (choice)
		{
		case 1:
		{
			cout << "请输入您要退票的订单编号：" << endl;
			string no;
			cin >> no;
			while (!c.empty())
			{
				Client_list_Node* p = c.front();
				c.pop();
				if (p->client.get_no() == no)
				{
					cout << "已查找到该订单号的机票，请问您是否要退掉它(Y/N)" << endl;
					char choice;
A:					cin >> choice;
					if (choice == 'Y' || choice == 'y')
					{
						Client_list_Node* p1 = c_head->head;
						flight = p->client.get_flight();
						if (p1 == p)
						{
							c_head->head = p->next;
							delete p;
						}
						else
						{
							while (p1->next != p)
							{
								p1 = p1->next;
							}
							p1->next = p->next;
							delete p;
						}

						delete_flight(f_head, flight);
						savefile_client(c_head);
						init_client(c_head);
						init_flight(f_head);
						cout << "当前退票手续已办理成功！" << endl;
						system("pause");
						system("cls");
						flag = false;
					}
					else if (choice == 'N' || choice == 'n')
					{
						cout << "已撤销退票操作！" << endl;
						system("pause");
						system("cls");
						return;
					}
					else
					{
						cout << "您的输入有误，请重新输入！" << endl;
						system("pause");
						system("cls");
						goto A;
					}
				}
			}
			break;
		}
		case 2:
		{
			cout << "请输入您要退票的航班号：" << endl;
			string no;
			cin >> no;
			while (!c.empty())
			{
				Client_list_Node* p = c.front();
				c.pop();
				if (p->client.get_flight().get_no() == no)
				{
					cout << "已查找到该航班号的机票，请问您是否要退掉它(Y/N)" << endl;
					char choice;
B:					cin >> choice;
					if (choice == 'Y' || choice == 'y')
					{
						Client_list_Node* p1 = c_head->head;
						flight = p->client.get_flight();
						if (p1 == p)
						{
							c_head->head = p->next;
							delete p;
						}
						else
						{
							while (p1->next != p)
							{
								p1 = p1->next;
							}
							p1->next = p->next;
							delete p;
						}
						delete_flight(f_head, flight);
						savefile_client(c_head);
						init_client(c_head);
						init_flight(f_head);
						cout << "当前退票手续已办理成功！" << endl;
						flag = false;
					}
				}
				else if (choice == 'N' || choice == 'n')
				{
					cout << "已撤销退票操作！" << endl;
					system("pause");
					system("cls");
					return;
				}
				else
				{
					cout << "您的输入有误，请重新输入！" << endl;
					system("pause");
					system("cls");
					goto B;
				}
			}
			break;
		}
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			cin >> choice;
			system("pause");
			system("cls");
			break;
		}
	}

}

void search_client(Client_list_head* c_head)
{
	init_client(c_head);
	bool flag=readfile_client(c_head);
	if (!flag)
	{
		return;
	}
	Client_list_Node* p = c_head->head;
	if (p == NULL)
	{
		cout << "当前客户信息为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您的身份证号以查询信息" << endl;
	string idcard;
	cin >> idcard;
	regex pattern("\\d{17}(x|\\d)");
	if (regex_match(idcard, pattern))
	{
		while (p != NULL&&p->client.get_idcard()!=idcard)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "未查询到该客户信息" << endl;
			init_client(c_head);
			return;
		}
		else
		{
			cout << "已查询到该客户信息，信息如下：" << endl;
			p->client.dis_client();
			system("pause");
			system("cls");
			init_client(c_head);
		}
	}

}
void modi_flight(Flight_list_head*& f_head)//修改航班信息
{
	init_flight(f_head);
	bool flag1 = readfile_flight(f_head);
	if (!flag1)
	{
		return;
	}
	Flight_list_node* p1 = f_head->head;
	if (p1 == NULL)
	{
		cout << "当前文件无任何航班信息！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要修改航班的航班号：" << endl;
	string no;
A:	cin >> no;
	regex pattern("\\w{2}\\d{4}");
	if (regex_match(no, pattern))
	{
		while (p1 != NULL && p1->flight.get_no() != no)
		{
			p1 = p1->next;
		}
		if (p1 == NULL)
		{
			cout << "未查询到航班号为 " << no << " 的航班信息" << endl;
			cout << "请检查后再执行本操作" << endl;
			return;
		}
		else
		{
			cout << "已查询到该航班" << endl;
			p1->flight.mod_flight();
			savefile_flight(f_head);
			init_flight(f_head);
		}
	}
	else
	{
		cout << "您输入的航班号不合法，请重新输入！" << endl;
		goto A;
	}
}
void modi_client(Client_list_head*& c_head)//修改乘客信息
{
	init_client(c_head);
	bool flag = readfile_client(c_head);
	if (!flag)
	{
		return;
	}
	Client_list_Node* p = c_head->head;
	if (p == NULL)
	{
		cout << "当前客户信息为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
A:	cout << "请输入您的身份证号以查询信息" << endl;
	string idcard;
	cin >> idcard;
	regex pattern("\\d{17}(x|\\d)");
	if (regex_match(idcard, pattern))
	{
		while (p != NULL && p->client.get_idcard() != idcard)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "未查询到该客户信息" << endl;
			init_client(c_head);
			return;
		}
		else
		{
			cout << "已查询到该客户" << endl;
			p->client.mod_client();
			savefile_client(c_head);
			init_client(c_head);
		}
	}
	else
	{
		cout << "您输入的身份证号不合法，请重新输入！" << endl;
		goto A;
	}
}
void dis_flight_info(Flight_list_head*& f_head)
{
	Flight_list_node* p = f_head->head;
	cout << "当前所有航班信息如下" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	while (p != NULL)
	{
		p->flight.dis_flight();
		cout << endl;
		p = p->next;
	}
	cout << "---------------------------------------------------------------------" << endl;
}
void dis_client_info(Client_list_head*& c_head)
{
	Client_list_Node* p = c_head->head;
	cout << "当前所有乘客信息如下：" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	while (p != NULL)
	{
		p->client.dis_client();
		cout << endl;
		p = p->next;
	}
	cout << "---------------------------------------------------------------------" << endl;
}
void init_list(Client_list_head*& c_head, Flight_list_head*& f_head)
{
	c_head = new Client_list_head;
	f_head = new Flight_list_head;
	c_head->head = NULL;
	f_head->head = NULL;
	c_head->num = 0;
	f_head->num = 0;
}
void init_flight(Flight_list_head*& f_head)
{
	Flight_list_node* p = f_head->head;
	Flight_list_node* pre = p;
	while (p != NULL)
	{
		p = p->next;
		delete pre;
		pre = p;
	}
	delete pre;
	f_head->head = NULL;
	f_head->num = 0;
}
void init_client(Client_list_head*& c_head)
{
	Client_list_Node* p = c_head->head;
	Client_list_Node* pre = p;
	while (p != NULL)
	{
		p = p->next;
		delete pre;
		pre = p;
	}
	delete pre;
	c_head->head = NULL;
	c_head->num = 0;
}
