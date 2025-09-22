#include <bits/stdc++.h>

using namespace std;

int N, M;
int sx, sy;
int a, b, c;
int mountain[501][501];
bool visited[501][501];
long long costs[501][501];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

int highest{};
int ex, ey;

struct Move
{
    int x,y;
    long long t;

    bool operator<(const Move& other) const
    {
        return t > other.t;
    }
};

void bfs()
{
    priority_queue<Move> Q;
    costs[sx][sy] = 0;
    Q.push({sx,sy,0});

    while(!Q.empty())
    {
        Move cur = Q.top();
        Q.pop();
        
        if (cur.t > costs[cur.x][cur.y]) continue;
        if (visited[cur.x][cur.y]) continue;

        visited[cur.x][cur.y] = true;

        if(cur.x == ex && cur.y == ey)
        {
            cout << cur.t;
            return;
        }
        
        //cout << cur.x << " , " << cur.y << " = " << cur.t << endl;
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
            
            long long nCost = 1;
            int diff = mountain[cur.x][cur.y] - mountain[nx][ny];

            if(abs(diff) > c) continue;

            if(diff > 0)
                nCost = b * diff;
            else if(diff < 0)
                nCost = a * -diff;

            if(costs[nx][ny] < cur.t + nCost) continue;

            costs[nx][ny] = cur.t + nCost;
            Q.push({nx,ny,costs[nx][ny]});

        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N>> M;
    cin >> sx >> sy;
    cin >> a >> b >> c;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1; j <= M ; ++j)
        {
            cin >> mountain[i][j];
            costs[i][j] = LLONG_MAX;

            if(highest < mountain[i][j])
            {
                highest = mountain[i][j];
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    return 0;
}
