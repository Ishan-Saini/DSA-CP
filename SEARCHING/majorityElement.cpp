/*
MOORE'S VOTING ALGORITHM

FIND AN ELEMENT WHICH IS PRESENT MORE THAN N/2 TIMES IN AN ARRAY.
N = SIZE OF ARRAY
*/


#include <iostream>
using namespace std;

int majorityElement(int arr[], int n)
{
	int res = 0, count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[res] == arr[i])
			count++;
		else
			count--;

		if (count == 0)
		{
			res = i;
			count = 1;
		}
	}
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[res] == arr[i])
			c++;
	}
	if (c <= n / 2)
		return -1;
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif
	int arr[] = {6, 6, 6, 6, 7, 7, 7, 7, 6};
	int n = sizeof(arr) / sizeof(int);
	int res = majorityElement(arr, n);
	cout << res;
	return 0;
}
