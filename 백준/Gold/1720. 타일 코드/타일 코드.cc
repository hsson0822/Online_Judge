#include <bits/stdc++.h>
using namespace std;

long long dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }

    long long symmetric;
    if (n % 2 == 1)
    {
        symmetric = dp[n / 2];
    }
    else
    {
        symmetric = dp[n / 2] + 2 * dp[n / 2 - 1];
    }

    cout << (dp[n] + symmetric) / 2;
    return 0;
}
