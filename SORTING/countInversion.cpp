/*
We need to calculate inversions in an array.
By inversion we mean, all those pairs of numbers (a[i],a[j])
such that a[i] > a[j] and i<j.
OPTIMAL approach would be to use merge sort concepts.
*/



#include <iostream>
using namespace std;

int merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	int right[n1], left[n2];
	int k = 0, j = 0, count = 0, c = l;
	for (int i = 0; i < n1; ++i)
	{
		left[i] = a[i + l];
	}
	for (int i = 0; i < n2; ++i)
	{
		right[i] = a[i + m + 1];
	}
	while (k < n1 && j < n2) {
		if (left[k] <= right[j]) {
			a[c] = left[k];
			k++;
		}
		else {
			a[c] = right[j];
			j++;
			count = count + (n1 - k);
		}
		c++;
	}
	while (k < n1) {
		a[c] = left[k];
		c++;
		k++;
	}
	while (j < n2) {
		a[c] = right[j];
		j++;
		c++;
	}
	return count;
}

int inversion(int a[], int l, int r) {
	int inv = 0;
	if (r > l) {
		int m = l + (r - l) / 2;
		inv += inversion(a, l, m);
		inv += inversion(a, m + 1, r);
		inv += merge(a, l, m, r);
	}
	return inv;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {2, 4, 3, 1, 5};
	int n = sizeof(a) / sizeof(int);
	int c = inversion(a, 0, n - 1);
	cout << c;
	return 0;
}