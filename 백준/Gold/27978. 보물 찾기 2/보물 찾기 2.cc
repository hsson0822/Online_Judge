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
char treasure[501][501];
int kx;
int ky;

int tx;
int ty;

int fuelX[]{1,-1,0,1,-1};
int fuelY[]{0,0,-1,-1,-1};

int noFuelX[]{-1,0,1};
int noFuelY[]{1,1,1};

const int INF = INT_MAX;
int visited[501][501];

void bfs()
{
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			visited[i][j] = INF;
		}
	}

	queue<tuple<int,int,int>> Q;
	visited[kx][ky] = 0;
	Q.push({ kx,ky,0 });

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int w = get<2>(Q.front());
		Q.pop();

		if (visited[x][y] < w) continue;

		for (int i = 0; i < 5; ++i)
		{
			int nx = x + fuelX[i];
			int ny = y + fuelY[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (treasure[nx][ny] == '#') continue;
			if (visited[nx][ny] <= w + 1) continue;
			
			visited[nx][ny] = w + 1;
			Q.push({ nx,ny,w + 1 });
		}

		for (int i = 0; i < 3; ++i)
		{
			int nx = x + noFuelX[i];
			int ny = y + noFuelY[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (treasure[nx][ny] == '#') continue;
			if (visited[nx][ny] <= w) continue;

			visited[nx][ny] = w;
			Q.push({ nx,ny,w});
		}
	}
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
			cin >> treasure[i][j];
			if (treasure[i][j] == 'K')
			{
				kx = i;
				ky = j;
			}
			else if (treasure[i][j] == '*')
			{
				tx = i;
				ty = j;
			}
			
		}
	}

	bfs();

	/*for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/

	if (visited[tx][ty] == INF)
		cout << -1;
	else
		cout << visited[tx][ty];

	return 0;
}
