#include"menu.h"
void main_menu()
{
	cout << "1��չʾ���к���" << endl;
	cout << "2����ѯ������Ϣ" << endl;
	cout << "3��¼�뺽����Ϣ" << endl;
	cout << "4���޸ĺ�����Ϣ" << endl;
	cout << "5����ѯ�˿���Ϣ" << endl;
	cout << "6���޸ĳ˿���Ϣ" << endl;
	cout << "7��չʾ���г˿�" << endl;
	cout << "8����Ʊ" << endl;
	cout << "9����Ʊ" << endl;
	cout << "0���˳�ϵͳ" << endl;
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
		case 5:  //��ѯ�˿���Ϣ
		{
			search_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 6:  //�޸Ŀͻ���Ϣ
		{
			modi_client(c_head);
			system("pause");
			system("cls");
			break;
		}
		case 7:  //չʾ���г˿���Ϣ
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
		case 8:  //��Ʊ
		{
			pushback_client(c_head, f_head);
			system("pause");
			system("cls");
			break;
		}
		case 9:  //��Ʊ
		{
			refund_ticket(c_head, f_head);
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