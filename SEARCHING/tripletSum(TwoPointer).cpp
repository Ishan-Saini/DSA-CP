/*
FIND IF THERE EXIST THREE NUMBERS WHOSE SUM IS EQUAL TO THE GIVEN
SUM IN A SORTED ARRAY.

TWO POINTER APPROACH
*/

#include <iostream>
using namespace std;

bool sumTriplet(int arr[], int n, int s)
{
	for (int i = 0; i < n - 2; ++i)
	{
		int l = i + 1, r = n - 1;
		int sum = s - arr[i];
		while (l < r)
		{
			if (arr[l] + arr[r] == sum)
				return true;
			else if (arr[l] + arr[r] > sum)
				r--;
			else
				l++;
		}
	}
	return false;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int arr[] = {2, 3, 4, 8, 9, 20, 40};
	int n = sizeof(arr) / sizeof(int);
	int sum;
	cin >> sum;
	bool res = sumTriplet(arr, n, sum);
	cout << res;
	return 0;
}
