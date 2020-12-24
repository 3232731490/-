#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Dep = did;
	this->m_name = name;
}//构造函数
void Boss::m_show_Info()//显示个人信息
{
	cout << "职工编号：  " << this->m_ID
		<< "\t职工姓名:  " << this->m_name
		<< "\t职工岗位:  " << this->getDeptName()
		<< "\t职工职责： 管理公司所有事物" << endl;
}
string Boss::getDeptName()//获取岗位名称

{
	return string("老板");
}
