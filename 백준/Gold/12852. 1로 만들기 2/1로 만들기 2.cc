#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        dp[i] = i;

    for (int i = 2; i <= N; ++i)
    {
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);

        dp[i] = min(dp[i], dp[i - 1]) + 1;
    }

    cout << dp[N] - 1 << "\n";

    while (N != 0)
    {
        cout << N << " ";

        if (dp[N] == dp[N - 1] + 1)
            N = N - 1;
        else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
            N = N / 2;
        else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
            N = N / 3;
    }

    return 0;
}