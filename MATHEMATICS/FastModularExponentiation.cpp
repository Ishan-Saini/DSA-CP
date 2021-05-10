#include <iostream>
using namespace std;
#define ll long long
#define fastIO 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll M = 1000000007;

ll fastModExponent(ll x, ll n, ll mod)
{
	ll res = 1;

	x = x % mod;

	if (x == 0)
		return 0;

	while (n > 0)
	{
		if (n & 1)
			res = (res * x) % mod;

		x = (x * x) % mod;
		n = n >> 1;
	}

	return res;
}

int main()
{
	fastIO

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	ll res = fastModExponent(5, 3, 10);

	cout << res;
	return 0;
}