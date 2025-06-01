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
char ice[1001][1001];
int visited[1001][1001];

int sx, sy;
int ex, ey;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

bool answer;

void bfs()
{
	queue<pair<int, int>> Q;
	Q.push({ sx,sy });

	if (sx == ex && sy == ey)
		visited[sx][sy] = 1;
	else
		visited[sx][sy] = 2;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		//cout << x << " , " << y << endl;

		if (x == ex && y == ey && visited[x][y] == 2)
		{
			answer = true;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny] == 2) continue;
			
			if (nx == ex && ny == ey)
			{
				++visited[nx][ny];
			}
			else
				visited[nx][ny] = 2;

			Q.push({ nx,ny });
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
			cin >> ice[i][j];

			if (ice[i][j] == 'X')
			{
				visited[i][j] = 2;
			}
		}
	}

	cin >> sx >> sy;
	cin >> ex >> ey;

	if (visited[ex][ey] == 2)
		visited[ex][ey] = 1;

	bfs();
	
	if (answer)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
