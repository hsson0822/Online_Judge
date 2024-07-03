#include <iostream>
#include <climits>

using namespace std;

long long point[201][201];
long long dp[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	long long big = LLONG_MIN;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> point[i][j];
			dp[i][j] =  point[i][j] + dp[i-1][j] + dp[i][j - 1]- dp[i-1][j-1];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = i; k <= N; k++)
			{
				for (int l = j; l <= M; l++)
				{
					long long result = dp[k][l] - dp[k][j - 1] - dp[i - 1][l] + dp[i - 1][j - 1];
					big = max(big,result);
				}
			}
		}
	}

	cout << big;

	return 0;
}