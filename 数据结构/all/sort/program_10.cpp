#include"all_sort.h"

int main()
{
	int* a = NULL;
	int choice;
	int n=MAXSIZE1;
	int **b=NULL ;
	while (1)
	{
		dis_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Input(a, n);
			system("pause");
			system("cls");
			break;
		case 2:
			random_num(b);
			
			Cmp_time(b);
			system("pause");
			system("cls");
			break;
		case 3:
			arti(a, n);
			system("pause");
			system("cls");
			break;
		case 0:
			delete a;
			delete b;
			return 0;
		default:
			cout << "����ѡ������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}