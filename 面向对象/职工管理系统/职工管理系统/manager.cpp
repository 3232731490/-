#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Dep = did;
	this->m_name = name;
}//构造函数
void Manager:: m_show_Info()//显示个人信息
{
	cout << "职工编号：  " << this->m_ID
		<< "\t职工姓名:  " << this->m_name
		<< "\t职工岗位:  " << this->getDeptName()
		<< "\t职工职责：  完成老板交代的任务并下发任务给员工" << endl;
}
 string Manager::getDeptName()//获取岗位名称

{
	 return string("经理");
}
