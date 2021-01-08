#include"info_define.h"

Person::Person(string name , int age, string port, float wages, string addr , string phone_num,int sex)
{
	this->addr = addr;
	this->name = name;
	this->age = age;
	this->port = port;
	this->wages = wages;
	this->phone_num = phone_num;
	this->sex = sex;
}
void Person::set_name(string name)
{
	this->name = name;
}
void Person::set_age(int age)
{
	this->age = age;
}
void Person::set_port(string port)
{
	this->port = port;
}
void Person::set_wages(float wages)
{
	this->wages = wages;
}
void Person::set_phone(string phone_num)
{
	this->phone_num = phone_num;
}
string Person::get_name()
{
	return this->name;
}
int Person::get_age()
{
	return this->age;
}
string Person::get_port()
{
	return this->port;
}
float Person::get_wages()
{
	return this->wages;
}
void Person::set_addr(string addr)
{
	this->addr = addr;
}
string Person::get_addr()
{
	return this->addr;
}
string Person::get_phone()
{
	return this->phone_num;
}
void Person::set_sex(int sex)
{
	this->sex = sex;
}
int Person::get_sex()
{
	return sex;
}
void Person::dis_info()
{
	cout << "\t姓名： " << name << "\t年龄： "  << age <<"\t性别："<<((sex==1)?"男":"女" )<< "\t住址： " <<addr<< "\n\t\t职务： " <<port<< "\t工资： " <<wages << "\t手机号： " <<phone_num << endl;
}