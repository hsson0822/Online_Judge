#include <bits/stdc++.h>

using namespace std;

int N;
int room[51][51];
bool visited[51][51];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

struct Move
{
    int x, y;
    int cnt, change;

    bool operator<(const Move& other) const  
    {
        if(change == other.change)
            return cnt > other.cnt;

        return change > other.change;
    }
};

void bfs()
{
    priority_queue<Move> Q;
    Q.push({1,1,0,0});
    visited[1][1] = true;

    while(!Q.empty())
    {
        Move cur = Q.top();
        Q.pop();

        //cout << cur.x << "," << cur.y << " : " << cur.cnt << " , " << cur.change << endl;

        if(cur.x == N && cur.y == N)
        {
            cout << cur.change;
            return;
        }

        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            if(room[nx][ny] == 0)
                Q.push({nx,ny,cur.cnt+1, cur.change+1});
            else
                Q.push({nx,ny,cur.cnt+1, cur.change});
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            char ch;
            cin >> ch;
            room[i][j] = ch-'0';
        }
    }

    bfs();

    return 0;
}
