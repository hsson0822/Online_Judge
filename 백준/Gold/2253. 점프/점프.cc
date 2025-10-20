#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int N, M;
bool blocked[10001];
int dp[10001][150];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0 ; i < M ; ++i)
    {
        int n;
        cin >> n;
        blocked[n] = true;
    }

    for(int i = 0 ; i <= N ; ++i)
        fill(dp[i],dp[i]+150, INF);

    dp[1][0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int k = 0; k < 150; ++k)
        {
            if (dp[i][k] == INF || blocked[i]) continue;

            for (int nk = k - 1; nk <= k + 1; ++nk)
            {
                if (nk <= 0) continue;
                int next = i + nk;
                if (next > N || blocked[next]) continue;
                dp[next][nk] = min(dp[next][nk], dp[i][k] + 1);
            }
        }
    }

    int ans = *min_element(dp[N], dp[N] + 150);
    cout << (ans == INF ? -1 : ans);
    
    return 0;
}