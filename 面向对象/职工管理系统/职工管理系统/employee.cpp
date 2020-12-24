#include"employee.h"
Employee::Employee(int id, string name ,int did)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_Dep = did;
}
void Employee::m_show_Info()//显示个人信息
{
    cout << "职工编号：  " << this->m_ID
        << "\t职工姓名:  " << this->m_name
        << "\t职工岗位:  " << this->getDeptName()
        << "\t职工职责：  完成经理交代的任务" << endl;
}
string Employee::getDeptName()//获取岗位名称
{
    return string("员工");
}