#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[31]{0};

    dp[0] = 0;
    dp[2] = 3;

    for (int i = 4; i <= 30; i += 2)
    {
        dp[i] = dp[i - 2] * 3+ 2;
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] * 2;
    }

    int n;
    cin >> n;
    cout << dp[n];

	return 0;
}