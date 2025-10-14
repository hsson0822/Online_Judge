#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int graph[201][201];
int costs[201][201];
int sum[201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    fill(&graph[0][0], &graph[0][0] + 201 * 201, 1e9);

    for (int i = 1; i <= N; ++i)
        graph[i][i] = 0;

    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a][b] = min(graph[a][b], w);
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    cin >> K;
    vector<int> friends(K);
    for (int i = 0; i < K; ++i)
        cin >> friends[i];

    for (int city = 1; city <= N; city++)
    {
        int maxDist = 0;

        for (int f : friends)
        {
            if (graph[f][city] == 1e9 || graph[city][f] == 1e9) {
                maxDist = 1e9;
                break;
            }
            maxDist = max(maxDist, graph[f][city] + graph[city][f]);
        }
        sum[city] = maxDist;
    }

    int miniest = *min_element(&sum[1], &sum[N+1]);

    for (int i = 1; i <= N; ++i)
        if (sum[i] == miniest)
            cout << i << " ";

    return 0;
}
