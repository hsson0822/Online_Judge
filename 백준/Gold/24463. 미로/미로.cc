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
char maze[2002][2002];
bool visited[2002][2002];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

int sx, sy;
int ex, ey;

bool dfs(int x , int y)
{
	if(x == ex && y == ey)
	{
		return true;
	}

	for(int i = 0 ; i < 4 ; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
		if(maze[nx][ny] == '+') continue;
		if(visited[nx][ny]) continue;

		visited[nx][ny] = true;
		if(dfs(nx,ny))
			return true;
		visited[nx][ny] = false;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>> M;

	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j =1 ; j <= M ; ++j)
		{
			cin >> maze[i][j];

			if(maze[i][j] == '.' && (i == 1 || j == 1 || i == N || j == M))
			{
				if(sx == 0)
				{
					sx = i;
					sy = j;
				}
				else if (ex == 0)
				{
					ex = i;
					ey = j;
				}
			}
		}
	}

	if(dfs(sx,sy))
		visited[sx][sy] = true;

	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j =1 ; j <= M ; ++j)
		{
			if(maze[i][j] == '+')
				cout << "+";
			else
			{
				if(visited[i][j])
					cout << ".";
				else
					cout <<"@";
			}
		}
		cout << endl;
	}

	return 0;
}