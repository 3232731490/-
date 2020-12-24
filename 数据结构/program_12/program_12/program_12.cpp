#include"linklist.h"

int main()
{
	LinkList* L = NULL;
	int choice;
	while (1)
	{
		dis_menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			init_Link(&L);
			system("pause");
			system("cls");
			break;
		case 2:
			push_link(L);
			system("pause");
			system("cls");
			break;
		case 3:
			dis_Link(L);
			system("pause");
			system("cls");
			break;
		case 4:
			if (get_len(L) != -1)
				cout << "当前链表长度为：" << get_len(L) << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			search(L);
			system("pause");
			system("cls");
			break;
		case 6:
			push(L);
			system("pause");
			system("cls");
			break;
		case 7:
			isEmpty(L);
			system("pause");
			system("cls");
			break;
		case 8:
			del(L);
			system("pause");
			system("cls");
			break;
		case 9:
			free_link(&L);
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			cout << "无该选项，请重新选择：" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}