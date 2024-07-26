#include <iostream>

using namespace std;

int pic[1001][1001];
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	int K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> pic[i][j];
			dp[i][j] = pic[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}



	for (int i = 0; i < K; ++i)
	{
		int x1;
		int y1;
		int x2;
		int y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		int cnt = (x2 - x1 + 1) * (y2 - y1 + 1);

		cout << sum / cnt << "\n";

	}

	return 0;
}