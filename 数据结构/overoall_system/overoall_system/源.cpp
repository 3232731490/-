#include"all_system.h"

int main()
{
	while (1)
	{
		dis_all_system_menu();
		cout << "��ѡ����Ҫ�����ϵͳ" << endl;
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
			cout << "��ӭ�´�ʹ�ñ�ϵͳ��" << endl;
			system("pause");
			system("cls");
			return 0;
		default:
			cout << "����������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}