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

char maze[1001][1001];

int JX;
int JY;

queue<pair<int, int>> fire;

int dX[]{ 1,0,-1,0 };
int dY[]{ 0, 1,0,-1 };

int answer = INT_MAX;

void bfs()
{
	queue<tuple<int, int, int>> Q;
	Q.push({ JX,JY,1 });

	while (!Q.empty())
	{
		int size = Q.size();

		for (int k = 0; k < size; ++k)
		{
			int x, y, t;
			tie(x, y, t) = Q.front();
			Q.pop();

			if (maze[x][y] == 'F') continue;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dX[i];
				int ny = y + dY[i];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M)
				{
					answer = min(answer, t);
					continue;
				}

				if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;
				if (maze[nx][ny] == 'J') continue;

				maze[nx][ny] = 'J';
				Q.push({ nx,ny, t + 1 });
			}
		}

		int k = fire.size();

		for (int i = 0; i < k; ++i)
		{
			int fx = fire.front().first;
			int fy = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = fx + dX[j];
				int ny = fy + dY[j];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
				if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

				maze[nx][ny] = 'F';
				fire.push({ nx,ny });
			}
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
			cin >> maze[i][j];

			if (maze[i][j] == 'J')
			{
				JX = i;
				JY = j;
			}
			else if (maze[i][j] == 'F')
				fire.push({ i,j });
		}
	}

	bfs();

	if (answer == INT_MAX)
		cout << "IMPOSSIBLE";
	else
		cout << answer;

	return 0;
}
