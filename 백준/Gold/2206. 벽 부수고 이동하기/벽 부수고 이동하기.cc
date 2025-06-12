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

int world[1001][1001];
int visited[1001][1001][2];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };
const int INF = INT_MAX;

void bfs()
{
	

	queue<pair<pair<int, int>, pair<int,int> >> Q;
	Q.push({ {1,1},{1,1} });

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;

		int dist = Q.front().second.first;
		int key = Q.front().second.second;

		Q.pop();

		if (x == N && y == M)
		{
			//visited[x][y][key] = dist;
			cout << dist;
			return;
		}

		if (visited[x][y][key]) continue;
		visited[x][y][key] = 1;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;

			if (world[nx][ny] == 1 && key == 1)
				Q.push({ {nx,ny},{dist+1,0} });

			if (world[nx][ny] == 0)
				Q.push({ {nx,ny},{dist+1,key} });
		}
	}

	cout << -1;
	return;
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
			char ch;
			cin >> ch;

			world[i][j] = ch - '0';
		}

	}

	bfs();

	//int ans= -1;

	//if (visited[N][M][0] != INF && visited[N][M][1] != INF)
	//	ans = min(visited[N][M][0], visited[N][M][1]);
	//else if(visited[N][M][0] != INF)
	//	ans = visited[N][M][0];
	//else if (visited[N][M][1] != INF)
	//	ans = visited[N][M][1];

	//cout << ans;

	return 0;
}
