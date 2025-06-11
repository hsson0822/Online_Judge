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

int N;
int M;

int HX;
int HY;

int EX;
int EY;

int maze[1001][1001];
int visited[1001][1001][2];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void bfs()
{
	queue<pair<pair<int,int>,pair<int,int>>> Q;
	Q.push({ { HX,HY }, {0,1} });

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;

		int depth = Q.front().second.first;
		int key = Q.front().second.second;

		Q.pop();

		if (x == EX && y == EY)
		{
			cout << depth;
			return;
		}

		if (visited[x][y][key]) continue;
		visited[x][y][key] = 1;

		for (int k = 0; k < 4; ++k)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;

			if (maze[nx][ny] == 1 && key == 1)
				Q.push({ {nx,ny},{depth+1,0 } });

			if(maze[nx][ny] == 0)
				Q.push({ {nx,ny},{depth+1,key } });
		}
	}

	cout << "-1";
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> HX >> HY;
	cin >> EX >> EY;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> maze[i][j];

	bfs();

	return 0;
}
