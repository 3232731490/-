#include"workerManager.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

WorkerManger::WorkerManger()
{
	//1、文件不存在
	//初始化
	ifstream ifs;
	ifs.open(FILNAME, ios::in);
	if (!ifs.is_open())
	{
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2、文件存在，但内容为空
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//3、文件存在且不为空,并且记录数据

	int num = this->get_EmpNum();  //获取现有职工人数
		this->m_EmpNum = num;
		
		//开辟空间
		this->m_EmpArray = new Worker * [this->m_EmpNum];
	
		//将文件中的数据存到数组中
		this->init_Emp();
}
void WorkerManger::show_Menu()
{
	cout << "**************************************************" << endl;
	cout << "**************欢迎使用职工管理系统****************" << endl;
	cout << "**************0、退出管理系统*********************" << endl;
	cout << "**************1、增加职工信息*********************" << endl;
	cout << "**************2、显示职工信息*********************" << endl;
	cout << "**************3、删除职工信息*********************" << endl;
	cout << "**************4、修改职工信息*********************" << endl;
	cout << "**************5、查找职工信息*********************" << endl;
	cout << "**************6、按照编号排序*********************" << endl;
	cout << "**************7、清空所有文档*********************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}
WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
	}
}
void WorkerManger::exit_system()
{
	cout << "欢迎下次使用！  " << endl;
	system("pause");
	exit(0);//  退出程序
}

//添加职工
void  WorkerManger::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新的空间大小
		int newsize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newspace=new Worker* [newsize];

		//将原来空间下数据拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择；
			cout << "请输入第" << i + 1 << "个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名： " << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;  //定义一个基类指针，用于多态指向派生类
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name,2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//将创建的职工指针保存到数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		//释放原有的空间
		delete[]this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newspace;
		//更新新职工人数
		this->m_EmpNum = newsize;
		//更新文件不为空的标志
		this->m_FileIsEmpty = false;
		//提示成功添加
		cout << "成功添加" << addNum << "个新员工" << endl;

		//保存数据到文件中
		this->save();
	}
	else 
	{
		cout << "输入有误..." << endl;
	}
	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManger::save()
{
	ofstream ofs(FILNAME,ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)//将职工写入文件
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_Dep << " "<<endl;
	}
//关闭文件
	ofs.close();
}
//统计文件中人数
int  WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILNAME, ios::in);
	int id; string name; int did;
	int num = 0;//统计人数
	while (ifs >> id && ifs >> name && ifs >> did)//当所有职工都读取完后退出循环
	{
		num++;
	}
	ifs.close();
	return num;
}
//初始化职工
void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILNAME);
	
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL; //定义一个基类指针，用于多态指向派生类

		if (did == 1)//普通职工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//经理
		{
			worker = new Manager(id, name, did);
		}
		else //老板
		{
			worker =new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;

	}
	ifs.close();//关闭文件
}

//显示职工信息
void WorkerManger::show()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->m_show_Info();
		}
	}
	system("pause");
	system("cls");
}

//查找职工是否存在
int WorkerManger::ISExist(int ID)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (ID == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入您要删除的职工：" << endl;
		int ID;
		cin >> ID;
		int index = this->ISExist(ID);
		if (index== -1)  
		{
			cout << "该职工不存在" << endl;
			return;
		}
		else
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组记录的人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else 
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->ISExist(id);
		if(ret!=-1)
		{
		//查找到该编号的职工

			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dselect = 0;
			cout << "查到： " << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;
			Worker* worker=NULL;  //定义一个基类指针，用于多态指向派生类
			switch (dselect)
			{
			case 1:
				worker = new Employee(newId, newName, dselect);
					break;
			case 2:
				worker = new Manager(newId, newName, dselect);
				break;
			case 3:
				worker = new Boss(newId, newName, dselect);
				break;
			}
			this->m_EmpArray[ret] = worker;
			delete worker;
			cout << "修改成功" << endl;
			this->save();//保存到文件中
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按职工编号查找：" << endl;
		cout << "2、按职工姓名查找：" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = this->ISExist(id);
			if(ret != -1)
			{
				//找到职工
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->m_show_Info();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			cout << "请输入您要查找职工姓名：" << endl;
			string name;
			cin >> name;
			bool flag=false;//  判断是否查到的标志，默认未找到
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为：" <<this->m_EmpArray[i]->m_ID<<"号职工信息如下："<< endl;
					this->m_EmpArray[i]->m_show_Info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
		}
		}
		else
		{
			cout << "您输入的编号有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序序列：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "1、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int min0rMax = i;  //声明最大值或最小值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[min0rMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						min0rMax = j;
					}
				}
				else //降序
				{
					if (this->m_EmpArray[min0rMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						min0rMax = j;
					}
				}
			}
			if (i != min0rMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min0rMax];
				this->m_EmpArray[min0rMax] = temp;
		    }
		}
		cout << "排序成功，排序排序后的结果为：" << endl;
		this->save();  //将排序后的结果保存在文件中
		this->show();  //展示排序后的职工
	}
}

//清空文件
void WorkerManger::clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILNAME, ios::trunc);
		ofs.close();

		//删除堆区的每个职工对象
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}