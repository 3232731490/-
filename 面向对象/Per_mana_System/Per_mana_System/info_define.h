#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

class Person
{
public:
	Person(string name = "NULL", int age = 0, string port = "NULL", float wages = 0, string addr = "NULL", string phone_num = "NULL" ,int sex=1);
	void set_name(string name);
	void set_age(int age);
	void set_port(string port);
	void set_wages(float wages);
	void set_phone(string phone_num);
	void set_addr(string addr);
	void set_sex(int sex);
	string get_name();
	int get_age();
	string get_port();
	float get_wages();
	string get_addr();
	string get_phone();
	void dis_info();
	int get_sex();
private:
	string name;
	int age;
	string port;
	float wages;
	string addr;
	string phone_num;
	int sex;
};

struct PortList
{
	string port;
	list<Person> list;
	PortList* next;
	int count;
};