#include"select.h"
void select_sort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}
void select_sort_reverse(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[k] < a[j])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}

