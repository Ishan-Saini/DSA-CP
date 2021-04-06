//UNBOUND BINARY SEARCH
//USED IN SEARCHING AN ELEMENT IN AN INFINITELY BIG ARRAY
//CONSIDER THE ARRAY WE HAVE TAKEN HERE TO BE INFINITELY BIG

#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int l, int h)
{
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (arr[mid] > x)
			h = mid - 1;
		else if (arr[mid] < x)
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}

int search(int arr[], int x)
{
	if (arr[0] == x)
		return 0;
	else {
		int i = 1;
		while (arr[i] < x)
			i *= 2;
		if (arr[i] == x)
			return i;
		return binarySearch(arr, x, (i / 2) + 1, i - 1);
	}
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int x;
	cin >> x;
	int arr[] = {10, 14, 19, 22, 46, 58, 69, 101, 200, 278, 303, 405, 506};
	int res = search(arr, x);
	cout << res;
	return 0;
}
