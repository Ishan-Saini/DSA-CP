#include <iostream>
#include <utility>
using namespace std;

void countSort(int a[], int n, int k)
{
	int arr[k] = {0};
	int temp[n];
	for (int i = 0; i < n; ++i)
	{
		arr[a[i]] += 1;
	}
	for (int i = 1; i < k; ++i)
	{
		arr[i] = arr[i - 1] + arr[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		temp[arr[a[i]] - 1] = a[i];
		arr[a[i]]--;
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = temp[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int a[] = {4, 8, 6, 2, 4, 11};
	int n = sizeof(a) / sizeof(a[0]);

	countSort(a, n, 12);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}




