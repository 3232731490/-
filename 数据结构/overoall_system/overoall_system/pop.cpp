#include"pop.h"
void pop_sort(int* a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
void pop_sort_reverse(int* a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (a[j] > a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
