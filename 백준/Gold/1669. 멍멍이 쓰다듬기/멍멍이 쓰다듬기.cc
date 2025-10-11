#include <bits/stdc++.h>
using namespace std;

long long dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long X, Y;
    cin >> X >> Y;

    long long D = Y - X;
    if (D == 0)
    {
        cout << 0;
        return 0;
    }

    long long n = sqrt(D);

    if (n * n == D)
        cout << 2 * n - 1;
    else if (D <= n * n + n)
        cout << 2 * n;
    else
        cout << 2 * n + 1;


    return 0;
}
