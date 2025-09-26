#include <bits/stdc++.h>

using namespace std;

const int INF = 98765432;

int N;
int M;

int maze[101][101];
bool visited[101][101];

int dirX[4]{1, 0, -1, 0};
int dirY[4]{0, 1, 0, -1};

struct Move
{
    int x, y;
    int cnt;

    bool operator<(const Move& other) const
    {
        return cnt > other.cnt;
    }
};

void bfs()
{
    priority_queue<Move> Q;

    visited[1][1] = true;

    Q.push({1, 1, 0});

    while (!Q.empty())
    {
        Move cur = Q.top();
        Q.pop();

        if (cur.x == N && cur.y == M)
        {
            cout << cur.cnt;
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + dirX[i];
            int ny = cur.y + dirY[i];

            if (nx <= 0 || ny <= 0 || nx > N || ny > M)
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;

            if (maze[nx][ny] == 1)
                Q.push({nx, ny, cur.cnt + 1});
            else
                Q.push({nx, ny, cur.cnt});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            char ch;
            cin >> ch;
            maze[i][j] = ch - '0';
        }
    }

    bfs();

    return 0;
}