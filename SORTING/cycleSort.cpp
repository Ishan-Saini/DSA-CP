#include <bits/stdc++.h>
using namespace std;

void cycleSort(int a[], int n)
{
	for (int cs = 0; cs < n - 1; cs++)
	{
		int item = a[cs];
		int pos = cs;
		for (int i = cs + 1; i < n; i++)
		{
			if (a[i] < item)
				pos++;
		}
		swap(item, a[pos]);

		while (pos != cs)
		{
			pos = cs;
			for (int i = cs + 1; i < n; i++)
			{
				if (a[i] < item)
					pos++;
			}
			swap(item, a[pos]);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int a[] = {20, 40, 50, 10, 30, 60, 12};
	int n = sizeof(a) / sizeof(a[0]);

	cycleSort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}




