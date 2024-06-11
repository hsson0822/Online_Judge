#include <iostream>

using namespace std;

unsigned long long dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	for (int t = 0; t < testCase; ++t)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}