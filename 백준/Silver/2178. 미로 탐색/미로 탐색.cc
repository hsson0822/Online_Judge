#include <iostream>
#include <queue>

using namespace std;

int N;
int M;

int maze[101][101];
int cnt[101][101];
bool visited[101][101];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push(pair(x, y));

	while (!que.empty())
	{
		auto x = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (maze[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[x.first][x.second] + 1;
				que.push(pair(nx, ny));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char ch;
			cin >> ch;
			maze[i][j] = ch-'0';
		}
	}

	visited[0][0] = true;
	cnt[0][0] = 1;
	bfs(0, 0);

	cout << cnt[N-1][M-1];

	return 0;
}