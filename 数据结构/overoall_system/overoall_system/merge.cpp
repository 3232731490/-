#include"merge.h"
void merge(int a[], int low, int mid, int high)
{
	int N = high - low + 1;
	int* b = new int[N];
	int left = low;
	int right = mid + 1;
	int i = 0;
	while (left <= mid && right <= high)
	{
		b[i++] = (a[left] < a[right]) ? a[right++] : a[left++];
	}
	while (left <= mid)
	{
		b[i++] = a[left++];
	}
	while (right <= high)
	{
		b[i++] = a[right++];
	}
	for (int i = 0; i < N; i++)
	{
		a[low + i] = b[i];
	}
	delete[] b;
}
void merge_reverse(int a[], int low, int mid, int high)
{
	int N = high - low + 1;
	int* b = new int[N];
	int left = low;
	int right = mid + 1;
	int i = 0;
	while (left <= mid && right <= high)
	{
		b[i++] = (a[left] > a[right]) ? a[right++] : a[left++];
	}
	while (left <= mid)
	{
		b[i++] = a[left++];
	}
	while (right <= high)
	{
		b[i++] = a[right++];
	}
	for (int i = 0; i < N; i++)
	{
		a[low + i] = b[i];
	}
	delete[] b;
}
void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge_reverse(a, low, mid, high);
	}

}
void mergesort_reverse(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort_reverse(a, low, mid);
		mergesort_reverse(a, mid + 1, high);
		merge(a, low, mid, high);
	}

}
