#include <bits/stdc++.h>

using namespace std;

int board[20][20];
bool visited[20][20][4];

int dx[]{1,0,1,-1};
int dy[]{0,1,1,1};

bool check(int i, int j, int d, int c)
{
    int cnt = 1;

    while(true)
    {
        int nx = i + dx[d];
        int ny = j + dy[d];

        if(nx <= 0 || ny <= 0 || nx > 19 || ny > 19) break;
        if(board[nx][ny] != c) break;
        if(visited[nx][ny][d]) break;

        visited[nx][ny][d] = true;
        ++cnt;

        i = nx;
        j = ny;
    }

    if(cnt == 5)
        return true;
    
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i <= 19 ; ++i)
        for(int j = 1; j <= 19 ; ++j)
            cin >> board[i][j];

    for(int i = 1; i <= 19 ; ++i)
    {
        for(int j = 1; j <= 19 ; ++j)
        {
            if(board[j][i] == 0) continue;

            for(int d = 0 ; d < 4 ; ++d)
            {
                if(visited[j][i][d]) continue;

                visited[j][i][d] = true;

                if(check(j, i, d, board[j][i]))
                {
                    cout << board[j][i] <<"\n";
                    cout << j << " " << i;
                    return 0;
                }

            }
        }
    }

    cout << 0;
        
    return 0;
}
