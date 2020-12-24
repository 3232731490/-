#include"all_sort.h"

void Input(int*& a, int& n)
{
	cout << "��������Ҫ���뼸������" << endl;
	cin >> n;
	if (n > MAXSIZE1)
	{
		cout << "������Ĵ�С����" << endl;
		return;
	}
	a = new int[n + 1];
	a[0] = n;
	for (int i = 1; i <= n; i++)
	{
		cout << "������� " << i << " �����ݣ�";
		cin >> a[i];
	}
	cout << "������ϣ�" << endl;
}


void dis_list(int* a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}

void dis_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t******************************����ϵͳ*******************************" << endl;
	cout << "\t\t\t***\t1���ֶ��������������\t\t       2���Ƚ��㷨ʱ������***" << endl;
	cout << "\t\t\t***\t3���������\t\t\t       0���˳�\t  \t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}

void arti_menu()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*******************************�����㷨******************************" << endl;
	cout << "\t\t\t***\t1����������\t\t\t        2��ϣ������\t  ***" << endl;
	cout << "\t\t\t***\t3����������\t\t  \t        4����������\t  ***" << endl;
	cout << "\t\t\t***\t5��ѡ������\t\t         \t6��������\t  ***" << endl;
	cout << "\t\t\t***\t7���鲢����\t\t\t      \t0���˳�\t\t  ***" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
}

void arti(int* a, int n)
{
	if (a == NULL)
	{
		cout << "�����ֶ���������" << endl;
		return;
	}
	else
	{
		if (n >= MAXSIZE1)
		{
			cout << "��ǰ����Ϊ����������ݣ��޷����д˲���" << endl;
			return;
		}
	}
	system("cls");
	int choice;
	while (1)
	{
		arti_menu();
	A:  cout << "����ѡ������(1)���ǽ���(2)���У�" << endl;
		int b;
		cin >> b;
		if (b != 1 && b != 2)
		{
			cout << "������������,������ѡ��" << endl;
			goto A;
		}
		cout << "��ѡ����Ҫʹ����������ʽ�� " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				Insert_sort(a, n);
			else
				Insert_sort_reverse(a, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				Xi_sort(a, n);
			else
				Xi_sort_reverse(a, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				pop_sort(a, n);
			else
				pop_sort_reverse(a, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				quick_sort(a, 1, n);
			else
				quick_sort_reverse(a, 1, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				select_sort(a, n);
			else
				select_sort_reverse(a, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				HeapSort(a, n);
			else
				HeapSort_reverse(a, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "����ǰ�� ";
			dis_list(a, n);
			if (b == 1)
				mergesort(a, 1, n);
			else
				mergesort_reverse(a, 1, n);
			cout << "����� ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 0:
			return;
		default:
			cout << "����������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void random_num(int**& a)
{
	int count = 0;
	a = new int* [7];
	for (int i = 0; i < 7; i++)
	{
		a[i] = new int[MAXSIZE2 + 1];
		a[i][0] = MAXSIZE2;
	}
	int b = 2 * MAXSIZE2;
	for (int i = 1; i <= MAXSIZE2; i++)
	{
		a[0][i] = rand() % b;
		for (int j = 1; j < 7; j++)
		{
			a[j][i] = a[0][i];
		}
	}
}

void Cmp_time(int** b)
{
	cout << "��������ʽ��30000�����������ʱ���£� " << endl << endl;

	clock_t start_time = clock();
	Insert_sort(b[0], MAXSIZE2);
	clock_t end_time = clock();
	cout << "���������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	Xi_sort(b[1], MAXSIZE2);
	end_time = clock();
	cout << "ϣ�������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	pop_sort(b[2], MAXSIZE2);
	end_time = clock();
	cout << "ð�������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	quick_sort(b[3], 1, MAXSIZE2);
	end_time = clock();
	cout << "���������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	HeapSort(b[4], MAXSIZE2);
	end_time = clock();
	cout << "�������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	mergesort(b[5], 1, MAXSIZE2);
	end_time = clock();
	cout << "�鲢�����ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;

	start_time = clock();
	select_sort(b[6], MAXSIZE2);
	end_time = clock();
	cout << "ѡ�������ʱ : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"��" << endl << endl;
}


void sort_main()
{
	int* a = NULL;
	int choice;
	int n = MAXSIZE1;
	int** b = NULL;
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
			return ;
		default:
			cout << "����ѡ������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return ;
}