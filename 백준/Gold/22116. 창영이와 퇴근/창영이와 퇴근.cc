#include <bits/stdc++.h>

using namespace std;

int N;
int road[1001][1001];
int dist[1001][1001];

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

struct Move
{
    int x, y;
    int cost;

    bool operator<(const Move &other) const
    {
        return cost > other.cost;
    }
};

void bfs()
{
    int answer = 1e9;

    priority_queue<Move> PQ;
    dist[1][1] = 0;
    PQ.push({1, 1, 0});

    while (!PQ.empty())
    {
        Move cur = PQ.top();
        PQ.pop();

        if (cur.x == N && cur.y == N)
        {
            cout << cur.cost;
            return;
        }

        if (dist[cur.x][cur.y] < cur.cost)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N)
                continue;
            
            int diff = abs(road[nx][ny] - road[cur.x][cur.y]);
            int nc = max(cur.cost, diff);
            
            if(dist[nx][ny] > nc)
            {
                dist[nx][ny] = nc;
                PQ.push({nx,ny, nc});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> road[i][j];

    for (int i = 1; i <= N; ++i)
        fill(dist[i], dist[i] + N + 1, 1e9);

    bfs();

    return 0;
}