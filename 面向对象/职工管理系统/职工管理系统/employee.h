#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id,string name ,int did);//构造函数
	virtual void m_show_Info();//显示个人信息
	virtual string getDeptName();//获取岗位名称

};