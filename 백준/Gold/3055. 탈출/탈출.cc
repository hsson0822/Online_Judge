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

int R;
int C;
char forrest[51][51];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

int DX;
int DY;

int SX;
int SY;
queue<pair<int, int>> water;
int cache[51][51];


int bfs()
{
	queue<pair<int, int>> hedge;
	hedge.push({ SX,SY });
	cache[SX][SY] = 1;

	while (!hedge.empty())
	{
		int size = water.size();
		for (int i = 0; i < size; ++i)
		{
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;
				if (forrest[nx][ny] == '.')
				{
					forrest[nx][ny] = '*';
					water.push({ nx,ny });
				}
			}
		}

		int k = hedge.size();

		for (int i = 0; i < k; ++i)
		{
			int x = hedge.front().first;
			int y = hedge.front().second;
			hedge.pop();

			if (x == DX && y == DY)
			{
				return cache[x][y] - 1;
			}

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;

				if ((forrest[nx][ny] == '.' || forrest[nx][ny] == 'D') && cache[nx][ny] == 0 )
				{
					cache[nx][ny] = cache[x][y] + 1;
					hedge.push({ nx,ny });
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> forrest[i][j];

			if (forrest[i][j] == 'D')
			{
				DX = i;
				DY = j;
			}
			else if (forrest[i][j] == 'S')
			{
				SX = i;
				SY = j;
			}
			else if (forrest[i][j] == '*')
				water.push({ i,j });

		}
	}
	
	int result = bfs();
	if (result == -1)
		cout << "KAKTUS";
	else
		cout << result;


	return 0;
}
