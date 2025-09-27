#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int country[51][51];
bool visited[51][51];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

struct Country
{
    int x, y;
};

bool bfs(int x, int y)
{
    queue<Country> Q;
    Q.push({x,y});
    visited[x][y] = true;

    int cnt{};
    int people{};

    vector<Country> vec;

    while(!Q.empty())
    {
        int cx = Q.front().x;
        int cy = Q.front().y;
        Q.pop();

        ++cnt;
        people += country[cx][cy];
        vec.push_back({cx,cy});

        for(int i = 0 ; i <4 ; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx <= 0 || ny <= 0 || nx > N || ny> N) continue;
            if(visited[nx][ny]) continue;
            
            int diff = abs(country[cx][cy] - country[nx][ny]);
            if(diff < L || diff > R) continue;
            
            visited[nx][ny] =true;
            Q.push({nx,ny});
        }
    }

    if(cnt >= 2)
    {
        people = people / cnt;
        for(int i = 0 ; i < cnt ; ++i)
        {
            int cx = vec[i].x;
            int cy = vec[i].y;
            country[cx][cy] = people;
        }
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= N ; ++j)
            cin >> country[i][j];

    int answer{};
    while(1)
    {
        for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				visited[i][j] = false;
	
        bool flag =false;
        for(int i =1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N ; ++j)
            {
                if(visited[i][j])continue;
                if(bfs(i,j)) flag = true;
            }
        }
        if(flag)
            ++answer;
        else
            break;

    }

    cout <<answer;

    return 0;
}