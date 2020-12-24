#include"quick.h"
void quick_sort(int* a, int low, int high)
{
	if (low >= high)
		return;
	int left = low, right = high;
	int p = a[high];
	while (left < right)
	{
		while (left < right && a[left] <= p)
		{
			left++;
		}
		a[right] = a[left];
		while (left<right && a[right]>=p)
		{
			right--;
		}
		a[left] = a[right];
	}
	if (left >= right)
	{
		a[left] = p;
	}
	quick_sort(a, low, right - 1);
	quick_sort(a, right + 1, high);
}
void quick_sort_reverse(int* a, int low, int high)
{
	if (low >= high)
		return;
	int left = low, right = high;
	int p = a[right];
	while (left < right)
	{
		while (left < right && a[left] >= p)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right && a[right] <= p)
		{
			right--;
		}
		a[left] = a[right];
	}
	if (left >= right)
	{
		a[left] = p;
	}
	quick_sort_reverse(a, low, left - 1);
	quick_sort_reverse(a, left + 1, high);
}

