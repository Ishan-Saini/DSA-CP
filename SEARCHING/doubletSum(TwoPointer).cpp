/*
TWO POINTER APPROACH IS THE BEST SOLUTION WHEN WE HAVE TO FIND IF THERE
EXIST TWO NUMBERS WHOSE SUM IS EQUAL TO THE GIVEN SUM IN A SORTED ARRAY.
THIS IS BECAUSE THERE IS NO REQUIREMENT OF EXTRA AUXILIARY SPACE.

HOWEVER, IF THERE IS AN UNSORTED ARRAY, THEN HASHING IS PREFERRED. IT WILL
TAKE O(n) EXTRA SPACE BUT WILL ONLY HAVE O(n) TIME COMPLEXITY WHICH IS ALWAYS
BETTER THAN HAVING TO SORT THE ARRAY AND PERFORM THE TWO POINTER APPROACH BECAUSE
SORTING WILL HAVE O(nlogN) COMPLEXITY.
*/

#include <iostream>
using namespace std;

bool sumDoublet(int arr[], int n, int sum)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		if (arr[l] + arr[r] == sum)
			return true;
		else if (arr[l] + arr[r] > sum)
			r--;
		else
			l++;
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
	bool res = sumDoublet(arr, n, sum);
	cout << res;
	return 0;
}
