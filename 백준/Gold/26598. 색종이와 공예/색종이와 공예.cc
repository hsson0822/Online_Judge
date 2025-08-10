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
char paper[1001][1001];
bool visited[1001][1001];

int sx,sy,ex,ey;

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

void bfs(int i , int j)
{
	sx = i;
	sy = j;

	ex = i;
	ey = j;

	char ch = paper[i][j];

	queue<pair<int,int>> Q;
	Q.push({i,j});
	visited[i][j] = true;

	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if( sx > x)
			sx = x;

		if( sy > y)
		 	sy = y;

		if(x > ex)
			ex = x;

		if( y > ey)
			ey = y;

			//cout << x << " , " << y << endl;

		for(int i = 0 ; i < 4 ; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if(paper[nx][ny] != ch) continue;
			if(visited[nx][ny]) continue;

			visited[nx][ny] = true;
			Q.push({nx,ny});
		}
	}
}

bool check()
{
	char ch = paper[sx][sy];
	int total = ((ex-sx+1) * (ey-sy+1));
	int cnt{};
	//cout << sx << " , " << sy << " : " << ex << " , " << ey << endl;
	for(int i = sx ; i <= ex ; ++i)
	{
		for(int j = sy ; j <= ey ; ++j)
		{
			if(paper[i][j] != ch)
				return false;
			else
				++cnt;
		}
	}
	//cout << cnt << " / " << total << endl;
	if(total != cnt)
		return false;

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if(!visited[i][j])
			{
				bfs(i,j);
				if(!check())
				{
					cout << "BaboBabo";
					return 0;
				}
			}
		}
	}

	cout <<"dd";

	return 0;
}