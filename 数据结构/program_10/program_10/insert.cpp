#include"insert.h"
void Insert_sort(int a[], int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 2; i <=len; i++)
	{
		if (a[i] < a[i - 1])
		{
			temp = a[i];
			int j = i - 1;
			while (j >= 1 && temp < a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
	}
}
void Insert_sort_reverse(int a[], int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 2; i <= len; i++)
	{
		if (a[i] > a[i - 1])
		{
			temp = a[i];
			j = i - 1;
			while (j >= 1 && temp > a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
	}
}
