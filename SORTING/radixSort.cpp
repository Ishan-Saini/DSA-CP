#include <iostream>
using namespace std;

void countSort(int a[], int n, int exp)
{
	int count[10] = {0};
	int temp[n];
	for (int i = 0; i < n; ++i)
	{
		count[(a[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		temp[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = temp[i];
	}
}

void radixSort(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > mx)
			mx = a[i];
	}

	for (int exp = 1; mx / exp > 0; exp *= 10)
	{
		countSort(a, n, exp);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int a[] = {319, 212, 6, 8, 100, 50};
	int n = sizeof(a) / sizeof(a[0]);

	radixSort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}




