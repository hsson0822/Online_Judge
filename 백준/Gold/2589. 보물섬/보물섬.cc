#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int M;

char MAP[51][51];
bool visited[51][51];
int best{};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	queue<pair<pair<int, int>, int>> Q;
	Q.push(pair(pair(x, y), 0));

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int len = Q.front().second;
		visited[x][y] = true;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (MAP[nx][ny] == 'W') continue;
			if (visited[nx][ny]) continue;

			Q.push(pair(pair(nx,ny), len + 1));
			visited[nx][ny] = true;
			best = max(best, len + 1);
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
		for (int j = 1; j <= M; ++j)
			cin >> MAP[i][j];
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (MAP[i][j] == 'L')
			{
				bfs(i, j);

				memset(visited, false, sizeof(visited));
			}
		}
	}

	cout << best;

	return 0;
}