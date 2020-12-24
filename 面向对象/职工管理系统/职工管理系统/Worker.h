#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
using namespace std;
class Worker   //抽象的职工基类
{
public:
	virtual void m_show_Info() = 0;
	virtual string getDeptName() = 0;

	int m_ID;  //职工编号
	string m_name;   //职工姓名
	int m_Dep;//职工岗位
};
