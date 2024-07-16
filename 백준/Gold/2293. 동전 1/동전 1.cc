#include <iostream>

using namespace std;

int N;
int K;
int coin[101];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> coin[i];
	
	dp[0] = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = coin[i]; j <= K; ++j)
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[K];

	return 0;
}