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

/*

题目2、 订票系统 
（1）问题描述 
通过此系统可以实现如下功能： 1）录入：可以录入航班情况（数据可以存储在一个数据文件中，数据结构、具体数据自定）
 2）查询：可以查询某个航线的情况（如，输入航班号，查询起降时间，起飞抵达城市，航班票价，票价折扣，确定航班是否满仓）； 
 可以输入起飞抵达城市，查询飞机航班情况； 
 3）订票：（订票情况可以存在一个数据文件中，结构自己设定）可以订票，如果该航班已经无票，可以提供相关可选择航班；  
 4）退票： 可退票，退票后修改相关数据文件；客户资料有姓名，证件号，订票数量及航班情况，订单要有编号。  
 5）修改航班信息：当航班信息改变可以修改航班数据文件

 （2）要求
根据以上功能说明，设计航班信息，订票信息的存储结构，设计程序完成功能；
*/


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

