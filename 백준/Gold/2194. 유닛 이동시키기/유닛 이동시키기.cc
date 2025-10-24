#include <bits/stdc++.h>

using namespace std;

struct Unit
{
    int x, y;
    int cnt;
};

int N, M, A, B, K;

bool arr[502][502];
bool visited[502][502];

int sx, sy, ex, ey;
int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

bool check(int x, int y)
{

    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j)
            if (arr[x + i][y + j])
                return false;

    return true;
}

void bfs()
{
    int answer = -1;

    queue<Unit> Q;
    Q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!Q.empty())
    {
        Unit cur = Q.front();
        Q.pop();

        if (cur.x == ex && cur.y == ey)
        {
            answer = cur.cnt;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx <= 0 || nx + A - 1 > N || ny <= 0 || ny + B - 1 > M)
                continue;
            if (!check(nx, ny))
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            Q.push({nx, ny, cur.cnt + 1});
        }
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> A >> B >> K;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = true;
    }

    cin >> sx >> sy >> ex >> ey;

    bfs();

    return 0;
}