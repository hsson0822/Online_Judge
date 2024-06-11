#include <iostream>

using namespace std;

const int MAX = 101;

int N;
int K;
int W[MAX];
int V[MAX];
int dp[MAX][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (j >= W[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}