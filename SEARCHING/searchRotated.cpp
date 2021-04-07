/*
FIND AN ELEMENT IN SORTED + ROTATED ARRAY
*/


#include <iostream>
using namespace std;

int searchRotate(int arr[], int n, int x)
{
	int l = 0, h = n - 1;
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (arr[mid] == x)
			return mid;
		else if (arr[l] < arr[mid])
		{
			if (arr[mid] > x && x >= arr[l])
				h = mid - 1;
			else
				l = mid + 1;
		}
		else {
			if (arr[mid] < x && x <= arr[h])
				l = mid + 1;
			else
				h = mid - 1;
		}
	}
	return -1;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int arr[] = {100, 200, 300, 10, 20};
	int n = sizeof(arr) / sizeof(int);
	int x;
	cin >> x;
	int res = searchRotate(arr, n, x);
	cout << res;
	return 0;
}
