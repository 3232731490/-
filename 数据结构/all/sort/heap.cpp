#include"heap.h"
void shift(int* a, int low, int n)
{
	int i = low, j = 2 * i;
	int temp = a[low];
	while (j <= n)
	{
		if (j < n&& a[j] < a[j + 1])
		{
			j++;
		}
		if (temp < a[j])
		{
			a[i] = a[j];
			i = j;
			j *= 2;
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
}
void shift_reverse(int* a, int low, int n)
{
	int i = low, j = 2 * i;
	int temp = a[i];
	while (j <= n)
	{
		if (j <n && a[j] > a[j + 1])
		{
			j++;
		}
		if (temp > a[j])
		{
			a[i] = a[j];
			i = j;
			j *= 2;
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void HeapSort(int* a, int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		shift(a, i, n);
	}
	for (int i = n; i > 1; i--)
	{
		swap(a[i], a[1]);
		shift(a, 1, i - 1);
	}

}
void HeapSort_reverse(int* a, int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		shift_reverse(a, i, n);
	}
	for (int i = n; i > 1; i--)
	{
		swap(a[i], a[1]);
		shift_reverse(a, 1, i - 1);
	}

}
