#include <iostream>

using namespace std;

int N;

int pipe[17][17];

int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

int cnt;

void dfs(int x, int y, int dir)
{
	if (x > N || y > N)
		return;

	if (x == N && y == N)
	{
		++cnt;
		return;
	}

	if (pipe[x + 1][y] != 1 && pipe[x][y + 1] != 1 && pipe[x + 1][y + 1] != 1)
	{
		dfs(x + 1, y + 1, 2);
	}

	if (dir == 0)
	{
		if (pipe[x][y+1] != 1)
		{
			dfs(x, y + 1, 0);
		}
	}
	else if (dir == 1)
	{	
		if (pipe[x + 1][y] != 1)
		{
			dfs(x + 1, y, 1);
		}
	}
	else if (dir == 2)
	{

		if (pipe[x][y + 1] != 1)
		{
			dfs(x, y + 1, 0);
		}

		if (pipe[x + 1][y] != 1)
		{
			dfs(x + 1, y, 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int k;
			cin >> k;
			pipe[i][j] = k;
		}
	}

	dfs(1, 2, 0);

	cout << cnt;

	return 0;
}