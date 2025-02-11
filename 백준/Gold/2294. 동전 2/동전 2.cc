#include <iostream>
#include <algorithm>

using namespace std;

int n;
int k;
int coin[101];
int dp[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	fill_n(dp, k+1, 10001);
	dp[0] = 0;

	for (int i = 1; i <= n ; ++i)
	{
		cin >> coin[i];

		for (int j = coin[i]; j <= k; ++j)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}

	if (dp[k] == 10001)
		cout << -1 << endl;
	else
		cout << dp[k] << endl;

	return 0;
}