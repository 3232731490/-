#include<iostream>
#include<string>
#include<fstream>
#include"workerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;
int main()
{
	WorkerManger wm;
	int choice = 0;
	while (true)
	{
		wm.show_Menu();         //展示菜单
		cout << "请输入您的选择：  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //退出系统
			wm.exit_system();
			break;
		case 1:  //增加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			wm.show();
			break;
		case 3:  //删除职工
			wm.Del_Emp();
			break;
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空职工
			wm.clean_File();
			break;

		}
	}
	return 0;
}