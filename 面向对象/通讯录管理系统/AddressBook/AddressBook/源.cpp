#include"function.h"
list<User> User_List;
int main()
{
	int choice;
	while (1)
	{
		dis_menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			open_File(User_List);
			system("pause");
			system("cls");
			break;
		case 2:
			add_File();
			system("pause");
			system("cls");
			break;
		case 3:
			search_info(User_List);
			system("pause");
			system("cls");
			break;
		case 4:
			del_User(User_List);
			system("pause");
			system("cls");
			break;
		case 5:
			mod_User(User_List);
			system("pause");
			system("cls");
			break;
		case 6:
			clear_User(User_List);
			system("pause");
			system("cls");
			break;
		case 7:
			merge_File(User_List);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ñ�ϵͳ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "���������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}