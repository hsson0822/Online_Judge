#include <bits/stdc++.h>
using namespace std;

int N, K, M;
vector<int> graph[100001 + 1000]; // 역 N + 튜브 M
int dist[100001 + 1000];

void bfs()
{
    fill(dist, dist + N + M + 1, -1);

    queue<int> q;
    dist[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int next : graph[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int n; cin >> n;
            // 역 n <-> 튜브 (N+i) 연결
            graph[n].push_back(N + i);
            graph[N + i].push_back(n);
        }
    }

    bfs();

    if (dist[N] == -1)
        cout << -1;
    else
        cout << (dist[N] + 1) / 2; // 역,튜브 둘다 세므로 2로 나눔

    return 0;
}
