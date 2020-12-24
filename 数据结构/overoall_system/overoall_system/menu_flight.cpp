#include"menu_flight.h"
void main_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************订票系统******************************" << endl;
	cout << "\t\t\t***\t1、航班信息操作\t\t\t        2、乘客信息操作\t  ***" << endl;
	cout << "\t\t\t***\t0、退出系统     \t\t         \t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void flight_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************航班信息******************************" << endl;
	cout << "\t\t\t***\t1、展示所有航班\t\t\t        2、查询航班信息\t  ***" << endl;
	cout << "\t\t\t***\t3、录入航班信息\t\t  \t        4、修改航班信息\t  ***" << endl;
	cout << "\t\t\t***\t5、清空航班信息\t\t\t        0、退出系统  \t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void client_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************乘客信息******************************" << endl;
	cout << "\t\t\t***\t1、查询乘客信息\t\t         \t2、修改乘客信息\t  ***" << endl;
	cout << "\t\t\t***\t3、展示所有乘客\t\t\t      \t4、订票\t\t  ***" << endl;
	cout << "\t\t\t***\t5、退票\t\t\t \t        6、清空乘客信息   ***" << endl;
	cout << "\t\t\t***\t0、退出系统            \t\t\t\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void flight_function(Flight_list_head *f_head)
{
	system("cls");
	bool flag;
	while (1)
	{
		flight_menu();
		cout << "请输入您的选择：" << endl;
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
		case 5:
		{
			clear_flight_info();  //清空航班信息
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			return ;
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

void client_function(Flight_list_head* f_head, Client_list_head* c_head)
{
	system("cls");
	bool flag;
	int choice;
	while (1)
	{
		client_menu();
		cout << "请输入您的选择：" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:  //查询乘客信息
		{
			search_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 2:  //修改客户信息
		{
			modi_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 3:  //展示所有乘客信息
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
		case 4:  //订票
		{
			pushback_client(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 5:  //退票
		{
			refund_ticket(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			clear_client_info();  //清空用户信息
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
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
void flight_main_funcion()
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
		case 1:  //航班信息操作
		{
			flight_function(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 2: //用户信息操作
		{
			client_function(f_head, c_head);
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