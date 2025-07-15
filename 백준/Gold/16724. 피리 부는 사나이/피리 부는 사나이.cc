#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N, M;
char zone[1001][1001];
int safeCnt[1001][1001];
bool visited[1001][1001];
pair<int,int> endPoint[1001][1001];

pair<int, int> dir[]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<int,int> dfs(int x, int y)
{
    visited[x][y] = true;
    int d{};
    if (zone[x][y] == 'U')
        d = 0;
    else if (zone[x][y] == 'D')
        d = 1;
    else if (zone[x][y] == 'L')
        d = 2;
    else if (zone[x][y] == 'R')
        d = 3;

    int nx = x + dir[d].first;
    int ny = y + dir[d].second;

    if(safeCnt[nx][ny] > 0)
    {
        endPoint[x][y] = {nx, ny};
        return {nx, ny};
    }

    if(visited[nx][ny] && endPoint[nx][ny] == pair(0,0))
    {
        ++safeCnt[x][y];
        endPoint[x][y] = {x,y};
        return endPoint[x][y];
    }
    else if (visited[nx][ny])
    {
        endPoint[x][y] = endPoint[nx][ny];
        return endPoint[x][y];
    }

    endPoint[x][y] = dfs(nx,ny);
    return endPoint[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> zone[i][j];

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (!visited[i][j])
                dfs(i, j);
        }
    }

    int answer{};
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            //cout << safeCnt[i][j] << " ";
            if(safeCnt[i][j] > 0)
            ++answer;
            
        }
        //cout <<endl;
    }

    cout << answer;

    return 0;
}