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
char maze[501][501];
bool visited[501][501];
bool escape[501][501];

//	U R D L
int dx[]{-1, 0, 1, 0};
int dy[]{0, 1, 0, -1};

bool dfs(int i, int j)
{
	int x = i;
	int y = j;
	int dir = 0;

	if (maze[i][j] == 'U')
		dir = 0;
	else if (maze[i][j] == 'R')
		dir = 1;
	else if (maze[i][j] == 'D')
		dir = 2;
	else if (maze[i][j] == 'L')
		dir = 3;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (visited[nx][ny] && escape[nx][ny])
		return true;

	if (visited[nx][ny] && !escape[nx][ny])
		return false;

	if (nx <= 0 || ny <= 0 || nx > N || ny > M)
	{
		escape[x][y] = true;
		return true;
	}

	visited[x][y] = true;

	if (dfs(nx, ny))
	{
		escape[x][y] = true;
		return true;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> maze[i][j];

	int answer{};
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (dfs(i, j))
				++answer;

	cout << answer;

	return 0;
}