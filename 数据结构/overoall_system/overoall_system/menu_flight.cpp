#include"menu_flight.h"
void main_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************��Ʊϵͳ******************************" << endl;
	cout << "\t\t\t***\t1��������Ϣ����\t\t\t        2���˿���Ϣ����\t  ***" << endl;
	cout << "\t\t\t***\t0���˳�ϵͳ     \t\t         \t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void flight_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************������Ϣ******************************" << endl;
	cout << "\t\t\t***\t1��չʾ���к���\t\t\t        2����ѯ������Ϣ\t  ***" << endl;
	cout << "\t\t\t***\t3��¼�뺽����Ϣ\t\t  \t        4���޸ĺ�����Ϣ\t  ***" << endl;
	cout << "\t\t\t***\t5����պ�����Ϣ\t\t\t        0���˳�ϵͳ  \t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void client_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************�˿���Ϣ******************************" << endl;
	cout << "\t\t\t***\t1����ѯ�˿���Ϣ\t\t         \t2���޸ĳ˿���Ϣ\t  ***" << endl;
	cout << "\t\t\t***\t3��չʾ���г˿�\t\t\t      \t4����Ʊ\t\t  ***" << endl;
	cout << "\t\t\t***\t5����Ʊ\t\t\t \t        6����ճ˿���Ϣ   ***" << endl;
	cout << "\t\t\t***\t0���˳�ϵͳ            \t\t\t\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}
void flight_function(Flight_list_head *f_head)
{
	system("cls");
	bool flag;
	while (1)
	{
		flight_menu();
		cout << "����������ѡ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:  //չʾ���к���
		{
			flag = readfile_flight(f_head);
			if (flag)
			{
				if (f_head->head == NULL)
				{
					cout << "��ǰ������ϢΪ�գ�" << endl;
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
		case 2: //��ѯ������Ϣ
		{
			flag = readfile_flight(f_head);
			if (flag)
			{
				if (f_head->head == NULL)
				{
					cout << "��ǰ������ϢΪ�գ�" << endl;
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
		case 3:  //¼�뺽����Ϣ
		{
			pushback_flight(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 4:  //�޸ĺ�����Ϣ
		{
			modi_flight(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			clear_flight_info();  //��պ�����Ϣ
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
			cout << "���ѡ���������������룡" << endl;
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
		cout << "����������ѡ��" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:  //��ѯ�˿���Ϣ
		{
			search_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 2:  //�޸Ŀͻ���Ϣ
		{
			modi_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 3:  //չʾ���г˿���Ϣ
		{
			flag = readfile_client(c_head);
			if (flag)
			{
				if (c_head->head == NULL)
				{
					cout << "��ǰ�˿���ϢΪ�գ�" << endl;
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
		case 4:  //��Ʊ
		{
			pushback_client(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 5:  //��Ʊ
		{
			refund_ticket(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			clear_client_info();  //����û���Ϣ
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
			cout << "���ѡ���������������룡" << endl;
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
		cout << "����������ѡ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:  //������Ϣ����
		{
			flight_function(f_head);
			system("pause");
			system("cls");
			break;
		}
		case 2: //�û���Ϣ����
		{
			client_function(f_head, c_head);
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			cout << "��ӭ�´�ʹ�ñ�ϵͳ" << endl;
			return;
		}
		default:
		{
			cout << "���ѡ���������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}