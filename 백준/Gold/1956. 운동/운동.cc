#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> dist(V+1, vector<int>(V+1,INF));

    for (int i = 0; i < E; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        dist[a][b] = w;
    }

    for (int k = 1; k <= V; ++k)
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int answer = INF;
    for (int i = 1; i <= V; ++i)
        answer = min(answer, dist[i][i]);

    if (answer == INF)
        cout << -1;
    else
        cout << answer;
    return 0;
}
