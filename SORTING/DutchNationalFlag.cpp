/*
	DUTCH NATIONAL FLAG ALGORITHM
	USED FOR :
	1.Three way partitioning
	2.Segregate 0s, 1s and 2s
*/

#include <iostream>
#include <utility>
using namespace std;

void segregate(int a[], int n)
{
	int mid = 0, l = 0, h = n - 1;
	while (mid <= h) {
		if (a[mid] == 0) {
			swap(a[mid], a[l]);
			l++;
			mid++;
		}
		else if (a[mid] == 1) {
			mid++;
		}
		else {
			swap(a[mid], a[h]);
			h--;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int a[] = {0, 1, 0, 2, 1, 2};
	int n = sizeof(a) / sizeof(a[0]);
	segregate(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}