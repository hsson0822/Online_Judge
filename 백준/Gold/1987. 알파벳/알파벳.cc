#include <iostream>

using namespace std;

int R;
int C;
char board[21][21];
bool visited[26];

int dX[4]{ 1,0,-1,0 };
int dY[4]{ 0,1,0,-1};

int big{};

void dfs(int x, int y, int cnt)
{
	if (big < cnt)
		big = cnt;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dX[i];
		int ny = y + dY[i];

		if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;
		if (visited[board[nx][ny] - 'A']) continue;

		visited[board[nx][ny] - 'A'] = true;

		dfs(nx, ny, cnt + 1);
		visited[board[nx][ny] - 'A'] = false;

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			cin >> board[i][j];

	visited[board[1][1] - 'A'] = true;
	dfs(1, 1, 1);

	cout << big;

	return 0;
}