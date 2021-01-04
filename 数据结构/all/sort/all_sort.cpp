#include"all_sort.h"

void Input(int*& a, int& n)
{
	cout << "请输入您要输入几个数字" << endl;
	cin >> n;
	if (n > MAXSIZE1)
	{
		cout << "您输入的大小有误！" << endl;
		return;
	}
	a = new int[n + 1];
	a[0] = n;
	for (int i = 1; i <= n; i++)
	{
		cout << "请输入第 " << i << " 个数据：";
		cin >> a[i];
	}
	cout << "输入完毕！" << endl;
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
	cout << "1、手动输入待排序序列" << endl;
	cout << "2、随机生成整数排序比较算法时间消耗" << endl;
	cout << "3、排序并输出(手动输入后可执行此操作)" << endl;
	cout << "0、退出" << endl;
}

void arti_menu()
{
	cout << "1、插入排序\n2、希尔排序\n3、起泡排序\n4、快速排序\n5、选择排序\n6、堆排序\n7、归并排序\n0、退出" << endl;
}

void arti(int *a ,int n)
{
	if (a == NULL)
	{
		cout << "请先手动输入序列" << endl;
		return;
	}
	else
	{
		if (n >= MAXSIZE1)
		{
			cout << "当前序列为随机生成数据，无法进行此操作" << endl;
			return;
		}
	}
	system("cls");
	int choice;
	while (1)
	{
		arti_menu();
	A:  cout << "请先选择升序(1)还是降序(2)排列：" << endl;
		int b;
		cin >> b;
		if (b != 1 && b != 2)
		{
			cout << "您的输入有误,请重新选择！" << endl;
			goto A;
		}
		cout << "请选择您要使用哪种排序方式： " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "排序前： ";
			dis_list(a, n);
			if(b==1)
				Insert_sort(a, n);
			else
				Insert_sort_reverse(a, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				Xi_sort(a, n);
			else
				Xi_sort_reverse(a, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				pop_sort(a, n);
			else
				pop_sort_reverse(a, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				quick_sort(a, 1,n);
			else
				quick_sort_reverse(a,1, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				select_sort(a, n);
			else
				select_sort_reverse(a, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				HeapSort(a, n);
			else
				HeapSort_reverse(a, n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "排序前： ";
			dis_list(a, n);
			if (b == 1)
				mergesort(a, 1,n);
			else
				mergesort_reverse(a, 1,n);
			cout << "排序后： ";
			dis_list(a, n);
			system("pause");
			system("cls");
			break;
		case 0:
			return;
		default:
			cout << "您的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void random_num(int**&a)
{
	int count = 0;
	a = new int*[7];
	for (int i = 0; i < 7; i++)
	{
		a[i] = new int[MAXSIZE2+1];
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

void Cmp_time(int**b)
{
	cout << "各种排序方式对30000个整数排序耗时如下： " << endl << endl;

	clock_t start_time = clock();
	Insert_sort(b[0], MAXSIZE2);
	clock_t end_time = clock();
	cout << "插入排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl<<endl;

	start_time = clock();
	Xi_sort(b[1], MAXSIZE2);
	end_time = clock();
	cout << "希尔排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl<<endl;

	start_time = clock();
	pop_sort(b[2], MAXSIZE2);
	end_time = clock();
	cout << "冒泡排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl << endl;
	
	start_time = clock();
	quick_sort(b[3],1, MAXSIZE2);
	end_time = clock();
	cout << "快速排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl << endl;

	start_time = clock();
	HeapSort(b[4], MAXSIZE2);
	end_time = clock();
	cout << "堆排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl << endl;

	start_time = clock();
	mergesort(b[5], 1,MAXSIZE2);
	end_time = clock();
	cout << "归并排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl << endl;

	start_time = clock();
	select_sort(b[6], MAXSIZE2);
	end_time = clock();
	cout << "选择排序耗时 : " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<
		"秒" << endl<<endl;
}