#include <bits/stdc++.h>

using namespace std;

int cost[1001][1001];
int dp[1001][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >>N;

	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j = 0 ; j < 3 ; ++j)
		{
			cin >> cost[i][j];
		}
	}

	for(int i = 1 ; i <= N ; ++i)
	{
		dp[i][0] = min(dp[i-1][1] + cost[i][0], dp[i-1][2] + cost[i][0]);
		dp[i][1] = min(dp[i-1][0] + cost[i][1], dp[i-1][2] + cost[i][1]);
		dp[i][2] = min(dp[i-1][0] + cost[i][2], dp[i-1][1] + cost[i][2]);
	}
	cout << min({dp[N][0], dp[N][1],dp[N][2]});

	return 0;
}