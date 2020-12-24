#include"function.h"
list<User> User_List;
int main()
{
	int choice;
	while (1)
	{
		dis_menu();
		cout << "请输入您的选择:" << endl;
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
			cout << "欢迎下次使用本系统！" << endl;
			system("pause");
			return 0;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}