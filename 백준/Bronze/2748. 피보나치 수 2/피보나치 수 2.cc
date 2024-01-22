#include <iostream>

using namespace std;

long long dp[200];

long long pibo(int n)
{
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n ; ++i)
	{
		dp[i] = dp[i-1] + dp[i - 2];
	}

	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << pibo(n);

	return 0;
}