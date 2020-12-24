#include"Xier.h"
void Xi_sort(int* a, int n)
{
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d + 1; i <= n; i++)
		{
			int temp = a[i];
			int j = i - d;
			while (j >= 1 && temp < a[j])
			{
				a[j + d] = a[j];
				j -= d;
			}
			a[j + d] = temp;
		}
		d /= 2;
	}
}
void Xi_sort_reverse(int* a, int n)
{
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d + 1; i <= n; i++)
		{
			int temp = a[i];
			int j = i - d;
			while (j >= 1 && temp > a[j])
			{
				a[j + d] = a[j];
				j -= d;
			}
			a[j + d] = temp;
		}
		d /= 2;
	}
}

