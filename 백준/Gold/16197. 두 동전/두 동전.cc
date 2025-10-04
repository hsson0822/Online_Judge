#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> board;

int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};

struct State
{
    int x1, y1, x2, y2, cnt;
};

bool isOut(int x, int y)
{
    return (x < 0 || y < 0 || x >= N || y >= M);
}

int bfs(pair<int,int> c1, pair<int,int> c2)
{
    queue<State> Q;
    Q.push({c1.first, c1.second, c2.first, c2.second, 0});
    set<tuple<int,int,int,int>> visited;
    visited.insert({c1.first, c1.second, c2.first, c2.second});

    while (!Q.empty())
    {
        int x1 = Q.front().x1;
        int y1 = Q.front().y1;
        int x2 = Q.front().x2;
        int y2 = Q.front().y2;
        int cnt = Q.front().cnt;

        Q.pop();

        if (cnt >= 10) return -1;

        for (int d=0; d<4; d++) {
            int nx1 = x1 + dx[d];
            int ny1 = y1 + dy[d];
            int nx2 = x2 + dx[d];
            int ny2 = y2 + dy[d];

            bool out1 = isOut(nx1, ny1);
            bool out2 = isOut(nx2, ny2);

            if (!out1 && board[nx1][ny1] == '#')
            {
                nx1 = x1; ny1 = y1;
            }

            if (!out2 && board[nx2][ny2] == '#')
            {
                nx2 = x2; ny2 = y2;
            }

            if (out1 ^ out2) return cnt+1;

            if (out1 && out2) continue;

            if (!visited.count({nx1,ny1,nx2,ny2}))
            {
                visited.insert({nx1,ny1,nx2,ny2});
                Q.push({nx1,ny1,nx2,ny2,cnt+1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N);

    vector<pair<int,int>> coins;

    for (int i=0; i<N; i++) {
        cin >> board[i];
        for (int j=0; j<M; j++) {
            if (board[i][j] == 'o') {
                coins.push_back({i,j});
                board[i][j] = '.';
            }
        }
    }

    cout << bfs(coins[0], coins[1]);
    return 0;
}
