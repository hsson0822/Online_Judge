#include <iostream>

using namespace std;

pair<int, int> dp[41];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    dp[0] = { 1,0 };
    dp[1] = { 0,1 };
    dp[2] = { 1,1 };
    dp[3] = { 1,2 };


    for (int i = 4; i < 41; ++i)
    {
        int front = dp[i - 2].first + dp[i-2].second;
        int back = dp[i - 1].first + dp[i - 1].second;
        dp[i] = { front, back };
    }

    int N{};
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int k{};
        cin >> k;
        cout << dp[k].first << " " << dp[k].second << endl;
    }

	return 0;
}
