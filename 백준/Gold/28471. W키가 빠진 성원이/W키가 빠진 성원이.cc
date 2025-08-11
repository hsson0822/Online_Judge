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
char game[2001][2001];
bool visited[2001][2001];

int sx, sy;

int dx[]{0, -1, 0, 1, 1, -1, -1};
int dy[]{1, 0, -1, 1, -1, 1, -1};

int answer{};

void bfs()
{
	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> Q;
	Q.push({sx, sy});
	visited[sx][sy] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 7; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				continue;
			if (visited[nx][ny])
				continue;
			if (game[nx][ny] == '#')
				continue;
				
			++answer;
			visited[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= N; ++j)
		{
			cin >> game[i][j];
			if (game[i][j] == 'F')
			{
				sx = i;
				sy = j;
			}
		}
	}

	bfs();

	cout << answer;

	return 0;
}