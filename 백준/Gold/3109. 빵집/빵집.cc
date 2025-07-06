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
char pipe[10001][501];

pair<int,int> d[]{{-1,1},{0,1},{1,1}};
int answer, complete{};

void dfs(int x, int y)
{
    pipe[x][y] = 'x';

    complete = answer;

    if(y == M)
    {
        ++answer;
        return;
    }
    
    for(auto [dx,dy] : d)
    {
        int nx = x + dx;
        int ny = y + dy;

        if(nx <= 0 || nx > N || ny <= 0 || ny > M)
            continue;

        if(pipe[nx][ny] == '.')
        {
            if(complete != answer) return;
            dfs(nx,ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j =1 ; j <= M ; ++j)
        {
            cin >> pipe[i][j];
        }
    }

    for(int i = 1; i <= N ; ++i)
    {
        if(pipe[i][1] != 'x')
        {
            dfs(i,0);
        }
    }

    cout << answer;
    
    return 0;
}