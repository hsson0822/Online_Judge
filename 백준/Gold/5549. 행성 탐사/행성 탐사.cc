#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;
    
    int K;
    cin >> K;

    vector<string> grid(M + 1);
    for (int i = 1; i <= M; i++)
    {
        string s;
        cin >> s;
        grid[i] = " " + s;
    }

    vector<vector<int>> sumJ(M + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sumO(M + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sumI(M + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sumJ[i][j] = sumJ[i - 1][j] + sumJ[i][j - 1] - sumJ[i - 1][j - 1];
            sumO[i][j] = sumO[i - 1][j] + sumO[i][j - 1] - sumO[i - 1][j - 1];
            sumI[i][j] = sumI[i - 1][j] + sumI[i][j - 1] - sumI[i - 1][j - 1];

            char c = grid[i][j];
            if (c == 'J')
                sumJ[i][j]++;
            else if (c == 'O')
                sumO[i][j]++;
            else if (c == 'I')
                sumI[i][j]++;
        }
    }

    while (K--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int cntJ = sumJ[c][d] - sumJ[a - 1][d] - sumJ[c][b - 1] + sumJ[a - 1][b - 1];
        int cntO = sumO[c][d] - sumO[a - 1][d] - sumO[c][b - 1] + sumO[a - 1][b - 1];
        int cntI = sumI[c][d] - sumI[a - 1][d] - sumI[c][b - 1] + sumI[a - 1][b - 1];

        cout << cntJ << " " << cntO << " " << cntI << "\n";
    }

    return 0;
}
