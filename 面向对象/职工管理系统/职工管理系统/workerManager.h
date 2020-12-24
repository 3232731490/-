#pragma once//防止头文件重复包含
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILNAME "empFile.text"
using namespace std;
class WorkerManger
{
public:
	WorkerManger();

	void exit_system();

	void show_Menu();
	
	//添加职工
	void Add_Emp();

	//保存文件
	void save();
	~WorkerManger();

	//统计文件中人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工信息
	void show();

	//查找职工是否存在 存在返回职工编号，不存在返回-1
	int ISExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void clean_File();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty;
};

