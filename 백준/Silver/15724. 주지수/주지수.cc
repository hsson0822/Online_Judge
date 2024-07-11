#include <iostream>

using namespace std;

int dp[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int k;
			cin >> k;

			dp[i][j] = k + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{

		int ax;
		int ay;

		int bx;
		int by;

		cin >> ax >> ay >> bx >> by;

		cout << dp[bx][by] - (dp[bx][ay - 1] + dp[ax - 1][by] - dp[ax - 1][ay - 1]) << "\n";

	}

	return 0;
}