#include"all_system.h"

int main()
{
	while (1)
	{
		dis_all_system_menu();
		cout << "请选择您要进入的系统" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			sort_main();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			Huff_main_func();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			flight_main_funcion();
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			cout << "欢迎下次使用本系统！" << endl;
			system("pause");
			system("cls");
			return 0;
		default:
			cout << "您的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}