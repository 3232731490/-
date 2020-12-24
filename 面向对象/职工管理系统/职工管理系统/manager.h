#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Manager :public Worker
{
public:
	Manager(int id, string, int);
	virtual void m_show_Info();//显示个人信息
	virtual string getDeptName();//获取岗位名称
};