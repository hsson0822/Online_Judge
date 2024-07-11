#include <iostream>

using namespace std;

#define MAX 999999999;

int N;
int M;
int fuel[1001][1001];
int dp[1001][1001][3];

int solve(int x, int y, int dir)
{
	if (x <= 0 || x > N || y <= 0 || y > M) return MAX;
	if (dp[x][y][dir] < 999999999) return dp[x][y][dir];

	int val = MAX;

	switch (dir)
	{
	case 0:
		val = fuel[x][y] + min(solve(x - 1, y, 1), solve(x - 1, y + 1, 2));
		break;

	case 1:
		val = fuel[x][y] + min(solve(x - 1, y - 1, 0), solve(x - 1, y + 1, 2));
		break;

	case 2:
		val = fuel[x][y] + min(solve(x - 1, y - 1, 0), solve(x - 1, y, 1));
		break;
	}

	return dp[x][y][dir] = val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			for (int k = 0; k <= 2; ++k)
				dp[i][j][k] = MAX;
			fuel[i][j] = MAX;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> fuel[i][j];

			if (i == 1)
			{
				dp[1][j][0] = fuel[i][j];
				dp[1][j][1] = fuel[i][j];
				dp[1][j][2] = fuel[i][j];
			}
		}
	}

	int ans = MAX;

	for (int j = 1; j <= M; ++j)
	{
		for (int i = 0; i <= 2; ++i)
		{
			ans = min(ans, solve(N, j, i));
		}
	}

	cout << ans;

	return 0;
}