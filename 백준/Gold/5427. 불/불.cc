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

int T, N, M;
char building[1001][1001];

queue<pair<int, int>> sang;
queue<pair<int, int>> fire;

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

void MoveFire()
{
	int cnt = fire.size();

	for (int i = 0; i < cnt; ++i)
	{
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();

		for (int j = 0; j < 4; ++j)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M)
				continue;
			if (building[nx][ny] != '.')
				continue;

			building[nx][ny] = '*';
			fire.push({nx, ny});
		}
	}
}

int MoveS()
{
	int time = 0;
	while (!sang.empty())
	{
		++time;
		MoveFire();

		int cnt = sang.size();
		for (int i = 0; i < cnt; ++i)
		{
			int x = sang.front().first;
			int y = sang.front().second;
			sang.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M)
					return time;

				if (building[nx][ny] != '.')
					continue;

				building[nx][ny] = '@';
				sang.push({nx, ny});
			}
		}
	}

	return -1;
}

void Reset()
{
	for(int i = 0 ; i <= N ; ++i)
		for(int j = 0 ; j <= M ; ++j)
			building[i][j] = '.';

	while(!sang.empty())
	sang.pop();

	while(!fire.empty())
	fire.pop();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> M >> N;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> building[i][j];

				if (building[i][j] == '@')
					sang.push({i, j});
				else if (building[i][j] == '*')
					fire.push({i, j});
			}
		}

		int time = MoveS();

		if (time == -1)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << time << "\n";

			Reset();
	}

	return 0;
}