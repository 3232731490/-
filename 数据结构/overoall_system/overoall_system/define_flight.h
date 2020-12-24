#pragma once
#include<string>
#include<iostream>
#include<ctime>
#include<regex>
#include<queue>
#include<fstream>
#include<cstdio>
#define random(x) rand()%x

using namespace std;

class FTime {
public:
	FTime();
	FTime(int year, int month, int day, int hours, int minte);
	void set_time(int year, int month, int day, int hours, int minte);
	bool mod_Time();
	void dis_time();
	bool is_legal(int year, int month, int day, int hours, int minte);
	bool is_day_legal(int year, int month, int day);
	bool is_leap(int year);
	int get_year();
	int get_month();
	int get_day();
	int get_hour();
	int get_minite();
private:
	int m_year;
	int m_month;
	int m_day;
	int m_hours;
	int m_minite;
};

class Flight {
public:
	Flight();
	Flight(string no, FTime t_begin, FTime t_end, string l_begin, string l_end, float price, float disc, int num, int maxsize);
	void set_flight(string no, FTime t_begin, FTime t_end, string l_begin, string l_end, float price, float disc, int num, int maxsize);
	void dis_flight();
	void mod_flight();
	void set_no(string no);
	void set_time(FTime begin, FTime end);
	void set_price(float price);
	void set_loc(string begin, string end);
	void set_disc(float disc);
	void set_num(int num);
	void set_maxsize(int maxsize);

	string get_no();
	FTime get_begin_time();
	FTime get_end_time();
	float get_price();
	string get_begin_loc();
	string get_end_loc();
	float get_disc();
	int get_num();
	int get_maxsize();
private:
	string f_no;  //航班编号
	FTime time_begin, time_end;  //起降时间
	float f_price;  //票价
	string loc_begin, loc_end;  //起降地点
	float f_disc;  //折扣
	int f_num;  //当前已定人数
	int f_maxsize;  //最大乘坐人数
};

class Client {

public:
	Client();
	Client(string name, string id, string no, int num, Flight flight);
	void set_client(string name, string id, string no, int num, Flight flight);
	void dis_client();
	void mod_client();
	void set_name(string name);
	void set_idcard(string id);
	void set_no(string no);
	void set_num(int num);
	void set_flight(Flight flight);

	string get_name();
	string get_idcard();
	string get_no();
	int get_num();
	Flight get_flight();

private:
	string c_name;  //客户姓名
	string c_idcard;  //身份证号
	string c_no;  //订单编号
	int c_num;  //订票数量
	Flight c_flight;  //所定航班
};

struct Flight_list_node {   //航班数据链表节点
	Flight flight;  //航班信息
	Flight_list_node* next;  //下一个航班节点
};

struct Flight_list_head { //航班数据链表头
	Flight_list_node* head;  //头指针
	int num;   //航班总数
};
struct Client_list_Node { //客户数据链表节点
	Client client;  //客户信息
	Client_list_Node* next;   //下一个客户
};
struct Client_list_head {
	Client_list_Node* head;  //头
	int num;  //客户总数
};

