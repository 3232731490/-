#include"add_define.h"
User::User() {
	phone_num = "��";
	User_name = "��";
	User_age = -1;
	User_addr = "��";
}
void User::set_num(string num)
{
	phone_num = num;
}
void User::set_name(string name)
{
	User_name = name;
}
void User::set_age(int age)
{
	User_age = age;
}
void User::set_addr(string addr)
{
	User_addr = addr;
}
void User::set_No(int No)
{
	User_No = No;
}
string User::get_num()
{
	return phone_num;
}
string User::get_addr()
{
	return User_addr;
}
string User::get_name()
{
	return User_name;
}
int User::get_No()
{
	return User_No;
}
int User::get_age()
{
	return User_age;
}
 void User::set_sum_0()
{
	User_sum = 0;
}
 void User::add_User()
 {
	 User_sum++;
 }
 void User::sub_User()
{
	User_sum--;
}
 int User::get_sum()
{
	return User_sum;
}
void User::dis_info()
{
	cout << "\t��ţ� " << User_No << "������ " << User_name << " �绰�� " << phone_num << " ���䣺 " << User_age << " סַ�� " << User_addr << endl;
}

int User::User_sum = 0;