#include <bits/stdc++.h>

using namespace std;

int R, C;
int chess[501][501];
pair<int, int> dest[501][501];
int ball[501][501];

int dx[]{0, 1, 0, -1, 0, -1, -1, 1, 1};
int dy[]{0, 0, 1, 0, -1, -1, 1, 1, -1};

pair<int, int> dfs(int x, int y)
{
	int minValue = INT_MAX;
	int dir{};

	for (int i = 1; i < 9; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || ny <= 0 || nx > R || ny > C)
			continue;

		if (chess[x][y] > chess[nx][ny])
		{
			if (minValue > chess[nx][ny])
			{
				minValue = chess[nx][ny];
				dir = i;
			}
		}
	}

	if (dir == 0)
	{
		++ball[x][y];
		return {x,y};
	}
	else
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (dest[nx][ny] == make_pair(0,0))
		{
			pair<int, int> end = dfs(nx, ny);
			dest[x][y] = end;
			return end;
		}
		else
		{
			int ex = dest[nx][ny].first;
			int ey = dest[nx][ny].second;

			++ball[ex][ey];

			return dest[nx][ny];
		}
	}

	return {-1, -1};
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			cin >> chess[i][j];

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			dfs(i, j);

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cout << ball[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}