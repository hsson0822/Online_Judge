#include <iostream>
#include <cstring>
using namespace std;

int sticker[2][100001];
int dp[2][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		int M;
		cin >> M;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				int n;
				cin >> n;
				sticker[i][j] = n;
			}
		}

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i <= M; ++i)
		{
			dp[0][i] = sticker[0][i] + max(max(dp[0][i - 2], dp[1][i - 1]), max(dp[0][i - 2], dp[1][i - 2]));
			dp[1][i] = sticker[1][i] + max(max(dp[0][i - 1], dp[1][i - 2]), max(dp[0][i - 2], dp[1][i - 2]));
		}

		cout << max(dp[0][M], dp[1][M]) << "\n";

		memset(sticker, 0, sizeof(sticker));
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}