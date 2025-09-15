#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000007;

int N, M, C;
int gameRoom[51][51];
long long dp[51][51][51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> C;

    for (int i = 1; i <= C; ++i)
    {
        int x, y;
        cin >> x >> y;

        gameRoom[x][y] = i;
    }

    if (gameRoom[1][1] == 0)
        dp[1][1][0][0] = 1;
    else
    {
        int g = gameRoom[1][1];
        
            dp[1][1][1][g] = 1;
        
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (i == 1 && j == 1)
                continue;

            int curG = gameRoom[i][j];

            for (int k = 0; k <= C; k++)
            {
                for (int l = 0; l <= C; l++)
                {
                    long long fromUp = (i > 1 ? dp[i - 1][j][k][l] : 0);
                    long long fromLeft = (j > 1 ? dp[i][j - 1][k][l] : 0);

                    long long ways = (fromUp + fromLeft) % MOD;
                    if (ways == 0)
                        continue;

                    if (curG == 0)
                    {
                        // 관광지 없는 칸이면 그대로 이어감
                        dp[i][j][k][l] = (dp[i][j][k][l] + ways) % MOD;
                    }
                    else
                    {
                        // 관광지 칸이면, 반드시 순서 지켜야 함
                        if (curG > l)
                        {
                            dp[i][j][k + 1][curG] = (dp[i][j][k + 1][curG] + ways) % MOD;
                        }
                    }
                }
            }
        }
    }

    for (int k = 0; k <= C; k++) {
        long long ans = 0;
        for (int l = 0; l <= C; l++) {
            ans = (ans + dp[N][M][k][l]) % MOD;
        }
        cout << ans;
        if (k < C) cout << " ";
    }

    return 0;
}
