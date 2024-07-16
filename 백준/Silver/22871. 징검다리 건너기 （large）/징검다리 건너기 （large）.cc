#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 98765432100

using namespace std;

int stone[5001];
long long dp[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> stone[i];

    fill_n(&dp[0], 5001, INF);

    dp[1] = 0;

    for (long long i = 2; i <= n; i++)
    {
        for (long long j = 1; j < i; j++)
        {
            long long mpower = (i - j) * (1 + abs(stone[j] - stone[i]));
            mpower = mpower >= dp[j] ? mpower : dp[j];         
            dp[i] = dp[i] <= mpower ? dp[i] : mpower;
        }
    }

    cout << dp[n];

	return 0;
}