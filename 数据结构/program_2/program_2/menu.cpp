#include"menu.h"
void main_menu()
{
	cout << "1、展示所有航班" << endl;
	cout << "2、查询航班信息" << endl;
	cout << "3、录入航班信息" << endl;
	cout << "4、修改航班信息" << endl;
	cout << "5、查询乘客信息" << endl;
	cout << "6、修改乘客信息" << endl;
	cout << "7、展示所有乘客" << endl;
	cout << "8、订票" << endl;
	cout << "9、退票" << endl;
	cout << "0、退出系统" << endl;
}

void main_funcion()
{

	Flight_list_head* f_head = NULL;
	Client_list_head* c_head = NULL;
	init_list(c_head, f_head);
	bool flag;
	while (1)
	{
		main_menu();
		cout << "请输入您的选择" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:  //展示所有航班
		{
			flag = readfile_flight(f_head);
			if (flag)
			{
				if (f_head->head == NULL)
				{
					cout << "当前航班信息为空！" << endl;
					system("pause");
					system("cls");
					break;
				}
				dis_flight_info(f_head);
				init_flight(f_head);
			}
			system("pause");
			system("cls");
			break;
		}
		case 2: //查询航班信息
		{
			flag = readfile_flight(f_head);
			if (flag)
			{
				if (f_head->head == NULL)
				{
					cout << "当前航班信息为空！" << endl;
					system("pause");
					system("cls");
					break;
				}
				search_flight(f_head);
				init_flight(f_head);
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:  //录入航班信息
		{
			pushback_flight(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 4:  //修改航班信息
		{
			modi_flight(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 5:  //查询乘客信息
		{
			search_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 6:  //修改客户信息
		{
			modi_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 7:  //展示所有乘客信息
		{
			flag = readfile_client(c_head);
			if (flag)
			{
				if (c_head->head == NULL)
				{
					cout << "当前乘客信息为空！" << endl;
					system("pause");
					system("cls");
					break;
				}
				dis_client_info(c_head);
				init_client(c_head);
			}
			system("pause");
			system("cls");
			break;
		}
		case 8:  //订票
		{
			pushback_client(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 9:  //退票
		{
			refund_ticket(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			cout << "欢迎下次使用本系统" << endl;
			return;
		}
		default:
		{
			cout << "你的选择有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}