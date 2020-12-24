#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<regex>
using namespace std;

class User {
public:
	User();

	void set_num(string num);

	void set_name(string name);

	void set_age(int age);

	void set_addr(string addr);

	void set_No(int);
	
	void dis_info();

	static void add_User();

	static void set_sum_0();

	static void sub_User();

	static int get_sum();

	string get_num();

	string get_addr();

	string get_name();

	int get_No();

	int get_age();

private:
	string phone_num;
	string User_name;
	int User_age;
	string User_addr;
	int User_No;
	static int User_sum;
};


