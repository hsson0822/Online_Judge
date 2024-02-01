#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int leng;

int program[251][251];
bool visited[251][251];
int cnt;

int dx[8]{ 1,0,-1,0,1,1,-1,-1 };
int dy[8]{ 0,1,0,-1,1,-1,1,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push(pair(x, y));

	while (!que.empty())
	{
		auto x = que.front();
		que.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (program[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
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
			int n;
			cin >> n;
			program[i][j] = n;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (program[i][j] == 1 && visited[i][j] == false)
			{
				++cnt;
				bfs(i, j);
			}
		}
	}

	cout << cnt;

	return 0;
}